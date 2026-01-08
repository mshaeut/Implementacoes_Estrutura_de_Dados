#include <stdio.h>
#include <stdlib.h>
/// declarando estrutura ///

struct no{
	int dado;
	struct no* prox;
};

/// declarando funções ///

void criarPilha(struct no** p);
void push(struct no** p, int element);
void pop(struct no** p);
void limparPilha(struct no** p);
void mostrarPilha(struct no* p);

/// função main ///

int main(){
	struct no* pilha;
	
	criarPilha(&pilha);
	
	printf("Mostando elementos:\n");
	mostrarPilha(pilha);
	
	push(&pilha, 4);
	push(&pilha, 3);
	push(&pilha, 2);
	push(&pilha, 1);
	
	printf("Mostando elementos:\n");
	mostrarPilha(pilha);
	
	pop(&pilha);
	
	printf("Mostando elementos:\n");
	mostrarPilha(pilha);
	
	limparPilha(&pilha);
	
	printf("Mostando elementos:\n");
	mostrarPilha(pilha);
	
	return 0;
}

/// inicializando funções ///

void criarPilha(struct no** p){
	*p = 0;
}

void push(struct no** p, int element){
	struct no* topo = (struct no*)malloc(sizeof(struct no));
	
	if(topo){
		topo->dado = element;
		topo->prox = *p;
		
		*p = topo;
	}else{
		printf("Alocação dinâmica de memória falhou!\n");
	}
}

void pop(struct no** p){
	if(*p){
		struct no* aux = *p;
		
		*p = (*p)->prox;
		free(aux);
	}else{
		printf("Não é possível remover elementos de uma pilha vazia!\n");
	}
}

void limparPilha(struct no** p){
	if(*p){		
		if((*p)->prox){
			limparPilha(&((*p)->prox));
		}
		
		free(*p);
		*p = 0;
	}else{
		printf("A lista já está vazia!\n");
		return;
	}
}

void mostrarPilha(struct no* p){
	if(p){
		if(p->prox){
			printf("%d\n", p->dado);
			mostrarPilha(p->prox);
		}else{
			printf("%d\n", p->dado);
		}
		return;
	}else{
		printf("Não é possível exibir elementos de uma lista vazia!\n");
	}
}
