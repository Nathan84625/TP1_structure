#pragma once // Empêche plusieurs inclusions du même fichier.
#include <string> // Nécessaire parce que source et destinataire sont du texte.
#include "Biscuit.h" // Nécessaire parce qu'une commande contient des objets Biscuit.
// (#include <Client.h>) // Code original : pas nécessaire ici car on conserve seulement le nom des clients.
// (#include "Liste.h") // Code original : la liste interne de biscuits sera gérée directement dans Commande.
using namespace std;
class Commande
{
private:
    // (Liste client;) // Code original 
    // (Liste biscuits;) // Code original.
    string source; // AJOUT : contient le nom du client qui fait la commande.
    string destinataire; // AJOUT : contient le nom du client qui reçoit la commande.
    
public:
    Commande(); // Code original : constructeur vide.
    Commande(string source, string destinataire); // AJOUT : permet de créer directement une commande avec les deux clients.
    ~Commande(); // Code original : destructeur.
    string getSource() const; // AJOUT : permet de connaître le client qui a fait la commande.
    string getDestinataire() const; // AJOUT : permet de connaître le client qui reçoit la commande.
};