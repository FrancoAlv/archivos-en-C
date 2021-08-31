#include <stdio.h>
#include <stdlib.h>
int obtenertamanio();
void llenarvector(int tamanio,int *vector);
void mostrar(int tamanio,int *vector);
int main(int argc, char const *argv[])
{
    	
  	int tamanio;
  	tamanio=obtenertamanio();
  	int *vector=(int*)malloc(tamanio*sizeof(int));
  	llenarvector(tamanio,vector);
  	mostrar(tamanio,vector);
	free(vector);
	return 0;
}
int obtenertamanio(){
	int numero;
	printf("Cuantos dimesion va tener el arreglo\n");
	scanf("%i",&numero);
	return numero;
}

void llenarvector(int tamanio,int *vector){
	int numero;
for (int i = 0; i <tamanio ; ++i)
		{
			
	printf("%i).Cual es su numero\n",(i+1));		
scanf("%i",&numero);
*(vector+i)=numero;		
		}		
	
	
}

void mostrar(int tamanio,int *vector){
	for (int i = 0; i < tamanio; ++i)
	{
		printf("EL numero es %i\n",*(vector+i));
        printf("La posicion es %p\n",(vector+i));   	
	}
}