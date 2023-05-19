/*
	FAETERJ-Rio
	FPR - Fundamentos de Programa��o - Manh�
	Professor Leonardo Vianna
	Aluno Thiago Moreira
	
	Prova a compor a AV1 (Parte I) - 15/05/2023
	
	ATIVIDADE 01:
	Dada uma matriz M de LINHAxCOLUNA, onde LINHA e COLUNA s�o constantes, e uma coluna C,
	desenvolver uma fun��o que desloque todos os elementos da coluna C para a �ltima coluna da
	matriz.
	
	Consequentemente, as colunas C+1 � �ltima dever�o ser�o deslocadas uma posi��o para a
	esquerda, conforme ilustrado no exemplo abaixo:				
					
						
					
		Exemplo:
		
		{ 1 5 7 1 4 6 }
		{ 6 2 1 4 7 7 }
	M = { 3 6 9 7 0 1 }
		{ 2 4 5 7 2 4 }
		{ 2 4 8 9 1 2 }
		
		
	C = 1 (ou seja, a 2a coluna)
		
		{ 1 7 1 4 6 5 }
		{ 6 1 4 7 7 2 }
	M = { 3 9 7 0 1 6 }
		{ 2 5 7 2 4 4 } 
		{ 2 8 9 1 2 4 }
		
		
	Nota: se o valor de C for v�lido, a fun��o far� o que foi solicitado e retornar� 1, ao
	final; caso contr�rio, apenas retornar� 0.
	
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define LINHA 5
#define COLUNA 6 

//prot�tipos das fun��es???????????????????????????
void exibirMatriz (int m[LINHA][COLUNA]);
int deslocarColunaMatriz (int m[LINHA][COLUNA], int coluna);

//main
void main ()
{
	//declara��o de vari�veis
	int resp;
	int col;
	int matriz[LINHA][COLUNA] = {{1, 5, 7, 1, 4, 6},
								{6, 2, 1, 4, 7, 7},
								{3, 6, 9, 7, 0, 1},
								{2, 4, 5, 7, 2, 4},
								{2, 4, 8, 9, 1, 2}};
	
	exibirMatriz (matriz);
	
	printf("Insira a coluna: ");
	scanf("%d", &col);
	
	resp = deslocarColunaMatriz (matriz, col);
	
	if(resp == 1) {
		printf("\nMatriz alterada com sucesso! ");
		exibirMatriz (matriz);
	}
	else {
		printf("\nNao foi possivel realizar a alteracao.");
	}
}
	
		
	
//implementa��o das fun��es
int deslocarColunaMatriz (int m[LINHA][COLUNA], int coluna) {
	
	printf("Hello, world!");
	return 1;
}

void exibirMatriz (int m[LINHA][COLUNA])
{
	//declara��o de vari�veis
	int i, j;
	
	printf ("\n\n\nElementos da matriz:\n\n");
	
	for (i=0;i<COLUNA;i++)
	{
		for (j=0;j<LINHA;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
	
	printf ("\n\n");
}
