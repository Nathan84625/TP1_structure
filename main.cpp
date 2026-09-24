#include <iostream>
#include "Liste.h"
#include "Client.h"
#include <string>
#include<fstream>

using namespace std;

/// @brief Charge les clients à partir d'un fichier.
/// @param nomFichierClients Le nom du fichier contenant les clients.
/// @return La liste des cleints chargés à partir du fichier.
void ChargerClients(const string nomFichierClients, Liste<Client>& clients)
{
	ifstream entree;
	string nom;
	string numeroCivique;
	string rue;
	entree.open(nomFichierClients, ios::in);
	if (entree)
	{
        while(entree.peek() != EOF)
        {
		getline(entree, nom);
		getline(entree, numeroCivique);
		getline(entree, rue);
        clients.Inserer(Client(nom, rue, stoi(numeroCivique)));
        }
	entree.close();
    }
}

void SauvegarderClients(Liste<Client> & listeClient, const string nomFichierClients)
{
    ofstream sortie;

    sortie.open(nomFichierClients,  fstream::app);

    if(sortie)
    {
        for (int i = 0; i < listeClient.Longueur(); i++)
        {
            listeClient.FixerPosition(i);
            sortie << listeClient.ValeurCourante().getNom() << endl;
            sortie << listeClient.ValeurCourante().getNumero() << endl;
            sortie << listeClient.ValeurCourante().getAdresse() << endl;
        }
    }
}
int main()
{
    Liste<Client> listeClient;
    string option = "0";
    int choix = 0;
    bool continuer = true;
    string nomFichierClients = "CLIENTS.txt";
    string nomFichierCommandes = "COMMANDES.txt";
    // À enlever éventuellement, sert de test pour vérifier que le fichier se remplis
    Liste<Client> listeTest;
    Client clientTest("Test", "123 rue test", 123);
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
        // Charger la liste des clients et leurs commandes
           ChargerClients(nomFichierClients,listeClient);
        // À enlever éventuellement, sert de test pour vérifier que la liste est bien remplie
           for (int i = 0; i < listeClient.Longueur() ; i++)
           {
            listeClient.FixerPosition(i);
            cout << listeClient.ValeurCourante().getNom() << endl;
           }
            break;
        case 2:
        
        listeTest.Inserer(clientTest);
        // Sauvegarder la liste des clients et leurs commandes
            SauvegarderClients(listeTest, nomFichierClients);
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

