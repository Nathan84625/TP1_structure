#pragma once

#include "noeud.h"
#include <string>

using namespace std;

class Liste {
public:
	Liste(); // Constructeur
	~Liste(); // Destructeur
	void FixerTete();
    void Inserer(const TElement &);
private:
	noeud * Tete; // position du premier �l�ment
	noeud * Queue; // position du dernier �l�ment
	noeud * Courant; // position de l'él�ment courant
};
