#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *numero=(int*) malloc(sizeof(int));
	printf("%p\n",numero);
	printf("%d\n",*numero);	
	
	
	return 0;
}