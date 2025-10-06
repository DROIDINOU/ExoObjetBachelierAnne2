#include <string.h>
#include <stdio.h>
#include "client.h"      // contient les prototypes des getters/setters + initClient
#include "crudClients.h" // contient Clients + prototypes du CRUD
#include "console.h"
#include "outils.h"

/*======================================================================
  Fonctions CRUD
 ======================================================================*/

bool ajouter(Clients *clients, int numero,
             char *nom, char *prenom, char *adresse,
             Frequentation frequentation)
{
    int idx = trouverEspaceLibre(clients);
    if (idx == -1)
    {
        return false; // pas de case libre
    }

    Client *cli = getClientAt(clients, idx);
    if (cli == NULL)
        return false; // sécurité

    // Initialiser le client avec les setters
    initClient(cli, numero, nom, prenom, adresse, frequentation);

    incrementCountUsed(clients);
    return true;
}

bool supprimer(Clients *clients, int numero)
{
    int idx = trouverIndex(clients, numero);
    if (idx == -1)
    {
        afficherMessageConsole(NULL, INFOERRORSUPPRESSION);
        return false;
    }

    Client *cli = getClientAt(clients, idx);
    if (cli != NULL)
    {
        setUsed(cli, false);
        decrementCountUsed(clients);
    }
    return true;
}

bool saisirInfosCrud(Console *c,
                     char *nom, size_t nomSize,
                     char *prenom, size_t prenomSize,
                     char *adresse, size_t adresseSize,
                     Frequentation *frequentation)
{

    if (!saisirChaineConsole(c, nom, nomSize,
                             "Nom: ", INFONOMINVALIDE))
        return false;

    if (!saisirChaineConsole(c, prenom, prenomSize,
                             "Prénom: ", INFOPRENOMINVALIDE))
        return false;

    if (!saisirChaineConsole(c, adresse, adresseSize,
                             "Adresse: ", INFOADRESSEINVALIDE))
        return false;

    int choix;
    if (!saisirEntierConsole(c, &choix,
                             "Fréquentation (1=Très régulier, 2=Régulier, 3=Occasionnel): ",
                             INFOFREQUENTATIONINVALIDE))
    {
        return false;
    }

    if (choix < 1 || choix > 3)
    {
        afficherMessageConsole(c, INFOFREQUENTATIONINVALIDE);
        return false;
    }

    *frequentation = (Frequentation)choix;
    return true;
}

void afficherClientsConsole(Console *c, Clients *clients)
{
    (void)c; // Console pas encore utilisée
    printf("\n----------- Listing clients -----------\n");
    printf("# Id | Prénom | Nom | Adresse | Fréquentation\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < MAXCLIENTS; ++i)
    {
        Client *cli = getClientAt(clients, i);
        if (isUsedClient(cli))
        {
            printf("# %d | %s | %s | %s | %s\n",
                   getNumero(cli),
                   getPrenom(cli),
                   getNom(cli),
                   getAdresse(cli),
                   frequentationVersChaine(getFrequentation(cli)));
        }
    }

    printf("*****************************\n");
    if (getCountUsed(clients) == 0)
        printf("Aucun client.\n");
    else
        printf("Total: %d client(s).\n", getCountUsed(clients));
    printf("*****************************\n");
}

void afficherClientsTries(Console *c, Clients *clientsTries, Frequentation frequentation)
{
    (void)c; // Console pas encore utilisée
    printf("\n----------- Listing clients triés -----------\n");
    printf("# Id | Prénom | Nom | Adresse | Fréquentation\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < MAXCLIENTS; ++i)
    {
        Client *cli = getClientAt(clientsTries, i);
        if (isUsedClient(cli) && getFrequentation(cli) == frequentation)
        {
            printf("# %d | %s | %s | %s | %s\n",
                   getNumero(cli),
                   getPrenom(cli),
                   getNom(cli),
                   getAdresse(cli),
                   frequentationVersChaine(getFrequentation(cli)));
        }
    }

    printf("*****************************\n");
    if (getCountUsed(clientsTries) == 0)
        printf("Aucun client.\n");
    else
        printf("Total: %d client(s).\n", getCountUsed(clientsTries));
    printf("*****************************\n");
}

/*======================================================================
  Triage de la liste de Clients
 ======================================================================*/
void trierClientsParFrequentation(Clients *clients,
                                  Clients *clientsTries,
                                  Frequentation frequentation)
{
    clientsTries->countUsed = 0; // on part d'une collection vide

    for (int i = 0; i < MAXCLIENTS; i++)
    {
        Client *cli = &clients->tabClients[i];

        if (isUsedClient(cli) && getFrequentation(cli) == frequentation)
        {
            // copier dans la collection triée à la prochaine position
            clientsTries->tabClients[clientsTries->countUsed] = *cli;
            clientsTries->countUsed++;
        }
    }
}
