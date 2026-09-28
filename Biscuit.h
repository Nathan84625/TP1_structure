#pragma once
#include <string>
class Biscuit
{
private:
    std::string nom; // contient le type du biscuit.
    int nombre; // contient la quantité de ce biscuit.
public:
    Biscuit();  //permet de créer un Biscuit vide.
    Biscuit(std::string nom, int nombre); // AJOUT : permet de créer directement un biscuit avec son nom et sa quantité.
    ~Biscuit(); // destructeur.
    std::string getNom() const; // AJOUT : permet de connaître le nom parce que nom est private.
    int getNombre() const; // AJOUT : permet de connaître la quantité parce que nombre est private.
};
