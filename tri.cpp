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
void triUnique(ConteneurTDE& c, Joueurs& j, Item entree, int cpt, unsigned int& etoilesdaffilee) {

	Mot tmp;
	strcpy(tmp, entree);
	for (int i = 0; i <= cpt; ++i) {
		if (strcmp(tmp, c.tab[i]) == 0) {
			//cout << "Votre mot : " << tmp << " existe deja dans la base -> " << entree << endl;
			//cout << "la gueule du mot d'avant : " << c.tab[i - 1] << endl;
			//cout << "la gueule qu'il a : " << c.tab[i] << endl;
			//cout << "la gueule du mot d'apres : " << c.tab[i + 1] << endl;
			j.nbdemot--;
			return;
		}
	}
	ecrire(c, cpt, tmp);
	etoilesdaffilee = 0;
	//cout << "MOT ENREGISTE : " << tmp << endl;
	//cout << "########################################################" << endl;
	//cout << "# Affichage des mots jusqu'ici" << endl;
	//for (int i = 1; i <= j.nbdemot; i++) {
		//cout << "# " << c.tab[i] << endl;
	//}
	//cout << "########################################################" << endl;


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
	tabIndices = new int[300];
	/*Pour i=0, i allant au max des jouers,i++
		  pour k - i - 1, k allant au max des jouers,k++
				comparer jouer i à jouer k
				  Si c pareil c'est que les mots sont egaux

  */
	for (int joueur1 = 0; joueur1 <= nbjoueurs; joueur1++) {
		for (int joueur2 = 1; joueur2 <= nbjoueurs; joueur2++) {
			for (unsigned int k = 0; k <= j[joueur2].nbdemot; ++k) {//la liste de mots du gars
				for (unsigned int i = 1; i <= j[joueur1].nbdemot; ++i) { //le dico ou la liste de l'autre gars
					Unique = 1;
					if (strcmp(j[joueur2].conteneurDesMots.tab[k], j[joueur1].conteneurDesMots.tab[i]) == 0) {
						Unique = 0;
						break;
					}
				}
				if (Unique == 0) {
					tabIndices[hit] = k;
					hit++;
				}
			}
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

		for (int j = 1; j <= jr.nbdemot - i - 1; j++) {
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