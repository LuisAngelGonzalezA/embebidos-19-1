#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_HILOS 4

/*
int * reservarMemoria( );
void llenarArreglo( int *datos );
void imprimirArreglo( int *datos );
void * mayorArreglo( void *arg );
void * menorArreglo( void *arg );
*/

int main()
{
	int nhs[NUM_HILOS], *res;
    register int nh;
	pthread_t tids[NUM_HILOS];

	printf("Probando hilos ...\n");
/*
        datos = reservarMemoria();
        llenarArreglo( datos );
        imprimirArreglo( datos);
*/

for (nh = 0; nh < NUM_HILOS; nh++)
{
    nhs[nh]=nh;
    pthread_create(&tids[nh], NULL, funHilo,(void *)&nhs[nh]);
}
for (nh = 0; nh < NUM_HILOS; nh++)
{
    pthread_join(tids[nh],(void ** )&res);
    printf("Hilo %d terminado", *res);
}

return 0
}

void * funHilo (void *arg)
{
register int i;
int nh = *(int *)arg;
pthread_exit( arg );

}

/*
	pthread_create( &tid_men, NULL, menorArreglo, (void *)datos );
	pthread_create( &tid_may, NULL, mayorArreglo, (void *)datos );

	pthread_join(tid_men, (void **)&res_men );
	pthread_join(tid_may, (void **)&res_may );

	printf("El mayor es: %d\n", *res_may);
	printf("El menor es: %d\n", *res_men);

	return 0;
}

void llenarArreglo( int *datos )
{
        register int i;

        srand( getpid() );
        for( i = 0; i < N; i++ )
        {
                datos[i] = rand() % 255;
        }
}

int * reservarMemoria( )
{
        int *mem;

        mem = (int *)malloc( sizeof(int) * N  );
        if( !mem )
        {
                perror("Error al asignar memoria...\n");
                exit(EXIT_FAILURE);
        }
        return mem;
}
void * menorArreglo( void *arg )
{
        register int i;
	static int menor;
	int *datos = (int *)arg;

        menor = datos[0];
        for( i = 1; i < N; i++ )
        {
                if( datos[i] < menor )
                        menor = datos[i];
        }
	pthread_exit((void *)&menor);
}

void * mayorArreglo( void *arg )
{
        register int i;
	static int mayor;
	int *datos = arg;

        mayor = datos[0];
        for( i = 1; i < N; i++ )
        {
                if( datos[i] > mayor )
                        mayor = datos[i];
        }
       	pthread_exit((void *)&mayor);
}
void imprimirArreglo( int *datos )
{
        register int i;

        for( i = 0; i < N; i++ )
        {
                if( !(i%16) )
                        printf("\n");
                printf("%3d ", datos[i]);
        }
        printf("\n");
}

*/