#include "Commande.h"


// ============================================================
// CLASSE BISCUIT
// ============================================================

Biscuit::Biscuit(std::string typeBiscuit,
    int qte)
{
    type = typeBiscuit;
    quantite = qte;

    // Aucun biscuit suivant
    suivant = nullptr;
}


std::string Biscuit::getType() const
{
    return type;
}


int Biscuit::getQuantite() const
{
    return quantite;
}


Biscuit* Biscuit::getSuivant() const
{
    return suivant;
}


void Biscuit::setSuivant(Biscuit* nouveauSuivant)
{
    suivant = nouveauSuivant;
}


// ============================================================
// CLASSE COMMANDE
// ============================================================

Commande::Commande(std::string nomDestinataire)
{
    destinataire = nomDestinataire;

    // Aucune liste de biscuits au départ
    biscuits = nullptr;

    // Aucune commande suivante
    suivante = nullptr;
}


// ============================================================
// DESTRUCTEUR
// ============================================================

Commande::~Commande()
{
    /*
     * Supprimer tous les biscuits
     * de cette commande.
     */

    Biscuit* courant = biscuits;

    while (courant != nullptr)
    {
        Biscuit* temporaire = courant;

        courant = courant->getSuivant();

        delete temporaire;
    }

    biscuits = nullptr;
}


// ============================================================
// GETTERS
// ============================================================

std::string Commande::getDestinataire() const
{
    return destinataire;
}


Biscuit* Commande::getBiscuits() const
{
    return biscuits;
}


Commande* Commande::getSuivante() const
{
    return suivante;
}


// ============================================================
// SETTER
// ============================================================

void Commande::setSuivante(Commande* nouvelleSuivante)
{
    suivante = nouvelleSuivante;
}


// ============================================================
// AJOUTER UN BISCUIT
// ============================================================

void Commande::ajouterBiscuit(std::string typeBiscuit,
    int quantite)
{
    Biscuit* nouveau =
        new Biscuit(typeBiscuit, quantite);


    /*
     * Si aucun biscuit n'existe encore.
     */

    if (biscuits == nullptr)
    {
        biscuits = nouveau;
        return;
    }


    /*
     * Chercher le dernier biscuit.
     */

    Biscuit* courant = biscuits;

    while (courant->getSuivant() != nullptr)
    {
        courant = courant->getSuivant();
    }


    courant->setSuivant(nouveau);
}