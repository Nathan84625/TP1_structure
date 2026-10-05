#include "ListeCommandes.h"
#include <fstream>
#include <iostream>

ListeCommandes::ListeCommandes()
{
}

ListeCommandes::~ListeCommandes()
{
}

bool ListeCommandes::ChargerListes(const string& nomFichierClients, const string& nomFichierCommandes)
{
    ifstream fichierClients(nomFichierClients);
    ifstream fichierCommandes(nomFichierCommandes);
    if (!fichierClients)
    {
        cout << "Erreur lors de l'ouverture du fichier "
             << nomFichierClients << endl;
        return false;
    }

    if (!fichierCommandes)
    {
        cout << "Erreur lors de l'ouverture du fichier "
             << nomFichierCommandes << endl;
        return false;
    }

    Liste<Client> clientsVides;
    Liste<Commande> commandesVides;
    clients = clientsVides;
    commandes = commandesVides;
    string nom;
    int numero;
    string adresse;
    while (fichierClients >> nom >> numero >> adresse)
    {
        Client nouveauClient(nom, adresse, numero);
        clients.FixerPosition(clients.Longueur());
        clients.Inserer(nouveauClient);
    }

    string source;
    string destinataire;
    while (fichierCommandes >> source >> destinataire)
    {
        Liste<Biscuit> biscuits;
        string nomBiscuit;
        while (fichierCommandes >> nomBiscuit && nomBiscuit != "&")
        {
            int quantite;
            if (!(fichierCommandes >> quantite))
            {
                cout << "Format invalide dans le fichier "
                     << nomFichierCommandes << endl;
                return false;
            }

            biscuits.FixerPosition(biscuits.Longueur());
            biscuits.Inserer(Biscuit(nomBiscuit, quantite));
        }

        Commande nouvelleCommande(source, destinataire, biscuits);
        commandes.FixerPosition(commandes.Longueur());
        commandes.Inserer(nouvelleCommande);
    }
    return true;
}
bool ListeCommandes::SauvegarderListes(const string& nomFichierClients, const string& nomFichierCommandes)
{
    ofstream fichierClients(nomFichierClients);
    if (!fichierClients)
    {
        cout << "Erreur lors de la sauvegarde du fichier "
             << nomFichierClients << endl;
        return false;
    }

    for (int i = 0; i < clients.Longueur(); i++)
    {
        clients.FixerPosition(i);
        Client& client = clients.ValeurCourante();
        fichierClients << client.getNom() << endl;
        fichierClients << client.getNumero() << endl;
        fichierClients << client.getAdresse() << endl;
    }

    fichierClients.close();
    ofstream fichierCommandes(nomFichierCommandes);
    if (!fichierCommandes)
    {
        cout << "Erreur lors de la sauvegarde du fichier "
             << nomFichierCommandes << endl;
        return false;
    }

    for (int i = 0; i < commandes.Longueur(); i++)
    {
        commandes.FixerPosition(i);
        Commande& commande = commandes.ValeurCourante();
        fichierCommandes << commande.getSource() << endl;
        fichierCommandes << commande.getDestinataire() << endl;
        Liste<Biscuit> biscuits = commande.getBiscuits();
        for (int j = 0; j < biscuits.Longueur(); j++)
        {
            biscuits.FixerPosition(j);
            Biscuit& biscuit = biscuits.ValeurCourante();
            fichierCommandes << biscuit.getNom()
                             << " "
                             << biscuit.getNombre()
                             << endl;
        }
        fichierCommandes << "&" << endl;
    }

    fichierCommandes.close();
    return true;
}
bool ListeCommandes::AjouterClient(const string& nom, int numero, const string& adresse)
{
    for (int i = 0; i < clients.Longueur(); i++)
    {
        clients.FixerPosition(i);
        if (clients.ValeurCourante().getNom() == nom)
        {
            cout << "Le client " << nom << " existe deja." << endl;
            return false;
        }
    }
    Client nouveauClient(nom, adresse, numero);
    clients.FixerPosition(clients.Longueur());
    clients.Inserer(nouveauClient);
    return true;
}

