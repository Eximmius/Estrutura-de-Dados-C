#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilhas pilha_t;

pilha_t* cria_pilha();

void push (void* dado, pilha_t* pilha);

void* pop (pilha_t* pilha);

void libera_pilha (pilha_t* pilha);


#endif // PILHA_H_INCLUDED
