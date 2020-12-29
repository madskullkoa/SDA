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
			//cout << "Votre mot existe deja dans la base" << endl;
			j.nbdemot--;
			return;
		}
	}
	ecrire(c, cpt, tmp);
}

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
	}

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
			if (hit > 1)
				break;
			j[nbjoueurs].nbdemot--;
			nbjoueurs++;
			cpt = 0;
			continue;
		}
		/*if (nbjoueurs > 1)
			break;*/
		

		triUnique(j[nbjoueurs].conteneurDesMots, j[nbjoueurs], entree, cpt);
		calcul_de_points(j[nbjoueurs]);
		cpt++;

	} while (true);
	nbjoueurs--;


	//for (int i = 0; i < nbjoueurs; i++) {
	//	triAlpha(j[i].conteneurDesMots, j[i]);
	//}

	triAlpha(j[0].conteneurDesMots, j[0]);
	triAlpha(j[1].conteneurDesMots, j[1]);


	/*for (int i = 0; i < j[nbjoueurs].nbdemot; i++) {

		for(int k = 0; k < nbjoueurs; k++) {
			cout << "mots de joueur" << i << " : " << endl;
			cout << j[i].conteneurDesMots.tab[k] << endl;
		}
		
	}*/
	cout << "joueur 1 :" << endl;
	cout << j[0].conteneurDesMots.tab[0] << endl;
	cout << j[0].conteneurDesMots.tab[1] << endl;
	cout << j[0].conteneurDesMots.tab[2] << endl;
	cout << j[0].conteneurDesMots.tab[3] << endl;
	cout << j[0].conteneurDesMots.tab[4] << endl;
	cout << j[0].conteneurDesMots.tab[5] << endl;
	cout << j[0].conteneurDesMots.tab[6] << endl;
	cout << j[0].conteneurDesMots.tab[7] << endl;
	cout << j[0].conteneurDesMots.tab[8] << endl;
	cout << j[0].conteneurDesMots.tab[9] << endl;
	cout << j[0].conteneurDesMots.tab[10] << endl;
	cout << j[0].conteneurDesMots.tab[11] << endl;
	cout << j[0].conteneurDesMots.tab[12] << endl;
	cout << j[0].conteneurDesMots.tab[13] << endl;
	cout << j[0].conteneurDesMots.tab[14] << endl;
	cout << j[0].conteneurDesMots.tab[15] << endl;
	cout << j[0].conteneurDesMots.tab[16] << endl;
	cout << j[0].conteneurDesMots.tab[17] << endl;
	cout << j[0].conteneurDesMots.tab[18] << endl;
	cout << j[0].conteneurDesMots.tab[19] << endl;
	cout << j[0].conteneurDesMots.tab[20] << endl;
	cout << j[0].conteneurDesMots.tab[21] << endl;
	cout << j[0].conteneurDesMots.tab[22] << endl;
		    
															    
	cout << "joueur 2 :" << endl;							    
	cout << j[1].conteneurDesMots.tab[0] << endl;
	cout << j[1].conteneurDesMots.tab[1] << endl;
	cout << j[1].conteneurDesMots.tab[2] << endl;
	cout << j[1].conteneurDesMots.tab[3] << endl;
	cout << j[1].conteneurDesMots.tab[4] << endl;
	cout << j[1].conteneurDesMots.tab[5] << endl;
	cout << j[1].conteneurDesMots.tab[6] << endl;
	cout << j[1].conteneurDesMots.tab[7] << endl;
	cout << j[1].conteneurDesMots.tab[8] << endl;
	cout << j[1].conteneurDesMots.tab[9] << endl;
	cout << j[1].conteneurDesMots.tab[10] << endl;
	cout << j[1].conteneurDesMots.tab[11] << endl;
	cout << j[1].conteneurDesMots.tab[12] << endl;
	cout << j[1].conteneurDesMots.tab[13] << endl;
	cout << j[1].conteneurDesMots.tab[14] << endl;
	cout << j[1].conteneurDesMots.tab[15] << endl;
	cout << j[1].conteneurDesMots.tab[16] << endl;
	cout << j[1].conteneurDesMots.tab[17] << endl;
	cout << j[1].conteneurDesMots.tab[18] << endl;
	cout << j[1].conteneurDesMots.tab[19] << endl;
	cout << j[1].conteneurDesMots.tab[20] << endl;
	cout << j[1].conteneurDesMots.tab[21] << endl;
	cout << j[1].conteneurDesMots.tab[22] << endl;			    
															    
	cout << "*" << endl;

}