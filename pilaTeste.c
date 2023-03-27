#include <stdio.h>
#include "bibliotecaPilha.h"

int menu(){
	int op;
	printf("*** Estrutura de Dados I - Pilha Estatica ****\n");
	printf("1-Push (Inserir)\n");
	printf("2-Pop (Remover)\n");
	printf("3-Peek (Olhar Topo)\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------------
int main(){
	tPilha p1;
	inicializa(&p1);
	tdado dado; // 
	int op;
	do{
		printf("Indice do Topo:[%d]\n",p1.topo);
		mostraPilha(p1);
		op = menu();
		switch(op){
			case 1: printf("Dado para pilha [X e Y]:");
					scanf("%d",&dado.x);
					scanf("%d",&dado.y);
					if(push(&p1,dado)==1)
						printf("Inserido com sucesso\n");
					else
						printf("Pilha cheia - Stack Overflow\n");	
			break;
			case 2:	if(!isEmpty(p1)){//se nao for vazio
						dado = pop(&p1);
						printf("Dado removido:[%d,%d]\n",dado.x,dado.y);
					}
					else
						printf("Pilha vazia\n");
				break;
			case 3:	if(!isEmpty(p1)){//se nao for vazio
						dado = peek(p1);
						printf("Dado do topo:%d\n",dado);
					}
					else
						printf("Pilha vazia\n");
				break;	
								
		}// fim switch
	    getch();// pausa
		system("cls");// limpa tela	
	}while(op!=0);
	return 0;                                
}
