#include "matrice_carre.h"
#include <stdio.h>
#include <stdlib.h>
int** get_random_matrice(int N,int random){
  //Allocation de la mémoire pour la matrice

  if (random == 0)
  {
    int** matrice=(int**)calloc(N,sizeof(int*));

  for(int i =0;i<N;i++){
    matrice[i]= (int*)calloc(N,sizeof(int*));
  }
  return matrice;
  }else{
  
      int** matrice=(int**)malloc((N)*sizeof(int*));

      for(int i =0;i<N;i++){
        matrice[i]= (int*)malloc((N)*sizeof(int));
      }
      
      //Remplir la matrice avec des nombres aléatoires de 1-10
      srand(time(NULL));
      for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
          matrice[i][j] = rand()%10+1;
        }
        
      }
      return matrice;
  }
}

int trace_matrice(int** matrice,int N){
  int trace=0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if(i==j)trace+=matrice[i][j];
    }
    
  }
  return trace;
}


int** produit_de_convolution(int** matrice, int lengthMatrice,int** matriceFilter,int lengthMatriceFilter) {
  //Délcaration de la matrice résultats
  int** matriceConvo  = get_random_matrice(lengthMatrice,0);
   for (int i = 0; i < lengthMatrice; i++) {
        for (int j = 0; j < lengthMatrice; j++) {
            int result = 0;

            for (int k = 0; k < lengthMatriceFilter; k++) {
                for (int l = 0; l < lengthMatriceFilter; l++) {
                    // Check if the filter doesn't go beyond matrix boundaries
                    if (i + k < lengthMatrice && j + l < lengthMatrice) {
                        result += matriceFilter[k][l] * matrice[i + k][j + l];
                    }
                }
            }

            matriceConvo[i][j] = result;
        }
    }

  return matriceConvo;
}


void liberer_matrice(int** matrice,int N){

  for(int i =0;i<N;i++){
    free(matrice[i]);
  }
  free(matrice);

}

void afficher_matrice(int** matrice,int N){
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d\t",matrice[i][j]);
    }
    printf("\n");
  }
}

