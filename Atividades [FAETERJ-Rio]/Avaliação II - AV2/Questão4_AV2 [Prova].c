/*
	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	
	Prova a compor a AV1 (Parte II) - 11/05/2023
	
	Questão 04 [2,5 pontos]:
	Considerando a existência de um vetor, onde cada posição armazena 
	os seguintes dados: nome do aluno, código da disciplina, nota na 
	AV1 e nota na AV2, pede-se o desenvolvimento de uma função que, 
	dado um vetor nos moldes do descrito, crie (e retorne) um outro 
	vetor com os seguintes dados em cada posição: código da disciplina, 
	status (Aprovado, Reprovado ou Em AVF) e a quantidade de alunos 
	nesta situação.

	Exemplo: 

	JOAO	PEDRO	MARIA	ANA	CARLOS	PAULO	KATIA	SILVIA	GLORIA	ANTONIO	
	FAC		ESD		FPR		FAC	FAC		FPR		ESD		FAC		FPR		ESD
	10,0	6,0		10,0	8,0	7,0		5,0		5,0		2,0		4,0		3,0
	8,0		7,0		5,0		3,0	7,0		2,0		9,0		4,0		1,0		4,0


	FAC			ESD			FPR			FAC		FPR			FAC			ESD
	aprovado	aprovado	aprovado	em AVF	reprovado	reprovado	reprovado
	2			2			1			1			2		1			1
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de tipos
typedef struct {
	
	char nomeAluno[20];
	char codigoTurma[4];
	float notaAV1;
	float notaAV2;
	
} TAluno;

typedef struct {
	
	char codigoTurma[4];
	char situacao[10];
	int quantidadeAlunos;
	
} TDisciplina;

//protótipos das funções
void analisarAlunos (TAluno alunos[], int tamanhoAlunos, TDisciplina disciplina[], int tamanhoDisciplina);
int verificarDisciplina (TDisciplina disciplina[], int tamanho, char codigoTurma[], char situacao[]);
void inicializarAlunos (TAluno alunos[], int tamanho);
void exibirDisciplinas (TDisciplina vetDisciplinas[], int tamanho);

//main
void main ()
{
	//declaração de variáveis
	TAluno vetorAlunos[10];
	TDisciplina vetDisciplinas[10];	 
	int quantDisciplinas = 10;
		 
	//inicializando o vetor de alunos
	inicializarAlunos (vetorAlunos, 10);
	
	//chamando a função e retornando o vetor vetDisciplinas preenchido
	analisarAlunos (vetorAlunos, 10, vetDisciplinas, quantDisciplinas);
	
	//exibindo o vetor VetDisciplinas
	exibirDisciplinas (vetDisciplinas, quantDisciplinas);
}
	
//implementação das funções
void analisarAlunos (TAluno alunos[], int tamanhoAlunos, TDisciplina disciplina[], int tamanhoDisciplina) {
	
	int i, j, alunosAprovados = 0, alunosReprovados = 0, alunosAVF = 0, tam = 0, posicaoDisciplina;
	char situacao[10];
	float media;
	
	for(i=0;i<tamanhoAlunos;i++) {
		
		
		media = (alunos[i].notaAV1 + alunos[i].notaAV2) / 2;
		
		if(media >= 6) {
			alunosAprovados++;
			strcpy(situacao, "Aprovado");
			
		} else {
			if (media < 4) {
				alunosReprovados++;
				strcpy(situacao, "Reprovado");
			}
			else {
				alunosAVF++;
				strcpy(situacao, "Em AVF");
			}
		}
		

		if(verificarDisciplina(disciplina, tamanhoDisciplina, alunos[i].codigoTurma, situacao) < 0) {
			strcpy(disciplina[tam].codigoTurma, alunos[i].codigoTurma);
			strcpy(disciplina[tam].situacao, situacao);
			disciplina[tam].quantidadeAlunos = 1;
			
			tam++;
		
		} else {
			disciplina[posicaoDisciplina].quantidadeAlunos++;
		}
			
	}
}

int verificarDisciplina (TDisciplina disciplina[], int tamanho, char codigoTurma[], char situacao[]) {
	
	int i;
	
	for(i=0;i<tamanho;i++) {
		
		if(strcmp(codigoTurma, disciplina[i].codigoTurma) == 0) {
			if(strcmp(situacao, disciplina[i].situacao) == 0) {
				return i;
			}
		}
	}
	return -1;
}

void inicializarAlunos(TAluno alunos[], int tamanho) {
    //posicao 0
    strcpy(alunos[0].nomeAluno, "JOAO");
    strcpy(alunos[0].codigoTurma, "FAC");
    alunos[0].notaAV1 = 10.0;
    alunos[0].notaAV2 = 8.0;

    //posicao 1
    strcpy(alunos[1].nomeAluno, "PEDRO");
    strcpy(alunos[1].codigoTurma, "FPR");
    alunos[1].notaAV1 = 6.0;
    alunos[1].notaAV2 = 7.0;

    //posicao 2
    strcpy(alunos[2].nomeAluno, "MARIA");
    strcpy(alunos[2].codigoTurma, "FPR");
    alunos[2].notaAV1 = 10.0;
    alunos[2].notaAV2 = 5.0;

    //posicao 3
    strcpy(alunos[3].nomeAluno, "ANA");
    strcpy(alunos[3].codigoTurma, "FAC");
    alunos[3].notaAV1 = 8.0;
    alunos[3].notaAV2 = 3.0;

    //posicao 4
    strcpy(alunos[4].nomeAluno, "CARLOS");
    strcpy(alunos[4].codigoTurma, "FAC");
    alunos[4].notaAV1 = 7.0;
    alunos[4].notaAV2 = 7.0;

    //posicao 5
    strcpy(alunos[5].nomeAluno, "PAULO");
    strcpy(alunos[5].codigoTurma, "FPR");
    alunos[5].notaAV1 = 5.0;
    alunos[5].notaAV2 = 2.0;

    //posicao 6
    strcpy(alunos[6].nomeAluno, "KATIA");
    strcpy(alunos[6].codigoTurma, "ESD");
    alunos[6].notaAV1 = 5.0;
    alunos[6].notaAV2 = 9.0;

    //posicao 7
    strcpy(alunos[7].nomeAluno, "SILVIA");
    strcpy(alunos[7].codigoTurma, "FAC");
    alunos[7].notaAV1 = 2.0;
    alunos[7].notaAV2 = 4.0;

    //posicao 8
    strcpy(alunos[8].nomeAluno, "GLORIA");
    strcpy(alunos[8].codigoTurma, "ESD");
    alunos[8].notaAV1 = 4.0;
    alunos[8].notaAV2 = 1.0;

    //posicao 9
    strcpy(alunos[9].nomeAluno, "ANTONIO");
    strcpy(alunos[9].codigoTurma, "FPR");
    alunos[9].notaAV1 = 3.0;
    alunos[9].notaAV2 = 4.0;
}


void exibirDisciplinas (TDisciplina vetDisciplinas[], int tamanho)
{
	int i;
	
	for (i=0;i<tamanho;i++)
	{
		printf ("Disciplina: %s\n", vetDisciplinas[i].codigoTurma);
		printf ("Situacao: %s\n", vetDisciplinas[i].situacao);
		printf ("Quantidade de alunos: %d\n\n", vetDisciplinas[i].quantidadeAlunos);
	}
}
