#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct corredor {
char nombre[50];
int edad;
char sexo[10];	
char club[30];	

}corredor;
corredor macho[3];
void poner_datos(char nombre[50],int edad,char sexo[10],char club[30],int interado);
int main(){
int edad;
char nombre[30];
char sexo[10];
char club[30];

for(int i=0;i<3;i++){
fflush(stdin);	
printf("%i) Cual es su nombre \n",(i+1));	
gets(nombre);	
printf("\n%i)cual es su edad?\n",(i+1));
scanf("%i",&edad);
fflush(stdin);
printf("\n%i)cual es su sexo \n",(i+1));
gets(sexo);
printf("\n%i)El nombre del club\n",(i+1));
gets(club);
poner_datos(nombre,edad,sexo,club,i);	
}
for(int i=0;i<3;i++){
printf("\n");
printf("%i)Su nombre es: %s\n",(i+1),macho[i].nombre);
printf("%i)Su edad es: %i\n",(i+1),macho[i].edad);	
printf("%i)Su sexo es: %s\n",(i+1),macho[i].sexo);	
printf("%i)Su club es: %s\n",(i+1),macho[i].club);
if(macho[i].edad<=18){
	printf("Usted es juvenil");

}else if(macho[i].edad<=40){
printf("Usted es señorl");	
}else{
	printf("Usted es veterano");
}	
}
system("pause");
}
void poner_datos(char nombre[50],int edad,char sexo[10],char club[30],int interado){
strcpy(macho[interado].nombre,nombre); 	
macho[interado].edad=edad;
strcpy(macho[interado].sexo,sexo);
strcpy(macho[interado].club,club);	
}

