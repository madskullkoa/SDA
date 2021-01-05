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
	ecrire(c, cpt - 1, tmp);
	etoilesdaffilee = 0;
	//cout << "MOT ENREGISTE : " << tmp << endl;
	//cout << "########################################################" << endl;
	//cout << "# Affichage des mots jusqu'ici" << endl;
	//for (int i = 1; i <= j.nbdemot; i++) {
		//cout << "# " << c.tab[i] << endl;
	//}
	//cout << "########################################################" << endl;


}


bool triUniqueTabMot(Mot entre, Mot* tabMots, int& nb){
	for(int i = 0; i<nb;i++ ){
		if(strcmp(entre, tabMots[i])){
			//nb--;
			return 0;
		}
	}
	nb++;
	return 1;

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
	Mot* mots;

	bool Unique;
	int hit = 0;
	tabIndices = new int[300];
	mots = new Mot[300];

	for (int cpt1 = 0; cpt1 < nbjoueurs; cpt1++) {
		for (int cpt2 = cpt1+1; cpt2 < nbjoueurs; cpt2++) {
			for (unsigned int k = 0; k < j[cpt1].nbdemot; ++k) {//la liste de mots de cpt1
				for (unsigned int i = 0; i < j[cpt2].nbdemot; ++i) { //la liste de mot de cpt2
					Unique = 1;
					//cout << "je compare " << j[cpt1].conteneurDesMots.tab[k] << " avec " << j[cpt2].conteneurDesMots.tab[i] << endl;
					if (strcmp(j[cpt1].conteneurDesMots.tab[k], j[cpt2].conteneurDesMots.tab[i]) == 0) {
						//cout << "ils sont identiques" << endl;
						Unique = 0;
						break;
					}
				}
				if (Unique == 0) {
					tabIndices[hit] = k;

					//cout << "j'entre le mot " << j[cpt1].conteneurDesMots.tab[k] << endl;

					
					bool Motunique = triUniqueTabMot(j[cpt1].conteneurDesMots.tab[k], mots, hit);
					if(Motunique == 1){
						strcpy(mots[hit], j[cpt1].conteneurDesMots.tab[k]);
					}

					
				}
			}
		}
	}

	/*for (int k = 0; k < nbjoueurs; k++) {
		cout << "joueur " << k << endl;

		for (int i = 0; i < hit; ++i) {

			cout << j[k].conteneurDesMots.tab[tabIndices[i]] << endl;

		}
	}*/

	for (int i = 0; i < hit; i++) {
		cout << mots[i] << endl;
	}

	delete[] mots;
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