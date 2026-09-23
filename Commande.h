#pragma once // Empêche plusieurs inclusions du même fichier.
#include <string> // Nécessaire parce que source et destinataire sont du texte.
#include "Biscuit.h" // Nécessaire parce qu'une commande contient des objets Biscuit.
// (#include <Client.h>) // Code original : pas nécessaire ici car on conserve seulement le nom des clients.
// (#include "Liste.h") // Code original : la liste interne de biscuits sera gérée directement dans Commande.
class Commande
{
private:
    // (Liste client;) // Code original 
    // (Liste biscuits;) // Code original.
    std::string source; // AJOUT : contient le nom du client qui fait la commande.
    std::string destinataire; // AJOUT : contient le nom du client qui reçoit la commande.
    struct NoeudBiscuit // AJOUT : représente une case de la liste chaînée des biscuits.
    {
        Biscuit biscuit; // Stocke le biscuit, donc son nom et sa quantité.

        NoeudBiscuit* suivant; // Stocke l'adresse du prochain biscuit pour relier les noeuds.
    };
    NoeudBiscuit* teteBiscuits; // AJOUT : pointe vers le premier biscuit de la commande ; nullptr signifie aucun biscuit.
public:
    Commande(); // Code original : constructeur vide.
    Commande(std::string source, std::string destinataire); // AJOUT : permet de créer directement une commande avec les deux clients.
    Commande(const Commande& autre); // AJOUT : crée une vraie copie des biscuits lorsqu'une Commande est copiée.
    ~Commande(); // Code original : destructeur.
    Commande& operator=(const Commande& autre); // AJOUT : permet de copier correctement une Commande avec =.
    std::string getSource() const; // AJOUT : permet de connaître le client qui a fait la commande.
    std::string getDestinataire() const; // AJOUT : permet de connaître le client qui reçoit la commande.
    void ajouterBiscuit(Biscuit biscuit); // AJOUT : ajoute un biscuit à la fin de la commande.
    int nombreBiscuits() const; // AJOUT : compte combien de types de biscuits sont présents.
    Biscuit getBiscuit(int position) const; // AJOUT : récupère un biscuit selon sa position pour pouvoir parcourir les biscuits.
};