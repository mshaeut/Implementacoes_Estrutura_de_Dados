#include <stdio.h>
#include <locale.h>

// funcoes

void fibonacci(int);

//****************************************//

int main(){
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int termo;
	
	printf("Digite qual termo da sequência de Fibonacci deseja saber: ");
	scanf("%d", &termo);
	
	fibonacci(termo);
	
	return 0;
}

////////////////////////////////////////////

void fibonacci(int num){
	unsigned long long int antecessor = 0, sucessor = 1, copiador; //comportar valores extremadamente grandes
	int i;
	
	for(i = 1; i < num; i++){
		copiador = sucessor;
		sucessor = antecessor + sucessor;
		antecessor = copiador;
	}
	
	printf("\nO %d° termo da sequência de Fibonacci é %llu",num,sucessor); //%llu para printar os valores altos
}
