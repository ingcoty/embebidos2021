#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h> //confirmar

//SOCK_STREAM -> TCP
//SOCK_DGRAM -> UDP

int main(){
    
    int conection = 0;
    int socket_id = 0;
    char msg[] = "hola sistemas embebidos\r\n";
    socket_id = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(12000);

    conection = connect(socket_id, (struct sockaddr*)&server, sizeof(server));
    if(conection < 0){
        printf("Error al realizar la conexión\r\n");
        return(-1);
    }

    printf("Conexión realizada con éxito\r\n");
    send(socket_id, msg, sizeof(msg), 0);
    close(socket_id);          
    return(0);   
}