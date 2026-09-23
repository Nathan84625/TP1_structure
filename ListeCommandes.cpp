#include <iostream>

#include "ListeCommandes.h"

int main()
{
    ListeCommandes liste;

    int choix;

    do
    {
        std::cout << "\n";
        std::cout << "====================================\n";
        std::cout << "       GESTION DES CLIENTS          \n";
        std::cout << "====================================\n";

        std::cout << "1. Charger clients et commandes\n";
        std::cout << "2. Sauvegarder clients et commandes\n";
        std::cout << "3. Ajouter un client\n";
        std::cout << "4. Supprimer un client\n";
        std::cout << "5. Afficher les clients\n";
        std::cout << "0. Quitter\n";

        std::cout << "\nChoisissez une option : ";
        std::cin >> choix;


        switch (choix)
        {
        case 1:
        {
            /*
             * Charger les deux fichiers.
             */

            liste.charger(
                "CLIENTS.txt",
                "COMMANDES.txt"
            );

            break;
        }


        case 2:
        {
            /*
             * Sauvegarder dans les deux fichiers.
             */

            liste.sauvegarder(
                "CLIENTS.txt",
                "COMMANDES.txt"
            );

            break;
        }


        case 3:
        {
            std::string nom;
            int numero;
            std::string rue;


            std::cout << "Nom : ";
            std::cin >> nom;


            std::cout << "Numero : ";
            std::cin >> numero;


            std::cout << "Rue : ";
            std::cin >> rue;


            if (liste.ajouterClient(
                nom,
                numero,
                rue))
            {
                std::cout
                    << "Client ajoute avec succes."
                    << std::endl;
            }


            break;
        }


        case 4:
        {
            std::string nom;


            std::cout
                << "Nom du client a supprimer : ";

            std::cin >> nom;


            if (liste.supprimerClient(nom))
            {
                std::cout
                    << "Client supprime avec succes."
                    << std::endl;
            }


            break;
        }


        case 5:
        {
            liste.afficherClients();

            break;
        }


        case 0:
        {
            std::cout
                << "Programme termine."
                << std::endl;

            break;
        }


        default:
        {
            std::cout
                << "Choix invalide."
                << std::endl;
        }
        }

    } while (choix != 0);


    return 0;
}