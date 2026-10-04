#include <iostream>
#include "Liste.h"
#include "Client.h"
#include "Commande.h"
#include "Biscuit.h"
#include <string>
#include <fstream>

using namespace std;

    ifstream entree;
    string commande;
    entree.open(argv[1], ios::in);
    if (entree)
    {
        cout << "Fichier ouvert avec succes" << endl;
        Liste<Client> listeClient;
        Liste<Commande> listeCommande;

        while (entree >> commande)
        {

            cout << "Commande : " << commande << endl;
            if (commande == "O")
            {
                string nomFichierClients;
                string nomFichierCommandes;

                entree >> nomFichierClients;
                entree >> nomFichierCommandes;

                ChargerListes(nomFichierClients, listeClient, nomFichierCommandes, listeCommande);
            }
            else if (commande == "S")
            {
                string nomFichierClients;
                string nomFichierCommandes;

                entree >> nomFichierClients;
                entree >> nomFichierCommandes;

                SauvegarderListes(listeClient, nomFichierClients, nomFichierCommandes, listeCommande);
            }
            else if (commande == "+")
            {
                string nomClient;
                string adresseClient;
                string numeroClient;

                entree >> nomClient;
                entree >> adresseClient;
                entree >> numeroClient;
                // CreerClient(nomClient, adresseClient, stoi(numeroClient), listeClient);
            }
            else if (commande == "-")
            {
                string nomClient;

                entree >> nomClient;
                // SupprimerClient(nomClient, listeClient,listeCommande);
            }
            else if (commande == "=")
            {
                string nomClientSource;
                string nomClientDestinataire;
                Liste<Biscuit> biscuits;

                entree >> nomClientSource;
                entree >> nomClientDestinataire;

                string nomBiscuit;
                while (entree >> nomBiscuit && nomBiscuit != "&")
                {
                    string nombreBiscuits;
                    entree >> nombreBiscuits;

                    try
                    {
                        biscuits.Inserer(Biscuit(nomBiscuit, stoi(nombreBiscuits)));
                    }
                    catch (...)
                    {
                        cout << "Nombre de biscuits invalide" << endl;
                    }
                }
            }
            // AjouterCommande(nomClientSource, nomClientDestinataire, biscuits, listeCommande); Fonction pas encore créer

            else if (commande == "?")
            {
                string nomClient;
                entree >> nomClient;
                // AfficherCommandes(nomClient, listeCommande); Fonction pas encore créer
            }
            else if (commande == "$")
            {
                TrouverBiscuitPopulaire(listeCommande);
            }
            else
            {
                cout << "Commande invalide" << endl;
            }
        }
        entree.close();
    }
    else
    {
        cout << "Erreur lors de l'ouverture du fichier " << argv[1] << endl;
    }
}
