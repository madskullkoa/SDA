#pragma once
typedef struct {
	/// Capacité du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur alloué en mémoire dynamique.
	Mot* tab;
}ConteneurTDE;

typedef struct {
	/// Conteneur mémorisant les éléments de la liste.
	ConteneurTDE c;
	/// Nombre d'éléments stockés dans la liste.
	unsigned int nb;
}Liste;

typedef struct {
	int* pointparmot;
	int nbdemot;
	int total;
	ConteneurTDE conteneurDesMots;
}Joueurs;