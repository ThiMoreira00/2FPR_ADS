/*

	FAETERJ-Rio
	FPR - Fundamentos de Programa��o - Manh�
	Professor Leonardo Vianna
	Aluno Thiago Moreira
	
	Atividade 2 [Strings]
	
	Desenvolver uma fun��o que, dada uma string str, substitua uma substring s1 de str (definida
	pelas posi��es inicial e final) por outra string, s2.
	
	Exemplo:

		str originalmente:
		
		e ai, vc vem?
		01234567891111111
				  0123456
				  
		Substituir a substring s1 de str,
		definida pelas posi��es
		inicial (=6) e final (=7)
		pela string s2 igual a �voc�
		
		str ap�s a substitui��o:
		e ai, voce vem?
		01234567891111111
				  012345
*/

// Importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

// Defini��o de constantes
#define TAM 20

// Prot�tipo de fun��es
int substituirString (char stringOriginal[], int posicaoInicial, int posicaoFinal, char substringDestino[]);

// Fun��o main
void main() {
	
	// Declara��o de vari�veis
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

	// Exibindo a string antes da substitui��o
	printf("\nAntes da substituicao: %s", stringOriginal);
	
	// Chamando fun��o substituirString
	response = substituirString(stringOriginal, posicaoInicial, posicaoFinal, substringDestino);
	
	// Validando a resposta da fun��o susbtuirString
	if(response == 0) {
		printf("\nERRO! Os dados inseridos sao invalidos.");
	}
	else {
		printf("\nSubstituicao realizada com sucesso!");
		printf("\nDepois da substituicao: %s", stringOriginal);
	}
	
}

// Fun��o substituirString
int substituirString (char stringOriginal[], int posicaoInicial, int posicaoFinal, char substringDestino[]) {
	
	// Declara��o de vari�veis
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
	
	// Caso d� algum erro...
	else {
		return 0;
	}	
}
