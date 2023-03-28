#include <stdio.h> // traduz a linguagem de programação para o usuário
#include <stdlib.h> // responsável por alocar memórias para uma variável como ex.
#include <locale.h> // biblioteca de alocação de texto por região, como estamos no BR, permite a inclusão de acentos como ex.
#include <string.h> // possibilita o uso de strings

int registrar() // aba de registro
{
	// strings que são conjunto de variáveis
	char arquivo[40]; // variável do arquivo que sera gerado com o nome do CPF cadastrado
	char cpf[40]; // char para caracteres, 40 é o tamanho máximo de caracteres
	char nome[40];
	char sobrenome[40];
	char setor[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese"); // dizendo para a biblioteca locale qual linguagem desejo
	
	printf("Você escolheu registrar um funcionário!\n\n");
	printf("Digite o CPF do funcionário a ser cadastrado: ");
	scanf("%s", cpf); //%s para armazenar string e será armazenado na variável cpf
	system("cls");
	
	strcpy(arquivo, cpf); // responsável por copiar as variáveis do cpf para o nome do arquivo de registro gerado
	
	FILE *file; // chamando uma função ja existente do sistema para criar um arquivo
	file = fopen(arquivo, "w"); // quando criar esse arquivo, vou abri-lo (fopen) com o nome de arquivo (acima cpf foi copiado para arquivo, assim o arquivo será criado com a variável do CPF) e vou escreve-lo, já que não existe (w de write)
	fprintf(file, cpf); // usado para salvar dentro do arquivo, no caso salvando a variável CPF
	fclose(file); // abri, salvei e agora fechei o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo e atualizar o arquivo (a)
	fprintf(file, " | "); // salvando com uma vírgula dentro do arquivo para separar as informações
	fclose(file); // fechar o arquivo
	
	printf("Digite o nome do funcionário a ser cadastrado: ");
	scanf("%s", nome);
	system("cls");
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome do funcionário a ser cadastrado: ");
	scanf("%s", sobrenome);
	system("cls");
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " | ");
	fclose(file);
	
	printf("Digite o setor do funcionário a ser cadastrado: ");
	scanf("%s", setor);
	system("cls");
	
	file = fopen(arquivo, "a");
	fprintf(file, setor);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " | ");
	fclose(file);
	
	printf("Digite o cargo do funcionário a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese"); // dizendo para a biblioteca locale qual linguagem desejo
	
	printf("Você escolheu consultar um de nossos funcionários!\n");
	printf("Agora digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; // consultar um arquivo
	file = fopen(cpf, "r"); // abra esse arquivo com nome da variável CPF e leia (r) o conteúdo
	
	if(file  == NULL) // se o CPF não existir, for nulo:
	{
		printf("Esse CPF não está cadastrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // vá ao arquivo, busque os 200 caracteres que estão no conteúdo desse arquivo e salve na variável conteudo enquanto for diferente de nulo
	{
	printf("\nEssas são as informações do funcionário:\n\n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	setlocale(LC_ALL, "Portuguese"); // dizendo para a biblioteca locale qual linguagem desejo
	
	printf("Você escolheu deletar um funcionário!\n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // ler o arquivo cpf
	
	if(file == NULL)
	{
		printf("Este CPF não está cadastrado!\n");
		system("pause"); //faz a mensagem aparecer para o usuário até ele não querer mais
	}

}

int main() // função principal, menu do programa
{
	int opcao=0; // definindo a variável
	int x=1; // variável do laço de repetição
	
	for(x=1;x=1;) // dessa forma o laço de repetição fica eterno, ja que a entrada e saida do laço são iguais, além de não ter inclemento que seria dado por "x++"
	{ // início da chave, engloba o que ficará dentro do laço
		
		system("cls"); // função para limpar tela após usuário fazer a escolha
		
		setlocale(LC_ALL, "Portuguese"); // dizendo para a biblioteca locale qual linguagem desejo
	
		printf("\t\t Funcionários Maquira \t\t\n\n"); // printf envio esse texto para a tela do usuário
		printf("Escolha a opção desejada no menu:\n\n"); // diz para o usuário escolher uma opção
		printf("\t1- Registrar funcionário\n"); // primeira opção, leva o usuário para registrar o funcionário
		printf("\t2- Consultar funcionário\n"); // segunda opção, leva o usuário para consultar o funcionário
		printf("\t3- Deletar funcionário\n\n"); // terceira opção, leva o usuário para deletar o funcionário
		printf("Digite aqui a opção: ");
	
		scanf("%d", &opcao); // para armazenar uma variável do tipo inteiro é usado o %d, o uso do "&" indica qual variável desejo guardar
	
		system("cls"); // função para limpar tela após usuário fazer a escolha
	
		switch(opcao)
		{
			case 1: // se escolher a primeira opção:
			registrar();
			break;
			
			case 2: // se escolher a segunda opção:
			consultar();
			break;
			
			case 3: // se escolher a terceira opção:
			deletar();
			break;
			
			default: // // se escolher um número inválido:
			printf("Você escolheu uma opção indispoível, tente novamente!\n\n");
			system("pause"); //faz a mensagem aparecer para o usuário até ele não querer mais
			break;
		}
	
	} // fim do laço
}

