#include <stdio.h>
#include <stdlib.h>
#define TOPE 10
int main()
{
	double *p_array;
	int i;
	p_array=(double*) malloc(TOPE*sizeof(double));
	srand(time(NULL));
	for ( i = 0; i <TOPE ; i++)
	{
		*p_array=rand();
		printf("la posicion es %p \n",p_array);
		printf("la posicion es %lf \n",*p_array);
		p_array++;
		
	}
	printf("hola\n");
	for ( i = 0; i <TOPE ; i++)
	{
		p_array--;	
	}

	for ( i = 0; i <TOPE ; i++)
	{
		
		printf("la posicion es %p \n",p_array);
		printf("la posicion es %lf \n",*p_array);
		p_array++;
		
	}
	free(p_array);
	
		for ( i = 0; i <TOPE ; i++)
	{
		
		printf("la posicion es %p \n",p_array);
		printf("la posicion es %lf \n",*p_array);
		p_array++;
		
	}
	
	
	return 0;
}