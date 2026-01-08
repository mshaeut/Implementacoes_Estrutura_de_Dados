// bibliotecas

#include <stdio.h>
#include <stdlib.h>

// funções e estruturas

struct no{
	struct no* ant;
	int dado;
	struct no* prox;
};

struct lista{
	struct no* init;
	struct no* fim;
};

void criarLista(struct lista* list);
void inserirInicio(struct lista* list, int element);
void inserirMeio(struct lista* list, int element);
void inserirFim(struct lista* list, int element);
void removerInicio(struct lista* list);
void removerMeio(struct lista* list, int element);
void removerFim(struct lista* list);
void limparLista(struct lista* list);
void exibirLista(struct lista list);

void concatenarLista(struct lista* list1, struct lista* list2);
struct lista dividirLista(struct lista* list, int element);

// main

int main(){
	struct lista lista1, lista2;
	
	exibirLista(lista1);
	//exibirLista(lista2);
	
	criarLista(&lista1);
	//criarLista(&lista2);
	
	inserirInicio(&lista1, 3);
	inserirInicio(&lista1, 2);
	inserirInicio(&lista1, 0);
	
	exibirLista(lista1);

	inserirMeio(&lista1, 1);
	inserirFim(&lista1, 4);
	inserirMeio(&lista1, -1);
	inserirMeio(&lista1,-2);
	
	exibirLista(lista1);
	
	lista2 = dividirLista(&lista1, 1);

	exibirLista(lista1);
	exibirLista(lista2);
	
	concatenarLista(&lista1, &lista2);
	
	exibirLista(lista1);
	exibirLista(lista2);
	
	limparLista(&lista1);
	limparLista(&lista2);
	
	exibirLista(lista1);
	exibirLista(lista2);
	
	return 0;
}

// implementando funções

void criarLista(struct lista* list){
	list->init = 0;
	list->fim = 0;
}

void inserirInicio(struct lista* list, int element){
	struct no* novo = (struct no*)malloc(sizeof(struct no));
	
	if(novo){
		novo->dado = element;
		novo->ant = 0;
		novo->prox = list->init;
		
		if((list->init == 0) && (list->fim == 0)){
			list->init = novo;
			list->fim = novo;
		}else{
			list->init->ant = novo;
			list->init = novo;
		}
	}else{
		printf("Alocação dinâmica falhou!\n");
	}
}

void inserirMeio(struct lista* list, int element){
	struct no* novo = (struct no*)malloc(sizeof(struct no));
	struct no* aux1 = list->init;
	struct no* aux2 = 0;
	
	
	if(novo){
		novo->dado = element;
		
		for(; aux1 && (novo->dado > aux1->dado); aux1 = aux1->prox){
			aux2 = aux1;
		}
		
		if(aux2){
			novo->ant = aux2;
			novo->prox = aux2->prox;
			
			if(aux2->prox != 0){
				novo->prox->ant = novo;
				novo->ant->prox = novo;
			}else{
				novo->ant->prox = novo;
				list->fim = novo;
			}
		}else{
			inserirInicio(list, element);
		}
	}else{
		printf("Alocação dinâmica falhou!\n");
	}
}

void inserirFim(struct lista* list, int element){
	struct no* novo = (struct no*)malloc(sizeof(struct no));
	
	if(novo){
		novo->dado = element;
		novo->prox = 0;
		novo->ant = list->fim;
		
		if((list->init == 0) && (list->fim == 0)){
			list->init = novo;
			list->fim = novo;
		}else{
			list->fim->prox = novo;
			list->fim = novo;
		}
	}else{
		printf("Alocação dinâmica falhou!\n");
	}
}

void removerInicio(struct lista* list){
	struct no* aux = list->init;
	
	if(aux){
		if(aux->prox){
			aux->prox->ant = 0;
			list->init = aux->prox;
			free(aux);
		}else{
			list->init = aux->prox;
			list->fim = list->init;
			free(aux);
		}
	}else{
		printf("Não é possível remover elementos de uma lista vazia!\n");
	}	
}

void removerMeio(struct lista* list, int element){
	struct no* aux = list->init;
	
	if(aux){
		for(;aux && (aux->dado != element); aux = aux->prox){
		}
		
		if(aux->ant == 0 && aux->prox == 0){
			list->init = 0;
			list->fim = 0;
		}else if(aux->ant == 0){
			aux->prox->ant = aux->ant;
			list->init = aux->prox;
		}else if(aux->prox == 0){
			aux->ant->prox = aux->prox;
			list->fim = aux->ant;
		}else{
			aux->prox->ant = aux->ant;
			aux->ant->prox = aux->prox;
		}
		free(aux);
	}else{
		printf("Não é possível remover elementos de uma lista vazia!\n");
	}
}

void removerFim(struct lista* list){
	struct no* aux = list->fim;
	
	if(aux){
		if(aux->ant){
			aux->ant->prox = 0;
			list->fim = aux->ant;
			free(aux);
		}else{
			list->fim = aux->ant;
			list->init = list->fim;
			free(aux);
		}
	}else{
		printf("Não é possível remover elementos de uma lista vazia!\n");
	}	
}

void limparLista(struct lista* list){
	struct no* aux = list->init;
	
	if(aux){	
		for(;aux ; aux = aux->prox){
			removerInicio(list);
		}
	}else{
		printf("A lista já está vazia!\n");
	}
}

void exibirLista(struct lista list){
	struct no* aux = list.init;
	
	if(aux){
		printf("Elementos da lista: ");
		
		for(; aux; aux = aux->prox){
			printf("%d ", aux->dado);
		}
		
		printf("\n");
	}else{
		printf("Não é possível exibir os elementos de uma lista vazia!\n");
	}
}

void concatenarLista(struct lista* list1, struct lista* list2){
	struct no* aux = list2->init;
	
	for(;aux ; aux = aux->prox){
		inserirMeio(list1,aux->dado);
		removerMeio(list2,aux->dado);
	}
}

struct lista dividirLista(struct lista* list, int element){
	struct no* aux = list->init;
	struct lista nlist;
	
	criarLista(&nlist);
	
	for(; aux->dado != element; aux = aux->prox);
	
	aux->ant->prox = 0;
	list->fim = aux->ant;
	aux->ant = 0;
	
	nlist.init = aux;
	
	for(; aux->prox; aux = aux->prox);
	
	nlist.fim = aux;
	
	return nlist;
}
