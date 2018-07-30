#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "velhus.h"
#include "lista_enc.h"
#include "pilha.h"

struct pessoa
{
    char *nome;
    int idade;
    char sexo;
};

pilha_t* ler_arq(char* nome){

    int size, i, ret;
    char str[100];
    int idade;
    char sexo;
    pilha_t* pilha = cria_pilha();

    FILE* fp = fopen (nome,"r");
    if (fp == NULL){
        perror ("velhinhos.csv");
        exit(EXIT_FAILURE);
    }

    fgets(str,100,fp); //pula cabeçalho

    for(size=0; !feof(fp); size++) //tamanho do arquivo
        fgets(str,100,fp);
    rewind(fp);

    fgets(str,100,fp); //pula cabeçalho

    for(i=0; i<size; i++)
    {
        ret = fscanf(fp,"%100[^,],%d,%c\n",str,&idade,&sexo);
        //printf("%s; %d; %c\n", str, idade, sexo);
        if (ret != 3){
            perror ("arquivo corrompido");
            exit(EXIT_FAILURE);
        }

       velhos* pessoa = cria_velho(str, idade, sexo);
       push ((void*)pessoa, pilha);

    }
    fclose(fp);

    return pilha;
}

velhos* cria_velho(char *nome, int idade, char sexo){

    velhos* p = malloc(sizeof(velhos));

    if (p == NULL){
        perror ("malloc cria velho");
        exit(EXIT_FAILURE);
    }

    p->nome = malloc(strlen(nome)+1);

    if (p->nome == NULL){
        perror ("malloc nome");
        exit(EXIT_FAILURE);
    }
    strcpy(p->nome, nome);
    p->idade = idade;
    p->sexo = sexo;

    return p;
}

char* obter_nome (velhos* pessoa){
    return pessoa->nome;
}

int obter_idade (velhos* pessoa){
    return pessoa->idade;
}

char obter_sexo (velhos* pessoa){
    return pessoa->sexo;
}

void libera_pessoa(velhos* pessoa){
    free(pessoa->nome);
    free(pessoa);
}



