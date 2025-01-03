#include "Exercice1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
	// Graphe* monGraphe1 = (Graphe*)malloc(sizeof(Graphe));
	
	// monGraphe1 = insertionGraphe(monGraphe1, 1);
	// monGraphe1 = insertionGraphe(monGraphe1, 2);
	// monGraphe1 = insertionGraphe(monGraphe1, 3);
	// monGraphe1 = insertionGraphe(monGraphe1, 4);
	// monGraphe1 = insertionGraphe(monGraphe1, 5);
	// monGraphe1 = insertionGraphe(monGraphe1, 6);
	// monGraphe1 = insertionGraphe(monGraphe1, 7);
	// printf("test avant intialisation\n");
	Graphe* monGraphe2 = (Graphe*)malloc(sizeof(Graphe));
	intialiserGraphe(monGraphe2, 4);
	insertionGraphe(monGraphe2, 99);
	afficherGraphe(monGraphe2);
	// supprimerGraphe(monGraphe2);
	// afficherGraphe(monGraphe2);
	//Après la suppression, le graphe n'existe pas, donc il n'ya rien à afficher comme si le graphe n'éxitait pas
	return 0;
}