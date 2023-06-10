/*

	FAETERJ-Rio
	Aluno Thiago Moreira
	
	Atividade 5 [Recursividade]
	
	Desenvolver uma fun��o recursiva que, dado um n�mero inteiro n, determine a quantidade
	de divisores deste n�mero.
	
*/

// Importa��o de bibliotecas
#include <stdio.h>

// Prot�tipo das fun��es
int divisoresIterativa (int n);
int divisoresRecursiva (int n);
int divisoresAuxiliar (int numero, int i);
int divisao (int n, int d);

// Fun��o main
void main() {
	
	// Declara��o das vari�veis
	int numero, resposta;
	
	// Solicitando dados
	printf("Insira um numero: ");
	scanf("%d", &numero);
	
	// Exibindo o resultado das fun��es (interativa e recursiva)
	printf("Quantidade de divisores (iterativa): %d\n", divisoresIterativa(numero));
	printf("Quantidade de divisores (recursiva): %d\n", divisoresRecursiva(numero));
	
}

// Fun��o na maneira interativa (desconsiderar)
int divisoresIterativa (int n) {
	
	// Declara��o de vari�veis
	int i, cont = 0;
	
	// Varrendo de 1 at� metade de N
	// Se for divisor, contar +1
	for(i=1;i<=(n/2);i++) {
		if(n%i == 0) {
			cont++;
		}
	}
	
	// Retornar a quantidade de divisores + 1 (incluindo o 1)
	return cont+1;
	
}

// Fun��o divisoresRecursiva
int divisoresRecursiva (int n) {
	
	// Exemplo de divisores:
	// 30 = [1, 2, 3, 5, 6, 10, 15, 30] = 8
	// 12 = [1, 2, 3, 4, 6, 12] = 6
	// 17 = [1, 17] = primo (2)
	
	// Chamada de uma fun��o auxiliar com dois par�metros (um do n�mero atual, outro de contador)
	divisoresAuxiliar (n, n);
	
}

// Fun��o divisoresAuxiliar (passando como par�metros o n�mero atual e o contador)
int divisoresAuxiliar (int n, int i) {
	
	// Verificando se a sa�da da fun��o � 1 (caso base da recursividade)
	if(i == 1) {
		return 1;
	}
	
	// Se n�o for, continuar no m�todo de recursividade
	else {
		
		// Se o resto for diferente do zero, varrer na posi��o inferior
		if(n%i != 0) {
			return divisoresAuxiliar(n, i-1);
		}
		
		// Se tiver, adicionar mais um e varrer a posi��o inferior
		else {
			return 1 + divisoresAuxiliar(n, i-1);
		}
	}
}

