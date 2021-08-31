#include <stdio.h>
#define v 35
#define h 100
void pintar(char campo[v][h]);
void bordes(char campo[v][h]);
void comienzo(char campo[v][h]);
void pintar(char campo[v][h]);
void gameloop(char campo[v][h]);
int main()
{
 
 int pos[50];
 char campo[v][h];
 
 comienzo(campo);	
gameloop(campo);	
	
	
	return 0;
}

void bordes(char campo[v][h]){

	int i,j;
for ( i = 0; i < v; i++){
	for (j = 0; j < h; j++){
		if(i==0 || i==v-1){
			campo[i][j]='-';
		}else if(j==0 ||j==h-1){
			campo[i][j]='|';
		}else {
			campo[i][j]=' ';
		}
	}
}
	
}
void pintar(char campo[v][h]){
	system("cls");
	
	int i,j;
	for ( i = 0; i < v; i++){
	for (j = 0; j < h; j++){
		printf("%c",campo[i][j]);
	}
	printf("\n");
}
}

void gameloop(char campo[v][h]){
	
	
	do{
	pintar(campo);
	
	sleep(50);
	}while(1==1);
	
}

void comienzo(char campo[v][h]){
	bordes(campo);
	
	pintar(campo);
}
void nombre(char campo[v][h]){
	
	
	
}