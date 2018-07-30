#ifndef VELHUS_H_INCLUDED
#define VELHUS_H_INCLUDED

#include "pilha.h"
#include "lista_enc.h"

typedef struct pessoa velhos;


//lista_enc_t* ler_arq(char*);

pilha_t* ler_arq(char* nome);

velhos* cria_velho(char*, int, char);
char* obter_nome (velhos*);
int obter_idade (velhos*);
char obter_sexo (velhos* pessoa);
void libera_pessoa(velhos* pessoa);

#endif // VELHUS_H_INCLUDED
