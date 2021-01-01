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
	tabj.j = new Joueurs[1];
}

void detruireJoueurs(TabJoueurs& j) {
	delete[] j.j;
	j.j = NULL;

}


/**
 * @brief Ajoute uniquement un joueur
 * @param[in] j le conteneur
 * @param[in] nbjoueurs le nombre de joueurs avant de l'incrementer
 * @pre vide pour l'instant ? on verra
 */
void ajouterJoueurs(TabJoueurs& tabj, unsigned int& nbjoueurs) {

	unsigned int newT = ++nbjoueurs;
	tabj.j newTaille = new Joueurs[newT];

	for (int i = 0; i < nbjoueurs; i++) {
		newTaille[i] = tabj.j[i];
	}

	delete[] tabj.j;
	tabj.j = newTaille;
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
	initialisation(tabj.j[nbjoueurs]);
	initialiser(tabj.j[nbjoueurs].conteneurDesMots, 10, 2);
	do {
		cin >> entree;
		tabj.j[nbjoueurs].nbdemot++;
		if ((strcmp(entree, "*") == 0)) {
			etoile++;
			if (etoile == 2) {
				//on sort 
				tabj.j[nbjoueurs].nbdemot--;
				break;
			}

			tabj.j[nbjoueurs].nbdemot--;
			ajouterJoueurs(tabj, nbjoueurs);
			cpt = 0;
			continue;

		}
		triUnique(tabj.j[nbjoueurs].conteneurDesMots, tabj.j[nbjoueurs], entree, tabj.j[nbjoueurs].nbdemot, etoile);
		calcul_de_points(tabj.j[nbjoueurs]);
		cpt++;

	} while (true);



	//cout << "################################ AFFICHAGE FINAL ################################" << endl;
	triAlpha(tabj.j[0].conteneurDesMots, tabj.j[0]);
	triAlpha(tabj.j[1].conteneurDesMots, tabj.j[1]);
	//affichageDeTousLesMots(j, hit);
	comparaison(j, nbjoueurs);
	std::cout << "*" << endl;
}