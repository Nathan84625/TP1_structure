#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Commande.h"

class Client
{
private:
    std::string nom;
    int numero;
    std::string rue;

    // Liste chaînée des commandes du client
    Commande* commandes;

    // Pointeur vers le client suivant
    Client* suivant;

public:
    // Constructeur
    Client(std::string nom, int numero, std::string rue);

    // Destructeur
    ~Client();

    // Getters
    std::string getNom() const;
    int getNumero() const;
    std::string getRue() const;

    Commande* getCommandes() const;
    Client* getSuivant() const;

    // Setters
    void setSuivant(Client* suivant);

    // Ajouter une commande au client
    void ajouterCommande(Commande* commande);
};

#endif