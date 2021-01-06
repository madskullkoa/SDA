/*
  * @author MEDILEH Youcef & NUNES BORBA Manoel
  * @version 1 � 18/11/2020
  * @brief Types : co�t-m�moire et domaine de variation
  */
#pragma warning(disable:4996)
#include <ctime> // pour clock et CLOCKS_PER_SEC
#include <iostream>
#include <cstring>
#include <cassert>
#include "Liste.h"
#include "Structs.h"
#include "ConteneurTDE.h"
#include "points.h"
#include "tri.h"
#include "Joueurs.h"
using namespace std;
//Pour calculer le temps d'execution
double getTime() {
	clock_t t = clock();
	if (t == (clock_t)-1)
		return 0.;
	else
		return (double)t / CLOCKS_PER_SEC;
}

typedef struct {
	bool plateauVof[4][4];
	char plateauMots[4][4];
	int x;
	int y;
}Coord;

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
		cout << "############### joueur " << k + 1 << " ###############" << endl;
		for (int i = 0; i < j[k].nbdemot; i++) {
			std::cout << j[k].conteneurDesMots.tab[i] << endl;
		}
	}

	std::cout << "*" << endl;
}
void initialiserUnPlateau(Coord& c) {
	Mot entre;
	
	char alphabet[26] = "abcdefghijklmopqrstuvwxyz";
	int indice;
	for (int i = 0; i < 4; ++i) { // [i][]
		cin >> entre;

			for (int k = 0; k < 4; k++) {  // [i][k]
				c.plateauVof[i][k] = false;

				c.plateauMots[i][k] = entre[k];
			}
		
	}
}




//bool sousrecherche(Mot String, int pos, Coord& Coord) {
//	if (pos >= strlen(String)) {
//		return true;
//	}
//	if (Coord.plateauMots[Coord.x][Coord.y]==String[pos]) {
//		return false;
//	}
//}


int main() {

	double time1, time2;
	time1 = getTime();
	Coord c;
	

	Item entree; // de deux cases
	//Joueurs* j;
	unsigned int etoilesdaffilees = 0;
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
		
		initialiserUnPlateau(c);
		cin >> entree;
		tabj[nbjoueurs].nbdemot++;
		if ((strcmp(entree, "*") == 0)) {

			etoile++;
			etoilesdaffilees++;


			tabj[nbjoueurs].nbdemot--;
			if (etoilesdaffilees == 2) {
				//on sort
				tabj[nbjoueurs].nbdemot--;
				break;
			}
			ajouterJoueurs(tabj, nbjoueurs);

			cpt = 0;
			continue;

		}
		triUnique(tabj[nbjoueurs].conteneurDesMots, tabj[nbjoueurs], entree, tabj[nbjoueurs].nbdemot, etoilesdaffilees);


		//calcul_de_points(tabj[nbjoueurs - 1]);

		cpt++;

	} while (true);



	//cout << "################################ AFFICHAGE FINAL ################################" << endl;



	for (int i = 0; i < nbjoueurs; i++) {
		triAlpha(tabj[i].conteneurDesMots.tab, tabj[i].nbdemot);
	}

	//affichageDeTousLesMots(tabj, nbjoueurs);
	comparaison(tabj, nbjoueurs);
	std::cout << "*" << endl;
	time2 = getTime();
	cout << "Temps d'exécution du quickSort : " << time2 - time1
		<< " s." << endl;
}