// fila com vetor

#include <stdio.h>
#include <stdlib.h>

// definições

#define t 10

// tipos

struct fila{
    int vetor[t];
    int inicio;
    int fim;
};

// funções

void criarFila(struct fila* f);
void inserirFim(struct fila* f, int element);
void removerInicio(struct fila* f);
void limparFila(struct fila* f);
void exibirFila(struct fila f);

// main

int main(){
	struct fila f1;
	
	criarFila(&f1);
	
	exibirFila(f1);
	
	inserirFim(&f1, 1);
	
	exibirFila(f1);
	
	inserirFim(&f1, 2);
	inserirFim(&f1, 3);
	inserirFim(&f1, 4);
	
	exibirFila(f1);
	
	removerInicio(&f1);
	exibirFila(f1);
	
	removerInicio(&f1);
	exibirFila(f1);
	
	removerInicio(&f1);
	exibirFila(f1);
	
	removerInicio(&f1);
	exibirFila(f1);
	
	return 0;
}

// implementando funções

void criarFila(struct fila* f){
	f->inicio = -1;
	f->fim = -1;
}

void inserirFim(struct fila* f, int element){
	if(f->fim + 1 < t){
		if((f->inicio == -1) || (f->fim) == -1){
			f->inicio = 0;
		}
		f->vetor[f->fim + 1] = element;
		f->fim += 1;
	}else{
		printf("A fila está cheia!\n");
	}
}

void removerInicio(struct fila* f){
	if((f->inicio == -1) || (f->fim) == -1){
		printf("Não é possível remover elementos de uma fila vazia!\n");	
	}else{
		if(f->fim == f->inicio){
			f->fim = -1;
			f->inicio = -1; 
		}else{
			f->inicio += 1;
		}	
	}
}

void limparFila(struct fila* f){
	f->inicio = -1;
	f->fim = -1;
}

void exibirFila(struct fila f){
	if((f.inicio == -1) || (f.fim) == -1){
		printf("Não é possível remover elementos de uma fila vazia!\n");
	}else{
		int i = f.inicio;
		int j = f.fim;
		
		printf("Elementos da lista:");
		
		for(;i <= j; i++){
			printf(" %d", f.vetor[i]);
		}
		
		printf("\n");
	}
}

