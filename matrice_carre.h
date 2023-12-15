#ifndef __MATRICE_CARRE__H__
#define __MATRICE_CARRE__H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** get_random_matrice(int N,int random);
void liberer_matrice(int** matrice,int N);
void afficher_matrice(int** matrice,int N);
int trace_matrice(int** matrice,int N);
int** produit_de_convolution(int** matrice, int lengthMatrice,int** matriceFilter,int lengthMatriceFilter);
#endif
