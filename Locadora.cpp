#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <ctype.h>
#include "chara.h"
#define N 3


// STRUCT CARRO
struct especf_carro {
	int portas;
	char cambio[2];
	int lugares;
	char direcao[10];
	float motor;
};

struct carro {
	char marca [25];
	char modelo [30];
	float diaria;
	int idCarro;
	struct especf_carro info[N];
};

struct carro car[N];

FILE *fp;

// STRUCT CLIENTE
struct cliente_residencial {
	int cep, num_casa;
	char cidade[30], bairro[30], endereco[50];
};

struct cliente_pessoal {
	char nome[50];
	char mae[50];
	char email[50];
	char senha[20];
	char cpf[11];
	int celular;
	int idLocado;
	struct cliente_residencial res[N];
};

struct cliente_pessoal cliente[N];

void CadCliente();
void listaCliente();
void cadcarro();

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	system("title Aluguel");
	
	
	int p=1,i=0, j=0;

	char resposta;
	
	int opcao;
	
	
	while(opcao != 4)
	{
		inicio:
		system("CLS");
		resposta = 'S';
		// M�dulo principal
		printf("\n\n");
		printf("\tSTORM LOCADORA\n\n");
		printf("\t|1| - CADASTRAR.\n");
		printf("\t|2| - LOCAR CARRO.\n");
		printf("\t|3| - ADMINISTRADOR.\n");
		printf("\t|4| - SAIR.\n");
		printf("\n\tDigite a op��o desejada: ");
		scanf("%i",&opcao);
		
		system("CLS");
	
		switch (opcao)
		{
			case 1:
				CadCliente();
			break;
		
			case 2:
				break;
			
			case 3:
				
				char login_adm[15], senha_adm[15], conf_login_adm[15], conf_senha_adm[15];
				
				// login: adm || senha: adm
				strcpy(conf_login_adm,"adm");
				strcpy(conf_senha_adm,"adm");
				
				
				adm:
				printf("\n\n");
				system("CLS");
				printf("\n\n");
				printf("\tLogin: ");
					fflush(stdin);
					gets(login_adm);
					//fflush(stdin);
					
				printf("\tSenha: ");
					fflush(stdin);
					gets(senha_adm);
				
				if(strcmp (login_adm,conf_login_adm) != 0 && strcmp(senha_adm,conf_senha_adm) != 0) 
				{
					system("CLS");
					printf("\n\n");
					printf("\tLogin ou senha incorretos. Deseja continuar? [S/N]\n\t");
						scanf("%c",&resposta);
						
					resposta = toupper(resposta);
					if(resposta == 'S')
						goto adm;
					else
						goto inicio;
				}
				else
				{
						// MODULO ADM
						comeco:
						system("CLS");
						printf("\n\n");
						printf("\t|1| - BUSCAR CLIENTE CADASTRADO.\n");
						printf("\t|2| - LISTAR TODOS OS CLIENTES CADASTRADOS.\n"); 
						printf("\t|3| - CADASTRAR VE�CULO.\n");
						printf("\t|4| - VE�CULOS LOCADOS.\n") ;	//informa��es do cliente q locou, quanto tempo, etc...
						printf("\t|5| - INFORMA��ES DOS VE�CULOS.\n");
						printf("\t|6| - EDITAR VEICULOS.\n");
						printf("\t|7| - EDITAR CLIENTES.\n");
						printf("\t|8| - VOLTAR.\n");
					//	chara('_',30);
						printf("\n\tDigite a op��o desejada: ");
						scanf("%i",&opcao);
						
						system("CLS");
			
						switch (opcao)
						{
							case 1:
								
								break;
								
							case 2:
								listaCliente();
								printf("\n\n");
								system("pause");
								break;
							
							case 3:
								cadcarro();
								goto comeco;
								break;
								
							case 4:
								break;
							
							case 5:
							
								break;
							
							case 6:
	
								break;
							
							case 7:
								break;
								
							case 8:
								goto inicio;
								break;
								
							default:
								system("CLS");
								printf("Op��o inv�lida. Por favor, digite novamente.\n\n");
								system("pause");
								system("CLS");
								
						}
					//desloga o adm
				}//Sai do m�dulo adm
				
			case 4:
				int k;
				while(k < 4)
				{
					printf("Finalizando o programa ");
					for(j=0; j<3; j++)
					{
						Sleep(300);
						printf(".");
					}
					system("CLS");
					k++;
				}
				
				exit(0);
				break;
				
			default: //Default m�dulo main
				//invalido();
				printf("asdfsdfasd0");
		}
	} // Sai do m�dulo adm
		
}



void invalido()
{
	printf("Op��o inv�lida. Por favor, digite novamente.\n\n");
	system("pause");
}

