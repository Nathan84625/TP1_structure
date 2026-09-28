#pragma once

#include "noeud.h"
#include <string>
#include <cassert>

using namespace std;

template <typename Objet>

class Liste {
public:
	Liste(); // Constructeur
	~Liste(); // Destructeur
	void FixerTete();
    void Inserer(const Objet &);
	void Supprimer();
	Objet ValeurCourante() const;//retourne la valeur d'�l�ment � la position courante.
	bool EstDansListe() const; // retourne vrai si position courante est dans la liste
	int Longueur() const; // retourne la longueur courante de la liste
	void FixerPosition(const int); // met position courante � position donn�e


private:
	noeud<Objet> * Tete; // position du premier �l�ment
	noeud<Objet> * Queue; // position du dernier �l�ment
	noeud<Objet> * Courant; // position de l'él�ment courant
};
#include "Liste.tpp"