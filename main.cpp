#include <iostream>
#include "Liste.h"
#include <string>
#include<fstream>

using namespace std;


string ChargerClients(const string nomFichierClients)
{
	ifstream entree;
	string nom;
	string numeroCivique;
	string rue;
	string resultat;


	entree.open(nomFichierClients, ios::in);
	if (entree)
	{
		getline(entree, nom);
		getline(entree, numeroCivique);
		getline(entree, rue);
		resultat =  nom  + numeroCivique  + rue;
	}
	entree.close();
	return resultat;
}

int main()
{
    Liste listeClient;
    string option = "0";
    int choix = 0;
    bool continuer = true;
    string nomFichierClients = "CLIENTS.txt";
    string nomFichierCommandes = "COMMANDES.txt";
    string resultat = "";
    do
    {
        cout << "Choisisser une option : " << endl;
        cout << " 1) Charger la liste des clients et leurs commandes" << endl;
        cout << " 2) Sauvegarder la liste des clients et leurs commandes" << endl;
        cout << " 3) Ajouter un client de la liste." << endl;
        cout << " 4) Supprimer un client de la liste." << endl;
        cout << " 5) Faire une commande et l'ajouter à la liste des commandes." << endl;
        cout << " 6) Afficher toutes les commandes faites par un client" << endl;
        cout << " 7) Afficher le type de biscuit le plus populaire et le montant total reçu pour ce dernier." << endl;
        cout << " 8) Quitter" << endl;

        cin >> option;
        try
        {
             choix = std::stoi(option);
        }
        catch (...)
        {
          choix = 0;
        }
        switch (choix)
        {
        case 1:
           resultat = ChargerClients(nomFichierClients);
           cout << resultat << endl;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            continuer = false;
            break;
        default:
            cout << "Option invalide, veuillez choisir une option entre 1 et 8" << endl;
        }
    } while (continuer);


}

