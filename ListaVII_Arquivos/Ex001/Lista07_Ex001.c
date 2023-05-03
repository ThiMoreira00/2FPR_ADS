/*

	FAETERJ-Rio
	1FPR - Fundamentos de Programa��o para Computa��o
	Prof.� Leonardo Vianna
	
	Lista de Exerc�cios VII
	
	
	QUEST�O 01:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de caracteres no mesmo.
	
*/

// Importa��o de bibliotecas
#include <stdio.h>

// Prot�tipo das fun��es
int quantidadeCaracteres(char nomeArquivo[]);

// Fun��o main
void main() {
	
	FILE *arquivo;
	int quantCaracteres;
	char nomeArquivo[20];
	
	
	printf("Insira o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArquivo);
	
	
	quantCaracteres = quantidadeCaracteres(nomeArquivo);
	
	if(quantCaracteres < 0) {
		printf("O arquivo nao foi aberto.");
		
	} else {
		if(quantCaracteres == 0) {
			printf("O arquivo nao possui caracteres.");
			
		} else {
			printf("Foram encontradas %d caracteres.", quantCaracteres);
			
		}
	}

}

int quantidadeCaracteres(char nomeArquivo[]) {
	
	FILE *arquivo;
	char caractere;
	int quantCaracteres;
	
	
	arquivo = fopen(nomeArquivo, "r");
	
	if(arquivo) {
		return -1;
	
	} else {
		
	
		while(fscanf(arquivo, "%c", &caractere) != EOF) {
			quantCaracteres++;
			
		}
		
		fclose(arquivo);
		
	}
	
	return quantCaracteres;
}
