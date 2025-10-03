#include "clients.h"

/*======================================================================
  Initialisation des clients
  destruction des clients
 ======================================================================*/
void initClients(Clients *clients)
{
    clients->countUsed = 0;
    for (int i = 0; i < MAXCLIENTS; i++)
    {
        // initialise chaque client à 0, false etc...
        resetClient(&clients->tabClients[i]);
    }
}

void destroyClients(Clients *clients)
{
    clients->countUsed = 0;
    for (int i = 0; i < MAXCLIENTS; i++)
    {
        resetClient(&clients->tabClients[i]);
    }
}

/*======================================================================
  Triage de la liste de Clients
 ======================================================================*/
void trierClientsParFrequentation(const Clients *clients,
                                  Clients *clientsTries,
                                  Frequentation frequentation)
{
    clientsTries->countUsed = 0; // on part d'une collection vide

    for (int i = 0; i < MAXCLIENTS; i++)
    {
        const Client *cli = &clients->tabClients[i];

        if (isUsed(cli) && getFrequentation(cli) == frequentation)
        {
            // copier dans la collection triée à la prochaine position
            clientsTries->tabClients[clientsTries->countUsed] = *cli;
            clientsTries->countUsed++;
        }
    }
}
