
#pragma once LISTECOMMANDES_H

#include <iostream>
#include <fstream>
#include <string>

#include "Client.h"


/*
 * Classe ListeCommandes
 *
 * Elle contient une liste chaînée de clients.
 *
 * Chaque client contient lui-même
 * une liste chaînée de commandes.
 */
class ListeCommandes
{
private:

    // Premier client de la liste
    Client* premier;


    /*
     * Chercher un client par son nom.
     *
     * Retourne :
     *
     * - le pointeur vers le client
     * - nullptr si le client n'existe pas
     */
    Client* rechercherClient(std::string nom) const;


    /*
     * Supprimer toutes les données
     * présentes dans la liste.
     */
    void vider();


public:

    // Constructeur
    ListeCommandes();

    // Destructeur
    ~ListeCommandes();


    // ========================================================
    // FONCTIONNALITÉ 1
    // ========================================================

    /*
     * Charger les clients et leurs commandes
     * à partir de deux fichiers.
     */
    bool charger(std::string fichierClients,
        std::string fichierCommandes);


    /*
     * Sauvegarder les clients et leurs commandes
     * dans deux fichiers.
     */
    bool sauvegarder(std::string fichierClients,
        std::string fichierCommandes) const;


    // ========================================================
    // FONCTIONNALITÉ 2
    // ========================================================

    /*
     * Ajouter un client à la liste.
     */
    bool ajouterClient(std::string nom,
        int numero,
        std::string rue);


    /*
     * Supprimer un client de la liste.
     */
    bool supprimerClient(std::string nom);


    // Afficher les clients
    void afficherClients() const;
};


