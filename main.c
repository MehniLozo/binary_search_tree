#include "arbre.c"
#include <stdio.h>
#include <stdlib.h>


int main()
{

    struct noeud * abr = creer_arbre();

  ajouter(&abr,100);
  ajouter(&abr,150);
  ajouter(&abr,50);
  ajouter(&abr,20);
  ajouter(&abr,70);
  ajouter(&abr,120);
  ajouter(&abr,170);


    
   affiche(abr);
    
    /* ajouter(&abr,5);
    
    printf("\n%d\n",abr->cle);
    printf("\ngauche %d\n",abr->sag->cle);
    printf("\ndroite %d\n",abr->sad->cle);
    printf("\nEXISTE %d \t : %d\n",abr->sag->cle,recherche(abr,abr->sag->cle));
*/





return 0;}