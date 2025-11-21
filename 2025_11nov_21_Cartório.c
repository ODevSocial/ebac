#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file = fopen(arquivo, "w"); // corretíssimo agora (w minúsculo)
    if(file == NULL){
        printf("Erro ao criar o arquivo!\n");
        system("pause");
        return 1;
    }

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    // Agora salva tudo de uma vez, formatado
    fprintf(file, "%s,%s,%s,%s\n", cpf, nome, sobrenome, cargo);

    fclose(file);

    printf("Usuário cadastrado com sucesso!\n");
    system("pause");
    return 0;
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Usuário não encontrado!\n");
        system("pause");
        return 1;
    }

    if(fgets(conteudo, 200, file) != NULL)
    {
        char c_cpf[40], nome[40], sobrenome[40], cargo[40];

        // separando os dados salvos no arquivo
        sscanf(conteudo, "%[^,],%[^,],%[^,],%s", c_cpf, nome, sobrenome, cargo);

        printf("\n--- Dados do Usuário ---\n");
        printf("CPF: %s\n", c_cpf);
        printf("Nome: %s\n", nome);
        printf("Sobrenome: %s\n", sobrenome);
        printf("Cargo: %s\n", cargo);
        printf("------------------------\n\n");
    }

    fclose(file);
    system("pause");
    return 0;
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    if(remove(cpf) == 0)
        printf("Usuário deletado com sucesso!\n");
    else
        printf("Usuário não encontrado!\n");

    system("pause");
    return 0;
}

int main ()
{

	int opcao=0; //Definindo variáveis
	int laco=1;
	
	while(1)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
	
			switch(opcao) //Inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
		
	
	}

}
