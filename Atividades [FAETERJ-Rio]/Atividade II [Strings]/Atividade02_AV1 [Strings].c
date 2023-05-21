/*

	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	Aluno Thiago Moreira
	
	Atividade 2 [Strings]
	
	Desenvolver uma função que, dada uma string str, substitua uma substring s1 de str (definida
	pelas posições inicial e final) por outra string, s2.
	
	Exemplo:

		str originalmente:
		
		e ai, vc vem?
		01234567891111111
				  0123456
				  
		Substituir a substring s1 de str,
		definida pelas posições
		inicial (=6) e final (=7)
		pela string s2 igual a “você”
		
		str após a substituição:
		e ai, voce vem?
		01234567891111111
				  012345
*/

// Importação de bibliotecas
#include <stdio.h>
#include <string.h>

// Definição de constantes
#define TAM 20

// Protótipo de funções
int substituirString (char stringOriginal[], int posicaoInicial, int posicaoFinal, char substringDestino[]);

// Função main
void main() {
	
	// Declaração de variáveis
	char stringOriginal[TAM];
	char substringOrigem[TAM];
	char substringDestino[TAM];
	int response;
	int posicaoInicial, posicaoFinal;
	
	// Solicitando dados
	printf("Insira a string original: ");
	fflush(stdin);
	gets(stringOriginal);

	printf("Insira a posicao inicial da substring origem: ");
	scanf("%d", &posicaoInicial);
	
	printf("Insira a posicao final da substring origem: ");
	scanf("%d", &posicaoFinal);	
	
	printf("Insira a substring destino: ");
	fflush(stdin);
	gets(substringDestino);

	// Exibindo a string antes da substituição
	printf("\nAntes da substituicao: %s", stringOriginal);
	
	// Chamando função substituirString
	response = substituirString(stringOriginal, posicaoInicial, posicaoFinal, substringDestino);
	
	// Validando a resposta da função susbtuirString
	if(response == 0) {
		printf("\nERRO! Os dados inseridos sao invalidos.");
	}
	else {
		printf("\nSubstituicao realizada com sucesso!");
		printf("\nDepois da substituicao: %s", stringOriginal);
	}
	
}

// Função substituirString
int substituirString (char stringOriginal[], int posicaoInicial, int posicaoFinal, char substringDestino[]) {
	
	// Declaração de variáveis
	int i, j, tamanhoSubstringDestino = strlen(substringDestino);
	char stringAuxiliar[TAM];
	
	// Verificando se a substring existe
	if ((posicaoInicial < posicaoFinal) && (posicaoInicial < TAM) && (posicaoFinal < TAM)) {
		
		// Guardar o restante da string numa string auxiliar
		for(i=posicaoFinal+1, j=0; i<TAM; i++, j++) {
			stringAuxiliar[j] = stringOriginal[i];
		}
		
		// Inserindo a substringDestino na stringOriginal
		for(i=posicaoInicial, j=0; j<tamanhoSubstringDestino; i++, j++) {
			stringOriginal[i] = substringDestino[j];
		}
		
		// Adicionando o restante da string (guardada na string auxiliar) na stringOriginal
		for(i=posicaoInicial + tamanhoSubstringDestino, j=0; i<TAM; i++, j++) {
			stringOriginal[i] = stringAuxiliar[j];
		}
		
		// Adicionando o caracter de fim da string
		stringOriginal[i] = '\0';
		
		return 1;
	}
	
	// Caso dê algum erro...
	else {
		return 0;
	}	
}
