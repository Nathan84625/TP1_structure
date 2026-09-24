#include "Commande.h" // Donne accès à la classe Commande.
Commande::Commande()
{
    source = ""; // La commande commence sans client source.
    destinataire = ""; // La commande commence sans destinataire.
}
Commande::Commande(std::string source, std::string destinataire)
{
    this -> source = source;
    this->destinataire = destinataire;
}

Commande::~Commande()
{
   
}

std::string Commande::getSource() const
{
    return source; // Retourne le nom du client qui a fait la commande.

}

std::string Commande::getDestinataire() const
{
    return destinataire; // Retourne le nom du client qui reçoit la commande.
}
