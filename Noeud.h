#pragma once

typedef int TElement; 

class noeud {
public:
	TElement element;
	noeud * Suivant;
	noeud(const TElement & info, noeud * suiv = nullptr) { // constructeur1
		element = info;
		Suivant = suiv;
	}
	noeud(noeud * suiv = nullptr) { // constructeur 2
		Suivant = suiv;
	}
	~noeud() {
	}
}; 
