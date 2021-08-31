#include<stdio.h>

void sumar();
void menu();
void restar();
void dividir();
void multiplicar();
int main(){
	
menu();	
			
return 0;	
}

void menu(){
int a;	
	do{
	
	printf("\n1.Sumar\n");
	printf("2.Restar\n");
	printf("3.Multiplicar\n");
	printf("4.Dividir\n");
	printf("5.Salir\n");
	scanf("%i",&a);
	switch(a){
	case 1:
	sumar();	
	break;
	case 2:
	restar()	;
	break;
	case 3:
	multiplicar()	;
	break;
	case 4:
	dividir();	
	break;
	case 5:
		printf("Adios");
		break;
	default:
		printf("se equivoco");
	break;	
		

	}
	}while(a!=5);
}

void sumar(){
int resultado,a,b;	
	
	printf("Cual es el primer numero ");
	scanf("%i",&a);
	printf("Cual es el segundo numero ");
	scanf("%i",&b);
	resultado=a+b;
		printf("%i",resultado);
	
}
void restar(){
int resultado,a,b;	
	printf("Cual es el primer numero ");
	scanf("%i",&a);
	printf("Cual es el segundo numero ");
	scanf("%i",&b);
	resultado=a-b;
		printf("%i",resultado);
		
}
void multiplicar(){
	int resultado,a,b;
	printf("Cual es el primer numero ");
	scanf("%i",&a);
	printf("Cual es el segundo numero ");
	scanf("%i",&b);
	resultado=a*b;
		printf("%i",resultado);
}
void dividir(){
int resultado,a,b;
	printf("Cual es el primer numero ");
	scanf("%i",&a);
	printf("Cual es el segundo numero ");
	scanf("%i",&b);
	if(b==0){
		printf("no existe esa division ");
	}
	else{
		resultado=a/b;
		printf("%i",resultado);
	}
	
	
	
}
