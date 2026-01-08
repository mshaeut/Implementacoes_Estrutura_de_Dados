#include <stdio.h>
#include <stdlib.h>
/// declarando estrutura ///

struct no{
	int dado;
	struct no* prox;
};

/// declarando funções ///

void criarLista(struct no** list);
void inserirInicio(struct no** list, int element);
void inserirMeio(struct no** list, int element);
void inserirFim(struct no** list, int element);
void removerInicio(struct no** list);
void removerMeio(struct no** list, int element);
void removerFim(struct no** list);
void limparLista(struct no** list);
void mostrarLista(struct no* list);

/// função main ///

int main(){
	struct no* lista;
	
	criarLista(&lista);
	mostrarLista(lista);
	
	inserirFim(&lista, 1);
	
	mostrarLista(lista);
	
	inserirMeio(&lista, 0);
	inserirMeio(&lista, -1);
	inserirMeio(&lista, 2);
	inserirMeio(&lista, 3);
	inserirMeio(&lista, 4);
	
	mostrarLista(lista);
	
	limparLista(&lista);
	
	mostrarLista(lista);
	
	return 0;
}

/// inicializando funções ///

void criarLista(struct no** list){
	*list = 0;
}

void inserirInicio(struct no** list, int element){
	struct no* novo = (struct no*) malloc(sizeof(struct no));
	
	if(novo){
		novo->dado = element;
		novo->prox = *list;
		
		*list = novo;	
	}else{
		printf("Alocação dinâmica de memória mal sucedida!\n");
	}
}

void inserirMeio(struct no** list, int element){
	struct no* aux1 = *list;
	struct no* novo = (struct no*)malloc(sizeof(struct no));
	struct no* aux2 = 0;
		
	if(novo){
		novo->dado = element;
			
		//for(; aux1 && (novo->dado > aux1->dado); aux1 = aux1->prox){
		for(;aux1 && (aux1->dado < element); aux1 = aux1->prox){
			aux2 = aux1;
		}
			
		if(aux2 == 0){
			inserirInicio(list,element);
		}else{
			novo->prox = aux2->prox;
			aux2->prox = novo;
		}
	}else{
		printf("Alocação dinâmica de memória mal sucedida!\n");
	}	
}

void inserirFim(struct no** list, int element){
	struct no* aux = *list;
	
	if(aux == 0){
		inserirInicio(list,element);
	}else{
		struct no* novo = (struct no*)malloc(sizeof(struct no));

		if(novo){
			novo->dado = element;
			novo->prox = 0;
					
			for(; aux->prox; aux = aux->prox);
			
			aux->prox = novo;	
		}else{
			printf("Alocação dinâmica de memória mal sucedida!\n");
		}
	}
}

void removerInicio(struct no** list){
	if(*list){
		struct no* aux = *list;
	
		*list = (*list)->prox;
		free(aux);
	}else{
		printf("Não é possível remover elementos de uma lista vazia!\n");
	}
}

void removerMeio(struct no** list, int element){
	if(*list){
		struct no* remov = *list;
		struct no* aux = 0;
		
		for(; remov->prox && remov->dado != element; remov = remov->prox){
			aux = remov;
		}
		
		if(aux == 0){
			removerInicio(list);
		}else{
			aux->prox = remov->prox;
			free(remov);
		}
	}else{
		printf("Não é possível remover elementos de uma lista vazia!\n");
	}
}

void removerFim(struct no** list){
	if(*list){
		struct no* remov = *list;
		struct no* aux = 0;
		
		for(; remov->prox; remov = remov->prox){
			aux = remov;
		}
		
		if(aux == 0){
			removerInicio(list);
		}else{
			aux->prox = remov->prox;
			free(remov);
		}
	}else{
		printf("Não é possível remover elementos de uma lista vazia!\n");
	}
}

void limparLista(struct no** list){
	if(*list){
		struct no* aux;
		
		for(aux = *list; aux; aux = *list){
			*list = (*list)->prox;
			free(aux);
		}
	}else{
		printf("A lista já está limpa!\n");
	}
}

void mostrarLista(struct no* list){
	if(list){
		printf("Elementos da lista: ");
		
		while(list != 0){
			printf("%d ",list->dado);
			list = list->prox;
		}
		
		printf("\n");
	}else{
		printf("Não é possível exibir elementos de uma lista vazia!\n");
	}
}
