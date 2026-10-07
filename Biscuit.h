#pragma once
#include <string>
class Biscuit
{
private:
    std::string nom; 
    int nombre; 
public:
    Biscuit();  
    Biscuit(std::string nom, int nombre); 
    ~Biscuit(); 
    std::string getNom() const; 
    int getNombre() const; 
    void addNombre(int nombre);
};
