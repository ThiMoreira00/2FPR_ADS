/*

	FAETERJ-Rio
	Aluno Thiago Moreira
	
	Atividade 5 [Recursividade]
	
	Desenvolver uma função recursiva que, dado um número inteiro n, determine a quantidade
	de divisores deste número.
	
*/

// Importação de bibliotecas
#include <stdio.h>

// Protótipo das funções
int divisoresIterativa (int n);
int divisoresRecursiva (int n);
int divisoresAuxiliar (int numero, int i);
int divisao (int n, int d);

// Função main
void main() {
	
	// Declaração das variáveis
	int numero, resposta;
	
	// Solicitando dados
	printf("Insira um numero: ");
	scanf("%d", &numero);
	
	// Exibindo o resultado das funções (interativa e recursiva)
	printf("Quantidade de divisores (iterativa): %d\n", divisoresIterativa(numero));
	printf("Quantidade de divisores (recursiva): %d\n", divisoresRecursiva(numero));
	
}

// Função na maneira interativa (desconsiderar)
int divisoresIterativa (int n) {
	
	// Declaração de variáveis
	int i, cont = 0;
	
	// Varrendo de 1 até metade de N
	// Se for divisor, contar +1
	for(i=1;i<=(n/2);i++) {
		if(n%i == 0) {
			cont++;
		}
	}
	
	// Retornar a quantidade de divisores + 1 (incluindo o 1)
	return cont+1;
	
}

// Função divisoresRecursiva
int divisoresRecursiva (int n) {
	
	// Exemplo de divisores:
	// 30 = [1, 2, 3, 5, 6, 10, 15, 30] = 8
	// 12 = [1, 2, 3, 4, 6, 12] = 6
	// 17 = [1, 17] = primo (2)
	
	// Chamada de uma função auxiliar com dois parâmetros (um do número atual, outro de contador)
	divisoresAuxiliar (n, n);
	
}

// Função divisoresAuxiliar (passando como parâmetros o número atual e o contador)
int divisoresAuxiliar (int n, int i) {
	
	// Verificando se a saída da função é 1 (caso base da recursividade)
	if(i == 1) {
		return 1;
	}
	
	// Se não for, continuar no método de recursividade
	else {
		
		// Se o resto for diferente do zero, varrer na posição inferior
		if(n%i != 0) {
			return divisoresAuxiliar(n, i-1);
		}
		
		// Se tiver, adicionar mais um e varrer a posição inferior
		else {
			return 1 + divisoresAuxiliar(n, i-1);
		}
	}
}

