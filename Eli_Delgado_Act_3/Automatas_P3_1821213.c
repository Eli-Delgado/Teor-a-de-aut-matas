#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

void bienvenida();
void in(char string[MAX]);
int valCadena(char string[MAX]);
int valInt(char aux[MAX]);
void pause();
void cursor(int posicion);
void impresion(char cinta[MAX], int posicion);
int isEmpty(char cinta[MAX]);


int main() {
	int opcion;
	char aux[MAX], string[MAX];
	bienvenida();
	do {
		printf("\n\n\t Teoria de Automatas");
		printf("\n\n Matricula: 1821213");
		printf("\n Nombre: Eli Israel Delgado Escarcega");
		printf("\n\n L = {w^n c^2n w^(n+2)}");
		printf("\n w = 213");
		printf("\n c = eide");
		printf("\n\n\n Ingrese una cadena: ");
		in(string);
		//printf("\n Caracter         %cV%clido?\n", 168, 160);
		if(valCadena(string)) {
			printf("\n\n => %s SI es una cadena valida\n\n", string);
		} else {
			printf("\n\n => %s NO es una cadena valida\n\n", string);
		}
		
		do {
			printf("\n Desea ingresar otra cadena [1- SI / 2- NO]: ");
			in(aux);
			opcion = valInt(aux);			
		}while(opcion != 1 && opcion != 2);
		system("cls");	
	} while(opcion != 2);
	
	system("cls");
	printf("\n\n\n\n \t\t\tFIN DEL PROGRAMA \n\n\n");
	pause();
	
	return 0;
}

void bienvenida() {
	printf("\n\n\n\n");
	printf("\n\n\t\t\t    BIENVENIDO \n\n\n\t\t");
	printf(" PRESIONE UNA TECLA PARA INICIAR: ");
	getch();
	system("cls");
}

int valCadena(char string[MAX]) {
	int i, n, lenght, state, posicion, j;
	char matricula[3] = {'2', '1', '3'}, iniciales[4] = {'e', 'i', 'd', 'e'}, cinta[MAX] = {' '};
	printf("\n\n\n\n Analizando la cadena \n");
	strcat(cinta, string);
	strcat(cinta, " ");
	state = 1;
	posicion = 0;
	//printf("\n %s", cinta);
	cursor(posicion);
	//printf("\n%s\n%s", string, cinta);
	while((!isEmpty(cinta) || state == 25) && state != 99) {
		//printf("\n %d", state);
		switch(state) {
			case 1:
				if(cinta[posicion] == ' ') {
					state = 2;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 2:
				if(cinta[posicion] == '2') {
					state = 3;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 3:
				if(cinta[posicion] == '1') {
					state = 4;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 4:
				if(cinta[posicion] == '3') {
					state = 5;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 5:
				if(cinta[posicion] == 'x') {
					state = 5;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == '2') {
					state = 5;
					cinta[posicion] = '2';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == '1') {
					state = 5;
					cinta[posicion] = '1';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == '3') {
					state = 5;
					cinta[posicion] = '3';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'e') {
					state = 6;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 6:
				if(cinta[posicion] == 'i') {
					state = 7;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 7:
				if(cinta[posicion] == 'd') {
					state = 8;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 8:
				if(cinta[posicion] == 'e') {
					state = 9;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 9:
				if(cinta[posicion] == 'e') {
					state = 10;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 10:
				if(cinta[posicion] == 'i') {
					state = 11;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 11:
				if(cinta[posicion] == 'd') {
					state = 12;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
			case 12:
				if(cinta[posicion] == 'e') {
					state = 13;
					cinta[posicion] = 'x';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
			case 13:
				//printf("\n case %d", state);
				if(cinta[posicion] == '2') {
					state = 13;
					cinta[posicion] = '2';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == '1') {
					state = 13;
					cinta[posicion] = '1';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == '3') {
					state = 13;
					cinta[posicion] = '3';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'e') {
					state = 13;
					cinta[posicion] = 'e';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'i') {
					state = 13;
					cinta[posicion] = 'i';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'd') {
					state = 13;
					cinta[posicion] = 'd';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == ' ') {
					state = 14;
					cinta[posicion] = ' ';
					posicion--;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 14:
				if(cinta[posicion] == '3') {
					state = 15;
					cinta[posicion] = ' ';
					posicion--;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 15:
				if(cinta[posicion] == '1') {
					state = 16;
					cinta[posicion] = ' ';
					posicion--;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 16:
				if(cinta[posicion] == '2') {
					state = 17;
					cinta[posicion] = ' ';
					posicion--;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 17:
				if(cinta[posicion] == '2') {
					state = 17;
					cinta[posicion] = '2';
					posicion--;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == '1') {
					state = 17;
					cinta[posicion] = '1';
					posicion--;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == '3') {
					state = 17;
					cinta[posicion] = '3';
					posicion--;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'e') {
					state = 17;
					cinta[posicion] = 'e';
					posicion--;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'i') {
					state = 17;
					cinta[posicion] = 'i';
					posicion--;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'd') {
					state = 17;
					cinta[posicion] = 'd';
					posicion--;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'x') {
					state = 17;
					cinta[posicion] = 'x';
					posicion--;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == ' ') {
					state = 18;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 18: 
				if(cinta[posicion] == '2') {
					state = 3;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == 'x') {
					state = 19;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 19:
				if(cinta[posicion] == 'x') {
					state = 19;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else if(cinta[posicion] == '2') {
					state = 20;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 20:
				if(cinta[posicion] == '1') {
					state = 21;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 21:
				if(cinta[posicion] == '3') {
					state = 22;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 22:
				if(cinta[posicion] == '2') {
					state = 23;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 23:
				if(cinta[posicion] == '1') {
					state = 24;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 24:
				if(cinta[posicion] == '3') {
					state = 25;
					cinta[posicion] = ' ';
					posicion++;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 25:
				if(cinta[posicion] == ' ') {
					state = 99;
					cinta[posicion] = ' ';
					posicion = posicion;
					impresion(cinta, posicion);
				} else {
					state = 100;
				}
				break;
			case 99:				
				break;
			case 100:
				printf("\n\n No es el estado final");
				/*
				for(j = 0; j < strlen(cinta); j++) {
					cinta[j] = ' ';
				}
				*/
				return 0;
				break;
		}
	}
	
	if(state == 99 && isEmpty(cinta)) {
		return 1;
	} else {
		printf("\n\n No es el estado final");
		return 0;
	}
}

void in(char string[MAX]) {
	fflush(stdin);
	gets(string);
	return;
}

int valInt(char aux[MAX]) {
	int i, n, lon, flag=1;
	lon=strlen(aux);
	for(i=0;i<lon;i++)
	{
		if(isdigit(aux[i]))
			flag=1;
		else
			flag=0;
		if(flag==0)
			break;
	}
	if (lon==0)
		flag=0;
	if(flag==1)
		n=atoi(aux);
	else if(flag==0)
		n=-1;
	return n;
}

void pause() {
	printf("\n\n Presiones una tecla para continuar: ");
	getch();
	fflush(stdin);
}

void cursor(int posicion) {
	int i;
	printf("\n ");
	for(i = 0; i < posicion; i++) {
		printf(" ");
	}
	printf("-");
}

void impresion(char cinta[MAX], int posicion) {
	printf("\n %s", cinta);
	cursor(posicion);
}

int isEmpty(char cinta[MAX]) {
	int i, empty;
	empty = 1;
	for(i = 0; i < strlen(cinta); i++) {
		if(cinta[i] != ' ') {
			empty = 0;
			break;
		}
	}
	return empty;
}
