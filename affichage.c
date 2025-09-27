// import des binbliothèques nécessaires
#include <stdio.h>
#include <string.h>
// import des fichiers d'en-tête du projet
#include "constantes.h"
#include "crudClients.h"
#include "infoUtilisateur.h"

/********************************************************************************************************************
 * afficherClients : Affiche la liste des clients enregistrés dans le tableau.
 * afficherMessageInfo : Affiche un message d'information à l'utilisateur avec une icône selon le type de message.
 ****************************************************************************************************************** */

// Affiche la liste des clients en bouclant sur le tableau des clients
// Affiche un message si aucun client
// Utilise le champ countUsed de la structure Clients pour afficher le nombre de clients
void afficherClients(const Clients *clients)
{
    printf("\n----------- Listing clients -----------\n");
    printf("# Id | Prénom | Nom | Adresse\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < MAXCLIENTS; ++i)
    {
        // n'affiche que les clients utilisés (used == true)
        if (clientDansClientEstUtilise(clients, i))
        { // on affiche le client
            printf("# %d | %s | %s | %s\n",
                   clients->tabClients[i].numero,
                   clients->tabClients[i].prenom,
                   clients->tabClients[i].nom,
                   clients->tabClients[i].adresse);
        }
    }

    printf("*****************************\n");
    if (clients->countUsed == 0)
        printf("Aucun client.\n");
    else
        printf("Total: %d client(s).\n", clients->countUsed);
    printf("*****************************\n");
}

// Affiche un message d'info avec une icône selon le type
void afficherMessageInfo(Info info)
{
    switch (info)
    {

    case INFOSUCCES:
        printf("✅ Opération réussie.\n");
        break;
    case INFOSUCCESAJOUT:
        printf("✅ Ajout OK.\n");
        break;
    case INFOSUCCESSSUPPRESSION:
        printf("✅ Suppression OK.\n");
        break;
    case INFOCHOIXCRUD:
        printf("🔄\n1) Ajouter  2) Supprimer  3) Afficher  0) Quitter\n");
        break;
    case INFOINVITECOMMANDE:
        printf("Votre choix: ");
        break;
    case INFOAUREVOIR:
        printf("Fin du CRUD!\n");
        break;
    case INFOERROR:
        printf("❌ Choix invalide.\n");
        break;
    case INFOERRORCHOIXINEXISTANT:
        printf("❌ Ce choix n'existe pas dans le menu.\n");
        break;
    case INFONOMINVALIDE:
        printf("❌ Nom invalide.\n");
        break;
    case INFOPRENOMINVALIDE:
        printf("❌ Prénom invalide.\n");
        break;
    case INFOADRESSEINVALIDE:
        printf("❌ Adresse invalide.\n");
        break;
    case INFONUMEROINVALIDE:
        printf("❌ Numéro invalide.\n");
        break;
    case INFOERREURLISTINGPLEIN:
        printf("❌ Le listing est plein.\n");
        break;
    case INFONUMEROEXIST:
        printf("❌ Numéro déjà existant.\n");
        break;
    case INFOERRORSUPPRESSION:
        printf("❌ Numéro de client introuvable.\n");
        break;
    case INFOERRORINCONNUE:
        printf("❌ Erreur inconnue.\n");
        break;
    default:
        printf("❓ Message inconnu.\n");
        break;
    }
}
