#pragma once COMMANDE_H

#include <string>


/*
 * Représente un type de biscuit dans une commande.
 *
 * Exemple :
 *
 * Chocolat 20
 *
 * type = Chocolat
 * quantite = 20
 */
class Biscuit
{
private:
    std::string type;
    int quantite;

    // Biscuit suivant dans la liste
    Biscuit* suivant;

public:
    Biscuit(std::string type, int quantite);

    std::string getType() const;
    int getQuantite() const;

    Biscuit* getSuivant() const;
    void setSuivant(Biscuit* suivant);
};



/*
 * Représente une commande.
 *
 * Une commande contient :
 *
 * - un destinataire
 * - une liste de biscuits
 * - une commande suivante
 */
class Commande
{
private:
    std::string destinataire;

    // Première biscuit de la commande
    Biscuit* biscuits;

    // Commande suivante
    Commande* suivante;

public:
    Commande(std::string destinataire);

    // Destructeur
    ~Commande();

    std::string getDestinataire() const;

    Biscuit* getBiscuits() const;

    Commande* getSuivante() const;
    void setSuivante(Commande* suivante);

    // Ajouter un biscuit
    void ajouterBiscuit(std::string type, int quantite);
};

