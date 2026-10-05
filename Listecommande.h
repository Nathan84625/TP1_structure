#pragma once 
#include <string> 
#include "Liste.h" 
#include "Client.h" 
#include "Commande.h" 
#include "Biscuit.h" 
using namespace std;
class ListeCommandes
private:

    Liste<Client> clients; // AJOUTÉ : contient les clients chargés en mémoire.

    Liste<Commande> commandes; // AJOUTÉ : contient les commandes chargées en mémoire.

    bool ClientExiste(const string& nomClient); // AJOUTÉ : vérifie si un client est inscrit.

public: // AJOUTÉ : opérations accessibles au main.

    ListeCommandes(); // AJOUTÉ : constructeur.

    ~ListeCommandes(); // AJOUTÉ : destructeur.

    bool ChargerListes(const string& nomFichierClients, const string& nomFichierCommandes); // AJOUTÉ : opération O.

    bool SauvegarderListes(const string& nomFichierClients, const string& nomFichierCommandes); // AJOUTÉ : opération S.

    bool AjouterClient(const string& nom, int numero, const string& adresse); // AJOUTÉ : opération +.

    bool SupprimerClient(const string& nomClient); // AJOUTÉ : opération -.

    bool AjouterCommande(const string& source, const string& destinataire, Liste<Biscuit>& biscuits); // AJOUTÉ : opération =.

    bool AfficherCommandes(const string& nomClient); // AJOUTÉ : opération ?.

    void TrouverBiscuitPopulaire(); // AJOUTÉ : opération $.

}; // AJOUTÉ : fin de ListeCommandes.
