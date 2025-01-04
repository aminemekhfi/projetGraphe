#include "Exercice1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


//------------------------------------------- Question 2 : -----------------------------------------;
Noeud* creerNoeud(int valeur)
{
	Noeud* nouveauNoeud=(Noeud*)malloc(sizeof(Noeud));
	nouveauNoeud->donnee=valeur;
	nouveauNoeud->suivant=NULL;
	return nouveauNoeud;
}

int tailleGraphe(Graphe* graphe)
{
    Noeud* temp=graphe->listeSommets;
    int tailleGraphe=0;
    while(temp!=NULL)
    {
        tailleGraphe++;
        temp=temp->suivant;
    }
    return tailleGraphe;
}


arrete* ajouterArrete(Graphe* graphe, Noeud* sommet1, Noeud* sommet2)
{
    if(sommet1==sommet2)
    {
        return NULL;
    }
    arrete* nouvelleArrete = (arrete*)malloc(sizeof(arrete));
    nouvelleArrete->noeud1 = sommet1;
    nouvelleArrete->noeud2 = sommet2;
    nouvelleArrete->suivant = NULL;

    if (graphe->listeArretes == NULL) {
        graphe->listeArretes = nouvelleArrete;
    } else {
        arrete* tempArrete = graphe->listeArretes;
        while (tempArrete->suivant != NULL) {
            tempArrete = tempArrete->suivant;
        }
        tempArrete->suivant = nouvelleArrete;
    }
    return nouvelleArrete;
}

Graphe* insertionGraphe(Graphe* graphe, int valeur)
{
	//graphe n'existe pas
    if (graphe == NULL) {
        graphe = (Graphe*)malloc(sizeof(Graphe));
        graphe->listeSommets = NULL;
        graphe->listeArretes = NULL;
        graphe->nombreSommets = 0;
    }

    //Creaction sommet
    Noeud* nouveauNoeud = creerNoeud(valeur);

    //graphe vide
    if (graphe->listeSommets == NULL) {
        graphe->listeSommets = nouveauNoeud;
    } else {
        Noeud* temp = graphe->listeSommets;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouveauNoeud;
    }

    graphe->nombreSommets++;


    if(graphe->nombreSommets>1)
    {
        Noeud* precedant=graphe->listeSommets;
        while(precedant->suivant!=nouveauNoeud)
        {
            precedant=precedant->suivant;
        }
        ajouterArrete(graphe, precedant, nouveauNoeud);
    }

    //Arrete si se n'est pas le premier noeud
    // if (graphe->nombreSommets > 1) {
	// 	int indexAleatoire = rand() % graphe->nombreSommets;
    //     Noeud* temp = graphe->listeSommets;
	// 	for (int i = 0; i < indexAleatoire; i++) {
    //         temp = temp->suivant;
    //     }
    //     ajouterArrete(graphe, nouveauNoeud, temp);
    // }
	//Si c'est le premier noeud, on ne peut pas ajouter d'arrete
    return graphe;
}

//Fonction pour afficher le graphe

void afficherGraphe(Graphe* graphe)
{
    if(graphe==NULL)
    {
        printf("Graphe vide\n");
        return;
    }
	Noeud* temp = graphe->listeSommets;
	arrete* tempArrete = graphe->listeArretes;
	while (temp != NULL) {
		printf("%d\n", temp->donnee);
		temp = temp->suivant;
	}
    int i = 1;
	while (tempArrete != NULL) {

		printf("Arrete %d : %d -> %d\n", i, tempArrete->noeud1->donnee, tempArrete->noeud2->donnee);
		tempArrete = tempArrete->suivant;
        i++;
	}
}

int sommetExiste(Graphe* graphe, int valeur) {
    Noeud* temp = graphe->listeSommets;
    while (temp != NULL) {
        if (temp->donnee == valeur) {
            return 1;
        }
        temp = temp->suivant;
    }
    return 0;
}

void intialiserGraphe(Graphe* graphe, int nombreSommets) {
    srand(time(NULL));
    int valeurRandom = 0;

    for (int i = 0; i < nombreSommets; i++) {
        do {
            valeurRandom = rand() % 10;
        } while (sommetExiste(graphe, valeurRandom)==1);

        graphe = insertionGraphe(graphe, valeurRandom);
    }
}

void supprimerGraphe(Graphe* graphe)
{
    Noeud* temp = graphe->listeSommets;
    Noeud* temp2 = graphe->listeSommets;
    while (temp != NULL) {
        temp2 = temp->suivant;
        free(temp);
        temp = temp2;
    }
    arrete* tempArrete = graphe->listeArretes;
    arrete* tempArrete2 = graphe->listeArretes;
    while (tempArrete != NULL) {
        tempArrete2 = tempArrete->suivant;
        free(tempArrete);
        tempArrete = tempArrete2;
    }
    free(graphe);
}


//////Partie2

////Q1
bool estCircuit(Noeud* chemin[], int nbsommet) {
    if (nbsommet < 2) {  // Un circuit nécessite au moins 2 sommets
        return false;
    } else {
        if (chemin[0] == chemin[nbsommet - 1]) {     // Vérifie si le premier et le dernier sommet sont identiques
            return true; // C'est un circuit
        } else {
            return false; // Pas un circuit
        }
    }
}

//////////
//int main() {
    // Exemple de chemin
 //   Noeud* chemin[] = {noeud1, noeud2, noeud3, noeud4};
//    int nbsommet = 4; // Nombre de sommets dans le chemin

    // Vérifier si c'est un circuit
  //  if (estCircuit(chemin, nbsommet)) {
  //      printf("C'est un circuit.\n");
 //   } else {
 //       printf("Ce n'est pas un circuit.\n");
 //   }

 //   return 0;
//}
/////////

///Q3
bool estComplet(Graphe* graphe) {
    int nombreDeSommets = graphe->nombreSommets;
    int nombreAretesAttendues = nombreDeSommets * (nombreDeSommets - 1) / 2;
    int nombreAretesActuelles = 0;
    arrete* arêteCourante = graphe->listeArretes;
    while (arêteCourante != NULL) {      // Parcourir toutes les arêtes du graphe
        nombreAretesActuelles++;
        arêteCourante = arêteCourante->suivant;
    }
    if (nombreAretesActuelles == nombreAretesAttendues) {
        return true; //Graphe complet
    } else {
        return false;
    }
}



