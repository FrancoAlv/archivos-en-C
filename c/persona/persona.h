#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define Masculino "Masculino"
typedef struct 
{
char nombre[30];
int edad;	
int dni;
char sexo;
float peso;
float altura;		
}persona;
int calcularIMC(int peso,int altura){
	int calculo=peso/(altura*altura);
	if(calculo<20){
		return -1;
	}else if(calculo>=20 && calculo<=25){
		return 0;
	}else{
		return 1;
	}
	
}

bool esMayorDeEdad(int edad){
	if(edad>17){
		return true;
	}
	return false;
}

void comprobarSexo(char *sexo){
	switch (*sexo){
		case 'M':
		case 'm':
		case 'h':
		case 'H':
		printf("\n Su sexo es Masculino");
		
		
		break;
		case 'F':
		case 'f':
		printf("\n Su sexo es Femenino");
		
		
		break;
		default:
		printf("\n Su sexo es Masculino");
		
		
		break;
		
	}
	
}


