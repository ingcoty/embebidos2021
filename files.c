#include <stdio.h>
#include <stdlib.h>

int main(){
    char* ptrContent = NULL;
    long filesize = 0;
    FILE* ptrFile = NULL;
    ptrFile = fopen("index.html", "r");
    if(ptrFile == NULL){
        printf("Archivo no encontrado\r\n");
        return(0);
    }
    printf("Archivo encontrado\r\n");
    fseek(ptrFile, 0L, SEEK_END);  // enviar al final del archivo
    filesize = ftell(ptrFile);
    fseek(ptrFile, 0L, SEEK_SET);  //enviar al inicio del archivo
    printf("size -> %ld\r\n", filesize);
    ptrContent = (char*) malloc(filesize);
    fread(ptrContent, 1, filesize, ptrFile);
    printf(ptrContent);
    free(ptrContent);
    fclose(ptrFile);
    return(0);
}