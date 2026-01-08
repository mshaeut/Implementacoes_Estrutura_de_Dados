// bibliotecas

#include <stdio.h>
#include <stdlib.h>

// funï¿½ï¿½es e estruturas

struct no{
	int dado;
	struct no* prox;
};

struct fila{
	struct no* init;
	struct no* fim;
};

void criarFila(struct fila* f);
void inserirFim(struct fila* f, int element);
void removerInicio(struct fila* f);
void limparFila(struct fila* f);
void exibirFila(struct fila f);
void exibirFila2(struct no* inicio);
void copiarFila(struct fila* fb, struct fila* fc);

// main

int main(){
	struct fila f1, f2;
	
	criarFila(&f1);
	criarFila(&f2);
	
	exibirFila(f1);
	exibirFila(f2);
	
	inserirFim(&f1, 1);
	inserirFim(&f1, 2);
	inserirFim(&f1, 3);
	inserirFim(&f1, 4);
	
	exibirFila(f1);
	
	copiarFila(&f1, &f2);
	
	exibirFila(f1);
	exibirFila(f2);
	
	limparFila(&f1);
	limparFila(&f2);
	
	exibirFila(f1);
	exibirFila(f2);
	
	return 0;
}

// implementando funï¿½ï¿½es

void criarFila(struct fila* f){
	f->init = 0;
	f->fim = 0;
}

void inserirFim(struct fila* f, int element){
	struct no* novo = (struct no*)malloc(sizeof(struct no));
	
	if(novo){
		novo->dado = element;
		novo->prox = 0;
		
		if((f->init == 0) || (f->fim == 0)){
			f->init = novo;
			f->fim = novo;
		}else{
			f->fim->prox = novo;
			f->fim = novo;
		}
	}else{
		printf("Alocação dinâmica de memória mal sucedida!\n");
	}
}

void removerInicio(struct fila* f){
	if((f->init == 0) || (f->fim == 0)){
		printf("Não é possível remover elementos de uma lista vazia!\n");
	}else{
		struct no* aux = f->init;
		
		if(f->init == f->fim){
			f->init = 0;
			f->fim = 0;
		}else{
			f->init = f->init->prox;
		}	
		
		free(aux);
	}
}

void limparFila(struct fila* f){
	if((f->init == 0) || (f->fim == 0)){
		printf("A lista já está vazia!\n");
	}else{
		struct no* aux = f->init;
		
		for(; aux; aux = f->init){
			f->init = f->init->prox;
			free(aux);
		}
		
		f->fim = 0;
	}
}

void exibirFila2(struct no* inicio){
	if(inicio == 0){
		return;
	}

	printf("%d ", inicio->dado);
	exibirFila2(inicio->prox);
}

void exibirFila(struct fila f){
	if(f.init == 0 && f.fim == 0){
		printf("Não é possível exibir os elementos de uma lista vazia!\n");
	}else{
		struct no* aux = f.init;
		
		printf("Elementos da lista:");
		
		for(; aux; aux = aux->prox){
			printf(" %d", aux->dado);
		}
		
		printf("\n");
	}
}

void copiarFila(struct fila* fb, struct fila* fc){ //questão 7
	if(fb->init){
		inserirFim(fc, fb->init->dado);
		removerInicio(fb);
		copiarFila(fb, fc);
	}
	
	return;
}
