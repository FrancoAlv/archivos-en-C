#include<stdio.h>


long fibonacci(int n);
int main(){

int a=0;
long b;
printf("caul es  numero\n");
scanf("%i",&a);
//printf("%i",a);
b=fibonacci(a);
printf("su numero es: %li,",b);
 return 0;	
}






long fibonacci(int n)
{
    if (n>1){
       return fibonacci(n-1) + fibonacci(n-2);  //función recursiva
    }
    else if (n==1) {  // caso base
        return 1;
    }
    else if (n==0){  // caso base
        return 0;
    }
    else{ //error
      printf("Debes ingresar un tamaño mayor o igual a 1");
        return -1; 
    }
}
