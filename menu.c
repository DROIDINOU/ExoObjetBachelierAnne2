#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "constantes.h"
#include "crudClients.h"
#include "menu.h"
#include "outils.h"
#include "console.h"

// Lance le menu principal
void lancerMenuCrudClients(Clients *clients, Console *c, Clients *clientsTries)
{
    int choix;                   // choix du menu
    int numero;                  // numéro client
    char nom[256];               // buffer pour nom
    char prenom[256];            // buffer pour prénom
    char adresse[256];           // buffer pour adresse
    bool continuer = true;       // boucle principale
    Frequentation frequentation; // variable pour la fréquentation

    do
    {
        afficherMessageConsole(NULL, INFOCHOIXCRUD);

        if (lireEntierConsole(c, &choix, "Votre choix: ") == false)
        {
            afficherMessageConsole(NULL, INFOERROR);
            continue;
        }

        switch (choix)
        {

        case TRIER:
        {
            lancerMenuTrierClientsParFrequentation(clients, c, clientsTries);
        }
        break;

        case AJOUTER:
        {
            bool ok = true;

            // Vérifier si la liste est pleine
            if (estPlein(clients))
            {
                afficherMessageConsole(NULL, INFOERREURLISTINGPLEIN);
                ok = false;
            }

            // Numéro
            if (ok && !saisirEntierConsole(c, &numero, "Veuillez entrer le numero de client: ", INFONUMEROINVALIDE))
                ok = false;

            // Vérifier si ce numéro existe déjà
            if (ok && numeroExiste(clients, numero))
            {
                afficherMessageConsole(NULL, INFONUMEROEXIST);
                ok = false;
            }

            // Nom / prénom / adresse
            if (ok && !saisirInfosCrud(
                          c,
                          nom, sizeof(nom),
                          prenom, sizeof(prenom),
                          adresse, sizeof(adresse),
                          &frequentation))
            {
                ok = false;
            }

            if (ok && ajouter(clients, numero, nom, prenom, adresse, frequentation))
                afficherMessageConsole(NULL, INFOSUCCESAJOUT);
        }
        break;

        case SUPPRIMER:
        {
            bool ok = saisirEntierConsole(c, &numero, "Numero à supprimer: ", INFONUMEROINVALIDE);

            if (ok && supprimer(clients, numero))
                afficherMessageConsole(NULL, INFOSUCCESSSUPPRESSION);
        }
        break;

        case AFFICHER:
            afficherClientsConsole(NULL, clients);
            break;

        case QUITTER:
            afficherMessageConsole(NULL, INFOAUREVOIR);

            continuer = false;
            break;

        default:
            afficherMessageConsole(NULL, INFOERRORCHOIXINEXISTANT);

            break;
        }

    } while (continuer && choix != QUITTER);
}

// lancer menu triage par frequentation
void lancerMenuTrierClientsParFrequentation(Clients *clients, Console *c, Clients *clientsTries)
{
    bool ok = true;
    int choixTri; // choix du tri
    do
    {
        afficherMessageConsole(NULL, INFOCHOIXTRIAGE);
        if (lireEntierConsole(c, &choixTri, "Votre choix: ") == false)
        {
            afficherMessageConsole(NULL, INFOERROR);
            continue;
        }
        switch (choixTri)
        {
        case 1: // Très régulier
            trierClientsParFrequentation(clients, clientsTries, choixTri);
            afficherClientsConsole(NULL, clientsTries);
            ok = false;
            break;
        case 2: // Régulier
            trierClientsParFrequentation(clients, clientsTries, choixTri);
            afficherClientsConsole(NULL, clientsTries);

            ok = false;
            break;
        case 3: // Occasionnel
            trierClientsParFrequentation(clients, clientsTries, choixTri);
            afficherClientsConsole(NULL, clientsTries);

            ok = false;
            break;
        default:
            afficherMessageConsole(NULL, INFOERRORCHOIXINEXISTANT);
            break;
        }

    } while (ok);
}