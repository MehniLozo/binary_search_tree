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
    //basic Binary-Search : recherche dichotomique

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
/*
unsigned profondeur(struct noeud* abr)
{

    //STILL UNDER MAINTENANCE
    //retourne la profondeur ---> the maximum depth of the tree
   
    
}

*/
struct noeud* recherche_min(struct noeud *abr)
{
    assert(!arbre_vide(abr));
   struct noeud* pmin = abr; 
   while(pmin->sag) //on connait que le plus petit element est toujours a gauche
        pmin = pmin->sag; 

   return pmin;
   
}
struct noeud* recherche_max(struct noeud *abr)
{
   assert(!arbre_vide(abr));
   struct noeud* pmax = abr; 
   while(pmax->sad) //on connait que le plus petit element est toujours a gauche
     pmax = pmax->sad; 

   return pmax;
   
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
    //We literally took advantage of this by checking whether the element exists already in the tree & also
    //we capture the father of this node(appropriate position)
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

int successor(struct noeud* abr)
{
    /*Successor if root node is the smallest node on the right branch*/
    struct noeud* courant = abr;

    if(!(abr->sad))
    {
        printf("\n%d doesn't have no successor\n",abr->cle);
        return 0;
    }

    courant = abr->sad;

    while(courant->sag)
        courant = courant->sag;

    return courant->cle;


}
int predecessor(struct noeud *abr)
{

    /*Predecessor is the biggest node on the left node 
     * */
    struct noeud* courant = abr;
    
    if(!(abr->sag))
    {
        printf("\n----%d doesn't have no predecessor----\n",abr->cle);
        return 0;
    }

    courant = abr->sag;

    while(courant->sad) //we can find the biggest item on the right
        courant = courant->sad;
    
    printf("\n%d\n",courant->cle);

    return courant->cle;
}
void supprimer_element(struct noeud**abr,int x)
{
   /*   (a)-cas du noeud racine feuille ou demi-feuille
    *       -noeud racine feuille: (sans sag sad) en le supprimant
    *       l'arbre devient vide
    *       -demi-feuille:
    *           -noeud racine sans sag:sad devient la racine de l'arbre
    *           -noeud racine sans sad: sag devient la racine de l'arbre
    
    * */
   struct noeud *courant= *abr,*pere= NULL;

   while(courant && courant->cle != x)
   {
       pere = courant;//we need the father in the 2nd case
        if(x>courant->cle)
            courant = courant->sad;
        else
            courant = courant->sag;
    
   }

   if(!courant)
   {
    printf("\n%d n'existe pas dans l'arbre\n",x);
    return;
   }
   if(!pere) // on est dans le noeud root
   {
        if(! (*abr)->sag && !(*abr)->sad)
        { 
            free(abr); //l'arbre devient vide
            printf("\n%d (racine) has been successfully deleted\n",x);
        
            return;
        }
        else if(!(*abr)->sag || !(*abr)->sad)
        {    
                courant =*abr;
            if(!(*abr)->sag)
                 (*abr) = (*abr)->sad;
           else
                (*abr) =  (*abr)->sag;
            free(courant);
            printf("\n%d (racine) has been successfully deleted\n",x);

        }  
                //repeated code IF ROOT HAS TWO BRANCHES
             if((*abr)->sag && (*abr)->sad)
           {
               printf("\nReached up here\n");
               struct noeud* min = (*abr)->sad,*pere_mini;
               printf("valeur de abr = %d \n",(*abr)->cle);
               printf("valeur de droite de  abr = %d \n",(*abr)->sad->cle);

               printf("valeur de gauche droite  de  abr = %d \n",(*abr)->sad->sag->cle);
               

               while(min->sag)
               {
                   pere_mini = min;
                   min = min->sag; //recherchant la plus petite noeud
               }
               printf("\nvaleur de min = %d\n",min->cle);
               
               printf("\nReached up here2\n");

               if(min->sad)
                 pere_mini->sag = min->sad;
               printf("\nReached up here3\n");
               (*abr)->cle = min->cle;
               free(min); //ON NE SUPPPRIME PAS LE NOEUD EN QUESTION
            }

   }
    /*  (b) case du noeud non racine: feuille ou demi feuille:
     *      -noeud feuille: on supprime ce noeud et on affecte la valeur
     *          NULL au champ sag ou sad de son pere
     *      -non racine
     *          - sans sag: on affecte au champ sag ou sad se son pere
     *              l'adresse de son fils droit
     *          -sans sad: on affecte au champ sad ou sag de son pere
     *              l'adresse de son fils gauche
     * */
   else{
       if(courant)
       {
           if(!courant->sag && !courant->sad) //noeud feuille
           {
               
                if(x < pere->cle)
                    pere->sag = NULL;
                else
                    pere->sad = NULL;
                free(courant);
           }
           else{
                if(!courant->sag)
                {
                   if(x< pere->cle) //to check on which side of the node we in
                    pere->sag = courant->sad; 
                   else 
                       pere->sad = courant->sad;
                }else{
                
                   if(x< pere->cle) //to check on which side of the node we in
                        pere->sag = courant->sag; 
                   else 
                       pere->sad = courant->sag;
                
                }
            
                free(courant);
               
                printf("\n%d has been successully deleted\n",x);
                return;
           }
        
          /*    (c) cas du noeud avec un sag && sad
           *    on recherche le noeud contenant la plus petite valeur dans
           *    le sad(SON SAD).
           *    (on pourrait,rechercher le noeud contenant la plus grande
           *    valeur dans la sag).
           *    Ce noeud est forcément un sag.(FORCEMENT N'ADMET PAS UN SAG
           *    BECAUSE ITS THE SMALLEST BUT PROBABLY A SAD)
           *    La valeur contenue dans ce noeud
           *    est alors affactée au champ valeur du noeud contenant la valeur
           *    à supprimer
           *    NB: ON NE SUPPRIME PAS LE NOEUD EN QUESTION
           *
           * */  
           /*QUESTION?
            * COULDN'T THIS CASE BE "ROOT TREE ITSELF????BUT WE SURPASSED IT
            * "*/
           if(courant->sag && courant->sad)
           {
               struct noeud* min = courant->sad;

               while(min->sag)
               {
                   pere = min;
                   min = min->sag; //recherchant la plus petite noeud
               }
               if(min->sad)
                 pere->sag = min->sad;
               courant->cle = min->cle;
               free(min); //ON NE SUPPPRIME PAS LE NOEUD EN QUESTION
            }
       }
    
   
   
   
   }


}
