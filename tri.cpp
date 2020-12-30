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
 * @brief enleves les doublons
 * @param[in] c le conteneur des mots
 */
void triUnique(ConteneurTDE& c, Joueurs& j, Item entree, int cpt) {
	Mot tmp;
	strcpy(tmp, entree);
	for (int i = 0; i < j.nbdemot; ++i) {
		if (strcmp(tmp, c.tab[i]) == 0) {
			cout << "Votre mot : " << tmp <<" existe deja dans la base -> " << entree<<endl;
			cout << "la gueule du mot d'avant : " << c.tab[i-1] << endl;
			cout << "la gueule qu'il a : " << c.tab[i] << endl;
			cout << "la gueule du mot d'apres : " << c.tab[i+1] << endl;
			j.nbdemot--;
			return;
		}
	}
	ecrire(c, cpt, tmp);
	cout << "MOT ENREGISTE : " << tmp <<endl;
}


/**
 * @brief Compare deux listes
 * @param[in] c le conteneur des mots
 * @param[in] j La structure Joueurs
 */
 /*afficher les mots de la seconde liste n’apparaissant pas
dans la première ;*/
void comparaison(Joueurs* j, int nbjoueurs) {

	int* tabIndices;
	bool Unique;
	int hit = 0;
	tabIndices = new int[j[1].nbdemot];

	for (unsigned int k = 0; k < j[1].nbdemot; ++k) {
		for (unsigned int i = 0; i < j[0].nbdemot; ++i) {
			Unique = 1;
			if (strcmp(j[1].conteneurDesMots.tab[k], j[0].conteneurDesMots.tab[i]) == 0) {
				Unique = 0;
				break;
			}
		}
		if (Unique == 1) {
			tabIndices[hit] = k;
			hit++;
		}
	}
	for (int i = 0; i < hit; ++i) {

		cout << j[1].conteneurDesMots.tab[tabIndices[i]] << endl;

	}



	delete[] tabIndices;
}
/**
 * @brief Trier la liste de mots par ordre alphabetique
 * @param[in] entre le mot entré.
 * @param[in] c Le conteneur des mots
 * @param[in] j La structure Joueurs (sert a rien je crois)
 */
void triAlpha(ConteneurTDE& c, Joueurs& jr) {

	//char* tmp;
	Mot tmp;




	for (int i = 0; i < jr.nbdemot; i++) {
		//tmp = new char[30];

		for (int j = 0; j < jr.nbdemot - i - 1; j++) {
			if (strcmp(c.tab[j], c.tab[j + 1]) < 0) {

			}
			else if (strcmp(c.tab[j], c.tab[j + 1]) > 0)
			{
				strcpy(tmp, c.tab[j]);
				strcpy(c.tab[j], c.tab[j + 1]);
				strcpy(c.tab[j + 1], tmp);
			}
			else if (strcmp(c.tab[j], c.tab[j + 1]) == 0)
			{

			}
		}

		//delete[] tmp;

	}


}