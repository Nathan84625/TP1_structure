#include <iostream>
#include "Liste.h"
#include "Client.h"
#include "Commande.h"
#include "Biscuit.h"
#include <string>
#include<fstream>

using namespace std;



/// @brief Charge les clients à partir d'un fichier.
/// @param nomFichierClients Le nom du fichier contenant les clients.
/// @return La liste des cleints chargés à partir du fichier.
void ChargerListes(const string nomFichierClients, Liste<Client>& clients, const string nomFichierCommandes, Liste<Commande>& commandes)
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
        if(nom != "" && numeroCivique != "" && rue != "")
        clients.Inserer(Client(nom, rue, stoi(numeroCivique)));
        }
	entree.close();
    }

    string nomClientSource;
    string NomClientDestinataire;
    string nomBiscuit;
    string nombreBiscuits;
    string aSkip;
    entree.open(nomFichierCommandes, ios::in);
    if (entree)
    {
        while (entree.peek() != EOF)
        {
            Liste<Biscuit> biscuits;
            getline(entree, nomClientSource);
            getline(entree, NomClientDestinataire);
            while (entree.peek() != '&') 
            {
                entree >> nomBiscuit;
                entree >>nombreBiscuits;
                entree >> ws;
                biscuits.Inserer(Biscuit(nomBiscuit, stoi(nombreBiscuits)));
            }
            getline(entree, aSkip); // Forcément un &, donc on le lit pour avancer.

            commandes.Inserer(Commande(nomClientSource,NomClientDestinataire,biscuits));
        }
        entree.close();
    }

}

void SauvegarderListes(Liste<Client> & listeClient, const string nomFichierClients, const string nomFichierCommandes, Liste<Commande>& commandes)
{
    fstream sortie;

    sortie.open(nomFichierClients);

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
    sortie.close();
    sortie.open(nomFichierCommandes);

    if (sortie)
    {
        for (int i = 0; i < commandes.Longueur(); i++)
        {
            commandes.FixerPosition(i);
            sortie << commandes.ValeurCourante().getSource() << endl;
            sortie << commandes.ValeurCourante().getDestinataire() << endl;
            for ( i = 0; i < commandes.ValeurCourante().getBiscuits().Longueur(); i++)
            {
                sortie << commandes.ValeurCourante().getBiscuits().ValeurCourante().getNom() << " " << commandes.ValeurCourante().getBiscuits().ValeurCourante().getNombre() << endl;
                sortie << "&" << endl;
            }
            
        }
    }
    sortie.close();
}
Biscuit* TrouverBiscuitParNom(string nomATrouver, Liste<Biscuit>& biscuits) {
    Biscuit* biscuitTrouver = nullptr;
    for (int i = 0; i < biscuits.Longueur(); i++)
    {
        biscuits.FixerPosition(i);
        if (biscuits.ValeurCourante().getNom() == nomATrouver)
        {
            biscuitTrouver = &biscuits.ValeurCourante();
        }
    }
    return biscuitTrouver;
}
void TrouverBiscuitPopulaire(Liste<Commande>& commandes) {
   
    Liste<Biscuit> allBiscuits;
    Liste<string> nomBiscuits;
    Liste<Biscuit> biscuitsCompter;
    string nomBiscuitPopulaire;
    int nombreBiscuitPopulaire = 0;

    //Commence par itérer dans toutes les biscuits utiliser dans une liste
    for (int i = 0; i < commandes.Longueur(); i++)
    {
        commandes.FixerPosition(i);
        Liste<Biscuit> listeBiscuitsTemporaire = commandes.ValeurCourante().getBiscuits();
        
        for (int j = 0; j < listeBiscuitsTemporaire.Longueur(); j++)
        {
            listeBiscuitsTemporaire.FixerPosition(j); 

            allBiscuits.Inserer(listeBiscuitsTemporaire.ValeurCourante());
        }
    }
    // On ajoute Une itération de chaque biscuit dans une liste. Si on retombe sur un biscuit dejà dans la liste, on augmente sont nombre de vente
    for (int i = 0; i < allBiscuits.Longueur(); i++)
    {
        allBiscuits.FixerPosition(i);

        nomBiscuits.FixerTete(); 
        if (!nomBiscuits.Trouver(allBiscuits.ValeurCourante().getNom())) {
            nomBiscuits.Inserer(allBiscuits.ValeurCourante().getNom());
            biscuitsCompter.Inserer(allBiscuits.ValeurCourante());
        }
        else {
            Biscuit* biscuit = TrouverBiscuitParNom(allBiscuits.ValeurCourante().getNom(), biscuitsCompter);
            biscuit->addNombre(allBiscuits.ValeurCourante().getNombre());
        }
        
    }
    // On vérifie qu'elle biscuit a été le plus vendu et on l'affiche 
    for (int i = 0; i < biscuitsCompter.Longueur(); i++)
    {
        biscuitsCompter.FixerPosition(i);

        if (biscuitsCompter.ValeurCourante().getNombre() > nombreBiscuitPopulaire) {
            nombreBiscuitPopulaire = biscuitsCompter.ValeurCourante().getNombre();
            nomBiscuitPopulaire = biscuitsCompter.ValeurCourante().getNom();
        }
    }
    cout << "Le biscuit le plus populaire est " << nomBiscuitPopulaire << " avec " << to_string(nombreBiscuitPopulaire) << " biscuits" << endl;

}


int main()
{
    Liste<Client> listeClient;
    Liste<Commande> listeCommande;
    string option = "0";
    int choix = 0;
    bool continuer = true;
    string nomFichierClients = "CLIENTS.txt";
    string nomFichierCommandes = "COMMANDES.txt";

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
           ChargerListes(nomFichierClients,listeClient,nomFichierCommandes,listeCommande);
        // À enlever éventuellement, sert de test pour vérifier que la liste est bien remplie
           for (int i = 0; i < listeCommande.Longueur() ; i++)
           {
               listeCommande.FixerPosition(i);
            cout << listeCommande.ValeurCourante().getSource() << endl;
           }
            break;
        case 2:
        
        // Sauvegarder la liste des clients et leurs commandes
            SauvegarderListes(listeClient, nomFichierClients, nomFichierCommandes, listeCommande);
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
            TrouverBiscuitPopulaire(listeCommande);
            break;
        case 8:
            continuer = false;
            break;
        default:
            cout << "Option invalide, veuillez choisir une option entre 1 et 8" << endl;
        }
    } while (continuer);


}

