#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h> //confirmar

int main()
{

    //manejo de archivos
    char *ptrContent = NULL;
    long filesize = 0;
    FILE *ptrFile = NULL;
    ////////////////////////
    int client_socket, server_socket = 0;
    int addr_length = 0;
    char buff[] = "Hola desde mi primer servidor\r\n";
    char buff_receive[80] = {0};

    struct sockaddr_in server, client;
    //crear server socket
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        printf("Error al crear el socket\r\n");
        return (-1);
    }

    //configurar estructura del servidor
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = INADDR_ANY; //cualquier dirección //como pasar varias direcciones ips ? witheList
    server.sin_port = htons(12001);

    //enlace
    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Error de enlace\r\n");
        return (-1);
    }

    printf("Enlace Realizado\r\n");
    listen(server_socket, 2); //virtuales
    printf("Esperando conexiones\r\n");

    while (1)
    {
        client_socket = accept(server_socket, (struct sockaddr *)&client, &addr_length); //bloqueante
        while (recv(client_socket, buff_receive, sizeof(buff_receive), 0) > 0)
        {
            if (strncmp("GET", buff_receive, 3) == 0)
            {            
                ptrFile = fopen("index.html", "r");
                if (ptrFile == NULL)
                {
                    printf("Archivo no encontrado\r\n");
                    return (0);
                }
                printf("Archivo encontrado\r\n");
                fseek(ptrFile, 0L, SEEK_END); // enviar al final del archivo
                filesize = ftell(ptrFile);
                fseek(ptrFile, 0L, SEEK_SET); //enviar al inicio del archivo                
                ptrContent = (char *)malloc(filesize);
                fread(ptrContent, 1, filesize, ptrFile);                
                send(client_socket, ptrContent, filesize, 0);
                for(int i=0; i<100000000; i++);
                close(client_socket);
                free(ptrContent);
                fclose(ptrFile);
            }                      
        }       
    }    

    close(server_socket);
    close(client_socket);
    
    return (0);
}
