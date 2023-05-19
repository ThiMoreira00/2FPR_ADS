/*

	FAETERJ-Rio
	Aluno Thiago Moreira
	
	Atividade 1 [Matrizes]
	
	Dada uma matriz MLINHAxCOLUNA, onde LINHA e COLUNA s�o constantes, e uma coluna C,
	desenvolver uma fun��o que desloque todos os elementos da coluna C para a �ltima coluna da
	matriz.
	Consequentemente, as colunas C+1 � �ltima dever�o ser�o deslocadas uma posi��o para a
	esquerda, conforme ilustrado no exemplo abaixo:
	
		Exemplo:

		1 5 7 1 4 6
		6 2 1 4 7 7
	M = 3 6 9 7 0 1
		2 4 5 7 2 4
		2 4 8 9 1 2
		
		C = 1 (ou seja, a 2a coluna)

		1 7 1 4 6 5
		6 1 4 7 7 2
	M = 3 9 7 0 1 6
		2 5 7 2 4 4
		2 8 9 1 2 4
		
		
	Nota: se o valor de C for v�lido, a fun��o far� o que foi solicitado e retornar� 1, ao
	final; caso contr�rio, apenas retornar� 0.
	
*/

// Importa��o de bibliotecas
#include <stdio.h>

// Defini��o de constantes
#define LINHA 5
#define COLUNA 6

// Prot�tipo de fun��es
void exibirMatriz (int m[LINHA][COLUNA]);
int deslocarColuna (int matriz[LINHA][COLUNA], int coluna);

// Fun��o main
void main() {
	
	int coluna;
	int response;
	int matriz[LINHA][COLUNA] = {{1, 5, 7, 1, 4, 6},
								{6, 2, 1, 4, 7, 7},
								{3, 6, 9, 7, 0, 1},
								{2, 4, 5, 7, 2, 4},
								{2, 4, 8, 9, 1, 2}};
	
	// Exibindo matriz
	exibirMatriz (matriz);
	
	// Solicitando o n� da coluna a ser movida
	printf("Insira a coluna a ser movida: ");
	scanf("%d", &coluna);
	
	// Chamada de fun��o
	response = deslocarColuna(matriz, coluna);
	
	// Validando a resposta da fun��o deslocarColuna
	if(response == 0) {
		printf("ERRO! Numero da coluna invalido!");
	}
	else {
		printf("Coluna %d deslocada com sucesso!", coluna);
		exibirMatriz (matriz);
	}
	
}

// Fun��o deslocarColuna
int deslocarColuna (int matriz[LINHA][COLUNA], int coluna) {
	
	// Declara��o de vari�veis
	int i, j;
	int vetor[LINHA];
	
	// Verificando se o n� da coluna � v�lido
	if(coluna < 0 || coluna > COLUNA) {
		return 0;	
		
	}
	else {
		
		// Guardando valores da coluna a ser substituida num vetor
		for(i=0;i<LINHA;i++) {
			vetor[i] = matriz[i][coluna];
		}
		
		// Deslocando as colunas ap�s a selecionada para esquerda
		for(j=coluna;j<COLUNA-1;j++) {
			for(i=0;i<LINHA;i++) {
				matriz[i][j] = matriz[i][j+1];
			}
		}
		
		// Inserindo os valores da coluna substitu�da na �ltima posi��o
		for(i=0;i<LINHA;i++) {
			matriz[i][COLUNA-1] = vetor[i];
		}
		
		return 1;
	}
	
}

// Fun��o exibirMatriz
void exibirMatriz (int m[LINHA][COLUNA]) {
	
	// Declara��o de vari�veis
	int i, j;
	
	// Exibindo os valores da matriz
	printf ("\n\n\nElementos da matriz:\n\n");

	for(i=0;i<LINHA;i++) {
	    for(j=0;j<COLUNA;j++) {
	        printf("%3d ", m[i][j]);
	    }
	
	    printf("\n");
	}
	
	printf("\n\n");
}
