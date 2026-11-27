#pragma once
#include <iostream>
#include "conteneur.hpp"

Conteneur::Conteneur() {
	nb_items = 0;
	capaciteMax = 10; // Arbitraire, à tester
};

void Conteneur::ajouterRessource(char Ressource) {
	if (nb_items < capaciteMax) {
		nb_items++;
		Stockage[nb_items] = Ressource;
	}
	else {
		// -------> Erreur : Stockage plein	
	}
};


char Conteneur::retirerRessource(char Ressource) {
	// -------> Vérifier si la ressource est dans l'inventaire 
	for (int i = 0; i < nb_items; i++) {
		if (Stockage[i] == Ressource) {
			Stockage[i] = ' ';
			for (int j = i; j < nb_items; j++) {
				char temp = Stockage[j];
				Stockage[j] = Stockage[j + 1];
				Stockage[j + 1] = temp;
			}
			// -------> Supprimer le dernier élément du tableau
			// -------> Retirer la ressource de l'inventaire 
			nb_items--;
			return Ressource;
		}
	}
};