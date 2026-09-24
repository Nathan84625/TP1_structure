#include "Biscuit.h" // Donne accès à la classe Biscuit.
// (#include <string>) // Code original : pas nécessaire ici puisque Biscuit.h l'inclut déjà.
// (#include <fstream>) // Code original : pas nécessaire ici car ce fichier ne lit aucun fichier texte.

Biscuit::Biscuit()
{
    nom = ""; // Initialise le nom à vide parce qu'aucun type n'a encore été donné.
    nombre = 0; // Initialise la quantité à 0 pour éviter une valeur indéterminée.
}
Biscuit::Biscuit(std::string nom, int nombre)
{
    this->nom = nom; // Remplit la case nom de CET objet avec le nom reçu.
    this->nombre = nombre; // Remplit la case nombre avec la quantité reçue.
}
Biscuit::~Biscuit()
{
    // Rien à supprimer ici parce que Biscuit ne crée aucune mémoire avec new.
}
std::string Biscuit::getNom() const
{
    return nom; // Donne comme résultat le nom du biscuit.
}
