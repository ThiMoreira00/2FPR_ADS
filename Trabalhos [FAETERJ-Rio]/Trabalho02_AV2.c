/*

	FAETERJ-Rio
	FPR - Manhã
	Aluno: Thiago Moreira
	Prof° Leonardo Vianna
	
	Considerando as implementações de listas encadeadas
	feitas em aula, apresentar o código das funções de
	inserção, remoção, alteração, busca e exibição (além da
	main) para uma lista que restrinja que um elemento N
	apareça na lista, no máximo, N vezes.
	
	Por exemplo, o número 5 não pode aparecer na lista
	por mais de 5 vezes (pode aparecer 1, 2, 3, 4 ou 5
	vezes; pode, inclusive, não estar na lista; só não pode
	exceder 5 repetições).
	
	- Fonte do código: Aula 25/05/2023 [Listas encadeadas (listas dinâmicas)] - 
	
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int num1, int num2);
TLista buscar (TLista L, int numero);
void exibir (TLista L);
int localizarNumero (TLista L, int numero);

int menu ();

//main 
void main ()
{
	//declaração de variáveis
	TLista L = NULL;  //representando a lista inicialmente vazia
	int num1, num2, op, quant;
	TLista resp;	
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&L, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        quant = remover (&L, num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função
			        quant = alterar (L, num1, num2);
			        
			        if (quant > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        resp = buscar (L, num1);
			        
					if (resp != NULL)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}

//implementação das funções

//inserindo no início da lista
int inserir (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocar memória para o novo valor
	aux = malloc (sizeof(TNo));
	
	//verificar se a memória foi alocada
	if (!aux)
	{
		return FALSE;
	}
	else
	{
		if(localizarNumero(*L, numero) < numero) {
			
			//Passo 2: inserir o novo valor no campo 'valor' da memória rcém-alocada
			aux->valor = numero;
			
			//Passo 3: fazer com que o campo 'prox' da memória recém-alocada
			//aponte para o "antigo" primeiro nó da lista
			aux->prox = *L;
			
			//Passo 4: Faz a lista apontar para o novo nó
			*L = aux;
			
			return TRUE;
		}
		else {
			return FALSE;
		}
		
	}
}

int remover (TLista *L, int numero)
{
	//declaração de variáveis
	int quant = 0;
	TLista anterior, atual, aux;
	
	//removendo todas as ocorrências de 'numero' no início da lista. 
	while ((*L) && ((*L)->valor == numero))
	{
			atual = *L;
			*L = atual->prox;  //ou   *L = (*L)->prox;
			free (atual);
			
			//atualizando a quantidade de remoções
			quant++;
	}
	
	//verificando se a lista não está vazia
	if (*L)
	{
		//colocando os ponteiros 'anterior' e 'atual' nas duas primeiras
		//posições da lista
		anterior = *L;
		atual = anterior->prox;
		
		//percorrendo toda a lista
		//while (atual != NULL)
		while (atual)
		{
			//verificando se 'numero' foi encontrado
			if (atual->valor == numero)
			{
				anterior->prox = atual->prox;
				free (atual);
				
				quant++;
				
				atual = anterior->prox;
			}
			else
			{
				//atualizando os ponteiros
				anterior = atual;
				atual = anterior->prox;
			}
		}
	}
	
	//retornar a quantidade de remoções
	return quant;
}

int alterar (TLista L, int num1, int num2)
{
	//declaração de variáveis
	TLista aux;
	int quant = 0;
	
	//fazendo 'aux' apontar para o primeiro nó
	aux = L;
	
	//percorrendo toda a lista
	while (aux)
	{
		//verificando se o número a ser alterado foi encontrado
		if (aux->valor == num1)
		{
			if(localizarNumero(L, num2) < num2) {
				aux->valor = num2;
			
				quant++;	
			}
		}
		//atualizar o aux
		aux = aux->prox;
	}
	
	//retornando a quantidade de alterações realizadas
	return quant;
}

TLista buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//fazendo 'aux' apontar para o primeiro nó
	aux = L;
	
	//percorrendo toda a lista
	while (aux)
	{
		//verificando se 'numero' foi encontrado
		if (aux->valor == numero)
		{
			return aux;
		}
			
		//atualizar o aux
		aux = aux->prox;
	}
	
	return NULL;
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a lista está vazia
	//if (L == NULL)
	if (!L)
	{
		printf ("\n\nLista vazia!\n");
	}
	else
	{
		printf ("\n\nLista: ");	

		//fazendo 'aux' apontar para o primeiro nó
		aux = L;
	
		//percorrendo toda a lista
		//while (aux != NULL)
		while (aux)
		{
			//exibindo cada elemento da lista
			printf ("%d ", aux->valor);
			
			//atualizar o aux
			aux = aux->prox;
		}
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

int localizarNumero (TLista L, int numero) {
	
	TLista aux;
	// Declaração de variáveis
	int cont = 0;
//	
	//fazendo 'aux' apontar para o primeiro nó
	aux = L;
	
	// Percorrendo a lista
	while(aux) {
		
		// Verificando se o valor da lista é o número
		if(aux->valor == numero) {
			cont++;
		}
		
		// Atualizando o próximo da lista
		aux = aux->prox;
	}
	return cont;
	
}
