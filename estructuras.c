//estructuras
#include <stdio.h>
#include <stdlib.h>

typedef struct{ 
    char dato;
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


int main(){

    Nodo* nodo = new();
    nodo->dato = 5;
       
    return(0);
}
