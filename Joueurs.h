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


//02/01/2021 19H21

/**
 * @brief Affichage de toute les listes
 * @see detruire, la liste est à désallouer en fin d'utilisation.
 * @param[in] j le conteneur
 * @param[in] hit le nombre de joueurs/ le nombre de fois où le programme rencontre le "*"
 * @pre vide pour l'instant ? on verra
 */
void affichageDeTousLesMots(Joueurs* j, int hit);

/**
 * @brief Initialise le tableau de joueur
 * @see detruireJoueurs, Pour detruire les joueurs
 * @param[in] j le conteneur
 * @param[in] hit le nombre de joueurs/ le nombre de fois où le programme rencontre le "*"
 * @pre vide pour l'instant ? on verra
 */
void initialisationDesJoueurs(TabJoueurs& tabj, unsigned int nbj);

void detruireJoueurs(TabJoueurs& j);


/**
 * @brief Ajoute uniquement un joueur
 * @param[in] j le conteneur
 * @param[in] nbjoueurs le nombre de joueurs avant de l'incrementer
 * @pre vide pour l'instant ? on verra
 */
void ajouterJoueurs(TabJoueurs& tabj, unsigned int& nbjoueurs);