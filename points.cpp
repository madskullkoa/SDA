
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cassert>
#include "Liste.h"
#include "ConteneurTDE.h"
#include "points.h"
#include "Structs.h"
using namespace std;


void initialisation(Joueurs& j) {
	j.nbdemot = 0;
	//j.TabDesMotsEntres = new Item[30];
	j.pointparmot = new int[30];

}

void detruire(Joueurs& j) {
	//delete[] j.TabDesMotsEntres;
	delete[] j.pointparmot;
	//j.TabDesMotsEntres = NULL;
	j.pointparmot = NULL;

}

/**
* @brief Ajoute les points
* @param[in-out]
* @pre dnbdemot ne dois pas être null
*/
void ajout_des_points(Joueurs& j) {

	for (int i = 0; i < j.nbdemot; i++) {
		j.total = j.total + j.pointparmot[i];

	}
}

/**
* @brief Calcule les points pour chque joueur
* @param[out] SDP : Donne acces a la structure des donnés
* @pre SDP->nbdemot doit être supérieur à0
*/
void calcul_de_points(Joueurs& j) {

	int points = 0;
	if (j.nbdemot == 0)

		return;
	else {
		for (int i = 0; i < j.nbdemot; i++) { 
			int taille_du_mot = strlen(j.conteneurDesMots.tab[i]);


			if (taille_du_mot > 2) { //quand c'est supereiur a 1 ça vaut 1 point. quand c'est > 4 
				points++;
			}
			if (taille_du_mot > 4) {
				points++;
			}
			if (taille_du_mot > 5) {
				points++;
			}
			if (taille_du_mot > 6) {
				points = points + 2;
			}
			if (taille_du_mot >= 8) {
				points = +6;
			}
			j.pointparmot[i] = points;

		}


	}
	ajout_des_points(j);
}


/**
* @brief Enregistre les mots
* @param[in] donne : Le mot entré par l'utilisateur
* @param[out] SDP : Donne acces a la structure des donnés
* @param[in] i : la position où ajouter/modifier l'item
* @pre donne doit être un Mot et non une valeur numérique
* @param[in] donne : Mot à écrire
*/
void enregistrement_des_mots(Item donne, unsigned int i, Joueurs& j) {
	if (i >= j.nbdemot) {
		unsigned int nouvelleTaille = (i + 1);

		Item* nouvelleT = new Item[nouvelleTaille];//nouveau mot de taille 4

		for (unsigned int i = 0; i < j.nbdemot; ++i) {
			//strcpy(nouvelleT[i], j.TabDesMotsEntres[i]);
			//delete[] j.TabDesMotsEntres;
			//j.TabDesMotsEntres = nouvelleT;
			j.nbdemot = nouvelleTaille;

		}

	}
	//strcpy(j.TabDesMotsEntres[i], donne);
	j.nbdemot++;
}
