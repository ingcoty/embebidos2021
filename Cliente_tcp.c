#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h> //confirmar

//SOCK_STREAM -> TCP
//SOCK_DGRAM -> UDP

int main(){
    
    int conection = 0;
    int socket_id = 0;
    char msg[] = "GET\r\n";
    char buff[50] = {0};
    socket_id = socket(PF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("200.25.20.50");
    server.sin_port = htons(123);

    conection = connect(socket_id, (struct sockaddr*)&server, sizeof(server));
    if(conection < 0){
        printf("Error al realizar la conexión\r\n");
        return(-1);
    }

    printf("Conexión realizada con éxito\r\n");
    //send(socket_id, msg, sizeof(msg), 0);
    while(recv(socket_id, buff, sizeof(buff), 0) > 0){
        printf("%s", buff);
    }

    close(socket_id);          
    return(0);   
}