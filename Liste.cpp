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

string Liste::ChargerClients(const string nomFichierClients)
{
	ifstream entree;
	string nom;
	string numeroCivique;
	string rue;
	string resultat;


	entree.open(nomFichierClients, ios::in);
	if (entree)
	{
		getline(entree, nom);
		getline(entree, numeroCivique);
		getline(entree, rue);
		resultat =  nom  + numeroCivique  + rue;
	}
	entree.close();
	return resultat;
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