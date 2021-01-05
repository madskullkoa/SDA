#include <iostream>
#include <cstring>
#include <cassert>
#include "Liste.h"
#include "Structs.h"
#include "ConteneurTDE.h"
#include "points.h"
#include "tri.h"

/**
 * @brief Initialise le tableau de joueur
 * @see detruireJoueurs, Pour detruire les joueurs
 * @param[in] j le conteneur
 * @param[in] hit le nombre de joueurs/ le nombre de fois où le programme rencontre le "*"
 * @pre vide pour l'instant ? on verra
 */
void initialisationDesJoueurs(TabJoueurs& tabj, unsigned int nbj) {
	tabj = new Joueurs[1];
}

void detruireJoueurs(TabJoueurs& j) {
	delete[] j;
	j = NULL;

}


/**
 * @brief Ajoute uniquement un joueur
 * @param[in] j le conteneur
 * @param[in] nbjoueurs le nombre de joueurs avant de l'incrementer
 * @pre vide pour l'instant ? on verra
 */
void ajouterJoueurs(TabJoueurs& tabj, unsigned int& nbjoueurs) {

	unsigned int newT = nbjoueurs + 1;//0+1=1
	TabJoueurs newTaille = new Joueurs[newT + 1];//new Joueurs[2]; -> 0, 1 => 2 elements
	initialisation(newTaille[newT]); //initialise à l'indice prochain (joueur pro)
	initialiser(newTaille[newT].conteneurDesMots, 10, 2);
	for (int i = 0; i <= nbjoueurs; i++) {
		newTaille[i] = tabj[i];
	}

	delete[] tabj;
	tabj = newTaille;
	nbjoueurs++;
}