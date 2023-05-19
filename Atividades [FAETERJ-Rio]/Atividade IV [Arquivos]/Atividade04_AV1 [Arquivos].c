/*

	FAETERJ-Rio
	Aluno Thiago Moreira
	
	Atividade 4 [Arquivos]
	
	Implementar uma função que, dado um	arquivo texto A contendo números inteiros, um
	por linha, cria um novo arquivo texto, B, contendo os mesmos valores de A, porém em
	ordem inversa.

	Exemplo:
	
	
	A 		->		B
	1				2
	5				4
	7				9
	1				5
	4				4
	5				1
	9				7
	4				5
	2				1
*/

// Importação de bibliotecas
#include <stdio.h>

// Protótipo de funções
int inverterNumerosArquivos (char nomeArquivoOrigem[], char nomeArquivoDestino[]);
int buscarNumeroArquivo (char nomeArquivo[], int posicao);
void exibirArquivo (char nomeArquivo[]);

void main() {
	
	char nomeArquivoOrigem[20];
	char nomeArquivoDestino[20];
	int response;
	
	// Solicitando o n° da coluna a ser movida
	printf("Insira o nome do arquivo de origem: ");
	fflush(stdin);
	gets(nomeArquivoOrigem);
	
	// Solicitando o n° da coluna a ser movida
	printf("Insira o nome do arquivo de destino: ");
	fflush(stdin);
	gets(nomeArquivoDestino);
	
	// Chamada de função
	response = inverterNumerosArquivos(nomeArquivoOrigem, nomeArquivoDestino);
	
	if(response == 0) {
		printf("ERRO! Os arquivos nao puderam ser abertos!");
	}
	else {
		printf("Arquivo %s invertido para o arquivo %s com sucesso!\n\n", nomeArquivoOrigem, nomeArquivoDestino);
		exibirArquivo(nomeArquivoDestino);
	}
	
}

int inverterNumerosArquivos (char nomeArquivoOrigem[], char nomeArquivoDestino[]) {
	
	FILE *arquivoOriginal;
	FILE *arquivoDestino;
	int contArquivoOriginal = 0;
	int contArquivoDestino = 0;
	int numero;
	
	arquivoOriginal = fopen(nomeArquivoOrigem, "r");
	arquivoDestino = fopen(nomeArquivoDestino, "w");
	
	if(!arquivoOriginal || !arquivoDestino) {
		return 0;
	}
	else {
		while(fscanf(arquivoOriginal, "%d", &numero) != EOF) {
			contArquivoOriginal++; // 9
		}
		
		while(contArquivoOriginal > 0) {
			contArquivoOriginal--;
			fprintf(arquivoDestino, "%d\n", buscarNumeroArquivo (nomeArquivoOrigem, contArquivoOriginal));
		}
			
	}
	fclose(arquivoOriginal);
	fclose(arquivoDestino);
	return 1;
}

int buscarNumeroArquivo (char nomeArquivo[], int posicao) {
	
	FILE *arquivo;
	int numero;
	int cont = 0;
	
	
	arquivo = fopen(nomeArquivo, "r");
	
	if(!arquivo) {
		return -1;
	}
	else {
		
		while(fscanf(arquivo, "%d", &numero) != EOF) {
			if(cont == posicao) {
				return numero;
			}
			else {
				cont++;
			}
		}
	}
}



void exibirArquivo (char nomeArquivo[]) {
	
	FILE *arquivo;
	int numero;
	
	arquivo = fopen(nomeArquivo, "r");
	
	printf("ARQUIVO\n");
	while(fscanf(arquivo, "%d", &numero) != EOF) {
		printf("%d\n", numero);
	}
}
	



