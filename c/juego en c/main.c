#include <stdio.h>
#include <windows.h>
#include <time.h>
#define v 21 
#define h 75
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void ClearScreen()
{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
}

#else // !_WIN32
#include <unistd.h>
#include <term.h>

void ClearScreen()
{
  if (!cur_term)
  {
     int result;
     setupterm( NULL, STDOUT_FILENO, &result );
     if (result <= 0) return;
  }

   putp( tigetstr( "clear" ) );
}
#endif
void inicio(char campo[v][h],int pelX,int pelY,int inijuga,int finjuga,int iniia,int finia);
void borde(char campo[v][h]);
void pintar(char campo[v][h]);
void raquejuga(char campo[v][h],int inijuga,int finjuga);
void raqueia(char campo[v][h],int iniia,int finia);
void pelota(char campo[v][h],int pelX,int pelY);
void gameloop(char campo[v][h],int pelX,int pelY,int inijuga,int finjuga,int iniia,int finia,int modX,int modY,int modIA);
void imput(char campo[v][h],int *pelX,int *pelY,int *inijuga,int *finjuga,int *iniia,int *finia,int *modX,int *modY,int *modIA,int *goll,int *control);
void udpate(char campo[v][h],int pelX,int pelY,int inijuga,int finjuga,int iniia,int finia);

int main(){
	srand(time(NULL));
	//posicion
	int pelX,pelY ,inijuga,finjuga,iniia,finia;
	char campo[v][h];
	//modificacion
	int modX,modY,modIA;
	//inicializo posicion
	do{
	pelX =rand()%76;
    }while(pelX<20 || pelX>60);
	pelY=10;
	inijuga=8;
	finjuga=12;
	do{
    iniia=rand()%22;
    }while(iniia<2 || iniia>15);
	finia=iniia+4;
	//inicializo la modificacion 
	modX=-1;
	modY=-1;
	modIA=-1;
	inicio(campo,pelX,pelY,inijuga,finjuga,iniia,finia);
	gameloop(campo,pelX,pelY,inijuga,finjuga,iniia,finia,modX,modY,modIA);
	system("pause");
	return 0;
}

void inicio(char campo[v][h],int pelX,int pelY,int inijuga,int finjuga,int iniia,int finia){
borde(campo);	
raquejuga(campo,inijuga,finjuga);
raqueia(campo,iniia,finia);
pelota(campo,pelX,pelY);	
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
	//system("cls");
    ClearScreen();
	int i,j;
	for ( i = 0; i < v; i++){
	for (j = 0; j < h; j++){
		printf("%c",campo[i][j]);
	}
	printf("\n");
}
}
void raquejuga(char campo[v][h],int inijuga,int finjuga){
	int i,j;
	for(i=inijuga;i<=finjuga;i++){
		for(j=2;j<=3;j++){
			campo[i][j]='X';
		}
	}
	
}
void raqueia(char campo[v][h],int iniia,int finia){
	int i,j;
	for(i=iniia;i<=finia;i++){
		for(j=h-4;j<=h-3;j++){
			campo[i][j]='X';
		}
	}
	
}

void pelota(char campo[v][h],int pelX,int pelY){
campo[pelY][pelX]='O';	
}

void gameloop(char campo[v][h],int pelX,int pelY,int inijuga,int finjuga,int iniia,int finia,int modX,int modY,int modIA){
	int goll=0;
	int control=0;
	do{
		pintar(campo);
		imput(campo,&pelX,&pelY,&inijuga,&finjuga,&iniia,&finia,&modX,&modY,&modIA,&goll,&control);
		udpate(campo,pelX,pelY,inijuga,finjuga,iniia,finia);
		Sleep(100);
	}while(goll==0);
}
void imput(char campo[v][h],int *pelX,int *pelY,int *inijuga,int *finjuga,int *iniia,int *finia,int *modX,int *modY,int *modIA,int *goll,int *control){
	int i;
	char key ;
	if(*pelX >50){
	 if (*pelY != (*iniia+*finia)/2 && *control ==9){
	 	*modIA *=-1;
	 	*control=0;
	 }
	 *control+=1;
	}
	if(*pelY==1 || *pelY==v-2){
		*modY*=-1;
	}
	if(*pelX==1 || *pelX==h-2){
		*goll=1;
	}
	if(*pelX==4){
		for(i=(*inijuga);i<=(*finjuga);i++){
			if(i== (*pelY)){
				*modX *=-1;
			}
		}
	}
	if(*pelX==h-5){
		for(i=(*iniia);i<=(*finia);i++){
			if(i== (*pelY)){
			*modX *=-1;
			}
		}
	}
	if(*iniia==1 || *finia==v-1){
		*modIA *=-1;
	}
	if (*goll==0){
	*pelX+=(*modX);
	*pelY+=(*modY);
	*iniia+=(*modIA);
	*finia+=(*modIA);
	if (kbhit() ==1) {
		key=getch();
		if(key=='8'){
		if(*inijuga!=1){
		*inijuga-=1;
		*finjuga-=1;
		}	
		}
		if(key=='2'){
			if(*finjuga!=v-2){
			*finjuga+=1;
			*inijuga+=1;				
			}
		}
	}
	}
}
void udpate(char campo[v][h],int pelX,int pelY,int inijuga,int finjuga,int iniia,int finia){	
borde(campo);	
raquejuga(campo,inijuga,finjuga);
raqueia(campo,iniia,finia);
pelota(campo,pelX,pelY);	
}