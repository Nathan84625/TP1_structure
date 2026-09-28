#pragma once

#include "noeud.h"
#include <string>
#include <cassert>

using namespace std;

template <typename Objet>

class Liste {
public:
	Liste(); // Constructeur
    Liste(const Liste<Objet>& autre); // AJOUT : permet de créer une nouvelle Liste comme copie indépendante d'une autre Liste.
	~Liste(); // Destructeur
    Liste<Objet>& operator=(const Liste<Objet>& autre); // AJOUT : permet de faire liste1 = liste2 sans partager les mêmes noeuds.
	void FixerTete();
    void Inserer(const Objet &);
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
