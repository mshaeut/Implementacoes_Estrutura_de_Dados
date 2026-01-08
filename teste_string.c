#include <stdio.h>

int contadorVogais(char *string);

int main(){
	char palavra[50];
	int qt_vogais;

	printf("Digite uma palavra: ");
	scanf("%50s", palavra);

	qt_vogais = contadorVogais(palavra);

	printf("A palavra -> %s <- possui %d vogais", palavra, qt_vogais);

	return 0;
}

int contadorVogais(char *string){
	int contador = 0;
	char vogais[10] = {'a','e','i','o','u','A','E','I','O','U'};

	for(int i = 0; string[i] != '\0'; i++){
		for(int j = 0; j < 10; j++){
			if(string[i] == vogais[j]){
				contador = contador + 1;
			}
		}
	}
	
	return contador;	
}