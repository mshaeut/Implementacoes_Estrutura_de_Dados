// pilha com vetor

#include <stdio.h>
#include <stdlib.h>

// definições

#define t 10

// tipos

struct pilha{
    int vetor[t];
    int topo;
};

// funções

void criarPilha(struct pilha* p);
void push(struct pilha* p, int element);
void pop(struct pilha* p);
void limparPilha(struct pilha* p);
void mostrarPilha(struct pilha* p, int aux);

// main

int main(){
	struct pilha p1;
	
	criarPilha(&p1);
	
	push(&p1, 4);
	push(&p1, 3);
	push(&p1, 2);
	push(&p1, 1);
	
	printf("Mostando elementos:\n");
	mostrarPilha(&p1, p1.topo);
	
	pop(&p1);
	
	printf("Mostrando elementos:\n");
	mostrarPilha(&p1, p1.topo);
	
	limparPilha(&p1);
	
	printf("Mostrando elementos:\n");
	mostrarPilha(&p1, p1.topo);
	
	return 0;
}

// implementando funções

void criarPilha(struct pilha* p){
	p->topo = -1;
}

void push(struct pilha* p, int element){
	if(p->topo + 1 < t){
		p->vetor[p->topo + 1] = element;
		p->topo += 1;
	}else{
		printf("Não há mais espaço na pilha!\n");
	}
}

void pop(struct pilha* p){
	if(p->topo != -1){
		p->topo -= 1;
	}else{
		printf("Não é possível remover elementos de uma pilha vazia!\n");
	}
}

void limparPilha(struct pilha* p){
	p->topo = -1;
}

void mostrarPilha(struct pilha* p, int aux){
	if(p->topo != -1){
		if(aux == -1){
			return;
		}else{
			printf("%d\n", p->vetor[aux]);
			mostrarPilha(p, aux - 1);
		}
	}else{
		printf("Não é possível mostrar elementos de uma pilha vazia!\n");
	}
}
