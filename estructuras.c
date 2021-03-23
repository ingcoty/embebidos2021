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

void walkList(){
    Nodo* i = header;
    if(i == NULL){
        printf("Lista Vacia\r\n");        
        return;
    } 
    while(i != NULL){
        printf("%d->", i->dato);
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
    nodo->dato = 5;
    insertar(nodo);

    Nodo* nodo2 = new();
    nodo2->dato = 10;
    insertar(nodo2);
    
    Nodo* nodo3 = new();
    nodo3->dato = 15;
    insertar(nodo3);

    Nodo* nodo4 = new();
    nodo4->dato = 20;
    insertar(nodo4);

    walkList();

    free_memory();

    walkList();
       
    return(0);
}
