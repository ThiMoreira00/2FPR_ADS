/*
	FAETERJ-Rio
	FPR - Fundamentos de Programa��o - Manh�
	Professor Leonardo Vianna
	Aluno Thiago Moreira
	
	Prova a compor a AV1 (Parte I) - 10/05/2023
	
	Quest�o 02 [2,5 pontos]:
	Considerando a exist�ncia de um arquivo A contendo n�meros inteiros 
	positivos, um por linha, pede-se a implementa��o de uma fun��o que 
	crie um segundo arquivo, B, com as seguintes caracter�sticas:
	
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

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//prot�tipos das fun��es
int divisoresArquivo (char nomeArquivoOriginal[], char nomeArquivoNovo[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArqOriginal[20], nomeArqNovo[20];
	int retorno;
	
	//associando o arquivo "teste.txt" � vari�vel 'nomeArqOriginal'
	strcpy (nomeArqOriginal, "teste.txt");
	
	//associando o arquivo "novo.txt" � vari�vel 'nomeArqNovo'
	strcpy (nomeArqNovo, "novo.txt");
		
	//chamando a fun��o e armazenando o retorno na vari�vel 'retorno'
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
	
//implementa��o das fun��es
int divisoresArquivo (char nomeArquivoOriginal[], char nomeArquivoNovo[]) {
	
	// Implementa��o das vari�veis
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

