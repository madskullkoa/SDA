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

bool triUnique(Item entre, Liste l) {
	int taille = longueur(l);
	bool Unique = 1;
	for (int i = 0; i <= taille; i++) {
		if (strcmp(entre, l.c.tab[i]) == 0) {
			Unique = 0;
			return Unique;
		}	 
	}
	return Unique;
}

/**
 * @brief Supprimer les elements en double de la liste
 * @param[in] l La liste.
 */
void supprimer(Liste l) {
	//pour supprimer l'element, il faut un tableau des indices ou les mots sont en double. ensuite on utilise la fonction supprimer du prof pour supprimer l'element donné par le tableau
	
}


/**
 * @brief Trier la liste de mots par ordre alphabetique
 * @param[in] entre le mot entré.
 * @param[in] l La liste.
 * @param[in] j La structure Joueurs
 */
void triAlpha(Item& entre, Liste& l, Joueurs& j) {
	//assert(triUnique(entre, l));		//C'est très bien ca bg        merci ^^
	//le tri unique va servire a rien parce que avec strcmp on va comparer et si ça vaut 0 on sauvegarde pas, t'as capté le bail ?
	//Item test;
	int position = 0;
	//strcpy(test,entre);
	// if (l.nb == 0) {
	// 	for (int j = 0; j < 1; j++) {
	// 		if (strcmp(entre, l.c.tab[j])>0) { // Ne sont pas triés (Si la valeur est négative le premier mot est le plus proche de "a" ) ICI IL VA RENTRER DANS LE if
	// 			/*
	// 			strcmp("BETA", "ALPHA") --> return une valeur plus grande que 0
	// 			the first character that does not match has a lower value in ptr1 than in ptr2
	// 			*/
	// 		cout << "pas trié" << endl;
	// 			//position++;
	// 		}
	// 	}
	// }
		
		for (int i = 0; i < l.nb; i++) {
			for (int j = 0; j < i - 1; j++) {
				if (strcmp(entre, l.c.tab[j])<0) {
					cout << "ok" << endl;					
				}else if(strcmp(entre, l.c.tab[j])>0)
				{
					cout << "pas trié" << endl;	
				}else if (strcmp(entre, l.c.tab[j]))
				{
					cout << "identique" << endl;
				}
			}
		}
		inserer(l, position, entre); //c'est pas terminé mais askip c chaud
		
}

/**
 * @brief bah c'est le main quoi...
 */
int main() {
	Item entree;
	Joueurs j;
	
	initialisation(j); //initialiser le conteneur joueurs
	initialiser(j.listeDesMots, 20, 2); //initialiser la liste
	unsigned int cpt = 0;
	cout << "Wsh manoel\n";

	do {
		cin >> entree;
		if ((strcmp(entree, "*") == 0)) {
			break;
		}
		triAlpha(entree, j.listeDesMots,j);		//enregistrement_des_mots(entree, cpt, j);
		//ici on trie les mots avant de les ecrire dans la liste
		calcul_de_points(j);
		cpt++;
	} while (true);

	cout << j.total << endl;
}