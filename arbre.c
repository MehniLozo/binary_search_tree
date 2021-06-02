#include <stdio.h>
#include "pile_OA_chainé.c"
#include <stdlib.h>
#include <assert.h>
/*Une arbre binaire de recherche est une arbre ou on insere un nombre
  (*abr)uelcon(*abr)ue ,cette arbre reste trié.*/

/**************************Implementation_Abre_Binaire_Recherche**************/


struct noeud* creer_arbre()
{
    return NULL;

}
unsigned arbre_vide(struct noeud* abr)
{
    return abr == NULL;
}
unsigned recherche(struct noeud *abr,int info)

{

    assert(!arbre_vide(abr));
    struct noeud* q = abr;
    while(q)
    {
        if(q->cle == info)
            return 1;
        else
        {
            if(info <q->cle)
                q = q->sag;
            else 
                q = q->sad;
        }
    
    }
    return 0;
}
void ajouter(struct noeud** abr,int info)
{
    //3 cas à considérer
    //arbre vide
    //element existant 
    //insertion d'element telque l'arbre reste trié(endroit adéquat)
       if(arbre_vide(*abr))
    {
        *abr = (struct noeud*)malloc(sizeof(struct noeud));
        (*abr)->cle = info;
        (*abr)->sag = NULL;
        (*abr)->sad = NULL;
    
        return;
    }
    //else 
    //on a le cas si info existe déja dans l'arbre
     struct noeud *courant = *abr,*pere= NULL;
        int trouve = 0;
    while(courant && !trouve)
    {
        pere = courant;
        if(courant->cle == info)
            trouve = 1;
        else{
            if(info < courant->cle)
                courant = courant -> sag;
            else
                courant = courant->sad;
            }

    }

    if(trouve)
    {
        printf("\nElement existe déja\n");
        return;
    }

    courant = (struct noeud*)malloc(sizeof(struct noeud));
    courant->cle = info;
    courant->sag = NULL;
    courant->sad = NULL;

    if(info < pere->cle)
        pere->sag = courant;
    else
        pere->sad = courant;

}
void affiche(struct noeud* abr)
{
    //pour la fonction affiche on utilise la technique d'affichage
    //par profondeur
    //(affichage préfixé)
    //On utilise aussi une pile de struct noeud*
    //PQ pile? on a besoin du dernier element ajouter donc la pile offre
    //cetter fonctionalité
    //On commence:
    //Si le noeud admet un sad on l'enpile et on continue vers son sag
    //on fait le méme
    //so On approche au NULL on prend le dernier noeud empilé et on l'utilise
    
    assert(!arbre_vide(abr));
    struct noeud* n = abr;
    creer_pile();

   while(n || !pile_vide()) //on quitte la boucle quand on approche NULL
                            //et il'yavais aucun noeud dans la pile
   {
        while(!n && !pile_vide())
        {
            n = dernier();
//            printf("\nI HAVE ENTERED THIS\n");
            depiler();
            
        }    
        if(n->sad)
            empiler(n->sad);
        printf("%d\t",n->cle);
        n = n->sag; 
   } 
    printf("\n");
}
