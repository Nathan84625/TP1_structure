#include "Commande.h" // Donne accès à la classe Commande.
Commande::Commande()
{
    source = ""; // La commande commence sans client source.
    destinataire = ""; // La commande commence sans destinataire.
    teteBiscuits = nullptr; // Aucun biscuit n'existe encore, donc la tête ne pointe vers rien.
}
Commande::Commande(std::string source, std::string destinataire)
{
    this->source = source; // Remplit la case source avec le client reçu.
    this->destinataire = destinataire; // Remplit la case destinataire avec le client reçu.
    teteBiscuits = nullptr; // La nouvelle commande ne contient encore aucun biscuit.
}
Commande::Commande(const Commande& autre)
{
    source = autre.source; // Copie le nom du client source.
    destinataire = autre.destinataire; // Copie le destinataire.
    teteBiscuits = nullptr; // Commence avec une nouvelle liste vide pour ne pas partager les mêmes noeuds.
    NoeudBiscuit* courant = autre.teteBiscuits; // Commence au premier biscuit de la commande à copier.
    while (courant != nullptr) // Continue tant qu'il reste un biscuit à copier.
    {
        ajouterBiscuit(courant->biscuit); // Crée une nouvelle copie du biscuit dans cette commande.
        courant = courant->suivant; // Passe au biscuit suivant.
    }
}
Commande::~Commande()
{
    NoeudBiscuit* courant = teteBiscuits; // Commence au premier biscuit pour pouvoir libérer toute la liste.
    while (courant != nullptr) // Continue tant qu'il reste un noeud créé avec new.
    {
        NoeudBiscuit* suivant = courant->suivant; // Sauvegarde l'adresse suivante avant de supprimer courant.
        delete courant; // Libère la case mémoire du biscuit actuel.
        courant = suivant; // Continue avec le prochain noeud.
    }
}
Commande& Commande::operator=(const Commande& autre)
{
    if (this != &autre) // Vérifie qu'on ne fait pas commande = commande.
    {
        NoeudBiscuit* courant = teteBiscuits; // Commence au premier ancien biscuit.
        while (courant != nullptr) // Supprime les anciens biscuits avant de copier les nouveaux.
        {
            NoeudBiscuit* suivant = courant->suivant; // Sauvegarde le noeud suivant.
            delete courant; // Libère le noeud actuel.
            courant = suivant; // Passe au suivant.
        }
        teteBiscuits = nullptr; // La liste est maintenant vide.
        source = autre.source; // Copie le nouveau client source.
        destinataire = autre.destinataire; // Copie le nouveau destinataire.
        courant = autre.teteBiscuits; // Commence au premier biscuit de la commande à copier.
        while (courant != nullptr) // Copie tous ses biscuits.
        {
            ajouterBiscuit(courant->biscuit); // Crée une copie indépendante du biscuit.
            courant = courant->suivant; // Passe au suivant.
        }
    }
    return *this; // Retourne la commande qui vient d'être modifiée.
}

std::string Commande::getSource() const
{
    return source; // Retourne le nom du client qui a fait la commande.

}

std::string Commande::getDestinataire() const
{
    return destinataire; // Retourne le nom du client qui reçoit la commande.
}

void Commande::ajouterBiscuit(Biscuit biscuit)
{
    NoeudBiscuit* nouveau = new NoeudBiscuit; // Crée une nouvelle case mémoire parce qu'on ajoute un biscuit.
    nouveau->biscuit = biscuit; // Remplit la case biscuit avec le biscuit reçu.
    nouveau->suivant = nullptr; // Le nouveau biscuit sera le dernier, donc rien ne vient encore après lui.
    if (teteBiscuits == nullptr) // Vérifie si aucun biscuit n'est encore présent.
    {
        teteBiscuits = nouveau; // Le nouveau devient le premier biscuit de la commande.
    }
    else // Il existe déjà au moins un biscuit.
    {
        NoeudBiscuit* courant = teteBiscuits; // Commence au premier pour chercher le dernier.
        while (courant->suivant != nullptr) // Continue tant qu'il existe encore un biscuit après courant.
        {
            courant = courant->suivant; // Avance au biscuit suivant.
        }
        courant->suivant = nouveau; // Relie l'ancien dernier biscuit au nouveau.
    }
}

int Commande::nombreBiscuits() const
{
    int compteur = 0; // Commence à 0 parce qu'aucun noeud n'a encore été compté.
    NoeudBiscuit* courant = teteBiscuits; // Commence au premier biscuit.
    while (courant != nullptr) // Parcourt toute la liste jusqu'à nullptr.
    {
        compteur++; // Ajoute 1 parce qu'un biscuit vient d'être rencontré.
        courant = courant->suivant; // Passe au biscuit suivant.
    }
    return compteur; // Retourne le nombre de types de biscuits présents.
}

Biscuit Commande::getBiscuit(int position) const
{
    NoeudBiscuit* courant = teteBiscuits; // Commence au premier biscuit parce qu'une liste chaînée se parcourt depuis le début.
    int compteur = 0; // Représente la position du noeud actuel.
    while (courant != nullptr) // Continue tant qu'on n'a pas atteint la fin.
    {
        if (compteur == position) // Vérifie si on est arrivé à la position demandée.
        {
            return courant->biscuit; // Retourne le biscuit trouvé.
        }
        compteur++; // Passe à la position suivante.
        courant = courant->suivant; // Avance au noeud suivant.
    }
    return Biscuit(); // Si la position n'existe pas, retourne un Biscuit vide.
}