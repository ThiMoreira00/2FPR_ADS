/*
	FAETERJ-Rio
	Aluno Thiago Moreira
	
	Atividade 7 [Listas + Recursividade]
	
	Pede-se a implementa��o de uma fun��o recursiva que, dada uma lista do tipo TLista,
	ordenada crescentemente, determine a quantidade de valores distintos na lista.


*/


// Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Defini��o de constantes
#define TRUE 1
#define FALSE 0

// Defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

// Prot�tipos das fun��es
int inserir (TLista *L);
void exibirLista (TLista L);
int quantidadeDistintos (TLista L);

// Fun��o main
void main() {
	
	// Defini��o de vari�veis
	TLista L = NULL; // Representa��o da lista inicialmente vazia
	int quant;
	
	// Inserindo valores na lista L1
	inserir(&L);
	
	// Chamando a fun��o da atividade proposta e armazenando o resultado na vari�vel
	quant = quantidadeDistintos(L);
	
	// Exibindo lista
	exibirLista(L);
	
	// Verificando o resultado da fun��o
	if(quant == 0) {
		printf("\nLista vazia.");
	}
	else {
		printf("\nA lista possui %d itens distintos.", quant);	
	}
	
}


// Fun��o inserir (lista 1)
int inserir (TLista *L) {
	
	// Declara��o de vari�veis
	TLista aux;
	int numero;
	
	
	// LISTA ORDENADA: 5 4 3 2 2 2 2 1 1 1 1 1 1 1 (pra virar 1 1 1 1 1 1 1 2 2 2 2 3 4 5)
	do {
		printf("\nInsira um numero: ");
		scanf("%d", &numero);
		
		if (numero != 0) {
			
			// Passo 1: alocar mem�ria para o novo valor
			aux = malloc (sizeof(TNo));
			
			//verificar se a mem�ria foi alocada
			if (!aux) {
				return FALSE;
				
			} else {
				
				// Passo 2: inserir o novo valor no campo 'valor' da mem�ria rc�m-alocada
				aux->valor = numero;
				
				// Passo 3: fazer com que o campo 'prox' da mem�ria rec�m-alocada
				// aponte para o "antigo" primeiro n� da lista
				aux->prox = *L;
				
				// Passo 4: Faz a lista apontar para o novo n�
				*L = aux;
				
			}
		}
	} while(numero != 0);
	
	return TRUE;
}

// Fun��o exibirLista
void exibirLista (TLista L) {
	
	// Declara��o de vari�veis
	TLista aux;
	
	// Verificando se a lista est� vazia
	if (!L) {
		printf ("\n\nLista vazia!\n");
		
	} else {
		printf ("\n\nLista: ");	

		// Fazendo 'aux' apontar para o primeiro n�
		aux = L;
	
		// Percorrendo toda a lista
		
		while(aux) { //while (aux != NULL)
	
			// Exibindo os valores da lista
			printf ("%d ", aux->valor);
			
			// Atualizando o pr�ximo da lista
			aux = aux->prox;
		}
	}
}

// Fun��o quantidadeDistintos (fun��o da atividade proposta)
int quantidadeDistintos (TLista L) {
	
	
	// Objetivo da quest�o: varrer a lista at� chegar a NULL, retornando o valor da quantidade
	// A cada execu��o, se for diferente do n�mero anterior, soma um e puxa o pr�ximo
	// [] -> [1 | []] -> [1 | []] -> [2 | []] -> [3 | []] -> [3 | []] -> NULL
	// L
	
	// Verificando se a lista est� vazia
	if(!L) {
		
		// Retornando valor neutro
		return 0;
		
	} else {
		
		// Verificando se n�o existe mais de 2 elementos na lista (se o pr�ximo da lista � NULO)
		if(!L->prox) { 
			return 1;
		}
		else {
			
			// Se o valor do n� apontado for diferente do pr�ximo, retorna a fun��o somando 1.
			if(L->valor != L->prox->valor) { 
				return 1 + quantidadeDistintos(L->prox);
			}
			
			// Se n�o, apenas retorna a fun��o
			else {
				return quantidadeDistintos(L->prox);
			}
		}
	}
			
}
