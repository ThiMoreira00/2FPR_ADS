/*

	FAETERJ-Rio
	Aluno Thiago Moreira
	
	Atividade 2 [Strings]
	
	Desenvolver uma fun��o que, dada uma string str, substitua uma substring s1 de str (definida
	pelas posi��es inicial e final) por outra string, s2.
	
	Exemplo:

		str originalmente:
		
		e ai, vc vem?
		01234567891111111
				  0123456
				  
		Substituir a substring s1 de str,
		definida pelas posi��es
		inicial (=6) e final (=7)
		pela string s2 igual a �voc�
		
		str ap�s a substitui��o:
		e ai, voce vem?
		01234567891111111
				  0123456
*/

// Importa��o de bibliotecas
#include <stdio.h>

// Defini��o de constantes
#define LINHA 5
#define COLUNA 6

// Prot�tipo de fun��es
int substituirString (char stringOriginal[], char substringOrigem[], char substringDestino[]);

// Fun��o main
void main() {
	
	char stringOriginal[20];
	char substringOrigem[20];
	char substringDestino[20];
	int response;
	
	printf("Insira a string original: ");
	fflush(stdin);
	gets(stringOriginal);
	
	printf("Insira a substring origem: ");
	fflush(stdin);
	gets(substringOrigem);
	
	printf("Insira a substring destino: ");
	fflush(stdin);
	gets(substringDestino);
	
	// Chamada de fun��o
	response = substituirString(stringOriginal, substringOrigem, substringDestino);
	
	printf("%s", stringOriginal);
	// Validando a resposta da fun��o deslocarColuna
	if(response == 0) {
		printf("ERRO!");
	}
	else {
		printf("Substituicao realizada com sucesso!");
	}
	
}

int substituirString (char stringOriginal[], char substringOrigem[], char substringDestino[]) {
	
	
	
		
	
	return 1;
}
