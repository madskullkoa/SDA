/*
  * @author NUNES BORBA Manoel & MEDILEH Youcef
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
		}
		triUnique(j[nbjoueurs].conteneurDesMots, j[nbjoueurs], entree, cpt);
		calcul_de_points(j[nbjoueurs]);
		cpt++;

	} while (true);
	

	for (int i = 0; i < hit; i++) {
		triAlpha(j[i].conteneurDesMots, j[i]);
	}

	for (int k = 0; k < hit; k++) {
		for (int i = 0; i < j[k].nbdemot; i++) {
			cout << j[k].conteneurDesMots.tab[i] << endl;
		}
	}

	cout << "*" << endl;

}