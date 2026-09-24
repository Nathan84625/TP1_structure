#pragma once // Empeche le fichier d'etre inclus plusieurs fois.
#include <string> // Necessaire parce que le nom du biscuit est du texte.
using namespace std;

class Biscuit
{
private:
    string nom; // Code original : contient le nom/type du biscuit.
    int nombre; // Code original : contient la quantite de ce biscuit.

public:
    Biscuit(); // Code original : permet de créer un Biscuit vide.
    Biscuit(string nom, int nombre); // AJOUT : permet de créer directement un biscuit avec son nom et sa quantité.
    ~Biscuit(); // Code original : destructeur de l'objet Biscuit.
    string getNom() const; // AJOUT : permet de lire le nom puisque nom est private.
};