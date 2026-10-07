#include "Biscuit.h" 

Biscuit::Biscuit()
{
    nom = ""; 
    nombre = 0; 
}
Biscuit::Biscuit(std::string nom, int nombre)
{
    this->nom = nom; 
    this->nombre = nombre; 
}
Biscuit::~Biscuit()
{
}

std::string Biscuit::getNom() const
{
    return nom; 
}

int Biscuit::getNombre() const
{
    return nombre; 
}

void Biscuit::addNombre(int nombre) 
{
    this->nombre += nombre;
}
