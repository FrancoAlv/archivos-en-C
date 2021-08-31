#include<stdio.h>

int main(){
	int numero[10];
	int *p_numero;
	
	for(int i=0;i<10;i++){	
	fflush(stdin);
	printf("%i)Su numero es \n",(i+1));
	scanf("%i",&numero[i]);	
	}
	p_numero=numero;
    for(int i=0;i<10;i++){	
	printf("%i)Su numero es %i\n",(i+1),*p_numero);
	printf("Su espacion en memoria es: %p \n",p_numero);
	p_numero++;	
	}
	
	return 0;
}
