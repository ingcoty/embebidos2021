//punteros
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num_est = 0;
    char i=0;
    char* ptrInt = NULL;
    printf("ingrese el número de estudiantes \r\n");
    scanf("%d", &num_est);
   
    ptrInt = (char*) malloc(num_est); // malloc( tamaño de memoria en Bytes ) -> void*

    for(i=0; i<num_est; i++){
        *(ptrInt + i) = i;
        printf("%ld, ", (ptrInt + i));
    }

    free(ptrInt); //recolector de basura...
 
    return(0);
}
