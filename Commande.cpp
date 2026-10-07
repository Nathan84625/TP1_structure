#include "Commande.h" 
#include "liste.h" 

Commande::Commande()
{
    source = ""; 
    destinataire = ""; 
}

Commande::Commande(std::string source, std::string destinataire, Liste<Biscuit> listeBiscuits)
{
    this->source = source; 
    this->destinataire = destinataire; 
    this->biscuits = listeBiscuits;
}

Commande::~Commande()
{
}


std::string Commande::getSource() const
{
    return source; 
}


std::string Commande::getDestinataire() const
{
    return destinataire; 
}


void Commande::ajouterBiscuit(Biscuit biscuit)
{
    biscuits.FixerPosition(biscuits.Longueur()); 
    biscuits.Inserer(biscuit); 
}


int Commande::nombreBiscuits() const
{
    return biscuits.Longueur(); 
}


Biscuit Commande::getBiscuit(int position)
{
    biscuits.FixerPosition(position); 
    return biscuits.ValeurCourante(); 
}

Liste<Biscuit> Commande::getBiscuits()
{
    return biscuits;
}
