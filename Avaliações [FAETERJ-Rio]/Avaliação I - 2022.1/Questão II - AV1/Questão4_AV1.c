/*

	FAETERJ-Rio
	2FPR - Fundamentos de Programação para Computação
	Prof.° Leonardo Vianna
	
	AVALIAÇÃO I - AV1 [2022.1]
	
	QUESTÃO 04:
	Pede-se uma função que, dados dois arquivos textos, contendo números inteiros, determine se possuem os
	mesmos valores, independente do número de ocorrências de cada número nos arquivos.
	
*/

// Importação de bibliotecas
#include <stdio.h>

// Definição de constantes

// Protótipo das funções
int verificarArquivos (char nomeArquivo1[], char nomeArquivo2[]);
int gerarArquivos (char nomeArquivo[]);

// Função main
int main() {
	
	char nomeArquivo1[20];
	char nomeArquivo2[20];
	char nomeArquivo3[20];
	char resposta = 'N';

	printf("Voce deseja gerar novos arquivos? [S/N]");
	fflush(stdin);
	scanf("%c", &resposta);
	resposta = toupper(resposta);
	
	if(resposta == 'S') {
		
		printf("Insira o nome do arquivo a ser gerado: ");
		fflush(stdin);
		gets(nomeArquivo3);
		gerarArquivos(nomeArquivo3);
	}
	printf("Insira o nome do arquivo 1: ");
	fflush(stdin);
	gets(nomeArquivo1);
	
	printf("Insira o nome do arquivo 2: ");
	fflush(stdin);
	gets(nomeArquivo2);
	
	
	
	switch(verificarArquivos(nomeArquivo1, nomeArquivo2)) {
		
		case -1: printf("\nErro na leitura dos arquivos.");
				 break;
				 
		case 0: printf("\nOs arquivos nao sao iguais.");
				break;
				
		case 1: printf("\nOs arquivos sao identicos!");
	}
	
	return 0;
}

int verificarArquivos (char nomeArquivo1[], char nomeArquivo2[]) {
	
	FILE *arquivo1;
	FILE *arquivo2;
	int numeroArquivo1, numeroArquivo2;
	
	
	arquivo1 = fopen(nomeArquivo1, "r");
	arquivo2 = fopen(nomeArquivo2, "r");
	
	
	if(!arquivo1 || !arquivo2) {
		fclose(arquivo1);
		fclose(arquivo2);
		return -1;
	}
	else {
		
		while (fscanf(arquivo1, "%d", &nomeArquivo1) != EOF && fscanf(arquivo2, "%d", &nomeArquivo2) != EOF){
			if(nomeArquivo1 != nomeArquivo2) {
				return 0;
			}
		}
		
		return 1;
	}
	
	
}

int gerarArquivos (char nomeArquivo[]) {
	
	int numero;
	FILE *arquivo;
	char resposta = 'N';
	
	arquivo = fopen(nomeArquivo, "w");
	
	do {
		printf("Insira valores: ");
		scanf("%d", &numero);
		
		fprintf(arquivo, "%d\n", numero);
		
		
	} while (numero != -1);
	
	printf("\nArquivo gerado com sucesso!");
	fclose(arquivo);
	
	printf("\nDeseja gerar mais algum arquivo? [S/N] ");
	fflush(stdin);
	scanf("%c", &resposta);
	resposta = toupper(resposta);
	
	if(resposta == 'S') {
		
		printf("Insira o nome do arquivo a ser gerado: ");
		fflush(stdin);
		gets(nomeArquivo);
		gerarArquivos(nomeArquivo);
	}
	
}
