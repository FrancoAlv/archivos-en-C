#include <stdio.h>
void funcion(int numero,int *contador){
	
	if(numero==1){
		*contador+=1;
		printf("EL contador es %i\n",*contador);
		printf("EL numero es %i\n",numero);
		*contador=0;
	}else if(numero%2==0){
		numero=(numero)/2;
		contador+=1;
		printf("EL numero es par %i\n",numero);
		funcion(numero,contador);
	}else{
		numero=3*(numero)+1;
		contador+=1;
		printf("EL numero es %i\n",numero);
		funcion(numero,contador);
	}
}


int main(int argc, char const *argv[])
{
	int apuntador,contador=0;
	printf("Cual es su numero\n");
	scanf("%i",&apuntador);
	funcion(&apuntador,&contador);
	printf("El contador es %i\n",contador);

	while(apuntador>=0){
		apuntador-=1;
		printf("numero %i\n",apuntador);
		funcion(&apuntador,&contador);
		printf("El contador es %i\n",contador);
	}
	
	return 0;
}
