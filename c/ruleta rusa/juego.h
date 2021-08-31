#include"persona.h"
#include <stdbool.h>
#include <stdio.h>
#include"revolver.h"
bool fin_de_juego();
typedef struct juego{

int cantida;
 
 
  	
 struct revolver r;
int i;
bool fin_de_juego()
{
	for(i=0;i<cantida;i++){
	if(!personas[i].vivo){
		printf("\nSe convertio en misterio el pobre %s ",personas[i].nombre);
		return true;
		
	}			
	}
	return false;
}
void ronda(){
	for(i=0;i<cantida;i++){
		personas[i].disparar(r);
		r.siguientebala();
		
	}
}	
};