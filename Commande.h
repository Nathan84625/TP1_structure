#pragma once 
#include <string> 
#include "Client.h"
#include "Biscuit.h"
#include "Liste.h" 
using namespace std;

class Commande
{
private:
    string source; //contient le nom du client qui fait la commande.
    string destinataire; // contient le nom du client qui reçoit la commande.
    Liste<Biscuit> biscuits; //<Biscuit> indique que cette Liste contient des objets Biscuit.

public:
    Commande(); // constructeur vide.
    Commande(std::string source, std::string destinataire, Liste<Biscuit> listeBiscuits); // crée une commande avec sa source et son destinataire.
    ~Commande(); // destructeur.
    std::string getSource() const; // permet de connaître le client qui a fait la commande.
    std::string getDestinataire() const; // permet de connaître le destinataire.
    void ajouterBiscuit(Biscuit biscuit); // ajoute un Biscuit dans la Liste<Biscuit>.
    int nombreBiscuits() const; // retourne combien de types de biscuits sont dans la commande.
    Biscuit getBiscuit(int position); // permet de récupérer un biscuit selon sa position.
    Liste <Biscuit> getBiscuits();
};
