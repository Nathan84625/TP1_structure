#pragma once 
#include <string> 
#include "Liste.h" 
#include "Client.h" 
#include "Commande.h" 
#include "Biscuit.h" 
using namespace std;
class ListeCommandes
{
private:
    Liste<Client> clients; 
    Liste<Commande> commandes; 
    bool ClientExiste(const string& nomClient); 
public: 
    ListeCommandes(); 
    ~ListeCommandes(); 
    bool ChargerListes(const string& nomFichierClients, const string& nomFichierCommandes); 
    bool SauvegarderListes(const string& nomFichierClients, const string& nomFichierCommandes); 
    bool AjouterClient(const string& nom, int numero, const string& adresse); 
    bool SupprimerClient(const string& nomClient); 
    bool AjouterCommande(const string& source, const string& destinataire, Liste<Biscuit>& biscuits); 
    bool AfficherCommandes(const string& nomClient); 
    void TrouverBiscuitPopulaire();
}; 
