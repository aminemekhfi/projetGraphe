#ifndef EXERCIC1_H
#define EXERCIC1_H

//------------------------------------------- Question 1 : -----------------------------------------;
//	Structure d'un Noeud:

typedef struct Noeud
{
	int donnee;
	struct Noeud* suivant;
}Noeud;

//	Liste d'adjacence:

typedef struct listAdjacent
{
	struct Noeud* premierElement;
}listAdjacent;

//	Graphe

typedef struct Graphe
{
	Noeud* sommeGraphe;	
	listAdjacent* tableauListe;
}Graphe;

//	Fonctions pour créer un graphe

Noeud* creerNoeud(int valeur);
Graphe* insertionGraphe(Graphe* graphe, int valeur);




#endif