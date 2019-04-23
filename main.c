#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int num, i;
float condoSpenses = 1000;

struct apartment {
  char apartmentResident[50];
  int apartmentNumber, qtdResidents;
  float value, area;
  };

struct apartment vetApartment[2];

void apartmentRead(){
	for(i=0; i<2; i++){
		title();
		printf("INSERIR NOVO APARTAMENTO \n\n");
		printf("%dº Apartamento: \n\n", (i+1));
		fflush(stdin);
		printf("Nome do morador: ");
		gets(vetApartment[i].apartmentResident);
		fflush(stdin);
		printf("Número do apartamento: ");
		scanf("%d", &vetApartment[i].apartmentNumber);
		fflush(stdin);
		printf("Área do imovel: ");
		scanf("%f", &vetApartment[i].area);
		fflush(stdin);
		printf("Quantidade de moradores: ");
		scanf("%d", &vetApartment[i].qtdResidents);
		fflush(stdin);
		system("cls");
	}
}
void title(){
	printf("\n------------- SOFT CONDO ------------\n");
	printf("\n-------------------------------------");
	printf("\n- Sistemas de gestão de condomínios -");
	printf("\n--------------- (v1.1) --------------\n");
	printf("-------------------------------------\n\n\n");
}
void mainMenu(){
	title();
	printf("ESCOLHA A OPCÃO DESEJADA:\n\n");
    printf("1- Inserir novo apartamento\n");
    printf("2- Listar valores a serem pagos\n\n");
    printf("3- Sair do sistema\n\n");
    scanf("%d", &num);
}
int showResult(){
	title();
 	printf("VALORES A SEREM PAGOS: \n\n");
	printf("PROPRIETÁRIO / N.APART / VALOR:\n");
	for(i=0; i<2; i++){
		calculate(i);
    	printf("%s, AP %d: R$ %.2f\n",
		vetApartment[i].apartmentResident,
		vetApartment[i].apartmentNumber,
		vetApartment[i].value);
	}
}
void backMainMenu(){
	printf("\n\n2- Voltar ao menu inicial\n");
	printf("3- Sair do sistema\n\n");
	scanf("%d", &num);
	switch(num){
		case 2:
			system("cls");
			break;
		case 3:
			exit(0);
	}
}
int calculate(int i){
	int x;
	float totalArea = 0, areaSpenses;
	for(x=0;x<2;x++){
		totalArea += vetApartment[x].area;
	}
	areaSpenses = condoSpenses / totalArea;
	for(x=0;x<2;x++){
		vetApartment[i].value = areaSpenses * vetApartment[i].area;
	}
}
int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	do{
		mainMenu();
		switch(num){
		    case 1:
		    	system("cls");
		    	apartmentRead();
		        break;
		    case 2:
		    	system("cls");
		    	showResult();
		    	backMainMenu();
		    	break;
			case 3:
				exit(0);
			default:
				system("cls");
				printf("%d é uma opção inválida. Por favor, tente novamente.", num);
				break;
		}
	}while(num != 3);
}
