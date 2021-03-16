#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Variaveis globais
int i;
char arqDigi [25000];
FILE *arqOpen;



//Funcao para criptografar mensagens
int incripto()
{
	arqOpen = fopen ("Arq.txt", "w");
    if (arqOpen == NULL) 
	{
       printf ("Nao foi possível abrir o arquivo escolhido.\n");
       return 1;
    }
	fflush(stdin);		    
    printf("Por favor, digite o que deseja criptografar:\n");  
    gets(arqDigi);			    
    for( i = 0; i < strlen(arqDigi); i++ )
    {
        arqDigi[i] += 50;
    }			
    printf(">> Arquivo Gerado com Sucesso: %s\n\n ", arqDigi);			    
    for(i=0; arqDigi[i]; i++)
	{
		fputc(arqDigi[i], arqOpen);
	}	
    printf ("Arquivo criado com sucesso.\n");
    fclose(arqOpen);
    printf("Digite qualquer tecla para voltar a Home");
	printf("Obrigado por utilizar a aplicacao!");
	getchar();	
	system("cls");
}

//Funcao para descriptografar mensagens
int indescripto()
{
	fflush(stdin);
	int i;
	FILE *openDescript;
	openDescript = fopen("Arq.txt", "r");		
	if(openDescript == NULL)
	{
		printf("Algo deu errado, não foi possível abrir o arquivo escolhido!\n");
		getchar();
	}				
	system("cls");			 	
	while(fgets(arqDigi, 1000, openDescript) != NULL)
 	{
 		for( i = 0; i < strlen(arqDigi); i++ )
		    {
		        arqDigi[i] -= 50;
		    }
 		printf("%s", arqDigi);
	}
	printf("\n\nDigite qualquer tecla para voltar ao menu principal!");
	getchar();
	system("cls");
}



//Inicializacao do programa
int main()
{
int escolha=0;
	
	while(escolha < 3)
	{
		printf("\nSistema Cripto!\n\n Trabalho de APS\n Obrigado por utilizar minha aplicacao!\n\n\n");
		printf("Digite 1:\nPara criptografar uma mensagem.\n\n");
		printf("Digite 2:\nPara descriptografar uma mensagem.\n\n");
		printf("Digite 3:\nPara Sair.\n");
		scanf("%d",& escolha);
		switch(escolha)
		{			
			case 1:				
				incripto();		    
			break;
			case 2:				
			 	indescripto();
			break;
			case 3:
				exit(0);
			break;			
		}
	}
}