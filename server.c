#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h> //confirmar

int main(){

    int client_socket, server_socket = 0;
    int addr_length = 0;
    char buff[] = "Hola desde mi primer servidor\r\n";
    char buff_receive[80] = {0};
    
    struct sockaddr_in server, client;
    //crear server socket
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if(server_socket < 0){
        printf("Error al crear el socket\r\n");
        return(-1);
    }

    //configurar estructura del servidor
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = INADDR_ANY; //cualquier dirección //como pasar varias direcciones ips ? witheList
    server.sin_port = htons(12001);

    //enlace
    if(bind(server_socket, (struct sockaddr*)&server, sizeof(server)) < 0){
        printf("Error de enlace\r\n");
        return(-1);
    }

    printf("Enlace Realizado\r\n");
    listen(server_socket, 2);//virtuales
    printf("Esperando conexiones\r\n");    
   
    client_socket = accept(server_socket, (struct sockaddr*)&client, &addr_length); //bloqueante     
    printf("Cliente conectado\r\n");
    while(recv(client_socket, buff_receive, sizeof(buff_receive), 0) > 0){
        printf("%s\r\n", buff_receive);
    }
    //send(client_socket, buff, sizeof(buff),0);
    close(server_socket);
    close(client_socket);
    return(0);
}





