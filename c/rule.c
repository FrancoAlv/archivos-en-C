#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int comprobarcantida(int cantidad);
typedef struct revolver{
int posicion_actual; 
int posicion_bala;
bool disparar(){
if(posicion_actual==posicion_bala){
return true;	
}

return false;	
}	
void siguientebala(){
	if(posicion_actual==6){
		posicion_actual=1;
	}else{
		posicion_actual++;
	}
}	
}pistola;

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
	
}personas;

typedef struct juego{

int cantida;
persona personas[6];
revolver r;
int i;
bool fin_de_juego(){
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

int main(){
 srand(time(NULL));	
int numero;
juego juego;
int i;
char nombre[20];
printf("Cuantos usuarios van a hacer\n");
scanf("%i",&numero);
numero =comprobarcantida(numero);
juego.cantida=numero;
do{
	juego.r.posicion_actual=rand()%7;
}while(juego.r.posicion_actual>6 || juego.r.posicion_actual<1);
do{
	juego.r.posicion_bala=rand()%7;
}while(juego.r.posicion_bala>6 ||juego.r.posicion_bala<1 );
for(i=0;i<numero;i++){
printf("Su nombre es ");
fflush(stdin);
scanf("%s",nombre);
fflush(stdin);
strcpy(juego.personas[i].nombre,nombre);
juego.personas[i].id=i;
}

while(!juego.fin_de_juego()){
//printf("\nposicion actual %i y %i ",juego.r.posicion_actual,juego.r.posicion_bala);
	juego.ronda();
	
	fflush(stdin);
}	
printf("\nTermino el juego\n");
system("pause");	
	return 0;
}
int comprobarcantida(int cantidad){
	if(cantidad>6 || cantidad<1){
		cantidad=2;
	}
	return cantidad;
}

