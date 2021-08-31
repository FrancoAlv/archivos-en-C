#include <stdio.h>
#include "revolver.h"
#include "persona.h"
#include "juego.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
int numero;
int i;
printf("Cuantas personas van a jugar");
scanf("%i",&numero);		
persona persona[numero];
for(i=0;i<numero;i++){
	
}
	
	
	
	return 0;
}

int numero(int numero){
	if(numero>6 || numero<1){
		numero=2;
	}
	
}
