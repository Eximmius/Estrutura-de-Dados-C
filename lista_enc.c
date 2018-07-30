#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

//#define DEBUG

struct listas_enc {
    no_t* cabeca;
    no_t* cauda;
    int tamanho;
};

//cria uma lista vazia
lista_enc_t* cria_lista_enc (void) {
    lista_enc_t* p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void add_cauda(lista_enc_t* lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   //lista vazia
   if (lista->tamanho == 0)
   {

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desliga_no(elemento);
        // Liga cauda da lista com novo elemento
        liga_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}

no_t* obtem_cabeca(lista_enc_t* lista){
    return lista->cabeca;
}

void add_cabeca (lista_enc_t* lista, no_t* elemento){

    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   //lista vazia
   if (lista->tamanho == 0){

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);
   } else {
        // Liga cauda da lista com novo elemento
        liga_nos(elemento,lista->cabeca);

        lista->cabeca = elemento;
        lista->tamanho++;
   }
}

void* remove_cabeca (lista_enc_t* lista){

    if (lista == NULL){
        fprintf(stderr,"remove cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no_t* old_head = lista->cabeca;
    void* dado = NULL;

    if (lista->tamanho > 0)
        dado = obtem_dado(old_head);

    if (lista->tamanho == 0){

        return NULL;

    } else if (lista->tamanho == 1){
        lista->cabeca = NULL;
        (lista->tamanho)--;
        desliga_no(old_head);

    } else{
        lista->cabeca = obtem_proximo(old_head);
        (lista->tamanho)--;
    }

    free (old_head);
    return dado;
}


