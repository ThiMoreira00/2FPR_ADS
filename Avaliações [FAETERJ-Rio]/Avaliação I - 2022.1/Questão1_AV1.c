/*

	FAETERJ-Rio
	2FPR - Fundamentos de Programação para Computação
	Prof.° Leonardo Vianna
	
	AVALIAÇÃO I - AV1 [2022.1]
	
	QUESTÃO 01:
	Desenvolver uma função que, dada uma matriz de inteiros M10x10, troque de posição os elementos da
	linha L com os valores da coluna C. Caso a troca seja possível, a função deverá retornar a constante TRUE;
	caso contrário, FALSE.
	
*/

// Importação de bibliotecas
#include <stdio.h>
#include <time.h>

// Definição de constantes
#define L 10
#define C 10

#define TRUE 1
#define FALSE 0

// Protótipo das funções
void preencherMatriz (int matriz[L][C]);
void exibirMatriz (int matriz[L][C]);
int trocarPosicao (int matriz[L][C], int linha, int coluna);

// Função main
void main() {
	
	int matriz[L][C] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}};
	int resultado, linha, coluna;

	exibirMatriz(matriz);
	
	
	printf("Insira uma linha: ");
	scanf("%d", &linha);
	
	printf("Insira uma coluna: ");
	scanf("%d", &coluna);
	
	resultado = trocarPosicao(matriz, linha, coluna);
	
	
	if(resultado == TRUE) {
		printf("\n\nMatriz alterada com sucesso!\n");
		exibirMatriz(matriz);
		
	} else {
		printf("\n\nNao foi possivel alterar a matriz.");
		
	}
	
}

void preencherMatriz (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	srand (time(NULL));
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			matriz[i][j] = rand()%10;
		}
	}
}

void exibirMatriz (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			printf ("%3d ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}




int trocarPosicao (int matriz[L][C], int linha, int coluna) {
	
	int i, valorMatriz;
	int temp;
	
	if (linha < 0 || coluna < 0 || linha > L || coluna > C || linha == coluna)  {
		return FALSE;
	}
	
	else {
		
		for(i=0;i<L;i++) {
			temp = matriz[linha][i];
	        matriz[linha][i] = matriz[i][coluna];
	        matriz[i][coluna] = temp;
		}
		
		return TRUE;	
	}
}
