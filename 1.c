#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int res = 0;

typedef struct prod //estrutura de um produto
{
	int cod;
	char nome[50];
	int quant;
	float valorC;
	float valorV;
	struct prod* prox;
}prod;

prod *iP;

void criaListaP() //Inicializando o ponteiro
{
	iP = NULL;
}

typedef struct prodCaro //estrutura para armazenar produtos mais caros (caso haja mais de um)
{
	int cod;
	char nome[50];
	int quant;
	float valorC;
	float valorV;
	struct prodCaro* prox;
}prodCaro;

prodCaro *iPC;

void criaListaPC () //Inicializando o ponteiro
{
	iPC = NULL;
}

prod* criaProd() //função chamada dentro de addprod (add prod cria o nó)
{
	prod *aux;
	aux = (prod*) malloc(sizeof(prod));
	printf("Informe o código do produto: \n");
	scanf("%d",&aux->cod);
	printf(" Informe o nome do prooduto: \n");
	scanf("%s",aux->nome);
	printf("Informe a quantidade em estoque do produto \n");
	scanf("%d",&aux->quant);
	printf("Informe o preço de Compra do produto: \n");
	scanf("%f",&aux->valorC);
	printf("Informe o preço de Venda do produto: \n");
	scanf("%f",&aux->valorV);
	aux->prox = NULL;
	printf("\n");
	printf("Produto cadastrado com sucesso! \n");
	printf("\n");
	system("pause");
	return aux;
}

int prodVazia() //teste usado para verificar se a lista de produtos está vazia
{
	if (iP == NULL)
	{
		return 1;
	}
	return 0;	
}

int prodCaroVazia() //teste usado para verificar se a lista de produtos caros está vazia 
{
	if (iPC == NULL)
	{
		return 1;
	}
	return 0;		
}

int checkProdV() //função que verifica se o produto recém inserido é o mais caro ou não
{
	prod *auxProduto;
	auxProduto = iP->prox;
	prodCaro *aux1;
	aux1 = (prodCaro*) malloc(sizeof(prodCaro));
	
	//Parte responsável pelo erro de execução
	aux1->cod = auxProduto->cod;
	memcpy(aux1->nome, auxProduto->nome, sizeof(aux1->nome));
	aux1->quant = auxProduto->quant;
	aux1->valorC = auxProduto->valorC;
	aux1->valorV = auxProduto->valorV;
	//
	
	
 	if(prodCaroVazia()==1) //sempre que a lista estiver vazia, o promeiro a ser cadastrado será o mais caro
	{
		iPC = aux1;
		printf("Produto recém-inserido é o primeiro cadastrado.");
		return 1;
	}	
	else
	{	
		if(aux1->valorV > iPC->valorV)
		{
			iPC = aux1;
			printf("Produto recém-inserido é o mais caro até o momento.");
			iPC->prox = NULL;
			return 1;
		}
		else
		{
			if(aux1->valorV == iPC->valorV)
			{
				aux1->prox = iPC;
				printf("O produto recém-inserido tem o mesmo valor que o mais caro cadastrado antes dele. ");
				iPC = aux1;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	system("pause");
}

void addProd() //cria a estrutura de produto (ou nó, no caso)
{	
	prod *aux;
	aux = criaProd();
	if (prodVazia() == 0)
	{
		aux->prox = iP;	
	}
	iP = aux;	
	system("pause");		
}

void consultaProd() //função autodescritiva
{	
	int varCod = 0;
	printf("Informe o código do produto a ser consultado: \n");
	scanf("%d",&varCod);
	prod *aux;
	aux = iP;
	if (prodVazia()==1)
	{
		printf ("Lista de produtos vazia! \n");
	}
	else
	{
		while (aux != NULL)
		{
			if (aux->cod == varCod)
			{
				printf("Produto encontrado! \n ");
				printf("\n");
				printf("Código: %d \n",aux->cod);
				printf("Nome: %s \n",aux->nome);
				printf("Quantidade em estoque: %d \n",aux->quant);
				printf("Valor de Compra do produto: %.2f \n",aux->valorC);
				printf("Valor de Venda do produto: %.2f \n",aux->valorV);
			}
			aux = aux->prox;
		}
		if (aux == NULL)
		{
			printf("Código inserido não encontrado no registro de produtos. \n");
		}
	}
	system("pause");		
}

void imprimiProds() //fnção autodescritiva
{
	prod *aux;
	aux = iP;
	if (prodVazia()==1)
	{
		printf ("Lista de produtos vazia! \n");
	}
	else
	{
		while (aux != NULL)
		{
			printf("Código: %d \n",aux->cod);				
			printf("Nome: %s \n",aux->nome);
			printf("Quantidade em estoque: %d \n",aux->quant);
			printf("Valor de Compra do produto: %.2f \n",aux->valorC);
			printf("Valor de Venda do produto: %.2f \n",aux->valorV);
			printf("\n");
		}
		aux = aux->prox;
	}
	system("pause");
}
void prodsCaros() //impressão do(s) produto(s) mais caros
{
	prodCaro *aux;
	aux = iPC;
	if (prodCaroVazia()==1)
	{
		printf ("Lista de produtos vazia! \n");
	}
	else
	{
		while (aux != NULL)
		{
			printf("Código: %d \n",aux->cod);
			printf("Nome: %s \n",aux->nome);
			printf("Quantidade em estoque: %d \n",aux->quant);
			printf("Valor de Compra do produto: %.2f \n",aux->valorC);
			printf("Valor de Venda do produto: %.2f \n",aux->valorV);
			printf("\n");
		}
		aux = aux->prox;
	system("pause");						
	}	
}

int main ()
{
	criaListaP();
	criaListaPC();
	while (res != 5)
	{	
		system("cls");
		printf("APS UNICARIOCA: MENU DE PRODUTO \n");
		printf("\n");
		printf("Digite alguma das opções abaixo: \n");
		printf("\n");
		printf("1 - Inserir dados de um novo produto \n");
		printf("2 - Consultar dados de um novo produto \n");
		printf("3 - Imprimir dados de todos os produtos \n");	
		printf("4 - Imprimir o produto mais caro \n");	
		printf("5 - Sair \n");
		printf("Opção: ");
		scanf("%d",&res);
		system("cls");
		switch (res)	
		{
			case 1:
				printf("1 - Inserir dados de um novo produto \n");
				addProd();	
			checkProdV(); //função que verifica se o produto recém inserido é o mais caro ou não				
			break;
			case 2:
				printf("2 - Consultar dados de um produto \n");
				consultaProd();					
			break;			
			case 3:
				printf("3 - Imprimir dados de todos os produtos \n");
				imprimiProds();
			break;
			case 4:
				printf("4 - Imprimir o produto mais caro \n");	
				prodsCaros();
			break;
			case 5:
				printf("APS UNICARIOCA - ESTRUTUDA DE DADOS: \n");
				printf("\n");
				printf("Daniel Yago da Silva Orfeu Joaquim - 2015103344 \n");
				printf("Juliana ");
				printf("Johann ");
				printf("Karine "); 
			break;
			default:
				printf("Valor inválido! Insira um valor válido. \n");
				system("pause");	
		}			
	}
	system("pause");
	return 0;
}
