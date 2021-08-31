#include<stdio.h>

int main(){

unsigned long long a;
 int i=1;
 
while (i <= 25) {
    a = a * i;
    i = i + 1;
}
printf("Su numero es %lld",a);

	return 0;
}
