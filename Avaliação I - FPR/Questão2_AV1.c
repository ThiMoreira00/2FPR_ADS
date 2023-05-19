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
	int numero, i;
	int numeroArquivo;
	
	arquivoOriginal = fopen(nomeArquivoOriginal, "r");
	arquivoNovo = fopen(nomeArquivoNovo, "w");
	
	if ((!arquivoOriginal) || (!arquivoNovo)) {
		fclose(arquivoNovo);
		fclose(arquivoOriginal);
		return 0;
		
	} else {
		fscanf(arquivoOriginal, "%d", &numeroArquivo);
		do {
			
				for (i=1;i<=numero;i++) {				
					if(numero%i == 0) {
						fprintf(arquivoNovo, "%d ", i);
					}	
				}
				fprintf(arquivoNovo, "\n");
			
		} while (fscanf(arquivoOriginal, "%d", &numero) != EOF);
		
		
		fclose(arquivoNovo);
		fclose(arquivoOriginal);
		return 1;
	}
}

