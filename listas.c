// lista com vetor

#include <stdio.h>

// definições

#define t 10

// tipos

typedef struct{
    int vetor[t];
    int controle;
}lista;

// funções

int verificarLista(lista*);
void criarLista(lista*);
void limparLista(lista*);
void inserirFim(lista*, int);
void inserirInicio(lista *, int);
void inserirOrdenado(lista*, int);
void removerFim(lista*);
void removerInicio(lista*);
void mostrarLista(lista*);

/////////////////////////////////

int main(){
	lista l1;
	
	criarLista(&l1);
	//inserirFim(&l1,1);
	//inserirFim(&l1,2);
	//inserirFim(&l1,4);
	//inserirFim(&l1,5);
	//inserirFim(&l1,6);
    
    //mostrarLista(&l1);
    //printf("\n");
    
    inserirOrdenado(&l1,3);
    inserirOrdenado(&l1,2);
    inserirOrdenado(&l1,5);
    inserirOrdenado(&l1,1);
    
    mostrarLista(&l1);

	return 0;
}

// implementando funções

int verificarLista(lista* glist){
    if(glist->controle == -1){ 
        return -1;  // caso o controle da lista (vazia) seja -1, retorna -1
    }
    else{
        return 0;   // caso contrário (cheia), retorna 0
    }
}

void criarLista(lista* glist){
    glist->controle = -1;    // cria a lista setando o controle para -1
}

void limparLista(lista* glist){
    glist->controle = -1;    // esvazia a lista setando o controle para -1
}

void inserirFim(lista* glist, int elemento){
    if(glist->controle + 1 < t){ // verifica se a lista está cheia
        glist->vetor[glist->controle + 1] = elemento; // coloca o elemento na primeira posição disponível da lista
        glist->controle += 1;    // incrementa o controle
    }
    else{
        printf("A lista está cheia!\n");  // caso a lista esteja cheia, avisa ao usuário
    }
}

void inserirInicio(lista* glist, int elemento){
	if(glist->controle + 1 < t){
		int i; 
		for(i = glist->controle + 1; i > 0; i--){
			glist->vetor[i] = glist->vetor[i-1];
		}
		glist->vetor[0] = elemento;
		glist->controle += 1;
	}
	else{
		printf("A lista está cheia!\n");
	}
}

void inserirOrdenado(lista* glist, int elemento){
	if(glist->controle + 1 < t){
		
		if(glist->controle != -1){
		
		int i;
		for(i = 0 ; i < glist->controle + 1 ; i++){
			
			if(elemento < glist->vetor[i]){
				int j;
				
				for(j = glist->controle + 1; j > i; j--){
					glist->vetor[j] = glist->vetor[j-1];
				}
				
				glist->vetor[i] = elemento;
				glist->controle += 1;
				
				return;
			}
		}
		
		glist->vetor[i] = elemento;
		glist->controle += 1;
		
		}
		else{
			glist->vetor[glist->controle + 1] = elemento;
			glist->controle += 1;
		}
	}
	else{
		printf("A lista está cheia!\n");
	}
}

void removerFim(lista* glist){
    if(verificarLista(glist) == 0){ // verifica se a lista está vazia
        glist->controle -= 1;    // caso não esteja, decrementa o controle
    }
    else{
        printf("Não é possível remover elementos de uma lista vazia!\n"); // caso esteja, avisa ao usuário
    }
}

void removerInicio(lista* glist){
	if(glist->controle != -1){
		int i;
		for(i = 0; i < glist->controle ; i++){
			glist->vetor[i] = glist->vetor[i+1]; 
		}
		glist->controle -= 1;
	}
	else{
		printf("A lista está vazia!\n");
	}
}

void mostrarLista(lista* glist){
    if(verificarLista(glist) == 0){ // verifica se a lista está vazia
            int i;
			
			for(i = 0; i < glist->controle + 1 ; i++){    // caso tenha 2 elemento ou mais, printa todos os elementos
                printf("Elemento %d: %d\n", i + 1, glist->vetor[i]);
            }
    }
    else{
        printf("Não é possível exibir os elementos de uma lista vazia!\n");   // caso a lista esteja vazia, avisa ao usuário
    }
}
