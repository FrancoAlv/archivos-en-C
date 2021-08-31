	#include <stdio.h>
#include <windows.h>
	#include <time.h>
	#include <stdlib.h>
	#define v 21
	#define h 75
	#define n 100


	typedef struct 
	{
	int x;
	int y;
	char imagen;
	int modx;
	int mody;		
	}snak;
	typedef struct 
	{
	int x;
	int y;		
	}fruct;

	snak snake[n];
	fruct fructa;
	void inicio(int *tam,char campo[v][h]);
	void borde(char campo[v][h]);
	void pintar(char campo[v][h]);
	void intro_datos(char campo[v][h],int tam);
	void gameloop(char campo[v][h],int tam);
	void imput(char campo[v][h],int *tam,int *muerto);
	void update(char campo[v][h],int tam);
	void introdatos2(char campo[v][h],int tam);
	int main()
	{
		
	int tam;
	char campo[v][h];
	inicio(&tam,campo);	
	gameloop(campo,tam);
	system("pause");
		
		return 0;
	}

	void inicio(int *tam,char campo[v][h]){
		int i;
		snake[0].x=32;
		snake[0].y=10;
		 
		 *tam=4;
		
		srand(time(NULL));
		do{
		fructa.x=rand()%(h-1);
		}while(fructa.x==0);
		do{
		fructa.y=rand()%(v-1);
	}while(fructa.y==0);
	for ( i = 0; i <*tam ; i++)
	{
		snake[i].modx=1;
		snake[i].mody=0;
		
	}
	borde(campo);
	intro_datos(campo,*tam);


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
	void borde(char campo[v][h]){
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
	void intro_datos(char campo[v][h],int tam){
	int i;
	for ( i = 1; i < tam; i++)
	{
	snake[i].x=snake[i-1].x-1;
	snake[i].y=snake[i-1].y;
	snake[i].imagen='X';	
	}
	snake[0].imagen='O';
	for ( i = 0; i < tam; i++)
	{
		campo[snake[i].y][snake[i].x]=snake[i].imagen;
	}
	campo[fructa.y][fructa.x]='%';
	}
	void gameloop(char campo[v][h],int tam){
		int muerto=0;
		do{
			pintar(campo);
			imput(campo,&tam,&muerto);
			update(campo,tam);
			Sleep(50);
		}while(muerto==0);
	}

	void imput(char campo[v][h],int *tam,int *muerto){
	int i;
	char key;
	if(snake[0].x==0 || snake[0].x==h-1||snake[0].y==v-1||snake[0].y==0){
		*muerto=1;
	}	
		
		for ( i = 1; i < *tam && *muerto==0; i++)
			{
				if (snake[0].x==snake[i].x && snake[0].y==snake[i].y){
					*muerto=1;
					
				}
			}
			
		if(snake[0].x==fructa.x&&snake[0].y==fructa.y){
			*tam+=1;
			snake[*tam-1].imagen='X';
			do{
			fructa.x=rand()%(h-1);
			}while(fructa.x==0);
			do{
			fructa.y=rand()%(v-1);
		    }while(fructa.y==0);
			
		}	
			if (*muerto==0){
				if(kbhit()==1){
					key=getch();
					if(key=='2'&&snake[0].mody!=-1){
						snake[0].modx=0;
						snake[0].mody=1;
					}
					if(key=='8'&&snake[0].mody!=1){
							snake[0].modx=0;
						snake[0].mody=-1;
					}
					if(key=='4'&&snake[0].modx!=1){
							snake[0].modx=-1;
						snake[0].mody=0;	
					}
					if(key=='6'&&snake[0].modx!=-1){
								snake[0].modx=1;
						snake[0].mody=0;
						
					}
				}
			}
			
		}
		
		
	void update(char campo[v][h],int tam){
	borde(campo);
	introdatos2(campo,tam);	
	}
	void introdatos2(char campo[v][h],int tam){
	int i;
	for(i=tam-1;i>0;i--){
	snake[i].x=	snake[i-1].x;
		snake[i].y=snake[i-1].y;
	}	
	snake[0].x+=snake[0].modx;	
		snake[0].y+=snake[0].mody;
		for ( i = 0; i < tam; i++)
	{
		campo[snake[i].y][snake[i].x]=snake[i].imagen;
	}
	
		campo[fructa.y][fructa.x]='%';	
		
	}