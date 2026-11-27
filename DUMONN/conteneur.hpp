#pragma once
#include <iostream>

class Conteneur {
private:
	int nb_items;
	int capaciteMax;
	char Stockage[];

public:
	Conteneur();
	void ajouterRessource(char Ressource);
	char retirerRessource(char Ressource);
};