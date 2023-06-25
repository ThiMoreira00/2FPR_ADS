/*
	FAETERJ-Rio
	Aluno Thiago Moreira
	
	Atividade 7 [Listas + Recursividade]
	
	Pede-se a implementação de uma função recursiva que, dada uma lista do tipo TLista,
	ordenada crescentemente, determine a quantidade de valores distintos na lista.


*/


// Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Definição de constantes
#define TRUE 1
#define FALSE 0

// Definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

// Protótipos das funções
int inserir (TLista *L);
void exibirLista (TLista L);
int quantidadeDistintos (TLista L);

// Função main
void main() {
	
	// Definição de variáveis
	TLista L = NULL; // Representação da lista inicialmente vazia
	int quant;
	
	// Inserindo valores na lista L1
	inserir(&L);
	
	// Chamando a função da atividade proposta e armazenando o resultado na variável
	quant = quantidadeDistintos(L);
	
	// Exibindo lista
	exibirLista(L);
	
	// Verificando o resultado da função
	if(quant == 0) {
		printf("\nLista vazia.");
	}
	else {
		printf("\nA lista possui %d itens distintos.", quant);	
	}
	
}


// Função inserir (lista 1)
int inserir (TLista *L) {
	
	// Declaração de variáveis
	TLista aux;
	int numero;
	
	
	// LISTA ORDENADA: 5 4 3 2 2 2 2 1 1 1 1 1 1 1 (pra virar 1 1 1 1 1 1 1 2 2 2 2 3 4 5)
	do {
		printf("\nInsira um numero: ");
		scanf("%d", &numero);
		
		if (numero != 0) {
			
			// Passo 1: alocar memória para o novo valor
			aux = malloc (sizeof(TNo));
			
			//verificar se a memória foi alocada
			if (!aux) {
				return FALSE;
				
			} else {
				
				// Passo 2: inserir o novo valor no campo 'valor' da memória rcém-alocada
				aux->valor = numero;
				
				// Passo 3: fazer com que o campo 'prox' da memória recém-alocada
				// aponte para o "antigo" primeiro nó da lista
				aux->prox = *L;
				
				// Passo 4: Faz a lista apontar para o novo nó
				*L = aux;
				
			}
		}
	} while(numero != 0);
	
	return TRUE;
}

// Função exibirLista
void exibirLista (TLista L) {
	
	// Declaração de variáveis
	TLista aux;
	
	// Verificando se a lista está vazia
	if (!L) {
		printf ("\n\nLista vazia!\n");
		
	} else {
		printf ("\n\nLista: ");	

		// Fazendo 'aux' apontar para o primeiro nó
		aux = L;
	
		// Percorrendo toda a lista
		
		while(aux) { //while (aux != NULL)
	
			// Exibindo os valores da lista
			printf ("%d ", aux->valor);
			
			// Atualizando o próximo da lista
			aux = aux->prox;
		}
	}
}

// Função quantidadeDistintos (função da atividade proposta)
int quantidadeDistintos (TLista L) {
	
	
	// Objetivo da questão: varrer a lista até chegar a NULL, retornando o valor da quantidade
	// A cada execução, se for diferente do número anterior, soma um e puxa o próximo
	// [] -> [1 | []] -> [1 | []] -> [2 | []] -> [3 | []] -> [3 | []] -> NULL
	// L
	
	// Verificando se a lista está vazia
	if(!L) {
		
		// Retornando valor neutro
		return 0;
		
	} else {
		
		// Verificando se não existe mais de 2 elementos na lista (se o próximo da lista é NULO)
		if(!L->prox) { 
			return 1;
		}
		else {
			
			// Se o valor do nó apontado for diferente do próximo, retorna a função somando 1.
			if(L->valor != L->prox->valor) { 
				return 1 + quantidadeDistintos(L->prox);
			}
			
			// Se não, apenas retorna a função
			else {
				return quantidadeDistintos(L->prox);
			}
		}
	}
			
}
