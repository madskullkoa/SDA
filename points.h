#ifndef _POINTS_
#define _POINTS_

typedef int points;
typedef char Mot[30];
typedef Mot Item;

#include "Liste.h"
#include "ConteneurTDE.h"
#include "points.h"
#include "Structs.h"


void initialisation(Joueurs& j);
void detruire(Joueurs& j);
void ajout_des_points(Joueurs& j);
void calcul_de_points(Joueurs& j);
void enregistrement_des_mots(Item donne, unsigned int i, Joueurs& j);
#endif