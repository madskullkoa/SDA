#ifndef _LISTE_
#define _LISTE_

/**
 * @file Liste.h
 * @brief Composant de liste en mémoire dynamique et extensible.
 */

#include "Liste.h"
#include "ConteneurTDE.h"
#include "points.h"
#include "Structs.h"

 /**
  * @brief Initialiser une liste vide, la liste est allouée en mémoire dynamique.
  * @see detruire, la liste est à désallouer en fin d'utilisation.
  * @param[out] l La liste à initialiser.
  * @param[in] capa Capacité de la liste.
  * @param[in] pas Pas d'extension de la liste.
  * @pre capa > 0 et pas > 0.
  */
void initialiser(Liste& l, unsigned int capa, unsigned int pas);

/**
 * @brief D�sallouer une liste.
 * @see initialiser
 * @param[out] l La liste.
 */
void detruire(Liste& l);

/**
 * @brief Longueur de liste.
 * @param[in] l La liste.
 * @return La longueur de la liste.
 */
unsigned int longueur(const Liste& l);

/**
 * @brief Lire un �l�ment de liste.
 * @param[in] l La liste.
 * @param[in] pos Position de l'�l�ment � lire.
 * @return L'item lu en position pos.
 * @pre 0 <= pos < longueur(l).
 */
Item* lire(const Liste& l, unsigned int pos);

/**
 * @brief Ecrire un item dans la liste.
 * @param[in,out] l La liste.
 * @param[in] pos Position de l'�l�ment � �crire.
 * @param[in] it L'item.
 * @pre 0 <= pos < longueur(l).
*/
//void ecrire(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Ins�rer un �l�ment dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position � laquelle l'�l�ment est ins�r�.
 * @param[in] it L'�l�ment ins�r�.
 * @pre 0 <= pos <= longueur(l).
 */
void inserer(Liste& l, unsigned int pos, const Item& it);

/**
 * @brief Supprimer un �l�ment dans une liste.
 * @param[in,out] l La liste.
 * @param[in] pos La position de l'�l�ment � supprimer.
 * @pre longueur(l) > 0 et 0 <= pos < longueur(l).
 */
void supprimer(Liste& l, unsigned int pos);
#endif