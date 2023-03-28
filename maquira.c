#include <stdio.h> // traduz a linguagem de programa��o para o usu�rio
#include <stdlib.h> // respons�vel por alocar mem�rias para uma vari�vel como ex.
#include <locale.h> // biblioteca de aloca��o de texto por regi�o, como estamos no BR, permite a inclus�o de acentos como ex.
#include <string.h> // possibilita o uso de strings

int registrar() // aba de registro
{
	// strings que s�o conjunto de vari�veis
	char arquivo[40]; // vari�vel do arquivo que sera gerado com o nome do CPF cadastrado
	char cpf[40]; // char para caracteres, 40 � o tamanho m�ximo de caracteres
	char nome[40];
	char sobrenome[40];
	char setor[40];
	char cargo[40];
	
	setlocale(LC_ALL, "Portuguese"); // dizendo para a biblioteca locale qual linguagem desejo
	
	printf("Voc� escolheu registrar um funcion�rio!\n\n");
	printf("Digite o CPF do funcion�rio a ser cadastrado: ");
	scanf("%s", cpf); //%s para armazenar string e ser� armazenado na vari�vel cpf
	system("cls");
	
	strcpy(arquivo, cpf); // respons�vel por copiar as vari�veis do cpf para o nome do arquivo de registro gerado
	
	FILE *file; // chamando uma fun��o ja existente do sistema para criar um arquivo
	file = fopen(arquivo, "w"); // quando criar esse arquivo, vou abri-lo (fopen) com o nome de arquivo (acima cpf foi copiado para arquivo, assim o arquivo ser� criado com a vari�vel do CPF) e vou escreve-lo, j� que n�o existe (w de write)
	fprintf(file, cpf); // usado para salvar dentro do arquivo, no caso salvando a vari�vel CPF
	fclose(file); // abri, salvei e agora fechei o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo e atualizar o arquivo (a)
	fprintf(file, " | "); // salvando com uma v�rgula dentro do arquivo para separar as informa��es
	fclose(file); // fechar o arquivo
	
	printf("Digite o nome do funcion�rio a ser cadastrado: ");
	scanf("%s", nome);
	system("cls");
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome do funcion�rio a ser cadastrado: ");
	scanf("%s", sobrenome);
	system("cls");
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " | ");
	fclose(file);
	
	printf("Digite o setor do funcion�rio a ser cadastrado: ");
	scanf("%s", setor);
	system("cls");
	
	file = fopen(arquivo, "a");
	fprintf(file, setor);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " | ");
	fclose(file);
	
	printf("Digite o cargo do funcion�rio a ser cadastrado: ");
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
	
	printf("Voc� escolheu consultar um de nossos funcion�rios!\n");
	printf("Agora digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; // consultar um arquivo
	file = fopen(cpf, "r"); // abra esse arquivo com nome da vari�vel CPF e leia (r) o conte�do
	
	if(file  == NULL) // se o CPF n�o existir, for nulo:
	{
		printf("Esse CPF n�o est� cadastrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // v� ao arquivo, busque os 200 caracteres que est�o no conte�do desse arquivo e salve na vari�vel conteudo enquanto for diferente de nulo
	{
	printf("\nEssas s�o as informa��es do funcion�rio:\n\n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	setlocale(LC_ALL, "Portuguese"); // dizendo para a biblioteca locale qual linguagem desejo
	
	printf("Voc� escolheu deletar um funcion�rio!\n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // ler o arquivo cpf
	
	if(file == NULL)
	{
		printf("Este CPF n�o est� cadastrado!\n");
		system("pause"); //faz a mensagem aparecer para o usu�rio at� ele n�o querer mais
	}

}

int main() // fun��o principal, menu do programa
{
	int opcao=0; // definindo a vari�vel
	int x=1; // vari�vel do la�o de repeti��o
	
	for(x=1;x=1;) // dessa forma o la�o de repeti��o fica eterno, ja que a entrada e saida do la�o s�o iguais, al�m de n�o ter inclemento que seria dado por "x++"
	{ // in�cio da chave, engloba o que ficar� dentro do la�o
		
		system("cls"); // fun��o para limpar tela ap�s usu�rio fazer a escolha
		
		setlocale(LC_ALL, "Portuguese"); // dizendo para a biblioteca locale qual linguagem desejo
	
		printf("\t\t Funcion�rios Maquira \t\t\n\n"); // printf envio esse texto para a tela do usu�rio
		printf("Escolha a op��o desejada no menu:\n\n"); // diz para o usu�rio escolher uma op��o
		printf("\t1- Registrar funcion�rio\n"); // primeira op��o, leva o usu�rio para registrar o funcion�rio
		printf("\t2- Consultar funcion�rio\n"); // segunda op��o, leva o usu�rio para consultar o funcion�rio
		printf("\t3- Deletar funcion�rio\n\n"); // terceira op��o, leva o usu�rio para deletar o funcion�rio
		printf("Digite aqui a op��o: ");
	
		scanf("%d", &opcao); // para armazenar uma vari�vel do tipo inteiro � usado o %d, o uso do "&" indica qual vari�vel desejo guardar
	
		system("cls"); // fun��o para limpar tela ap�s usu�rio fazer a escolha
	
		switch(opcao)
		{
			case 1: // se escolher a primeira op��o:
			registrar();
			break;
			
			case 2: // se escolher a segunda op��o:
			consultar();
			break;
			
			case 3: // se escolher a terceira op��o:
			deletar();
			break;
			
			default: // // se escolher um n�mero inv�lido:
			printf("Voc� escolheu uma op��o indispo�vel, tente novamente!\n\n");
			system("pause"); //faz a mensagem aparecer para o usu�rio at� ele n�o querer mais
			break;
		}
	
	} // fim do la�o
}

