#include "Exercice1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
	//------------------------------------------- Graphe 1 initialiser manuelement : -----------------------------------------;
	// Graphe* monGraphe1 = (Graphe*)malloc(sizeof(Graphe));
	// monGraphe1 = insertionGraphe(monGraphe1, 1);
	// monGraphe1 = insertionGraphe(monGraphe1, 2);
	// monGraphe1 = insertionGraphe(monGraphe1, 3);
	// monGraphe1 = insertionGraphe(monGraphe1, 4);
	// monGraphe1 = insertionGraphe(monGraphe1, 5);
	// monGraphe1 = insertionGraphe(monGraphe1, 6);
	// monGraphe1 = insertionGraphe(monGraphe1, 7);
	// ajouterArreteParValeur(monGraphe1, 3, 7);
	// ajouterArreteParValeur(monGraphe1, 7, 3);
	// ajouterArreteParValeur(monGraphe1, 2, 2);
	// afficherGraphe(monGraphe1);

	//------------------------------------------- Graphe 2 initialiser aléatoirement : -----------------------------------------;
	// printf("test avant intialisation\n");
	// Graphe* monGraphe2 = (Graphe*)malloc(sizeof(Graphe));
	// intialiserGraphe(monGraphe2, 4);
	// insertionGraphe(monGraphe2, 99);
	// afficherGraphe(monGraphe2);

	//------------------------------------------- supprimer graphe : -----------------------------------------;
	// supprimerGraphe(monGraphe2);
	// afficherGraphe(monGraphe2);
	//Après la suppression, le graphe n'existe pas, donc il n'ya rien à afficher comme si le graphe n'éxitait pas

	//------------------------------------------- parcours en largeur : -----------------------------------------;
	Graphe* monGrapheParcours = (Graphe*)malloc(sizeof(Graphe));
	monGrapheParcours = insertionGraphe(monGrapheParcours, 1);
	monGrapheParcours = insertionGraphe(monGrapheParcours, 2);
	monGrapheParcours = insertionGraphe(monGrapheParcours, 3);
	monGrapheParcours = insertionGraphe(monGrapheParcours, 4);
	monGrapheParcours = insertionGraphe(monGrapheParcours, 5);
	ajouterArreteParValeur(monGrapheParcours, 5, 1);
	ajouterArreteParValeur(monGrapheParcours, 1, 3);
	ajouterArreteParValeur(monGrapheParcours, 4, 1);
	afficherGraphe(monGrapheParcours);
	return 0;
}