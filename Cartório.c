#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string
#include <stdio.h> //biblioteca de comunicasção com usuário
   
int registro()//função responsavel por cadastrar os usuários 
{
	//inicio da criação de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variaveis/string
   
    printf("Digite o CPF a ser cadastrado: "); // coletando enformação do usuário
    scanf("%s", cpf); //%s refere-se a string
   
    strcpy(arquivo, cpf); //Responsaval por copiar o arquivo das tsring
   
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo 
    fprintf(file,cpf); // salva o valor da variavel 
    fclose(file); // fecha o arquivo
   
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
  
    printf("Digite o nome a ser cadastrado:  ");
    scanf("%s",nome);
   
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
   
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
	printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
   
    system("pause");
    
}

int consultar()  
{
    setlocale(LC_ALL, "portuguese");//Definindo a linguagem 
   
    char cpf[40];
    char conteudo[200];
    
    printf("digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssa são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");	
	}
    
    system("pause");
    
    
}

int deletar()
{
   char cpf[40];
   
   printf("Digite o CPF a ser deletado: ");
   scanf("%s",cpf);
   
   remove(cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("O usuário não se encontra no sistema!.\n");
   	system("pause");
   }
   
}



int main()
    {
    setlocale(LC_ALL, "portuguese");//Definindo a linguagem 
   
    int opcao=0; //Definindo variaveis 
   
    while(1) 
    {
        system("cls");
	     	 
        printf("### Cartório da EBAC ###\n\n"); //inicio do menu 
	    printf("Escolha a opção desejada do menu\n\n");   
        printf("\t1 - Registrar nomes \n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");       
        printf("opção: ");//fim do menu
        
	    scanf("%d", &opcao); //armazenamento a escolha do usuário 

        system("cls");

        switch(opcao) //inicio da seleção do menu 
        {
		    case 1://inicio da seleção
		    registro();
		    break;
		    
		    case 2:
		    consultar();
		    break;
		    
		    case 3:
		    deletar();
		    break;		    		
		
		    default:
		    printf("Essa opçao não está disponivel!\n");
            system("pause");
			break;	
			//fim da seleção
		}    
    } 
}
