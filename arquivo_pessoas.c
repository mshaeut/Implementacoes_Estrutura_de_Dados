#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// estruturas

typedef struct{
	char nome[20];
	int idade;
}tPessoa;

// funcoes

void escreverArq(int);
void maiorDezoito(int);
void organizarArq(int);

//****************************************//

int main(){
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int quantidade;
	
	printf("Informe quantas pessoas deseja registrar: ");
	scanf("%d", &quantidade);
	
	getchar();
	
	//escreverArq(quantidade);
	//maiorDezoito(quantidade);
	organizarArq(quantidade);
	
	return(0);
}

////////////////////////////////////////////

void escreverArq(int quantidade){
	FILE* arquivo; // ponteiro para arquivo
	char nome[20]; // array para armazenar o nome da pessoa a ser registrada
	int idade; // idade da pessoa a ser registrada
	int i; // variável de controle
	
	if((arquivo = fopen("dados.txt", "w")) == NULL){
		printf("Erro a abrir arquivo!");
		return;
	}
	
	for(i = 1; i < quantidade + 1; i++){
		printf("Digite o nome da %d° pessoa: ", i);
		gets(nome);
		fprintf(arquivo,"%s ", nome);
		
		printf("Digite a idade da %d° pessoa: ", i);
		scanf("%d", &idade);
		fprintf(arquivo,"%d\n", idade);
		
		getchar();
	}
	
	fclose(arquivo);
}

////////////////////////////////////////////

void maiorDezoito(int quantidade){
	FILE* arquivo; 
	char nome[20];
	int idade;
	int j;
	
	if((arquivo = fopen("dados.txt", "r")) == NULL){
		printf("Erro a abrir arquivo!");
		return;
	}
	
	printf("\nPessoas registradas maiores de 18 anos: ");
	
	for(j = 0; j < quantidade; j++){
		fscanf(arquivo,"%s%d",nome,&idade);
		
		if(idade >= 18){
			if(j == quantidade - 1)
				printf("%s.",nome);
			else
				printf("%s, ",nome);
		}
	}
	
	fclose(arquivo);	
}

void organizarArq(int quantidade){
	FILE* arquivo;
	FILE* arquivo_org;
	char** pNome;
	int* pIdade;
	char nome[20];
	int idade; 
	int k;
	
	pNome = (char**)malloc(sizeof(char*)*quantidade); // alocação dinâmica de vetor de caracteres
	
	for(k = 0; k < quantidade; k++)
		pNome[k] = (char*)malloc(sizeof(char)*20); // alocação dinâmica de cada elemento do vetor de caracteres
	
	pIdade = (int*)malloc(sizeof(int)*quantidade); // alocação dinâmica para vetor de inteiros
	
	if((arquivo = fopen("dados.txt", "r")) == NULL){
		printf("Erro a abrir arquivo!");
		return;
	}
	
	for(k = 0; k < quantidade; k++){
		fscanf(arquivo,"%s%d",nome,&idade);
		
		strcpy(pNome[k],nome);
		pIdade[k] = idade;
		
		printf("%s ",pNome[k]);
	}

	for(k = 0; k < quantidade; k++)
		free(pNome[20]);
	
	free(pNome);
	free(pIdade);
	fclose(arquivo);
}

