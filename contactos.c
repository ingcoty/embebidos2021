//estructuras
#include <stdio.h>
#include <stdlib.h>

typedef struct estructuras
{
    char* nombre;
    long celular;
    char* grupo;

}contacto;

typedef struct{ 
    contacto registro;
    struct Nodo* ptrNext;
}Nodo;

Nodo* header = NULL;
Nodo* footer = NULL;

//creamos el nodo nuevo
Nodo* new(){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->ptrNext = NULL;
    return(nuevo);
}

void insertar(Nodo* nodo){
    if(header == NULL){
        header = nodo;
        footer = nodo;
    }
    else{
        footer->ptrNext = nodo;
        footer = nodo;
    }
}

void walkList(){
    Nodo* i = header;
    if(i == NULL){
        printf("Lista Vacia\r\n");        
        return;
    } 
    while(i != NULL){
        printf("nombre: %s\r\n", i->registro.nombre);
        printf("grupo: %s\r\n", i->registro.grupo);
        printf("cel: %ld\r\n", i->registro.celular);
        i = i->ptrNext;
    } 
    printf("\r\n");  
}

void free_memory(){
    Nodo* i = header;
    if(i == NULL){
        printf("Lista Vacía\r\n");
        return;
    }
    while(i != NULL){
        header = i->ptrNext;
        free(i);
        i = header;
    }
    header = NULL;
    footer = NULL;
    printf("Memoria Liberada\r\n");
}

int main(){

    Nodo* nodo = new();
    nodo->registro.nombre = "Carlos";
    nodo->registro.celular = 3232223231;
    nodo->registro.grupo = "trabajo";

    insertar(nodo);

    Nodo* nodo2 = new();
    nodo2->registro.nombre = "Anderson";
    nodo2->registro.celular = 323432321;
    nodo2->registro.grupo = "estudiante";

    insertar(nodo2);

    walkList();

    free_memory();
      
    return(0);
}