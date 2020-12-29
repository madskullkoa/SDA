/**
 * @file ConteneurTDE.cpp
 * @brief Composant de conteneur d'items de capacit� extensible
 */
#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

#include "Liste.h"
#include "ConteneurTDE.h"
#include "points.h"
#include "Structs.h"

void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa > 0) && (p > 0));
	c.capacite = capa;
	c.pasExtension = p;
	c.tab = new Mot[capa];
}

void detruire(ConteneurTDE& c) {
	delete[] c.tab;
	c.tab = NULL;
}

Item* lire(const ConteneurTDE& c, unsigned int i) {
	assert(i < c.capacite);
	return &c.tab[i];
}

void ecrire(ConteneurTDE& c, unsigned int i, const Item& it) {
	if (i >= c.capacite) {
		unsigned int newTaille = (i + 1) * c.pasExtension;
		Item* newT = new Item[newTaille];
		for (unsigned int i = 0; i < c.capacite; ++i)
			strcpy(newT[i], c.tab[i]);
		delete[] c.tab;
		c.tab = newT;
		c.capacite = newTaille;
	}
	strcpy(c.tab[i], it);
}
