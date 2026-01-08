#include <stdio.h>

int main(){
    unsigned char c; //remove o sinal de char, podendo ir de 0 até 255 (256 repesentações)

    printf("\t~ TABELA ASCII ~\n\n");

	for(c = 0; c < 255 ; c++)
		printf("%d | %c\n",c,c);
	
	printf("%d | %c\n",c,c); //printando o elemento 255° da tabela ASCII

    return 0;
}


