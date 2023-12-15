#include <stdio.h>
#include <stdlib.h>
#include "matrice_carre.h"
int main(void)
{
  int taille;
  int tailleFiltre;
  printf("Entrer la Taille de la matrice: ");
  scanf("%d",&taille);
  printf("Entrer la taille de la matrice filtre: ");
  scanf("%d",&tailleFiltre);
  if(taille<=tailleFiltre){
    printf("la taille de la matrice filtre doit etre infrieure a la taille du matrice\n");
    return 1;
  }
  int** matrice= get_random_matrice(taille,1);
  int** matriceFilter= get_random_matrice(tailleFiltre,1);
  printf("_____________LA MATRICE INTITIALE_____________\n");
  afficher_matrice(matrice,taille);
  printf("_____________________________________________ \n");


  int** matriceConvo = produit_de_convolution(matrice,taille,matriceFilter,tailleFiltre);
  printf("la trace de la matrice :%d\n",trace_matrice(matrice,taille));
  printf("_____________LA MATRICE FILTRE_____________ \n");
  afficher_matrice(matriceFilter,tailleFiltre);
  printf("________________________________________________\n");
  printf("_____________LA MATRICE CONVOLUTION_____________ \n");
  afficher_matrice(matriceConvo,taille);
  printf("________________________________________________\n");

liberer_matrice(matrice,taille);
liberer_matrice(matriceConvo,taille); 
liberer_matrice(matriceFilter,tailleFiltre);

  return 0;
}
