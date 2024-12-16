#include "Exercice1.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------- Question 2 : -----------------------------------------;

Noeud* creerNoeud(int valeur)
{
	Noeud* nouveauNoeud=(Noeud*)malloc(sizeof(Noeud));
	nouveauNoeud->donnee=valeur;
	nouveauNoeud->suivant=NULL;
	return nouveauNoeud;
}

Graphe* insertionGraphe(Graphe* graphe, int sommeGrapheEntree)
{
	if(graphe==NULL)
	{
		graphe=(Graphe*)malloc(sizeof(Graphe));
		graphe->sommeGraphe=sommeGrapheEntree;
		graphe->tableauListe=(listAdjacent*)malloc(sommeGrapheEntree*sizeof(listAdjacent));
	}
	// Noeud* nouveauNoeud = creerNoeud(valeur);
	
}