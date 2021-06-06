
struct noeud{
    int cle;
    struct noeud *sag,*sad;

};

struct noeud* creer_arbre();
unsigned arbre_vide(struct noeud* abr);
unsigned recherche(struct noeud *abr,int info);
struct noeud* recherche_min(struct noeud *abr);
struct noeud* recherche_max(struct noeud *abr);
void ajouter(struct noeud** abr,int info);
void affiche(struct noeud* abr);
