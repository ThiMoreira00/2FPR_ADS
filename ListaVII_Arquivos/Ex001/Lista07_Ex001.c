/*

	FAETERJ-Rio
	1FPR - Fundamentos de Programação para Computação
	Prof.° Leonardo Vianna
	
	Lista de Exercícios VII
	
	
	QUESTÃO 01:
	Desenvolver uma função que, dado um arquivo texto, verifique o número de caracteres no mesmo.
	
*/

// Importação de bibliotecas
#include <stdio.h>

// Protótipo das funções
int quantidadeCaracteres(char nomeArquivo[]);

// Função main
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
