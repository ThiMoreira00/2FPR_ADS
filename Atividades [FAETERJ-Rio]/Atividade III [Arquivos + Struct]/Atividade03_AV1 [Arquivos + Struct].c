/*

	FAETERJ-Rio
	FPR - Fundamentos de Programação - Manhã
	Professor Leonardo Vianna
	Aluno Thiago Moreira
	
	Atividade 3 [Arquivos + Struct]
	
	Uma Clínica Veterinária mantém um vetor de structs, do qual cada posição armazena as
	seguintes informações: código do cadastro, nome do pet, nome do tutor, e-mail de contato,
	data da última vacina.
	Desenvolver uma função que, dado um vetor com esta estrutura, gere um arquivo texto com
	os dados dos pets com vacina vencida (mais de um ano da última).
	
	Cada linha do arquivo terá a seguinte sintaxe:
		email|mensagem
	
	E a mensagem terá o formato apresentado	abaixo:
		Prezado <nome_tutor>, a vacina do pet <nome_pet> venceu no dia dd/mm/aaaa.
		Podemos agendar a nova dose?
	
	
*/

// Importação de bibliotecas
#include <stdio.h>
#include <time.h>

// Definição de constantes
#define TAM 3

// Definição de struct
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

// Protótipo de funções
void preencherStruct (TPet pets[], int tamanho);
int verificarPets (TPet pets[], int tamanho, char nomeArquivo[]);

// Função main
void main() {
	
	// Declaração de variáveis
	TPet pets[TAM];
	int response;
	char nomeArquivo[20];
	
	// Solicitando o arquivo que será guardado as mensagens
	printf("Insira o nome do arquivo: ");
	fflush(stdin);
	gets(nomeArquivo);
	
	// Chamando a função de preencherStruct (formulário)
	preencherStruct(pets, TAM);

	// Chamando a função verificarPets
	response = verificarPets(pets, TAM, nomeArquivo);
    
    // Validando a resposta da função verificarPets
    if(response == -1) {
    	printf("\nERRO! Algum erro ocorreu durante o processo.");
	}
	else {
		printf("\n%d pets estao com vacina vencida.", response);
		printf("\nAs notificacoes estao no arquivo %s.", nomeArquivo);
	}
}

// Função preencherStruct: preencher o struct de pets (dados)
void preencherStruct (TPet pets[], int tamanho) {
	
	// Declaração de variáveis
	int cont, i;
	
	// Varrendo o vetor de struct pets
	for(i=0;i<tamanho;i++) {
		printf("\n\nFormulario %d -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n", i+1);
		
		// Solicitando dados ao usuário
		printf("Insira o código de cadastro: ");
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

// Função verificarPets: analisando a data de validade das vacinas
int verificarPets (TPet pets[], int tamanho, char nomeArquivo[]) {
	
	// Declaração de variáveis
	FILE *arquivo;
	int cont = 0, i;
	
	// Coletando informações do sistema (dia, mês e ano atuais)
	// Trecho do código copiado em http://linguagemc.com.br/exibindo-data-e-hora-com-time-h/
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
				Verificando se passou um ano após a última vacina do pet
				Validações de exemplo:
				-	Se 2022 (ano anterior ao atual) for maior que o ano da última vacina;
				-	Se 2022 (ano anterior ao atual) for igual ao ano da última vacina E o mês for maior que o mês da última vacina;
				-	Se 2022 (ano anterior ao atual) for igual ao ano da última vacina, o mês for igual ao mês da última vacina E o dia for maior que o dia da última vacina.
				
				Em caso de ocorrência de um dos itens acima, será notificado no arquivo, além de contabilizar na quantidade de mensagens a serem enviadas.
			*/
			
			if (ano-1 > pets[i].dataUltimaVacina.ano || ((ano-1 == pets[i].dataUltimaVacina.ano) && (mes > pets[i].dataUltimaVacina.mes)) || ((ano-1 == pets[i].dataUltimaVacina.ano) && (mes == pets[i].dataUltimaVacina.mes) && (dia > pets[i].dataUltimaVacina.dia))) {
				fprintf(arquivo, "%s | Prezado %s, a vacina do pet %s venceu no dia %02d/%02d/%04d. Podemos agendar a nova dose?\n", pets[i].email, pets[i].nomeTutor, pets[i].nomePet, pets[i].dataUltimaVacina.dia, pets[i].dataUltimaVacina.mes, pets[i].dataUltimaVacina.ano);
				cont++;
			}
		}
		
		// Fechando o arquivo
		fclose(arquivo);
		
		// Retornando a quantidade de ocorrências
		return cont;
	}
}

