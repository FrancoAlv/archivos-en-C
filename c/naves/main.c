#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define v 28
#define h 90

typedef struct 
{
unsigned char x;
unsigned char y;
unsigned char mody;	
char imagen;
unsigned char disposicion;	
}bala;
typedef struct 
{
unsigned char x;
unsigned char y;
unsigned char modx;
unsigned char mody;
bala balas[1000];
char imagen;
}nave;

typedef struct 
{
	int x;
	int y;
	int mody;
	char imagen;
}meteotoro;

char campo[v][h];
nave naves[4];
meteotoro met[100];
int meteoros=100;
int n_bala=0;

void borde(char campo[v][h]);
void pintar(char campo[v][h]);
void ponernave(char campo[v][h]);
void inicializar();
void gameloop();
void imput(int *muerto);
void draw(int *muerto);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	
	borde(campo);
	ponernave(campo);
	inicializar();
	//pintar(campo);
	gameloop();
	
	return 0;
}

void ponernave(char campo[v][h]){
	int i;
	naves[0].x=35;
	naves[0].y=17;
	naves[0].imagen='|';
	for(i=1;i<4;i++){
		naves[i].y=naves[0].y+1;
		if(i==1){
			naves[i].x=naves[0].x-1;
			naves[1].imagen='<';
		}else if(i==2){
			naves[i].x=naves[0].x;
			naves[2].imagen='-';
		}else if(i==3){
			naves[i].x=naves[0].x+1;
				naves[3].imagen='>';
		}
	}
	for(i=0;i<4;i++){
		campo[naves[i].y][naves[i].x]=naves[i].imagen;
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
	
void pintar(char campo[v][h]){
	   
		int i,j;
		for ( i = 0; i < v; i++){
		for (j = 0; j < h; j++){
			printf("%c",campo[i][j]);
		}
		printf("\n");
	}
	}
	
void inicializar(){
int i;
for ( i = 0; i <4 ; i++){	
	naves[i].modx=0	;
	naves[i].mody=0;	
	}	
for(i=0;i<meteoros;i++){
do{
	met[i].x=rand()%76;
}while(met[i].x==0);
do{
	met[i].y=rand()%5;
}while(met[i].y==0);
met[i].mody=1;
met[i].imagen='*';

}	
for(i=0;i<meteoros;i++){
	campo[met[i].y][met[i].x]=met[i].imagen;
}	
}	
void gameloop(){
	int muerto=0;
	
	do{
		system("cls");
		//clrscr();
		pintar(campo);
		imput(&muerto);
		draw(&muerto);
		Sleep(50);
	}while(muerto==0);
	
	
}
void imput(int *muerto){
	char key;
	int i;
	int j;
	int k;
	//si una nave choca
	
	if(naves[1].x== 0 || naves[3].x ==h-1 || naves[0].y==0 || naves[1].y==v-1  ){
	*muerto+=1;
	}
	//si choca con meteoros
	for(i=0;i<meteoros;i++){
	for(j=0;j<4;j++){	
	if(naves[j].y==met[i].y && naves[j].x==met[i].x ){
		*muerto+=1;
	}
    }
    }
    if(n_bala==500){
    	n_bala=0;
    }
    
    if(n_bala>0){
    	
    for(k=0;k<4;k++){
    if(k!=2){
    for(i=0;i<n_bala;i++){
   for(j=0;j<meteoros;j++){
   	 if(naves[k].balas[i].disposicion==1){
   	 	 if(naves[k].balas[i].y==0){
   	naves[k].balas[i].disposicion=0;
   }
   if(naves[k].balas[i].y== met[j].y && naves[k].balas[i].x== met[j].x){
   naves[k].balas[i].disposicion=0;
   	do{
	met[j].x=rand()%74;
    }while(met[j].x==0);
    do{
	met[j].y=rand()%5;
    }while(met[j].y==0);
   }
   	 }
  
   
   }
}	
    }	
    	
    }	
   
}
    //si los meteoros no les cae balas
    for(i=0;i<meteoros;i++){
	if(met[i].y==v-1){
	do{
	met[i].x=rand()%74;
    }while(met[i].x==0);
    do{
	met[i].y=rand()%5;
	
    }while(met[i].y==0);
	}
    }
    //moviento a la nave
    if(*muerto==0){
    	if(kbhit()==1){
    		key=getch();
    		if(key=='2'){
    			naves[0].mody=1;
    			naves[0].modx=0;
    			naves[0].x+=naves[0].modx;
    			naves[0].y+=naves[0].mody;
    		}
    		if(key=='8'){
    			naves[0].mody=-1;
    			naves[0].modx=0;
    			naves[0].x+=naves[0].modx;
    			naves[0].y+=naves[0].mody;
    		}	
    		if(key=='4'){
    			naves[0].mody=0;
    			naves[0].modx=-1;
    			naves[0].x+=naves[0].modx;
    			naves[0].y+=naves[0].mody;
    		}
    		if(key=='6'){
    			naves[0].mody=0;
    			naves[0].modx=1;
    			naves[0].x+=naves[0].modx;
    			naves[0].y+=naves[0].mody;
    		}
    		if(key=='5'){
    			
    		}
    		
    	}
  for(i=0;i<4;i++){
    			if(i!=2){
    			naves[i].balas[n_bala].x=naves[i].x;
    			naves[i].balas[n_bala].y=naves[i].y-1;
    			naves[i].balas[n_bala].imagen='w';
    			naves[i].balas[n_bala].mody=-1;
    			naves[i].balas[n_bala].disposicion=1;
    			}}
    			n_bala+=1;
   		
    }
     if(n_bala>0){
     	for(j=0;j<4;j++){
    			if(j!=2){
     	for(i=0;i<n_bala;i++){	
     if(naves[j].balas[i].disposicion==1){
     	naves[j].balas[i].y+=naves[j].balas[i].mody;
     }		
   }
}
}
}
	//moviento de meteoro
	for(i=0;i<meteoros;i++){
	met[i].y+=met[i].mody;
	}
   }
	

void draw(int *muerto){
	int i;
	int j;
	
	borde(campo);
	for(i=0;i<meteoros;i++){
	campo[met[i].y][met[i].x]=met[i].imagen;
    }
    for(i=1;i<4;i++){
		naves[i].y=naves[0].y+1;
		if(i==1){
			naves[i].x=naves[0].x-1;
			naves[1].imagen='<';
		}else if(i==2){
			naves[i].x=naves[0].x;
			naves[2].imagen='-';
		}else if(i==3){
			naves[i].x=naves[0].x+1;
				naves[3].imagen='>';
		}
	}
	for(i=0;i<4;i++){
		campo[naves[i].y][naves[i].x]=naves[i].imagen;
	}
	if(n_bala>0){	
	for(j=0;j<4;j++){
    if(j!=2){				
	for(i=0;i<n_bala;i++){
	if(naves[j].balas[i].disposicion==1){	
	campo[naves[j].balas[i].y][naves[j].balas[i].x]=naves[j].balas[i].imagen;
	}
    }
    }
    }
}
}

