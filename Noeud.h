#pragma once
#include "Client.h"
template <typename Objet>
class noeud {
public:
	Objet element;
	noeud * Suivant;
	noeud(const Objet & info, noeud * suiv = nullptr) { // constructeur1
		element = info;
		Suivant = suiv;
	}
	noeud(noeud * suiv = nullptr) { // constructeur 2
		Suivant = suiv;
	}
	~noeud() {
	}
}; 
