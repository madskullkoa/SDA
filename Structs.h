#pragma once
typedef struct {
	/// Capacit� du conteneur (>0).
	unsigned int capacite;
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension;
	/// Conteneur allou� en m�moire dynamique.
	Item* tab;
}ConteneurTDE;

typedef struct {
	/// Conteneur m�morisant les �l�ments de la liste.
	ConteneurTDE c;
	/// Nombre d'�l�ments stock�s dans la liste.
	unsigned int nb;
}Liste;

typedef struct {
	int* pointparmot;
	int nbdemot;
	int total;
	Liste listeDesMots;
}Joueurs;