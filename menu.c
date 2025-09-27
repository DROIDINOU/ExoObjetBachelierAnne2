#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "constantes.h"
#include "crudClients.h"
#include "menu.h"
#include "affichage.h"
#include "outils.h"
#include "infoUtilisateur.h"
#include "console.h"

// Lance le menu principal
void lancerMenuCrudClients(Clients *clients, Console *c)
{
    int choix;             // choix du menu
    int numero;            // numéro client
    char nom[256];         // buffer pour nom
    char prenom[256];      // buffer pour prénom
    char adresse[256];     // buffer pour adresse
    bool continuer = true; // pour lancer ou stopper la boucle principale

    do
    {
        afficherMessageInfo(INFOCHOIXCRUD);

        if (lireEntierConsole(c, &choix, "Votre choix: ") == false)
        {
            afficherMessageInfo(INFOERROR);
            continue;
        }

        switch (choix)
        {
        case AJOUTER:
        {
            bool ok = true;

            // Vérifier si la liste est pleine
            if (estPlein(clients))
                ok = false;

            // Numéro
            if (ok && !saisirEntierConsole(c, &numero, "Veuillez entrer le numero de client: ", INFONUMEROINVALIDE))
                ok = false;

            // Vérifier si ce numéro existe déjà
            if (ok && numeroExiste(clients, numero))
                ok = false;

            // Nom / prénom / adresse
            if (ok && !saisirNomPrenomAdresseConsole(c, nom, sizeof(nom), prenom, sizeof(prenom), adresse, sizeof(adresse)))
                ok = false;

            // Ajout final
            if (ok && ajouter(clients, numero, nom, prenom, adresse))
                afficherMessageInfo(INFOSUCCESAJOUT);
        }
        break;

        case SUPPRIMER:
        {
            bool ok = saisirEntierConsole(c, &numero, "Numero à supprimer: ", INFONUMEROINVALIDE);

            if (ok && supprimer(clients, numero))
                afficherMessageInfo(INFOSUCCESSSUPPRESSION);
        }
        break;

        case AFFICHER:
            afficherClients(clients);
            break;

        case QUITTER:
            afficherMessageInfo(INFOAUREVOIR);
            continuer = false;
            break;

        default:
            afficherMessageInfo(INFOERRORCHOIXINEXISTANT);
            break;
        }

    } while (continuer && choix != QUITTER);
}
