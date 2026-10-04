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


// CONSTRUCTEUR DE COPIE // AJOUT DE NOTRE PART
template <typename Objet>
Liste<Objet>::Liste(const Liste<Objet>& autre)
{
    Tete = new noeud<Objet>; // AJOUT : crée un nouveau noeud d'en-tête parce que la copie doit avoir sa propre mémoire.
    Queue = Tete; // AJOUT : au départ, aucun vrai élément n'a encore été copié, donc Queue est sur l'en-tête.
    Courant = Tete; // AJOUT : Courant commence également sur l'en-tête.
    noeud<Objet>* temp = autre.Tete->Suivant; // AJOUT : temp commence au premier vrai élément de la Liste que l'on veut copier.
    while (temp != nullptr) // AJOUT : continue tant qu'il reste un Objet dans l'ancienne Liste.
    {
        Courant = Queue; // AJOUT : place Courant à la fin pour ajouter le prochain Objet après les précédents.
        Inserer(temp->element); // AJOUT : crée un nouveau noeud contenant une copie de l'Objet actuel.
        temp = temp->Suivant; // AJOUT : avance au prochain noeud de l'ancienne Liste.
    }
    Courant = Tete; // AJOUT : une fois la copie terminée, replace Courant au début.
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



//OPÉRATEUR = AJOUT
template <typename Objet>
Liste<Objet>& Liste<Objet>::operator=(const Liste<Objet>& autre)
{
    if (this != &autre) // AJOUT : évite de détruire la Liste si on écrit par erreur liste = liste.
    {
        while (Tete != nullptr) // AJOUT : supprime d'abord les anciens noeuds de cette Liste.
        {
            Courant = Tete; // AJOUT : garde l'adresse du noeud qu'on va supprimer.
            Tete = Tete->Suivant; // AJOUT : avance vers le prochain noeud avant de faire delete.
            delete Courant; // AJOUT : libère l'ancien noeud.
        }

        Tete = new noeud<Objet>; // AJOUT : recrée un noeud d'en-tête vide pour recevoir la nouvelle copie.
        Queue = Tete; // AJOUT : aucun vrai Objet n'a encore été copié.
        Courant = Tete; // AJOUT : Courant recommence au début.

        noeud<Objet>* temp = autre.Tete->Suivant; // AJOUT : commence au premier vrai Objet de la Liste à copier.
        while (temp != nullptr) // AJOUT : continue jusqu'à avoir copié toute l'autre Liste.
        {
            Courant = Queue; // AJOUT : se place à la fin de notre nouvelle Liste.
            Inserer(temp->element); // AJOUT : crée un nouveau noeud contenant une copie de l'Objet.
            temp = temp->Suivant; // AJOUT : passe au prochain Objet.
        }
        Courant = Tete; // AJOUT : replace Courant au début une fois la copie terminée.
    }
    return *this; // AJOUT : retourne la Liste qui vient de recevoir les nouvelles valeurs.
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
Objet& Liste<Objet>::ValeurCourante() {
    assert(EstDansListe());
    return Courant->Suivant->element;
}

template <typename Objet>
const Objet& Liste<Objet>::ValeurCourante() const {
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
template <typename Objet>
void Liste<Objet>::Supprimer()
{
    assert(EstDansListe());

    noeud<Objet>* aSupprimer = Courant->Suivant;

    Courant->Suivant = aSupprimer->Suivant;

    if (aSupprimer == Queue)
    {
        Queue = Courant;
    }

    delete aSupprimer;
}

template <typename Objet>
bool Liste<Objet>::Trouver(const Objet & valeur) { // recherche la valeur � partir
											   // de la position courante
	while (EstDansListe())
		if (Courant->Suivant->element == valeur)
			return true;
		else
			Courant = Courant->Suivant;
	return false;
}
