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
    //Le code en commentaire est pour empecher de creer une arrete entre un sommet et lui meme
    // if(sommet1==sommet2)
    // {
    //     return NULL;
    // }
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

arrete* ajouterArreteParValeur(Graphe* graphe, int sommet1, int sommet2)
{
    Noeud* temp1 = graphe->listeSommets;
    Noeud* temp2 = graphe->listeSommets;
    while (temp1 != NULL) {
        if (temp1->donnee == sommet1) {
            break;
        }
        temp1 = temp1->suivant;
    }
    while (temp2 != NULL) {
        if (temp2->donnee == sommet2) {
            break;
        }
        temp2 = temp2->suivant;
    }
    return ajouterArrete(graphe, temp1, temp2);
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

void parcoursGrapheLargeur(Graphe* graphe, Noeud* sommet)
{

}


//------------------------------------------- Partie 2 : -----------------------------------------;




//------------------------------------------- Q1 : -----------------------------------------;

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
// Fonction pour détecter un circuit dans un graphe
bool dfsDetecterCircuit(Noeud* noeud, Noeud* ndprece, bool visites[], Graphe* graphe) {
    // Marquer le nœud actuel comme visité
    visites[noeud->donnee] = true;
    // Parcourir toutes les arêtes du graphe
    Arrete* arreteCourante = graphe->listeArretes;
    while (arreteCourante != NULL) {
        // Vérifier si l'arête concerne le nœud actuel
        if (arreteCourante->noeud1 == noeud || arreteCourante->noeud2 == noeud) {
            // Trouver le voisin du nœud actuel
Noeud* voisin;
if (arreteCourante->noeud1 == noeud) {
    voisin = arreteCourante->noeud2;
} else {
    voisin = arreteCourante->noeud1;
}
            // Si le voisin est le noued precedent on l'ignore
            if (voisin == ndprece) {
                arreteCourante = arreteCourante->suivant;
                continue;
            }
            // Si le voisin a déjà été visité, il y a un circuit
            if (visites[voisin->donnee]) {
                return true;
            }
            // Sinon, on passe au voisin
            if (dfsDetecterCircuit(voisin, noeud, visites, graphe)) {
                return true;
            }
        }
        arreteCourante = arreteCourante->suivant;
    }
    return false; // Pas de circuit détecté
}

// Fonction pour vérifier si le graphe contient un circuit
bool contientCircuit(Graphe* graphe) {
    if (graphe == NULL || graphe->listeSommets == NULL) {
        return false; // Graphe vide, pas de circuit
    }
    // Tableau pour marquer les nœuds visités
    bool visites[100] = {false};
    // Parcourir tous les nœuds du graphe
    Noeud* noeudCourant = graphe->listeSommets;
    while (noeudCourant != NULL) {
        if (!visites[noeudCourant->donnee]) {
            if (dfsDetecterCircuit(noeudCourant, NULL, visites, graphe)) {
                return true; // Circuit détecté
            }
        }
        noeudCourant = noeudCourant->suivant;
    }
    return false; // Pas de circuit détecté
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
  // if (contientCircuit(monGraphe)) {
  //      printf("Le graphe contient un circuit.\n");
  //  } else {
 //       printf("Le graphe ne contient pas de circuit.\n");
 //   }

 //   return 0;
//}
/////////

//------------------------------------------- Q3 : -----------------------------------------;
bool estComplet(Graphe* graphe) {
    int nombreDeSommets = graphe->nombreSommets;

    // Parcourir chaque sommet
    Noeud* sommetCourant = graphe->listeSommets;
    while (sommetCourant != NULL) {
        int degre = 0;

        // Parcourir toutes les arêtes pour compter le degré du sommet courant
        arrete* arêteCourante = graphe->listeArretes;
        while (arêteCourante != NULL) {
            // Vérifier si l'arête est incidente au sommet courant
            if (arêteCourante->noeud1 == sommetCourant || arêteCourante->noeud2 == sommetCourant) {
                degre++;
            }
            arêteCourante = arêteCourante->suivant;
        }

        // Si un sommet n'a pas un degré de (n-1), le graphe n'est pas complet
        if (degre != nombreDeSommets - 1) {
            return false;
        }

        // Passer au sommet suivant
        sommetCourant = sommetCourant->suivant;
    }

    return true; // Tous les sommets ont un degré de (n-1), le graphe est complet
}



