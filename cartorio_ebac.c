#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//Fun��o respon�vel por cadastrar usu�rios no sistema
{
	//inicio da cria��o de v�riaveis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de v�riaveis/ string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s", cpf); //refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf ("Digite o cpf a ser consultado:  ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)  != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:  ");
		printf("%s" , conteudo);
		printf("\n\n");
	}
		
    system("pause");
}



int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado!\n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file ==NULL)
	{
		printf("O usuario n�o se encontra no sistema!\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //Definindo vari�veiss
	int laco=1;
	char senhadigitada[10] = "a";
	int comparacao;
	
	printf("### Cartorio da Ebac ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if (comparacao ==0)
	{
		system("cls");
		for(laco=1;laco=1;)
		{
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n"); 
   		printf("\t4 - Sair do sistema!\n\n");
   		printf("Op��o: "); //fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); //respons�vel por limpar a tela
		
    		switch(opcao) //inicio da sele��o do menu
    		{
    			case 1:
    			registro();
    			break;
			
    			case 2:
    			consulta();
    			break;
		
       			case 3:
    			deletar();
    			break;
			
    			case 4:
    			printf ("Obrigada por utilizar o sistema!\n\n");
    			return 0;
    			break;
				
    			default:
    			printf("Essa op��o n�o esta dispon�vel!\n");
    			system("pause");
    			break;
    		} //fim da sele��o
       }
    }

	else
        printf("Senha incorreta!"); 
	
}
