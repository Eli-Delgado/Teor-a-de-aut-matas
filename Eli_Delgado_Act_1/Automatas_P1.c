#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <locale.h>

#define MAX 100

void bienvenida();
void in(char string[MAX]);
int isLower(char lower);
int isDigit(char digit);
int valCadena(char string[MAX]);
int valInt(char aux[MAX]);
void pause();

int main() {
	//setlocale(LC_ALL, "spanish");
	//setlocale(LC_ALL, "es_ES");
	//setlocale(LC_ALL, "spanish");
	//setlocale(LC_ALL, "");
	int opcion;
	char aux[MAX], string[MAX];
	bienvenida();
	do {
		printf("\n\n\t Teoria de Automatas");
		printf("\n\n Matricula: 1821213");
		printf("\n Nombre: Eli Israel Delgado Escarcega");
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

void bienvenida()
{
	printf("\n\n\n\n");
	printf("\n\n\t\t\t    BIENVENIDO \n\n\n\t\t");
	printf(" PRESIONE UNA TECLA PARA INICIAR: ");
	getch();
	system("cls");
}

int valCadena(char string[MAX]) {
	int i, lenght, state = 1;
	char matricula[8] = {'1', '8', '2', '1', '2', '1', '3'}, iniciales[4] = {'e', 'i', 'd', 'e'};	
	lenght = strlen(string);
	char valido[] = "               SI", noValido[] = "               NO";
	//printf("\n Analizando la cadena ");
	for(i = 0; i < lenght; i++) {
		printf("   ");
		switch(state) {
			case 1:
				if(string[i] == matricula [i] && isDigit(string[i]) && !isLower(string[i]) && string[i] != '.') {
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
				if ((isLower(string[i]) || isDigit(string[i])) && string[i] != 'e'){
					printf(" %c %s\n", string[i], valido);
					state = 2;				
				} else if (string[i] == 'e') {
					printf(" %c %s\n", string[i], valido);
					state = 3;
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				break;
			case 3:
				if ((isLower(string[i]) || isDigit(string[i])) && string[i] != 'i'){
					printf(" %c %s\n", string[i], valido);
					state = 2;				
				} else if (string[i] == 'i') {
					printf(" %c %s\n", string[i], valido);
					state = 4;	
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				break;
			case 4:
				if ((isLower(string[i]) || isDigit(string[i])) && string[i] != 'd'){
					printf(" %c %s\n", string[i], valido);
					state = 2;				
				} else if (string[i] == 'd') {
					printf(" %c %s\n", string[i], valido);
					state = 5;	
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				break;
			case 5:
				if ((isLower(string[i]) || isDigit(string[i])) && string[i] != 'e'){
					printf(" %c %s\n", string[i], valido);
					state = 2;				
				} else if (string[i] == 'e') {
					printf(" %c %s\n", string[i], valido);
					state = 6;	
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				break;
			case 6:
				if ((isLower(string[i]) || isDigit(string[i]))){
					printf(" %c %s\n", string[i], valido);
					state = 6;				
				} else if (string[i] == '.') {
					printf(" %c %s\n", string[i], valido);
					state = 7;	
				} else {
					printf(" %c %s\n", string[i], noValido);
					state = 8;
				}
				break;
			case 7:
				printf(" %c %s\n", string[i], noValido);
				state = 8;
				break;
			case 8:
				printf("\n\n No es el estado final");
				return 0;
				break;
		}
	}
	
	if(state == 7) {
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

int isLower(char lower) {
	int i;
	char lowers[27] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 164, 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	for(i = 0; i < 27; i++) {
		if(lower == lowers[i]) {
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
