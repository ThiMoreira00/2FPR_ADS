/*

	FAETERJ-Rio
	FPR - Fundamentos de Programa��o - Manh�
	Professor Leonardo Vianna
	Aluno Thiago Moreira
	
	Atividade 3 [Arquivos + Struct]
	
	Uma Cl�nica Veterin�ria mant�m um vetor de structs, do qual cada posi��o armazena as
	seguintes informa��es: c�digo do cadastro, nome do pet, nome do tutor, e-mail de contato,
	data da �ltima vacina.
	Desenvolver uma fun��o que, dado um vetor com esta estrutura, gere um arquivo texto com
	os dados dos pets com vacina vencida (mais de um ano da �ltima).
	
	Cada linha do arquivo ter� a seguinte sintaxe:
		email|mensagem
	
	E a mensagem ter� o formato apresentado	abaixo:
		Prezado <nome_tutor>, a vacina do pet <nome_pet> venceu no dia dd/mm/aaaa.
		Podemos agendar a nova dose?
	
	
*/

// Importa��o de bibliotecas
#include <stdio.h>
#include <time.h>

// Defini��o de constantes
#define TAM 3

// Defini��o de struct
typedef struct {
	int dia;
	int mes;
	int ano;
} TData;

typedef struct {
	int codigoCadastro;
	char nomePet[20];
	char nomeTutor[20];
	char email[50];
	TData dataUltimaVacina;
} TPet;

// Prot�tipo de fun��es
void preencherStruct (TPet pets[], int tamanho);
int verificarPets (TPet pets[], int tamanho, char nomeArquivo[]);

// Fun��o main
void main() {
	
	// Declara��o de vari�veis
	TPet pets[TAM];
	int response;
	char nomeArquivo[20];
	
	// Solicitando o arquivo que ser� guardado as mensagens
	printf("Insira o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArquivo);
	
	// Chamando a fun��o de preencherStruct (formul�rio)
	preencherStruct(pets, TAM);

	// Chamando a fun��o verificarPets
	response = verificarPets(pets, TAM, nomeArquivo);
    
    // Validando a resposta da fun��o verificarPets
    if(response == -1) {
    	printf("\nERRO! Algum erro ocorreu durante o processo.");
	}
	else {
		printf("\n%d pets estao com vacina vencida.", response);
		printf("\nAs notificacoes estao no arquivo %s.", nomeArquivo);
	}
}

// Fun��o preencherStruct: preencher o struct de pets (dados)
void preencherStruct (TPet pets[], int tamanho) {
	
	// Declara��o de vari�veis
	int cont, i;
	
	// Varrendo o vetor de struct pets
	for(i=0;i<tamanho;i++) {
		printf("\n\nFormulario %d -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n", i+1);
		
		// Solicitando dados ao usu�rio
		printf("Insira o c�digo de cadastro: ");
		scanf("%d", &pets[i].codigoCadastro);
		
		printf("Insira o nome do pet: ");
		fflush(stdin);
		gets(pets[i].nomePet);
		
		printf("Insira o nome do tutor: ");
		fflush(stdin);
		gets(pets[i].nomeTutor);
		
		printf("Insira o e-mail do responsavel: ");
		fflush(stdin);
		gets(pets[i].email);
		
		printf("Insira a data da ultima vacina [DD MM YYYY]: ");
		scanf("%d %d %d", &pets[i].dataUltimaVacina.dia, &pets[i].dataUltimaVacina.mes, &pets[i].dataUltimaVacina.ano);
	}
	printf("\n-=-=-=-=-=-=-=-=-=-=--=-==-=-=-=-=-=-=-=--=-==-=-=-");
	printf("\nFIM DO FORMULARIO\n\n\n");
}

// Fun��o verificarPets: analisando a data de validade das vacinas
int verificarPets (TPet pets[], int tamanho, char nomeArquivo[]) {
	
	// Declara��o de vari�veis
	FILE *arquivo;
	int cont = 0, i;
	
	// Coletando informa��es do sistema (dia, m�s e ano atuais)
	// Trecho do c�digo copiado em http://linguagemc.com.br/exibindo-data-e-hora-com-time-h/
	time_t t = time(NULL);
    struct tm *data = localtime(&t);

    int dia = data->tm_mday;
    int mes = data->tm_mon + 1;
    int ano = data->tm_year + 1900;
	
	// Abrindo o arquivo para escrita (sobreposta)
	arquivo = fopen(nomeArquivo, "w");
	
	// Validando se a abertura do arquivo foi feita com sucesso ou deu algum erro
	if(!arquivo) {
		return -1;	
	} 
	else {
		
		// Varrendo o struct de pets
		for(i=0;i<tamanho;i++) {
			
			/* 
				Verificando se passou um ano ap�s a �ltima vacina do pet
				Valida��es de exemplo:
				-	Se 2022 (ano anterior ao atual) for maior que o ano da �ltima vacina;
				-	Se 2022 (ano anterior ao atual) for igual ao ano da �ltima vacina E o m�s for maior que o m�s da �ltima vacina;
				-	Se 2022 (ano anterior ao atual) for igual ao ano da �ltima vacina, o m�s for igual ao m�s da �ltima vacina E o dia for maior que o dia da �ltima vacina.
				
				Em caso de ocorr�ncia de um dos itens acima, ser� notificado no arquivo, al�m de contabilizar na quantidade de mensagens a serem enviadas.
			*/
			
			if (ano-1 > pets[i].dataUltimaVacina.ano || ((ano-1 == pets[i].dataUltimaVacina.ano) && (mes > pets[i].dataUltimaVacina.mes)) || ((ano-1 == pets[i].dataUltimaVacina.ano) && (mes == pets[i].dataUltimaVacina.mes) && (dia > pets[i].dataUltimaVacina.dia))) {
				fprintf(arquivo, "%s | Prezado %s, a vacina do pet %s venceu no dia %02d/%02d/%04d. Podemos agendar a nova dose?\n", pets[i].email, pets[i].nomeTutor, pets[i].nomePet, pets[i].dataUltimaVacina.dia, pets[i].dataUltimaVacina.mes, pets[i].dataUltimaVacina.ano);
				cont++;
			}
		}
		
		// Fechando o arquivo
		fclose(arquivo);
		
		// Retornando a quantidade de ocorr�ncias
		return cont;
	}
}

