#include <stdio.h> //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca�ao de espa�o de memoria
#include <locale.h> //biblioteca de aloca�ao de texto po regiao
#include <string.h> //biblioteca responsavel por cuidar das strings 

int registro() //Fun�ao responsavel por cadastrar os usuarios no sistema

{   //Inicio cria�ao de variaveis/string
   	char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
     //final da cria�ao de variaveis/string
     printf("Digite o CPF a ser cadastrado:  ");  //coletando informa�ao do usuario
     scanf("%s", cpf); //%s refere-se a string
     
     strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
     
     FILE *file; //cria o arquivo e o "w" significa  escrever
     file = fopen(arquivo, "w"); //cria o arquivo
     fprintf(file,cpf); //salvo o valor da variavel
     fclose(file); // fecha o valor
     
     
     file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     
     printf("Digite o nome a ser cadastrado:   ");
     scanf("%s",nome);
     
     file = fopen(arquivo, "a");
     fprintf(file,nome);
     fclose(file);
     
      file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     
      printf("Digite o sobrenome a ser cadastrado:  ");
       scanf("%s", sobrenome);
     
     file = fopen(arquivo, "a");
     fprintf(file,sobrenome);
     fclose(file);
     
     file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
     
     printf("Digite o cargo a ser cadastrado:  "); 
     scanf("%s", cargo);
     
     file = fopen(arquivo, "a");
     fprintf(file,cargo);
     fclose(file);
     
     system("pause");
     
     
}
int consulta()

{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:   ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
{
	printf("Nao foi possivel abrir o arquivo, nao localizado! \n");
}

    while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas sao as informa�oes do usuario:   ");
	printf("%s", conteudo);
	printf("\n\n");
}

    system("pause");

}
int deletar()

{
char cpf[40];

    printf("Digite o CPF do usuario a ser Deletado:   ");
    scanf("%s", cpf);


    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
{
	printf("O usuario nao se encotra no sistema! \n");
	system("pause");
}

  
}




int main(){
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;){
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
	
        printf("### Cartr�io da EBAC ###\n\n"); //inicio do menu
     	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n"); //fim do menu
	    printf("\t4 - Sair do sistema\n\n");            
	
    	scanf("%d", &opcao); //armazenado a escolha do usuario
	
    	system("cls"); // responsavel por limpar a tela
    	
    	switch(opcao){ //inicio da sele�ao do menu
    	
    	    case 1:
    	    	registro(); // chamada das fun�oes  
    	    	break;
    	    
    	    case 2:
    	    	consulta();
    	    	break;
    			
    		case 3:
    			deletar();
    			break;
    			
    		case 4:
    			printf("Obrigado por utilizar o sistema!");
    			return 0;
    			break;
			    	
    			
    			
    				default:
    				printf("Essa opcao nao esta disponivel!\n");
		            system("pause");
		            break;
    			
		}
	
    
	} //fim da sele�ao
}

