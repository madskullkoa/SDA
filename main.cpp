/*
  * @author NUNES BORBA Manoel & MEDILEH Youcef
  * @version 1 � 18/11/2020
  * @brief Types : co�t-m�moire et domaine de variation
  */

#pragma error(disable:4996)
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cassert>
#include "Liste.h"
#include "Structs.h"
#include "ConteneurTDE.h"
#include "points.h"
using namespace std;


/**
 * @brief enleves les doublons
 * @param[in] c le conteneur des mots
 */
void triUnique(ConteneurTDE& c, Joueurs j) {
	for (int k = 0; k < j.nbdemot; k++) {
		for (int i = 0; i < j.nbdemot; ++i) {
			if (strcmp(c.tab[i], c.tab[i + 1]) == 0) {
				strcpy(c.tab[i + 1], c.tab[i + 2]);
				j.nbdemot--;
			}
			/*if (strcmp(c.tab[i-1], c.tab[i]) == 0) {
			strcpy(c.tab[i], c.tab[i+1]);
	  j.nbdemot--;
		}*/
		}
	}
}

/*bool triUnique(Item entre, Liste l) {
	int taille = longueur(l);
	bool Unique = 1;
	for (int i = 0; i <= taille; i++) {
		if (strcmp(entre, l.c.tab[i]) == 0) {
			Unique = 0;
			return Unique;
		}
	}
	return Unique;
}*/


/**
 * @brief Trier la liste de mots par ordre alphabetique
 * @param[in] entre le mot entré.
 * @param[in] c Le conteneur des mots
 * @param[in] j La structure Joueurs (sert a rien je crois)
 */
void triAlpha(ConteneurTDE& c, Joueurs& jr) {

	Mot tmp;

	for (int i = 0; i < jr.nbdemot; i++) {
		for (int j = 0; j < jr.nbdemot - i - 1; j++) {
			if (strcmp(c.tab[j], c.tab[j + 1]) < 0) {
				//cout << "ok" << endl;
			}
			else if (strcmp(c.tab[j], c.tab[j + 1]) > 0)
			{
				//cout << "pas trié" << endl;
				strcpy(tmp, c.tab[j]);
				strcpy(c.tab[j], c.tab[j + 1]);
				strcpy(c.tab[j + 1], tmp);
			}
			else if (strcmp(c.tab[j], c.tab[j + 1]) == 0)
			{

			}
		}
	}

}

/**
 * @brief bah c'est le main quoi...
 */
int main() {
	Item entree;
	Joueurs j;

	initialisation(j); //initialiser le conteneur joueurs
	initialiser(j.conteneurDesMots, 10, 2);
	unsigned int cpt = 0;
	cout << "Wsh manoel\n";

	do {
		cin >> entree;
		if ((strcmp(entree, "*") == 0)) {
			break;
		}
		j.nbdemot++;
		ecrire(j.conteneurDesMots, cpt, entree);
		calcul_de_points(j);
		cpt++;
	} while (true);

	cout << "Affichage des mots entrés :" << endl;
	for (int i = 0; i < j.nbdemot; i++) {
		cout << j.conteneurDesMots.tab[i] << endl;
	}

	cout << "Affichage des mots triés :" << endl;
	triAlpha(j.conteneurDesMots, j);

	for (int i = 0; i < j.nbdemot; i++) {
		cout << j.conteneurDesMots.tab[i] << endl;
	}


	cout << "Affichage des mots sans doublons :" << endl;

	triUnique(j.conteneurDesMots, j);
	for (int i = 0; i < j.nbdemot; i++) {
		cout << j.conteneurDesMots.tab[i] << endl;
	}

}