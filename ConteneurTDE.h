#ifndef _CONTENEUR_TDE_
#define _CONTENEUR_TDE_

/**
 * @file ConteneurTDE.h
 * @brief Composant d'un conteneur d'items de capacit� extensible.
 */

#include "Liste.h"
#include "ConteneurTDE.h"
#include "points.h"
#include "Structs.h"



 /**
  * @brief Initialise un conteneur d'items.
  * Allocation en m�moire dynamique du conteneur d'items
  * de capacit� (capa) extensible par pas d'extension (p).
  * @see detruire, pour sa d�sallocation en fin d'utilisation.
  * @param[out] c Le conteneur d'items.
  * @param [in] capa Capacit� du conteneur.
  * @param [in] p Pas d'extension de capacit�.
  * @pre capa > 0 et p > 0.
  */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique.
 * @see initialiser.
 * @param[in,out] c Le conteneur d'items.
 */
void detruire(ConteneurTDE& c);

/**
 * @brief Lecture d'un item d'un conteneur d'items.
 * @param[in] c Le conteneur d'items.
 * @param[in] i La position de l'item dans le conteneur.
 * @return l'adresse de l'item � l'indice i
 * @pre i < c.capacite
 */
Item* lire(const ConteneurTDE& c, unsigned int i);

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @param[in,out] c Le conteneur d'items.
 * @param[in] i La position o� ajouter/modifier l'item.
 * @param[in] it L'item � �crire.
 */
void ecrire(ConteneurTDE& c, unsigned int i, const Item& it);

#endif