#pragma once
typedef struct {
	/// Capacit� du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur allou� en m�moire dynamique.
	Mot* tab;
	/// Capacit� r�elle de mots
	unsigned int nbMots;
}ConteneurTDE;

typedef struct {
	/// Conteneur m�morisant les �l�ments de la liste.
	ConteneurTDE c;
	/// Nombre d'�l�ments stock�s dans la liste.
	unsigned int nb;
}Liste;

typedef struct {
	unsigned int* pointparmot;
	unsigned int nbdemot;
	unsigned int total;
	ConteneurTDE conteneurDesMots;
}Joueurs;

typedef Joueurs* TabJoueurs;

/*typedef struct {
	Joueurs* j;
}TabJoueurs;*/