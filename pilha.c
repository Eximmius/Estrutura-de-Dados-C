#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "pilha.h"
#include "no.h"

struct pilhas {
    lista_enc_t* lista;
};


pilha_t* cria_pilha (){
    pilha_t* pilha = (pilha_t*)malloc (sizeof(pilha_t));
    if (pilha==NULL){
        perror("malloc pilha_t");
        exit(EXIT_FAILURE);
    }
    pilha->lista=cria_lista_enc();

    return pilha;
}

void push (void* dado, pilha_t* pilha){

    no_t* elemento = cria_no(dado);
    add_cabeca(pilha->lista, elemento);

}

void* pop (pilha_t* pilha){
    if (obtem_cabeca(pilha->lista) == NULL){
        //vazia
        return NULL;
    } else{
        void* dado_topo = obtem_dado(obtem_cabeca(pilha->lista));
        remove_cabeca(pilha->lista);
        return dado_topo;
    }

}

void libera_pilha (pilha_t* pilha){
    free (pilha->lista);
    free (pilha);
}

