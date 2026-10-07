#pragma once 
#include <string> 
#include "Client.h"
#include "Biscuit.h"
#include "Liste.h" 
using namespace std;

class Commande
{
private:
    string source; 
    string destinataire; 
    Liste<Biscuit> biscuits; 

public:
    Commande();
    Commande(std::string source, std::string destinataire, Liste<Biscuit> listeBiscuits);
    ~Commande(); 
    std::string getSource() const; 
    std::string getDestinataire() const; 
    void ajouterBiscuit(Biscuit biscuit); 
    int nombreBiscuits() const; 
    Biscuit getBiscuit(int position); 
    Liste <Biscuit> getBiscuits();
};
