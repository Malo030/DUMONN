#pragma once
#include <iostream>

class Inventaire {
private:
	int quantite_elec;
	int argent;
	char Ressources[];

public:
	void ajouter_Ressource();
	char retirer_Ressource();
	void ajouter_argent();
	void retirer_argent();
	void ajouter_elec();
	void retirer_elec();
	int getArgent();
	int getElec();
	char getRessources();
};