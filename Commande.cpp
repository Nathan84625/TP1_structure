#include "Commande.h" // Donne accès à Commande, Biscuit et Liste.
#include "liste.h" // Donne accès à Commande, Biscuit et Liste.

Commande::Commande()
{
    source = ""; // Aucune source n'a encore été donnée.
    destinataire = ""; // Aucun destinataire n'a encore été donné.
    
    // La variable biscuits se construit automatiquement comme une Liste<Biscuit> vide.
    
}
Commande::Commande(std::string source, std::string destinataire, Liste<Biscuit> listeBiscuits)
{
    this->source = source; // La case source reçoit le nom du client qui fait la commande.
    this->destinataire = destinataire; // La case destinataire reçoit le nom du client qui reçoit la commande.
    this->biscuits = listeBiscuits;
    // biscuits est automatiquement créé comme une Liste<Biscuit> vide.
}

Commande::~Commande()
{
    // Rien à supprimer directement ici.
    // La classe Liste possède déjà son propre destructeur.
}


std::string Commande::getSource() const
{
    return source; // Donne comme résultat le nom du client source.
}


std::string Commande::getDestinataire() const
{
    return destinataire; // Donne comme résultat le nom du destinataire.
}


void Commande::ajouterBiscuit(Biscuit biscuit)
{
    biscuits.FixerPosition(biscuits.Longueur()); // Place Courant à la fin de la liste parce qu'on veut ajouter le biscuit après les autres.
    biscuits.Inserer(biscuit); // Utilise la fonction Inserer du collègue pour ajouter le Biscuit dans Liste<Biscuit>.
}


int Commande::nombreBiscuits() const
{
    return biscuits.Longueur(); // Utilise Longueur() du collègue pour connaître le nombre de biscuits.
}


Biscuit Commande::getBiscuit(int position)
{
    biscuits.FixerPosition(position); // Déplace Courant à la position demandée.
    return biscuits.ValeurCourante(); // Donne comme résultat le Biscuit situé à cette position.
}

Liste<Biscuit> Commande::getBiscuits()
{
    return biscuits;
}
