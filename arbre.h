
struct noeud{
    int cle;
    struct noeud *sag,*sad;

};

struct noeud* creer_arbre();
unsigned arbre_vide(struct noeud* abr);
unsigned recherche(struct noeud *abr,int info);
void ajouter(struct noeud** abr,int info);
void affiche(struct noeud* abr);
