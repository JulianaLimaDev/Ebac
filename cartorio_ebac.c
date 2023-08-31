#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//Função responável por cadastrar usuários no sistema
{
	//inicio da criação de váriaveis/ string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de váriaveis/ string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)  != NULL)
	{
		printf("\nEssas são as informações do usuário:  ");
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
		printf("O usuario não se encontra no sistema!\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0; //Definindo variáveiss
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
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n"); 
   		printf("\t4 - Sair do sistema!\n\n");
   		printf("Opção: "); //fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls"); //responsável por limpar a tela
		
    		switch(opcao) //inicio da seleção do menu
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
    			printf("Essa opção não esta disponível!\n");
    			system("pause");
    			break;
    		} //fim da seleção
       }
    }

	else
        printf("Senha incorreta!"); 
	
}
