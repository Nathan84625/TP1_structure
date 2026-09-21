#pragma once
#include <string>
using namespace std;

class Client {

private:
    string nom;
    string adresse;
    int numero;
public:
    Client();
    Client(string nom, string adresse, int numero);
    ~Client();
    string getNom() const { return nom; }
    string getAdresse() const { return adresse; }
    int getNumero() const { return numero; }
};