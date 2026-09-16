#include "Liste.h"
#include <string>
#include <fstream>

using namespace std;

// Constructeur
Liste::Liste()
{
	Queue = Tete = Courant = new noeud; // crée le noeud entete
}

// Destructeur
Liste::~Liste()
{
	while (Tete != nullptr)
	{
		Courant = Tete;
		Tete = Tete->Suivant;
		delete Courant;
	}
}

void Liste::FixerTete()
{
	Courant = Tete;
}

void Liste::Inserer(const TElement &element)
{

	Courant->Suivant = new noeud(element, Courant->Suivant);
	if (Queue == Courant)
		Queue = Courant->Suivant; // l'�l�ment est ajout� � la fin de la liste.
}