bool ListeCommandes::SupprimerClient(const string& nomClient)
{
    bool trouve = false;
    for (int i = 0; i < clients.Longueur(); i++)
    {
        clients.FixerPosition(i);
        if (clients.ValeurCourante().getNom() == nomClient)
        {
            clients.Supprimer();
            trouve = true;
            break;
        }
    }

    if (!trouve)
    {
        cout << "Le client " << nomClient
             << " n'existe pas." << endl;
        return false;
    }

    int i = 0;
    while (i < commandes.Longueur())
    {
        commandes.FixerPosition(i);
        Commande& commande = commandes.ValeurCourante();
        if (commande.getSource() == nomClient ||
            commande.getDestinataire() == nomClient)
        {
            commandes.Supprimer();
        }
        else
        {
            i++;
        }
    }
    return true;
}

bool ListeCommandes::AjouterCommande(const string& source,
                                     const string& destinataire,
                                     Liste<Biscuit>& biscuits)
{
    bool sourceTrouvee = false;
    bool destinataireTrouve = false;
    for (int i = 0; i < clients.Longueur(); i++)
    {
        clients.FixerPosition(i);
        if (clients.ValeurCourante().getNom() == source)
        {
            sourceTrouvee = true;
        }

        if (clients.ValeurCourante().getNom() == destinataire)
        {
            destinataireTrouve = true;
        }
    }
    if (!sourceTrouvee)
    {
        cout << "Le client " << source
             << " n'est pas inscrit. Commande refusee."
             << endl;
        return false;
    }

    if (!destinataireTrouve)
    {
        cout << "Le client " << destinataire
             << " n'est pas inscrit. Commande refusee."
             << endl;
        return false;
    }

    Commande nouvelleCommande(source, destinataire, biscuits);
    commandes.FixerPosition(commandes.Longueur());
    commandes.Inserer(nouvelleCommande);
    return true;
}

bool ListeCommandes::AfficherCommandes(const string& nomClient)
{
    bool trouve = false;
    for (int i = 0; i < commandes.Longueur(); i++)
    {
        commandes.FixerPosition(i);
        Commande& commande = commandes.ValeurCourante();
        if (commande.getSource() == nomClient)
        {
            trouve = true;
            cout << commande.getSource() << endl;
            cout << commande.getDestinataire() << endl;
            Liste<Biscuit> biscuits = commande.getBiscuits();
            for (int j = 0; j < biscuits.Longueur(); j++)
            {
                biscuits.FixerPosition(j);
                Biscuit& biscuit = biscuits.ValeurCourante();
                cout << biscuit.getNom()
                     << " "
                     << biscuit.getNombre()
                     << endl;
            }
            cout << "&" << endl;
        }
    }
    if (!trouve)
    {
        cout << "Aucune commande trouvee pour "
             << nomClient << "." << endl;
    }
    return trouve;
}

void ListeCommandes::TrouverBiscuitPopulaire()
{
    string nomPopulaire = "";
    int quantitePopulaire = 0;
    for (int i = 0; i < commandes.Longueur(); i++)
    {
        commandes.FixerPosition(i);
        Commande& commandeCandidate = commandes.ValeurCourante();
        for (int j = 0; j < commandeCandidate.nombreBiscuits(); j++)
        {
            Biscuit candidat = commandeCandidate.getBiscuit(j);
            string nomCandidat = candidat.getNom();
            int total = 0;
            for (int k = 0; k < commandes.Longueur(); k++)
            {
                commandes.FixerPosition(k);
                Commande& commandeRecherche = commandes.ValeurCourante();
                for (int l = 0; l < commandeRecherche.nombreBiscuits(); l++)
                {
                    Biscuit biscuit = commandeRecherche.getBiscuit(l);
                    if (biscuit.getNom() == nomCandidat)
                    {
                        total += biscuit.getNombre();
                    }
                }
            }

            if (nomPopulaire == "" || total > quantitePopulaire)
            {
                nomPopulaire = nomCandidat;
                quantitePopulaire = total;
            }
        }
    }

    if (nomPopulaire == "")
    {
        cout << "Aucun biscuit vendu." << endl;
        return;
    }

    cout << "Le biscuit le plus populaire est "
         << nomPopulaire << "." << endl;

    cout << "Le montant total recu pour ce biscuit est de "
         << quantitePopulaire << " $." << endl;
}
