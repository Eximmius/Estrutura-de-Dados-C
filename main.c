#include <stdio.h>
#include <stdlib.h>
#include "lista_enc.h"
#include "no.h"
#include "velhus.h"
#include "pilha.h"

int main(){

    velhos* pessoa = NULL;
    pilha_t* pilha = (pilha_t*)ler_arq("velhinhos.csv");

    pessoa = pop (pilha);

    while (pessoa != NULL){
        printf ("%s, %d, %c\n", obter_nome(pessoa), obter_idade(pessoa), obter_sexo(pessoa));
        libera_pessoa(pessoa);
        pessoa = pop (pilha);
    }
    libera_pilha(pilha);
    return 0;

}
