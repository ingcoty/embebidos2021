//estructuras
#include <stdio.h>
#include <stdlib.h>

int main(){
    char tecla = 0;
    while( tecla != 'q'){
        printf("seleccione una opción\r\n");
        scanf("%c", &tecla);

        switch (tecla)
        {
        case '1':
            printf("seleccionaste la opcion 1\r\n");
            break;
        
        case '2':
            printf("seleccionaste la opcion 2\r\n");
            break;

        default:
            printf("opción no existe\r\n");
            break;
        }
    }

    return(0);
}