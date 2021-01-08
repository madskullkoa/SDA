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
using namespace std;
typedef struct
{
	int x;
	int y;
}Coord;

typedef struct {
	bool plateauVof[4][4];
	char plateauMots[4][4];
	Coord tabDesCoord[8];
}Plateau;



void radar(Plateau& plateau, Coord coordDonnee);
bool sousrecherche(Mot mot, int pos, Coord coord, Plateau& plateau);

//Pour calculer le temps d'execution
double getTime() {
	clock_t t = clock();
	if (t == (clock_t)-1)
		return 0.;
	else
		return (double)t / CLOCKS_PER_SEC;
}


void initialiserUnPlateau(Plateau& c) {
	Item entre;
	int indice;
	for (int k = 0; k < 4; ++k) { // [i][]
		cin >> entre;
		cout << "[";
		for (int i = 0; i < 4; i++) {  // [i][k]
			cout << "[";
			c.plateauVof[i][k] = false;

			c.plateauMots[i][k] = entre[i];
			cout << " " << c.plateauMots[i][k] << " ";
			cout << "]";
		}
		cout << "]" << endl;
	}
}






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

/**
 * @brief Initialise le tableau de joueur
 * @see detruireJoueurs, Pour detruire les joueurs
 * @param[in] j le conteneur
 * @param[in] hit le nombre de joueurs/ le nombre de fois où le programme rencontre le "*"
 * @pre vide pour l'instant ? on verra
 */
void initialisationDesJoueurs(TabJoueurs& tabj, unsigned int nbj) {
	tabj = new Joueurs[1];
}

void detruireJoueurs(TabJoueurs& j) {
	delete[] j;
	j = NULL;

}


/**
 * @brief Ajoute uniquement un joueur
 * @param[in] j le conteneur
 * @param[in] nbjoueurs le nombre de joueurs avant de l'incrementer
 * @pre vide pour l'instant ? on verra
 */
void ajouterJoueurs(TabJoueurs& tabj, unsigned int& nbjoueurs) {

	unsigned int newT = nbjoueurs + 1;//0+1=1
	TabJoueurs newTaille = new Joueurs[newT + 1];//new Joueurs[2]; -> 0, 1 => 2 elements
	initialisation(newTaille[newT]); //initialise à l'indice prochain (joueur pro)
	initialiser(newTaille[newT].conteneurDesMots, 10, 2);
	for (int i = 0; i <= nbjoueurs; i++) {
		newTaille[i] = tabj[i];
	}

	delete[] tabj;
	tabj = newTaille;
	nbjoueurs++;
}


bool recherche(Mot mot, Coord coord, Plateau& plateau) {
	//marque toutes les cases du plateau comme non visitées
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			plateau.plateauVof[i][j] = false;
		}
	}

	//pour toute coordonnée coord de la grille
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			coord.x = i;
			coord.y = j;
			if (sousrecherche(mot, 0, coord, plateau)) {
				return true;
			}
		}
	}
	return false;
}

bool sousrecherche(Mot mot, int pos, Coord coord, Plateau& plateau) {

	if (pos >= strlen(mot))
		return true;
	if (coord.x >= 4 || coord.y >= 4 || coord.x < 0 || coord.y < 0) {
		return false;
	}

	if (plateau.plateauMots[coord.x][coord.y] != mot[pos])
		return false;
	if (plateau.plateauVof[coord.x][coord.y] == true)
		return false;


	//marquer cette case comme visitée
	plateau.plateauVof[coord.x][coord.y] = true;
	
	
	//cout << mot[pos] << "et ses coord sont : x : " << coord.x << " y : " << coord.y << endl;


	radar(plateau, coord);
	/*for (int a = 0; a < 8; a++) {
		cout << "radar :" << endl;
		cout << plateau.tabDesCoord[a].x << endl;
		cout << plateau.tabDesCoord[a].y << endl;
	}*/
	for (int i = 0; i < 8; i++) {
		Coord coord2 = plateau.tabDesCoord[i];
		if (sousrecherche(mot, pos + 1, coord2, plateau))
		{
			return true;
		}
	}
	plateau.plateauVof[coord.x][coord.y] = false;
	return false;

}

void radar(Plateau& plateau, Coord coordDonnee) {

	/**
	 * diagonale-haut-gauche = coord.x - 1 , coord.y + 1 -- 0
	 * diagonale-haut-droite = coord.x + 1 , coord.y + 1 -- 1
	 * diagonale-bas-gauche = coord.x - 1 , coord.y - 1 -- 2
	 * diagonale-bas-droite = coord.x + 1 , coord.y - 1 -- 3
	 * haut = coord.y + 1 -- 4
	 * bas = coord.y - 1 -- 5
	 * droite = coord.x + 1 -- 6
	 * gauche = coord.y - 1 -- 7
	 **/


	plateau.tabDesCoord[0].x = coordDonnee.x - 1;
	plateau.tabDesCoord[0].y = coordDonnee.y - 1; //tabDeCoord[0] contient les valeurs de la coord d'en haut a gauche

	plateau.tabDesCoord[1].x = coordDonnee.x + 1;
	plateau.tabDesCoord[1].y = coordDonnee.y - 1; //tabDeCoord[1] contient les valeurs de la coord d'en haut a droite

	plateau.tabDesCoord[2].x = coordDonnee.x - 1;
	plateau.tabDesCoord[2].y = coordDonnee.y + 1;

	plateau.tabDesCoord[3].x = coordDonnee.x + 1;
	plateau.tabDesCoord[3].y = coordDonnee.y + 1;

	plateau.tabDesCoord[4].x = coordDonnee.x;
	plateau.tabDesCoord[4].y = coordDonnee.y - 1;

	plateau.tabDesCoord[5].x = coordDonnee.x;
	plateau.tabDesCoord[5].y = coordDonnee.y + 1;

	plateau.tabDesCoord[6].y = coordDonnee.y;
	plateau.tabDesCoord[6].x = coordDonnee.x + 1;

	plateau.tabDesCoord[7].y = coordDonnee.y;
	plateau.tabDesCoord[7].x = coordDonnee.x - 1;
}

int main() {
	double time1, time2;
	time1 = getTime();


	Plateau plateau;

	Coord coord;
	coord.x = 0;
	coord.y = 0;
	Coord coord2;
	coord2.x = 0;
	coord2.y = 0;

	bool tabBool[200]; //Tableau de boolean avec res (1d)

	//CLUE OBIG MENT ASAE


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
	initialiserUnPlateau(plateau);
	do {
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
	comparaison(tabj, nbjoueurs); //je sais pas si c'est inutile ou pas

	for(int i = 0; i<tabj[0].nbdemot; i++){
		bool res = recherche(tabj[0].conteneurDesMots.tab[i],  coord, plateau);
		tabBool[i] = res; //  
	}
	

	for(int i = 0; i < sizeof(tabBool); i++){
		if(tabBool[i] == true){   
			cout << tabj[0].conteneurDesMots.tab[i];
		}
	}



	std::cout << "*" << endl;
	time2 = getTime();
	cout << "Temps d'exécution du quickSort : " << time2 - time1
		<< " s." << endl;

}