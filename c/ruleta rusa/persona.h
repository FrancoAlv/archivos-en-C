#include"revolver.h"
#include <stdbool.h>
#include <stdio.h>
typedef struct persona{
	
char nombre[20];
bool vivo=true;
int id;
 
void disparar(revolver r){
printf("\nCoje el arma se apunta y dispara...");
if(r.disparar()){
	
	printf("\nEL usuario a muerto lo siento %s",nombre);
	vivo=false;
}else{
	printf("\nEL usuario sigue vivo %s ",nombre);
	
}	
} 	
	
};