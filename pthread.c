#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <time.h> 
#include<math.h>

#define M 4 
#define N 4
#define NBR_thr 4

int A [M][M];
int B [M][M];
int C [M][M]; 
int k = 0; 

 pthread_t threads[NBR_thr];

int main(int argc, char *argv[]) {

 for (int i = 0; i < M; i++) { 
        for (int j = 0; j < M; j++) { 
            A[i][j] = rand() % 10; 
            B[i][j] = rand() % 10; 
        } 
    } 

//fonction de decoupe
 void* multi(void* arg) 
{ 
	
    //int indice=k++ ; 
  
    // Each thread computes 1/4th of matrix multiplication 
    for (int i = 0; i <k; i++)  
        for (int j = 0; j < M; j++)  
            for (int k = 0; k < M; k++)  
                C[i][j] += A[i][k] * B[k][j]; 
} 
//fin 
	//affichage A 

		printf("matrice A \n") ;
	 for (int i = 0; i < M; i++) { 
        for (int j = 0; j < M; j++)
 		printf("%d \t",A[i][j]) ;
		}

		//affichage B 
			//printf("\n matrice B \n") ;
	 for (int i = 0; i < M; i++) { 
        for (int j = 0; j < M; j++)
 		printf("%d \t",B[i][j]);
}
	//creation thread
	for (int i = 0; i < NBR_thr; i++) { 
        int* p; 
        pthread_create(&threads[i], NULL, multi, (void*)(p)); 
    }
	//pthread join

	for (int i = 0; i < NBR_thr; i++)  
        pthread_join(threads[i], NULL);
 		//printf("\n matrice C \n") ;
		for (int i = 0; i <M; i++) { 
         for (int j = 0; j <M; j++)
 	printf("%d \t",A[i][j]);    
}
	return 0;
}

