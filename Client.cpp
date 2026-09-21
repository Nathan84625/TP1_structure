#include "Client.h"
#include <string>
#include <fstream>

Client::Client()
{
    nom = "";
    adresse = "";
}
Client::Client(string nom, string adresse, int numero)
{
    this->nom = nom;
    this->adresse = adresse;
    this->numero = numero;
}

Client::~Client()
{
}
