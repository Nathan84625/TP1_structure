#include "Liste.h"
#include <string>
#include <fstream>


using namespace std;



// Constructeur
template <typename Objet>
Liste<Objet>::Liste()
{
	Queue = Tete = Courant = new noeud<Objet>; // crée le noeud entete
}

// Destructeur
template <typename Objet>
Liste<Objet>::~Liste()
{
	while (Tete != nullptr)
	{
		Courant = Tete;
		Tete = Tete->Suivant;
		delete Courant;
	}
}

template <typename Objet>
void Liste<Objet>::FixerTete()
{
	Courant = Tete;
}

template <typename Objet>
void Liste<Objet>::Inserer(const Objet &element)
{

	Courant->Suivant = new noeud<Objet>(element, Courant->Suivant);
	if (Queue == Courant)
		Queue = Courant->Suivant; // l'�l�ment est ajout� � la fin de la liste.
}

template <typename Objet>
Objet Liste<Objet>::ValeurCourante() const {
	assert(EstDansListe());
	return Courant->Suivant->element;
}

template <typename Objet>
bool Liste<Objet>::EstDansListe() const {
	return (Courant != nullptr) && (Courant->Suivant != nullptr);
}

template <typename Objet>
int Liste<Objet>::Longueur() const {
	int cpt = 0;
	for (noeud<Objet> * temp = Tete->Suivant; temp != nullptr; temp = temp->Suivant)
		cpt++; 
	return cpt;
}

template <typename Objet>
void Liste<Objet>::FixerPosition(const int pos) {
	Courant = Tete;
	for (int i = 0; (Courant != nullptr) && (i < pos); i++)
		Courant = Courant->Suivant;
}