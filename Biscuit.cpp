#include "Biscuit.h" 
// (#include <string>) // déjà inclus par Biscuit.h.
// (#include <fstream>) // inutile ici parce qu'on ne lit pas de fichier dans Biscuit.cpp.

Biscuit::Biscuit()
{
    nom = ""; // Initialise le nom à vide parce qu'aucun biscuit n'a encore été donné.
    nombre = 0; // Initialise la quantité à 0 pour éviter une valeur inconnue.
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

int Biscuit::getNombre() const
{
    return nombre; // Donne comme résultat la quantité du biscuit.
}

void Biscuit::addNombre(int nombre) {
    this->nombre += nombre;
}
