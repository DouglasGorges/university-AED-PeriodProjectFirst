#include <stdio.h>
#include <stdlib.h>

int numero, i, sair = 0;;

struct apartamentos {
  char nome[50];
  int numeroApartamento, moradores;
  float area, valor;
  };

struct apartamentos vetApartamentos[2];

void lerApartamentos(int pos){
	printf("Nome do morador: ");
	gets(vetApartamentos[pos].nome);
	fflush(stdin);
	printf("Numero do apartamento: ");
	gets(vetApartamentos[pos].numeroApartamento);
	fflush(stdin);
	printf("Area do imovel: ");
	gets(vetApartamentos[pos].area);
	fflush(stdin);
	printf("Quatidade de moradores: ");
	gets(vetApartamentos[pos].moradores);
	fflush(stdin);
	system("cls");
}

void mostraResultado(int pos){
	printf("%s, %d: R$ %.2f\n", vetApartamentos[pos].nome, vetApartamentos[pos].numeroApartamento, vetApartamentos[pos].valor);
}

int main(int argc, char *argv[]) {
  
  	printf("\n------------- SOFT CONDO ------------\n");
	printf("\n-------------------------------------");
	printf("\n- Sistemas de gestao de condominios -");
	printf("\n--------------- (v1.1) --------------\n\n");
	
	printf("\nEscolha a opcao desejada:\n\n");
    printf("1- Inserir apartamento\n");
    printf("2- Listar valores a serem pagos\n\n");
    printf("3- Sair do sistema\n\n");
    scanf("%d", &numero);
	
    switch(numero){

	    case 1:
	    	system("cls");
	        printf("INSERIR NOVO APARTAMENTO: \n\n");
	        for(i=0; i<2; i++){
	        	lerApartamentos(i);
			}
	        break;
	
	    case 2:
	    	system("cls");
	     	printf("VALORES A SEREM PAGOS: \n\n");
			printf("PROPRIETARIO / N.APART / VALOR:\n");
			for(i=0; i<2; i++){
	        	mostraResultado(i);
			}
			break;
		
		case 3:
			exit(0);
			break;
			
		default:
			printf("Opcao invalida. Por favor, tente novamente.");
}
	getch();
	return 0;
}