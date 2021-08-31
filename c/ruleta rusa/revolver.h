#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef struct {
int posicion_actual;
int posicion_bala;	
srand(time(NULL));
	
}revolver;

int ponerbalaactual(int posicion_actual){	

do{	
 posicion_actual=rand()%7; 
}while(posicion_actual>6 || posicion_actual<1);
return posicion_actual;
}

int ponerbala(int posicion_bala){
srand(time(NULL));
do
{
 posicion_bala=rand()%7;
}
while(posicion_bala>6 || posicion_bala<1);
return posicion_bala;	
}
void siguientebala(int posicion_actual){
	if(posicion_actual==6){
		posicion_actual=1;
	}else{
		posicion_actual++;
	}
}

bool disparar(int posicion_actual,int posicion_bala) {
if(posicion_actual==posicion_bala){
return true;	
}

siguientebala(posicion_actual);
return false;
}