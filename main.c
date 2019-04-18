#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int numero, i;
struct apartamentos {
  char nome[50];
  int numeroApartamento, moradores;
  float valor, area;
  };

struct apartamentos vetApartamentos[2];

void lerApartamentos(int pos){
	cabecalho();
	printf("INSERIR NOVO APARTAMENTO \n\n");
	printf("%dº Apartamento: \n\n", (i+1));
	fflush(stdin);
	printf("Nome do morador: ");
	gets(vetApartamentos[pos].nome);
	fflush(stdin);
	printf("Número do apartamento: ");
	scanf("%d", &vetApartamentos[pos].numeroApartamento);
	fflush(stdin);
	printf("Área do imovel: ");
	scanf("%f", &vetApartamentos[pos].area);
	fflush(stdin);
	printf("Quantidade de moradores: ");
	scanf("%d", &vetApartamentos[pos].moradores);
	fflush(stdin);
	system("cls");
}

void mostraResultado(int pos){
	printf("%s, AP %d: R$ %.2f\n",
		vetApartamentos[pos].nome,
		vetApartamentos[pos].numeroApartamento,
		vetApartamentos[pos].valor);
}

void cabecalho(){
	printf("\n------------- SOFT CONDO ------------\n");
	printf("\n-------------------------------------");
	printf("\n- Sistemas de gestão de condomínios -");
	printf("\n--------------- (v1.1) --------------\n\n");
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	do{
		cabecalho();
		printf("ESCOLHA A OPCÃO DESEJADA:\n\n");
	    printf("1- Inserir novo apartamento\n");
	    printf("2- Listar valores a serem pagos\n\n");
	    printf("3- Sair do sistema\n\n");
	    scanf("%d", &numero);
		
	    switch(numero){
	
		    case 1:
		    	system("cls");
		        for(i=0; i<2; i++){
		        	lerApartamentos(i);
				}
		        break;
		    case 2:
		    	system("cls");
		    	cabecalho();
		     	printf("VALORES A SEREM PAGOS: \n\n");
				printf("PROPRIETÁRIO / N.APART / VALOR:\n");
				for(i=0; i<2; i++){
		        	mostraResultado(i);
				}
				printf("\n\n2- Voltar ao menu inicial\n");
				printf("3- Sair do sistema\n\n");
				scanf("%d", &numero);
				switch(numero){
					case 2:
						system("cls");
						break;
					
					case 3:
						exit(0);
				}
				break;
			case 3:
				exit(0);
			default:
				system("cls");
				printf("%d é uma opção inválida. Por favor, tente novamente.", numero);
				break;
		}
	}while(numero != 3);
}
