/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	Aluno Thiago Moreira
	
	Prova a compor a AV1 (Parte I) - 10/05/2023
	
	Questão 02 [2,5 pontos]:
	Considerando a existência de um arquivo A contendo números inteiros 
	positivos, um por linha, pede-se a implementação de uma função que 
	crie um segundo arquivo, B, com as seguintes características:
	
	- Para cada valor de A, escrever em B uma linha com todos os seus 
	  divisores;
	- Para cada elemento do primeiro arquivo, apenas uma linha de 
	  divisores deve ser inserida em B.

	Exemplo:

		Arquivo A:
			10
			5
			6
			10
			8
			4
			6

		Arquivo B:
			1 2 5 10
			1 5
			1 2 3 6
			1 2 4 8
			1 2 4 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int divisoresArquivo (char nomeArquivoOriginal[], char nomeArquivoNovo[]);
int buscaNumeroArquivo (char nomeArquivo[], int numero, char nomeArquivoRepeticao[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArqOriginal[20], nomeArqNovo[20];
	int retorno;
	
	//associando o arquivo "teste.txt" à variável 'nomeArqOriginal'
	strcpy (nomeArqOriginal, "teste.txt");
	
	//associando o arquivo "novo.txt" à variável 'nomeArqNovo'
	strcpy (nomeArqNovo, "novo.txt");
		
	//chamando a função e armazenando o retorno na variável 'retorno'
	retorno = divisoresArquivo (nomeArqOriginal, nomeArqNovo);
	
	//testando o retorno
	if (retorno == 1)
	{
		printf ("\nO arquivo %s foi gerado com sucesso!", nomeArqNovo);
	}
	else
	{
		printf ("\nErro na geracao do arquivo %s.", nomeArqNovo);
	}
}
	
//implementação das funções
int divisoresArquivo (char nomeArquivoOriginal[], char nomeArquivoNovo[]) {
	
	// Implementação das variáveis
	FILE *arquivoOriginal;
	FILE *arquivoNovo;
	FILE *arquivoRepeticao;
	int numero, i;
	int numeroArquivo;
	
	arquivoOriginal = fopen(nomeArquivoOriginal, "r");
	arquivoNovo = fopen(nomeArquivoNovo, "w");
	arquivoRepeticao = fopen("testeRepeticao.txt", "w");
	
	if ((!arquivoOriginal) || (!arquivoNovo)) {
		fclose(arquivoNovo);
		fclose(arquivoOriginal);
		return 0;
		
	} else {
		retirarRepeticaoArquivo(nomeArquivoOriginal, "testeRepeticao.txt");
		while (fscanf(arquivoOriginal, "%d", &numero) != EOF) {
			
			if(buscaNumeroArquivo(nomeArquivoOriginal, numero, "testeRepeticao.txt") == 1) {
				
				for (i=1;i<=numero;i++) {				
					if(numero%i == 0) {
						fprintf(arquivoNovo, "%d ", i);
					}	
				}
				fprintf(arquivoNovo, "\n");
				
			}
		} 
		
		
		fclose(arquivoNovo);
		fclose(arquivoOriginal);
		fclose(arquivoRepeticao);
		return 1;
	}
}

int retirarRepeticaoArquivo (char nomeArquivo[], char nomeArquivoRepeticao[]) {
	
	FILE *arquivo;
	FILE *arquivoRepeticao;
	int i, numeroArq, numeroRepet;
	
	arquivo = fopen(nomeArquivo, "r");
	arquivoRepeticao = fopen(nomeArquivoRepeticao, "w");
	
	while(fscanf(arquivo, "%d", &numeroArq) != EOF) {
		
		while(fscanf(arquivoRepeticao, "%d", numeroRepet) != EOF) {
			if(numeroArq != numeroRepet) {
				fprintf(arquivoRepeticao, "%d", numeroRepet);
			}	
		}
		printf("\n");
		
	}
	return 1;
}

int buscaNumeroArquivo (char nomeArquivo[], int numero, char nomeArquivoRepeticao[]) {
	
	FILE *arquivo;
	FILE *arquivoRepeticao;
	int i, numeroArq;
	
	
	arquivo = fopen(nomeArquivo, "r");
	arquivoRepeticao = fopen(nomeArquivoRepeticao, "w");
	
	while(fscanf(arquivo, "%d", &numeroArq) != EOF) {
		
		if(numeroArq != numero) {
			fprintf(arquivoRepeticao, "%d", numero);
			return 1;
		}
	}
	return 0;
}

