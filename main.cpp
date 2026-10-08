#include <fstream>
#include <iostream>
#include <string>
#include "ListeCommandes.h"
using namespace std;

int main()
{
   

    ifstream transactions("TRANSACTION.txt");

  
    ListeCommandes gestion;
    string operation;
    while (transactions >> operation)
    {
        if (operation == "O")
        {
            string nomFichierClients;
            string nomFichierCommandes;
            transactions >> nomFichierClients >> nomFichierCommandes;
            if (gestion.ChargerListes(nomFichierClients, nomFichierCommandes))
            {
                cout << "Les fichiers " << nomFichierClients << " et " << nomFichierCommandes << " ont ete charges." << endl;
            }
        }

        else if (operation == "S")
        {
            string nomFichierClients;
            string nomFichierCommandes;
            transactions >> nomFichierClients >> nomFichierCommandes;
            if (gestion.SauvegarderListes(nomFichierClients, nomFichierCommandes))
            {
                cout << "Les fichiers "  << nomFichierClients << " et " << nomFichierCommandes << " ont ete sauvegardes." << endl;   
            }
        }

        else if (operation == "+")
        {
            string nom;
            int numero;
            string adresse;
            transactions >> nom >> numero >> adresse;
            if (gestion.AjouterClient(nom, numero, adresse))
            {
                cout << "Le client "  << nom << " a ete ajoute." << endl;
            }
        }

        else if (operation == "-")
        {
            string nom;
            transactions >> nom;
            if (gestion.SupprimerClient(nom))
            {
                cout << "Le client "  << nom << " a ete supprime ainsi que ses commandes associees."  << endl;
            }
        }

        else if (operation == "=")
        {
            string source;
            string destinataire;
            Liste<Biscuit> biscuits;
            transactions >> source >> destinataire;
            string nomBiscuit;
            while (transactions >> nomBiscuit &&
                   nomBiscuit != "&")
            {
                int quantite;
                transactions >> quantite;
                biscuits.FixerPosition(
                    biscuits.Longueur()
                );
                biscuits.Inserer(
                    Biscuit(nomBiscuit, quantite)
                );
            }

            if (gestion.AjouterCommande(source, destinataire, biscuits))
            {
                cout << "La commande de " << source << " vers " << destinataire  << " a ete ajoutee." << endl;
            }
        }

        else if (operation == "?")
        {
            string nom;
            transactions >> nom;
            cout << "Commandes effectuees par "<< nom << " :" << endl;
            gestion.AfficherCommandes(nom);
            cout << "L'operation ? pour "    << nom << " a ete effectuee."   << endl;
        }

        else if (operation == "$")
        {
            cout << "Statistiques des biscuits :"   << endl;
            gestion.TrouverBiscuitPopulaire();
        }

        else if (operation == "#")
        {
            gestion.CalculerNombreBiscuits();
        }

        else
        {
            cout << "Operation invalide : "<< operation << endl;
        }
        cout << endl;
    }
    transactions.close();
    return 0;
}
