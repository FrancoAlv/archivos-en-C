#include<stdio.h>


int main(){
	int numero;
	int *p_numero=&numero;
	bool primo=false;
	printf("Cual es su numero \n");
	scanf("%i",&numero);
	for(int i=*p_numero-1;i>1;i--){
		if(*p_numero%i==0){
			primo=true;
		}
	}
	if(primo){
	printf("su numero no es primo %i\n",*p_numero);
	printf("su su posiscion en memoria es %p\n",p_numero);
	}else{
	printf("su numero  es primo %i\n",*p_numero);	
	printf("su su posiscion en memoria es %p\n",p_numero);
	}
	return 0;
}
