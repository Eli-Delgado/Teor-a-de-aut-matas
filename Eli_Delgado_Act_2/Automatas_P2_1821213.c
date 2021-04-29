#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

void bienvenida();
void in(char string[MAX]);
int isUpper(char upper);
int isDigit(char digit);
int valCadena(char string[MAX]);
int valInt(char aux[MAX]);
void pause();

int main() {
	int opcion;
	char aux[MAX], string[MAX];
	bienvenida();
	do {
		printf("\n\n\t Teoria de Automatas");
		printf("\n\n Matricula: 1821213");
		printf("\n Nombre: Eli Israel Delgado Escarcega");
		printf("\n\n L = {i (w)^n j (wI)^2n}");
		printf("\n i = 1821213");
		printf("\n w = EIDE");
		printf("\n j = DELGADO");
		printf("\n wI = EDIE");
		printf("\n\n\n Ingrese una cadena: ");
		in(string);
		printf("\n Caracter         %cV%clido?\n", 168, 160);
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
	int i, n, lenght, state = 1;
	char matricula[7] = {'1', '8', '2', '1', '2', '1', '3'}, iniciales[4] = {'E', 'I', 'D', 'E'}, 
	apellido[7] = {'D', 'E', 'L', 'G', 'A', 'D', 'O'}, inicialesInversa[4] = {'E', 'D', 'I', 'E'};	
	lenght = strlen(string);
	char valido[] = "               SI", noValido[] = "               NO";
	//printf("\n Analizando la cadena ");
	n = 0;
	for(i = 0; i < lenght; i++) {
		printf("   ");
		switch(state) {
			case 1:
				if(string[i] == matricula[i]) {
					printf(" %c %s\n", string[i], valido);
					state = 1;
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				if(i == 6) {
					state = 2;
				}
				break;
			case 2:
				if(string[i] == iniciales[(i - 7) % 4]) {
					printf(" %c %s\n", string[i], valido);
					state = 2;
					n++;
				} else if(n > 0 && n%4 == 0 && string[i] == apellido[0]) {
					printf("\b\b\b");
					i--;
					state = 3;
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				break;
			case 3:
				if(string[i] == apellido[(i - 7 - n) % 7]) {
					printf(" %c %s\n", string[i], valido);
					state = 3;
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				if((i - 7 - n) == 6) {
					state = 4;
				}
				break;
			case 4:
				//printf("\n true");
				if(string[i] == inicialesInversa[(i - 7 - n -7) % 4] && i < (3*n + 14)) {
					printf(" %c %s\n", string[i], valido);
					state = 4;
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				break;
			case 8:
				printf("\n\n No es el estado final");
				return 0;
				break;
		}
	}
	
	if(state == 4 && i == (3 * n +14)) {
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

int isUpper(char upper) {
	int i;
	char uppers[27] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 165, 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	for(i = 0; i < 27; i++) {
		if(upper == uppers[i]) {
			return 1;
		}
	}
	return 0;
}

int isDigit(char digit) {
	int i;
	char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for(i = 0; i < 10; i++) {
		if(digit == digits[i]) {
			return 1;
		}
	}
	return 0;
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
