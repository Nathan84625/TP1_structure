#pragma once 
#include <string> 
#include "Client.h"
#include "Biscuit.h"
#include "Liste.h" // nécessaire pour utiliser la classe template Liste.

class Commande
{
private:
    // (Liste client;)
    std::string source; // MODIFICATION : contient le nom du client qui fait la commande.
    std::string destinataire; // AJOUT : contient le nom du client qui reçoit la commande.
    // (Liste biscuits;) 
    Liste<Biscuit> biscuits; // MODIFICATION : <Biscuit> indique que cette Liste contient des objets Biscuit.
public:
    Commande(); // constructeur vide.
    Commande(std::string source, std::string destinataire, Liste<Biscuit> listeBiscuits); // AJOUT : crée une commande avec sa source et son destinataire.
    ~Commande(); // destructeur.
    std::string getSource() const; // AJOUT : permet de connaître le client qui a fait la commande.
    std::string getDestinataire() const; // AJOUT : permet de connaître le destinataire.
    void ajouterBiscuit(Biscuit biscuit); // AJOUT : ajoute un Biscuit dans la Liste<Biscuit>.
    int nombreBiscuits() const; // AJOUT : retourne combien de types de biscuits sont dans la commande.
    Biscuit getBiscuit(int position); // AJOUT : permet de récupérer un biscuit selon sa position.
    Liste <Biscuit> getBiscuits();
};
