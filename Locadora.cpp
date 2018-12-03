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
		// Módulo principal
		printf("\n\n");
		printf("\tSTORM LOCADORA\n\n");
		printf("\t|1| - CADASTRAR.\n");
		printf("\t|2| - LOCAR CARRO.\n");
		printf("\t|3| - ADMINISTRADOR.\n");
		printf("\t|4| - SAIR.\n");
		printf("\n\tDigite a opção desejada: ");
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
						printf("\t|3| - CADASTRAR VEÍCULO.\n");
						printf("\t|4| - VEÍCULOS LOCADOS.\n") ;	//informações do cliente q locou, quanto tempo, etc...
						printf("\t|5| - INFORMAÇÕES DOS VEÍCULOS.\n");
						printf("\t|6| - EDITAR VEICULOS.\n");
						printf("\t|7| - EDITAR CLIENTES.\n");
						printf("\t|8| - VOLTAR.\n");
					//	chara('_',30);
						printf("\n\tDigite a opção desejada: ");
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
								printf("Opção inválida. Por favor, digite novamente.\n\n");
								system("pause");
								system("CLS");
								
						}
					//desloga o adm
				}//Sai do módulo adm
				
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
				
			default: //Default módulo main
				//invalido();
				printf("asdfsdfasd0");
		}
	} // Sai do módulo adm
		
}



void invalido()
{
	printf("Opção inválida. Por favor, digite novamente.\n\n");
	system("pause");
}

void cadcarro()
{
	int opcao,i=0;
	
	
	printf("\tDigite a marca do veículo: ");
		fflush(stdin);
		gets(car[i].marca);
	
		printf("\tDigite o modelo do veículo: ");
			fflush(stdin);
			gets(car[i].modelo);
		
			printf("\tDigite o preço da diaria do veículo: R$");
				scanf("%f",&car[i].diaria);
													
				printf("\tDigite o número de portas do veículo: ");
					scanf("%i",&car[i].info[i].portas);
																
					printf("\tDigite o número de lugares do veículo: ");
						scanf("%i",&car[i].info[i].lugares);
					
						printf("\tMotor: ");
							scanf("%f",&car[i].info[i].motor);
						
														
							do
							{
								printf("\tCâmbio: \n");
								printf("\t1.Automático.\n");
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
								printf("\tDireção: \n");
								printf("\t1.Elétrica.\n");
								printf("\t2.Hidraulica.\n");
								printf("\t3.Eletrohidráulica.\n");
								scanf("%i",&opcao);
								if(opcao == 1)
									strcmp(car[i].info[i].direcao, "Elétrica");
								else if(opcao == 2)
									strcmp(car[i].info[i].direcao, "Hidráulica");
								else if(opcao == 3)
									strcmp(car[i].info[i].direcao, "Eletrohidráulica");
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
		printf("CPF válido: ");
			fflush(stdin);
			gets(cliente[i].cpf);
			
	/*	cont = strlen(cliente[i].cpf);		
		if(cont == 11)
		{	*/	
			printf("Nome completo: ");
				fflush(stdin);
				gets(cliente[i].nome);
				
			printf("Nome completo da mãe: ");
				fflush(stdin);
				gets(cliente[i].mae);
				
			printf("E-mail: ");
				fflush(stdin);
				gets(cliente[i].email);
				
			printf("Número do celular com DDD: ");
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
				
			printf("Endereço: ");
				fflush(stdin);
				gets(cliente[i].res[i].endereco);
				
			printf("Número (casa): ");
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
				printf("As senha não coincidem.\n\n");
				system("pause");
				goto senha;
			}
						
			
			
		/*}
		else
		{
			printf("\n\n");
			printf("CPF inválido. Certifique-se de escrever 11 dígitos.\n\n");
			system("pause");
		} */
	}
	else
	{
		printf("Número máximo de clientes cadastrados.\n");
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
			printf("Endereço: %s\n",cliente[j].res[j].endereco);
			printf("Nº da casa: %i\n",cliente[j].res[j].num_casa);
			printf("CEP: %i\n",cliente[j].res[j].cep);
			printf("\n\n");
		}
	}
}
