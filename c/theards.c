//Una vez terminan su ejecuci�n devuelven como resultado su identificador */ 
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_THREADS     10 
// tabla con los identificadores de los threads 
pthread_t tabla_thr[MAX_THREADS]; 
// tipo de datos y tabla con los parametros  
typedef struct { 
  int id; 
  char *cadena; 
} thr_param_t; 
thr_param_t param[MAX_THREADS]; 
// tenemos que crear una tabla para los par�metros porque los pasamos por  
// referencia. As�, si solo tuvi�ramos una variable para los par�metros 
// al modificar esta modificar�amos todas las que hab�amos pasado anteriormente 
// porque los threads no se quedan con el valor sino con la direcci�n 
void *funcion_thr(thr_param_t *p) 
{ 
  // Esta es la funcion que ejecutan los threads 
  // como veras, no tiene mucho secreto... 
  printf("%s %d\n", p->cadena, p->id); 
  // una vez terminamos, devolvemos el valor 
  pthread_exit(&(p->id)); 
} 
int main(void) 
{ 
  int i, *res; 
  // creamos los threads 
  printf("Creando threads...\n"); 
  for (i=0; i<MAX_THREADS; i++) { 
    param[i].cadena = strdup("Hola, soy el thread"); 
    param[i].id     = i; 
    pthread_create(&tabla_thr[i], NULL, (void *)&funcion_thr,  
     (void *)&param[i]); 
  } 
  // esperamos que terminen los threads 
  printf("Threads creados. Esperando que terminen...\n"); 
  for (i=0; i<MAX_THREADS; i++) { 
    pthread_join(tabla_thr[i], (void *)&res); 
    printf("El thread %d devolvio el valor %d\n", i, *res); 
  } 
  // sacamos el mensajito y salimos del programa 
  printf("Todos los threads finalizados. Adios!\n"); 
  return 0; 
} 
/*** <CORTAR AQUI> ***/ 

