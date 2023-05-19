/*

	FAETERJ-Rio
	Aluno Thiago Moreira
	
	Atividade 2 [Strings]
	
	Desenvolver uma função que, dada uma string str, substitua uma substring s1 de str (definida
	pelas posições inicial e final) por outra string, s2.
	
	Exemplo:

		str originalmente:
		
		e ai, vc vem?
		01234567891111111
				  0123456
				  
		Substituir a substring s1 de str,
		definida pelas posições
		inicial (=6) e final (=7)
		pela string s2 igual a “você”
		
		str após a substituição:
		e ai, voce vem?
		01234567891111111
				  0123456
*/

// Importação de bibliotecas
#include <stdio.h>

// Definição de constantes
#define LINHA 5
#define COLUNA 6

// Protótipo de funções
int substituirString (char stringOriginal[], char substringOrigem[], char substringDestino[]);

// Função main
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
	
	// Chamada de função
	response = substituirString(stringOriginal, substringOrigem, substringDestino);
	
	printf("%s", stringOriginal);
	// Validando a resposta da função deslocarColuna
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
