#include "Client.h"


// ============================================================
// CONSTRUCTEUR
// ============================================================

Client::Client(std::string nomClient,
    int numeroCivique,
    std::string nomRue)
{
    nom = nomClient;
    numero = numeroCivique;
    rue = nomRue;

    // Au départ, le client n'a aucune commande
    commandes = nullptr;

    // Au départ, aucun client après celui-ci
    suivant = nullptr;
}


// ============================================================
// DESTRUCTEUR
// ============================================================

Client::~Client()
{
    /*
     * On supprime toutes les commandes
     * appartenant au client.
     */

    Commande* courant = commandes;

    while (courant != nullptr)
    {
        Commande* temporaire = courant;

        courant = courant->getSuivante();

        delete temporaire;
    }

    commandes = nullptr;
}


// ============================================================
// GETTERS
// ============================================================

std::string Client::getNom() const
{
    return nom;
}


int Client::getNumero() const
{
    return numero;
}


std::string Client::getRue() const
{
    return rue;
}


Commande* Client::getCommandes() const
{
    return commandes;
}


Client* Client::getSuivant() const
{
    return suivant;
}


// ============================================================
// SETTER
// ============================================================

void Client::setSuivant(Client* nouveauSuivant)
{
    suivant = nouveauSuivant;
}


// ============================================================
// AJOUTER UNE COMMANDE
// ============================================================

void Client::ajouterCommande(Commande* commande)
{
    /*
     * Si le client n'a encore aucune commande,
     * la nouvelle commande devient la première.
     */

    if (commandes == nullptr)
    {
        commandes = commande;
        return;
    }


    /*
     * Sinon, on parcourt la liste des commandes
     * jusqu'à la dernière.
     */

    Commande* courant = commandes;

    while (courant->getSuivante() != nullptr)
    {
        courant = courant->getSuivante();
    }


    // Ajouter la nouvelle commande à la fin
    courant->setSuivante(commande);
}
