
// bibliotecas

#include <stdio.h>
#include <stdlib.h>

// estruturas

struct no {
	int valor;
	struct no* left;
	struct no* right;
};

// declaração das funções

void gerarArvore(struct no **tree);

struct no* criarArvore(int valor, struct no* fleft, struct no* fright);
struct no* criarArvoreBuscaBinaria(struct no* raiz, int valor);

struct no* rotacaoRR(struct no* raiz);
struct no* rotacaoLL(struct no* raiz);

void mostrarArvorePreFix(struct no* raiz);
void mostrarArvoreInFix(struct no* raiz);
void mostrarArvorePosFix(struct no* raiz);

struct no* limparArvore(struct no* raiz);

int alturaArvore(struct no* raiz);
int contarNoArvore(struct no* raiz);
int fatorBalanceamento(struct no* raiz);

// main

int main(){
	
}

// implementação das funções

void gerarArvore(struct no **tree){
	*tree = 0;
}

struct no* criarArvore(int valor, struct no* fleft, struct no* fright){
	struct no* novo = (struct no*)malloc(sizeof(struct no));
	
	if(novo){
		
		novo->valor = valor;
		novo->left = fleft;
		novo->right = fright;
		
		return novo;
		
	}else{
		
		printf("Alocação dinâmica falhou!\n");
		return 0;
		
	}
}

struct no* criarArvoreBuscaBinaria(struct no* raiz, int valor){
	if(!raiz){
		struct no* novo = (struct no*)malloc(sizeof(struct no));
		
		if(novo){
			
			novo->valor = valor;
			novo->left = 0;
			novo->right = 0;
			
			return novo;
			
		}else{
			
			return 0;
			
		}
	}else{
		if(valor < raiz->valor){
			
			raiz->left = criarArvoreBB(raiz->left, valor);
		
		}else{
			
			raiz->right = criarArvoreBB(raiz->right, valor);
		
		}
		
		return raiz;
	}
}

struct no* rotacaoRR(struct no* raiz){
	if(raiz){
		
		struct no* no = raiz->right;
		raiz->right = no->left;
		no->left = raiz;
		raiz = no;
		
		return raiz;
		
	}else{
		
		return 0;
		
	}
}

struct no* rotacaoLL(struct no* raiz){
	if(raiz){
		
		struct no* no = raiz->left;
		raiz->left = no->right;
		no->right = raiz;
		raiz = no;
		
		return raiz;
		
	}else{
		
		return 0;
		
	}
}

void mostrarArvorePreFix(struct no* raiz){
	if(raiz){
		
		printf("%d ", raiz->valor);
		mostrarArvore(raiz->left);
		mostrarArvore(raiz->right);
		
	}else{
		
		return;
		
	}
}

void mostrarArvoreInFix(struct no* raiz){
	if(raiz){
		
		mostrarArvoreBB(raiz->left);
		printf("%d ", raiz->valor);
		mostrarArvoreBB(raiz->right);
		
	}else{
		return;
	}
}

void mostrarArvorePosFix(struct no* raiz){
	if(raiz){
		
		mostrarArvoreBB(raiz->left);
		mostrarArvoreBB(raiz->right);
		printf("%d ", raiz->valor);
		
	}else{
		return;
	}
}

struct no* limparArvore(struct no* raiz){
	if(raiz){
		
		raiz->left = limparArvore(raiz->left);
		raiz->right = limparArvore(raiz->right);
		free(raiz);
		
		return 0;
		
	}else{
		
		return 0;
		
	}
}

int alturaArvore(struct no* raiz){
	if(raiz){
		
		int a, b;
		
		a = alturaArvore(raiz->left);
		b = alturaArvore(raiz->right);
		
		if(a > b){
		
			return(a + 1);
		
		}else{
		
			return(b + 1);
		
		}
		
	}else{
		
		return 0;
		
	}
}

int contarNoArvore(struct no* raiz){
	if(raiz){
		
		int a, b;
		
		a = contarNoArvore(raiz->left);
		b = contarNoArvore(raiz->right);
		
		return(a + b + 1);
		
	}else{
		
		return 0;
		
	}
}

int fatorBalanceamento(struct no* raiz){
	if(raiz){
		
		return alturaArvore(raiz->left) - alturaArvore(raiz->right);
		
	}else{
		
		return 0;
		
	}
}
