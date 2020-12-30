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
		for (int i = 1; i < j[k].nbdemot; i++) {
			cout << j[k].conteneurDesMots.tab[i] << endl;
		}
	}

	cout << "*" << endl;
}


int main() {
	Item entree;
	Joueurs j[4];
	int nbjoueurs = 0;
	int hit = 0;
	unsigned int cpt = 0;
	for (unsigned int i = 0; i < 4; ++i) {
		initialisation(j[i]);
		initialiser(j[i].conteneurDesMots, 10, 2);
	}

	do {
		cin >> entree;
		j[nbjoueurs].nbdemot++;
		if ((strcmp(entree, "*") == 0)) {
			hit++;
			if (hit > 1) {
				j[nbjoueurs].nbdemot--;
				break;
			}

			j[nbjoueurs].nbdemot--;
			nbjoueurs++;
			cpt = 0;
			continue;

			if (nbjoueurs == 1) {

				break;
			}
		}
		triUnique(j[nbjoueurs].conteneurDesMots, j[nbjoueurs], entree, j[nbjoueurs].nbdemot);
		calcul_de_points(j[nbjoueurs]);
		cpt++;

	} while (true);



	//cout << "################################ AFFICHAGE FINAL ################################" << endl;
	triAlpha(j[0].conteneurDesMots, j[0]);
	triAlpha(j[1].conteneurDesMots, j[1]);
	//affichageDeTousLesMots(j, hit);
	comparaison(j,hit);
	cout << "*" << endl;


}