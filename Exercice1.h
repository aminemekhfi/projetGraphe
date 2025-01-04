#ifndef EXERCIC1_H
#define EXERCIC1_H

//------------------------------------------- Question 1 : -----------------------------------------;
//	Structure d'un Noeud:

typedef struct Noeud
{
	int donnee;
	struct Noeud* suivant;
}Noeud;

//	arrete
typedef struct arrete
{
	Noeud* noeud1;
	Noeud* noeud2;
	struct arrete* suivant;
}arrete;


//	Graphe

typedef struct Graphe {
    Noeud* listeSommets; 
    arrete* listeArretes;
    int nombreSommets;
} Graphe;

//	Fonctions pour créer un graphe

Noeud* creerNoeud(int valeur);
arrete* ajouterArrete(Graphe* graphe, Noeud* sommet1, Noeud* sommet2);
Graphe* insertionGraphe(Graphe* graphe, int valeur);

//Fonction pour afficher le graphe

void afficherGraphe(Graphe* graphe);
void intialiserGraphe(Graphe* graphe, int nombreSommets);

int sommetExiste(Graphe* graphe, int valeur);

int tailleGraphe(Graphe* graphe);

void supprimerGraphe(Graphe* graphe);


///Partie 2
bool estCircuit(chemin, nbsommet);
bool estComplet(Graphe* graphe);




#endif