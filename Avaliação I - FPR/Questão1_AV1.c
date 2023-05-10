/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	Aluno Thiago Moreira
	
	Prova a compor a AV1 (Parte I) - 10/05/2023
	
	Questão 01 [2,5 pontos]:
	Considerando a existência de uma matriz de inteiros M, de ordem 
	N (ou seja, o nº de linhas e o nº de colunas são iguais a N), 
	onde N é uma constante, desenvolver uma função que retorne 1 se 
	a seguinte regra for atendida por M (caso contrário, o valor 0 
	deverá ser retornado):
	
	- A soma dos elementos da diagonal principal deve ser igual à 
	  soma dos elementos que estão acima desta diagonal, assim como 
	  à soma dos elementos abaixo da diagonal.

	Exemplo 1:

		Para a seguinte matriz, a função retornará 1: 

					6	3	1	2	6	
					1	3	5	4	2	
					3	4	4	2	2	
					5	9	1	9	3	
					4	0	2	1	8	

	Exemplo 2:

		Para a seguinte matriz, a função retornará 0: 
	
					1	8	5	9	4	
					2	5	4	6	5	
					4	1	2	3	6	
					4	5	5	8	7	
					4	2	5	6	9	
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define N 5

//protótipos das funções
int verificarOrdemMatriz (int m[N][N]);
void exibirMatriz (int m[N][N]);

//main
void main ()
{
	//declaração de variáveis
	int resp;

	int m1[N][N] = {{6, 3, 1, 2, 6},
	                {1, 3, 5, 4, 2},
	                {3, 4, 4, 2, 2},
	                {5, 9, 1, 9, 3},
	                {4, 0, 2, 1, 8}};

	int m2[N][N] = {{1, 8, 5, 9, 4},
	                {2, 5, 4, 6, 5},
	                {4, 1, 2, 3, 6},
	                {4, 5, 5, 8, 7},
	                {4, 2, 5, 6, 9}};

	//exibindo a matriz m1 antes da chamada à função
	exibirMatriz (m1);
	
	//chamando a função com m1 e atribuindo o retorno à variável 'resp'
	resp = verificarOrdemMatriz (m1);
	
	//testando o valor retornado
	if (resp == 1)
	{
		printf ("\n\nA matriz m1 atende ao especificado!");
	}
	else
	{
		printf ("\n\nA matriz m1 NAO atende ao especificado!");
	}
	
	//exibindo a matriz m2 antes da chamada à função
	exibirMatriz (m2);
	
	//chamando a função com m2 e atribuindo o retorno à variável 'resp'
	resp = verificarOrdemMatriz (m2);
	
	//testando o valor retornado
	if (resp == 1)
	{
		printf ("\n\nA matriz m2 atende ao especificado!");
	}
	else
	{
		printf ("\n\nA matriz m2 NAO atende ao especificado!");
	}
}
	
//implementação das funções
int verificarOrdemMatriz (int m[N][N]) {
	
	// Implementação das variáveis utilizadas
	int i, j, somaDiagonal = 0, somaAcima = 0, somaAbaixo = 0;
	
	// Para o número de linhas (ou colunas)...
	for (i=0; i<N; i++) { // linhas
		
		for (j=0; j<N; j++) { // Colunas
			
			// Se os parâmetros forem iguais, a soma é em diagonal
			if(i == j) {
				somaDiagonal += m[i][j];
				
			} else {
				
				// Se a posição da linha for menor que a da coluna, a soma é abaixo da diagonal
				if(i < j) {
					somaAcima += m[i][j];
				}
				else {
					// Senão, a soma é acima da diagonal
					somaAbaixo += m[i][j];
				}
			}
		}
	}

	// Se a soma diagonal for igual a da acima, e a acima for igual a da abaixo
	// pode-se concluir que a soma diagonal é igual a abaixo também, logo...
	if ((somaDiagonal == somaAcima) && (somaAcima == somaAbaixo)) { 
		return 1;
	}
	
	else {
		return 0;
	}
	
}

void exibirMatriz (int m[N][N])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\n\nElementos da matriz:\n\n");
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
	
	printf ("\n\n");
}
