#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;     //CORDENADAS LABIRINTO 
    int y;
} tdado;

typedef struct no {
    tdado dado;
    struct no *prox;
} tno;

typedef struct pilha {
    tno *topo;
} tPilha;

//-----------------------------------

void inicializa(tPilha *p) {
    p->topo = NULL;
}

//-----------------------------------

int push(tPilha *p, tdado novoDado) {
    tno *novo;
    novo = malloc(sizeof(tno));    
    
    if(novo == NULL)
        return 0;
    
    novo->dado = novoDado; //atribui o valor
    novo->prox = p->topo; //proximo é quem era o topo
    p->topo = novo;
    return 1;
}

//-----------------------------------

tdado pop(tPilha *p) {
    tdado removido = p->topo->dado;
    tno *aux = p->topo; // guardar endereço para liberar
    p->topo = p->topo->prox; //movendo o topo para o no de baixo
    free(aux);//libera a area de memoria
    return removido;
}

//------------------------------------

int isEmpty(tPilha p) {
    return p.topo == NULL;
}

//-----------------------------------------

void mostraPilha(tPilha p) {
    tno *aux = p.topo;
    while (aux != NULL) {
        printf("([%d|%d])", aux->dado.x, aux->dado.y);
        aux = aux->prox;
    }
    printf("\n");
}

//-----------------------------------------

//---------------------------------------





































