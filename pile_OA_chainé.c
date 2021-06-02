#include<assert.h>
#include<stdlib.h>
#include"pile_OA_chainé.h"


struct element {
    struct noeud* cle ;
    struct element *suivant ;
};

static struct element *sommet ;


void creer_pile()
{
    sommet=NULL;
}
unsigned pile_vide()
{
    return (sommet==NULL);
}
struct noeud* dernier()
{
    assert (!pile_vide());
    return (sommet->cle);
}
void empiler(struct noeud* info)
{
    struct element *q ;
    q=(struct element*)malloc(sizeof(struct element));
    q->cle=info;
    q->suivant=sommet;
    sommet=q;
}
void depiler()
{
    struct element *q;
    assert (!pile_vide());
    q=sommet;
    sommet=sommet->suivant;
    free(q);
}
