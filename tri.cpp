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
			//cout << "Votre mot existe deja dans la base" << endl;
			j.nbdemot--;
			return;
		}
	}
	ecrire(c, cpt, tmp);
}


/**
 * @brief Compare deux listes
 * @param[in] c le conteneur des mots
 * @param[in] j La structure Joueurs
 */
 /*afficher les mots de la seconde liste n’apparaissant pas
dans la première ;*/
void comparaison(Joueurs* j, int nbjoueurs){

	//bool unique = 0;
  
    for(unsigned int k=0; k < j[1].nbdemot;++k){
    	for(unsigned int i=0; i < j[0].nbdemot;++i){
        
			if(strcmp(j[1].conteneurDesMots.tab[k],j[0].conteneurDesMots.tab[i])==0){
				break;
			}
			else /*if(strcmp(j[1].conteneurDesMots.tab[k],j[0].conteneurDesMots.tab[i])!=0)*/{
          	cout << j[1].conteneurDesMots.tab[k] << endl;         
        	}

        }
    }
  


	//des que tu peux m'appeller n'hesite pas



    //Moij'aurais fait ce que j'ai mis la haut azy
	/*for(int i = 0; i < j[0].nbdemot; i++){
		for(int k = 0; k < j[1].nbdemot; k++){
			if(strcmp(j[1].conteneurDesMots.tab[k], j[1].conteneurDesMots.tab[i]) == 0){
				break;
			}

			
		}




	}*/



  
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