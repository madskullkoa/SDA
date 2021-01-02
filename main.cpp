/*
  * @author MEDILEH Youcef & NUNES BORBA Manoel
  * @version 1 � 18/11/2020
  * @brief Types : co�t-m�moire et domaine de variation
  */
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cassert>
#include "Liste.h"
#include "Structs.h"
#include "ConteneurTDE.h"
#include "points.h"
#include "tri.h"
using namespace std;


//02/01/2021 19H21

/**
 * @brief Affichage de toute les listes
 * @see detruire, la liste est à désallouer en fin d'utilisation.
 * @param[in] j le conteneur
 * @param[in] hit le nombre de joueurs/ le nombre de fois où le programme rencontre le "*"
 * @pre vide pour l'instant ? on verra
 */
void affichageDeTousLesMots(Joueurs* j, int hit) {

	for (int i = 0; i < hit; i++) {
		//triAlpha(j[i].conteneurDesMots, j[i]);
	}

	for (int k = 0; k < hit; k++) {
		//cout << "############### joueur " << k + 1 << " ###############" << endl;
		for (int i = 1; i <= j[k].nbdemot; i++) {
			std::cout << j[k].conteneurDesMots.tab[i] << endl;
		}
	}

	std::cout << "*" << endl;
}

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

	unsigned int newT = nbjoueurs+1;
	TabJoueurs newTaille = new Joueurs[newT+1];

	for (int i = 0; i < nbjoueurs; i++) {
		newTaille[i] = tabj[i];
	}

	delete[] tabj;
	tabj = newTaille;
	nbjoueurs++;
}

int main() {
	Item entree;
	//Joueurs* j;
	TabJoueurs tabj;
	unsigned int nbjoueurs = 0; //nombre de joueurs reel
	unsigned int cpt = 0; //nombre de mots reel
	unsigned int etoile = 0;
	//for (unsigned int i = 0; i < 4; ++i) {
	//	initialisation(j[i]);
	//	initialiser(j[i].conteneurDesMots, 10, 2);
	//}
	initialisationDesJoueurs(tabj, nbjoueurs);
	initialisation(tabj[nbjoueurs]);
	initialiser(tabj[nbjoueurs].conteneurDesMots, 10, 2);
	do {
		cin >> entree;
		tabj[nbjoueurs].nbdemot++;
		if ((strcmp(entree, "*") == 0)) {
			etoile++;
			if (etoile == 2) {
				//on sort 
				tabj[nbjoueurs].nbdemot--;
				break;
			}

			tabj[nbjoueurs].nbdemot--;
			ajouterJoueurs(tabj, nbjoueurs);
			cpt = 0;
			continue;

		}
		triUnique(tabj[nbjoueurs].conteneurDesMots, tabj[nbjoueurs], entree, tabj[nbjoueurs].nbdemot, etoile);
		calcul_de_points(tabj[nbjoueurs]);

		cpt++;

	} while (true);



	//cout << "################################ AFFICHAGE FINAL ################################" << endl;
	triAlpha(tabj[0].conteneurDesMots, tabj[0]);
	triAlpha(tabj[1].conteneurDesMots, tabj[1]);
	//affichageDeTousLesMots(j, hit);
	comparaison(tabj, nbjoueurs);
	std::cout << "*" << endl;
}