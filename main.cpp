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
using namespace std;


/**
 * @brief enleves les doublons
 * @param[in] c le conteneur des mots
 */
void triUnique(ConteneurTDE& c, Joueurs& j, Item entree, int cpt) {
	Mot tmp;
	strcpy(tmp, entree);
	for (int i = 0; i < j.nbdemot; ++i) {
		if (strcmp(tmp, c.tab[i]) == 0) {
			cout << "Votre mot existe deja dans la base" << endl;
			j.nbdemot--;
			return;
		}
	}
	ecrire(c, cpt, tmp);
	

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
		//ecrire(j.conteneurDesMots, cpt, entree);
		triUnique(j.conteneurDesMots, j, entree, cpt);
		calcul_de_points(j);
		cpt++;
	} while (true);


	cout << "Affichage du nombre de mots :" << endl;
	cout << j.nbdemot << endl;


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

	triUnique(j.conteneurDesMots, j, entree, cpt);
	for (int i = 0; i < j.nbdemot; i++) {
		cout << j.conteneurDesMots.tab[i] << endl;
	}

}