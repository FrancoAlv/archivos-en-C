#include <stdio.h>
#include "persona.h"
#include<time.h>

int main()
{
srand(time(NULL));
	persona persona1;
	printf("Cual es su nombre \n");
	gets(persona1.nombre);
	printf("\nCual es su edad\n");
	scanf("%i",&persona1.edad);
    printf("\nCual es su sexo\n");
    fflush(stdin);
    scanf("%c",&persona1.sexo);
    printf("\nCual es su peso\n");
    scanf("%f",&persona1.peso);
    printf("\nCual es su altura\n");
    scanf("%f",&persona1.altura);
	if(calcularIMC(persona1.peso,persona1.altura)==-1){
		printf("\nUsted esta en el peso ideal\n");
	}else if(calcularIMC(persona1.peso,persona1.altura)==0){
		printf("\nUsted esta por debajo del ideal\n");
	}else if(calcularIMC(persona1.peso,persona1.altura)==1){
		printf("\nUsted esta con sobrepeso \n");
	}
	do{
		persona1.dni=rand()&1000000;
	}while(persona1.dni>10000000 && persona1.dni<100000000);
	if(esMayorDeEdad(persona1.edad)){
		printf("\nUsted es Mayor De Edad" );
	}else{
		printf("\nUsted es Menor De Edad" );
	}
	printf("\nSu nombre es  %s",persona1.nombre);
	printf("\nSu edad es %i " ,persona1.edad);
	printf("\nSu dni es %i ",persona1.dni);
	comprobarSexo(&persona1.sexo);
	printf("\n");
system("pause");
	return 0;
}