void cadcarro()
{
	int opcao,i=0;
	
	
	printf("\tDigite a marca do ve�culo: ");
		fflush(stdin);
		gets(car[i].marca);
	
		printf("\tDigite o modelo do ve�culo: ");
			fflush(stdin);
			gets(car[i].modelo);
		
			printf("\tDigite o pre�o da diaria do ve�culo: R$");
				scanf("%f",&car[i].diaria);
													
				printf("\tDigite o n�mero de portas do ve�culo: ");
					scanf("%i",&car[i].info[i].portas);
																
					printf("\tDigite o n�mero de lugares do ve�culo: ");
						scanf("%i",&car[i].info[i].lugares);
					
						printf("\tMotor: ");
							scanf("%f",&car[i].info[i].motor);
						
														
							do
							{
								printf("\tC�mbio: \n");
								printf("\t1.Autom�tico.\n");
								printf("\t2.Manual.\n");
								scanf("%i",&opcao);
								if(opcao == 1)
									strcmp(car[i].info[i].cambio,"AT");
								else if(opcao == 2)
									strcmp(car[i].info[i].cambio,"M");
								else if(opcao < 1 && opcao > 2)
									invalido();
							}while(opcao < 1 || opcao > 2);
														
							do
							{					
								printf("\tDire��o: \n");
								printf("\t1.El�trica.\n");
								printf("\t2.Hidraulica.\n");
								printf("\t3.Eletrohidr�ulica.\n");
								scanf("%i",&opcao);
								if(opcao == 1)
									strcmp(car[i].info[i].direcao, "El�trica");
								else if(opcao == 2)
									strcmp(car[i].info[i].direcao, "Hidr�ulica");
								else if(opcao == 3)
									strcmp(car[i].info[i].direcao, "Eletrohidr�ulica");
								else if(opcao < 1 || opcao > 3)
									invalido();
							}while(opcao < 1 || opcao > 3);
							
							car[i].idCarro = i;
							i++;
	system("CLS");
}




void CadCliente()
{
	int i=0, cont = 0, j=0;
	char senha_cliente[20];
	
	if(i < N)
	{				
		system("CLS");
		printf("\n\n");
		printf("COMPLETE COM SEUS DADOS PESSOAIS\n");
		chara('_',30);
		printf("CPF v�lido: ");
			fflush(stdin);
			gets(cliente[i].cpf);
			
	/*	cont = strlen(cliente[i].cpf);		
		if(cont == 11)
		{	*/	
			printf("Nome completo: ");
				fflush(stdin);
				gets(cliente[i].nome);
				
			printf("Nome completo da m�e: ");
				fflush(stdin);
				gets(cliente[i].mae);
				
			printf("E-mail: ");
				fflush(stdin);
				gets(cliente[i].email);
				
			printf("N�mero do celular com DDD: ");
				scanf("%i",&cliente[i].celular);
								
			printf("\tCOMPLETE COM SEUS DADOS RESIDENCIAIS\n");
				chara('_',50);
			printf("CEP: ");
				scanf("%i",&cliente[i].res[i].cep);
									
			printf("Cidade: ");
				fflush(stdin);
				gets(cliente[i].res[i].cidade);
				
			printf("Bairro: ");
				fflush(stdin);
				gets(cliente[i].res[i].bairro);
				
			printf("Endere�o: ");
				fflush(stdin);
				gets(cliente[i].res[i].endereco);
				
			printf("N�mero (casa): ");
				scanf("%i",&cliente[i].res[i].num_casa);
			
			senha:
			printf("Crie uma senha: ");
				fflush(stdin);
				gets(cliente[i].senha);
				
			printf("Confirme a senha: ");
				fflush(stdin);
				gets(senha_cliente);
				
			if(strcmp(cliente[i].senha, senha_cliente) == 0)
			{
				
				system("CLS");
				printf("Cadastro realizado com sucesso :)\n\n");
				system("pause");
				
			/*	int o;
				char cpf[11];
				char pulaLinha = '\n';
				strcpy(cpf,cliente[i].cpf);
				
				// ABRE O TXT
				fp = fopen("Cliente.txt","a");
				if(fp == NULL)
				{
		     	 	printf("Erro na abertura do arquivo. Fim de programa.\n");
		      	 	system("pause");
		      	 	exit(1);
  				}
  				for(o = 0; o < strlen(cpf); o++)
    				fputc(cpf[o], fp);
    			fputc(pulaLinha, fp);
				fclose(fp);
				i++; */
  				
  				
			}
			else
			{
				printf("As senha n�o coincidem.\n\n");
				system("pause");
				goto senha;
			}
						
			
			
		/*}
		else
		{
			printf("\n\n");
			printf("CPF inv�lido. Certifique-se de escrever 11 d�gitos.\n\n");
			system("pause");
		} */
	}
	else
	{
		printf("N�mero m�ximo de clientes cadastrados.\n");
		system("CLS");
	}
}

//LISTAR TODOS OS CLIENTES 
void listaCliente()
{
	int j;
	fp = fopen("Cliente.txt","a");
		if(fp == NULL)
		{
		    printf("Erro na abertura do arquivo. Fim de programa.\n");
		    system("pause");
		    exit(1);
  		}
  		char c;
  		for(j=0; j<11; j++)
  		{
  			c = fgetc(fp);
  			printf("%c",c);
		}
		system("pause");
		fclose(fp);
  		
  	
	for(j=0; j<N; j++)
	{
		if(cliente[j].cpf != 0)
		{
			printf("\tDADOS PESSOAIS\n");
			printf("Nome: %s\n",cliente[j].nome);
			printf("E-mail: %s\n",cliente[j].email);
			printf("CPF: %i\n",cliente[j].cpf);
			printf("Contato: %i\n",cliente[j].celular);
			printf("\tDADOS RESIDENCIAIS\n");
			printf("Cidade: %s\n",cliente[j].res[j].cidade);
			printf("Bairro: %s\n",cliente[j].res[j].bairro);
			printf("Endere�o: %s\n",cliente[j].res[j].endereco);
			printf("N� da casa: %i\n",cliente[j].res[j].num_casa);
			printf("CEP: %i\n",cliente[j].res[j].cep);
			printf("\n\n");
		}
	}
}
