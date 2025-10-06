#include "clients.h"
#include <stdlib.h> // définit aussi NULL

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

void detruireClients(Clients *clients)
{
    clients->countUsed = 0;
    for (int i = 0; i < MAXCLIENTS; i++)
    {
        resetClient(&clients->tabClients[i]);
    }
}

/*======================================================================
  INFOS SUR CONTENU COLLECTION
  -> obtenir le nombre de clients via countUsed
  -> obtenir client a index spécifié
  -> incrementer decrementer
  -> trouver un espace libre
  -> trouver client par son numero
  -> verifier si tableau plein
  -> verifier si numero de client existe
 ======================================================================*/

int getCountUsed(Clients *clients)
{
    return clients->countUsed;
}

// retourne le client a index specifié
Client *getClientAt(Clients *clients, int index)
{
    if (index < 0 || index >= MAXCLIENTS)
        return NULL;
    return &clients->tabClients[index];
}

void incrementCountUsed(Clients *clients)
{
    clients->countUsed++;
}

void decrementCountUsed(Clients *clients)
{
    if (clients->countUsed > 0)
        clients->countUsed--;
}

// Cherche une case libre dans le tableau
int trouverEspaceLibre(Clients *clients)
{
    for (int i = 0; i < MAXCLIENTS; ++i)
    {
        Client *cli = getClientAt(clients, i); // plus de cast
        if (cli != NULL && !isUsedClient(cli))
            return i;
    }
    return -1;
}

// Trouve un client par son numéro
int trouverIndex(Clients *clients, int numero)
{
    for (int i = 0; i < MAXCLIENTS; ++i)
    {
        Client *cli = getClientAt(clients, i); // plus de cast
        if (cli != NULL && isUsedClient(cli) && getNumero(cli) == numero)
        {
            return i;
        }
    }
    return -1;
}
// verifie si tableau est plein
bool estPlein(Clients *clients)
{
    if (getCountUsed(clients) >= MAXCLIENTS)
    {
        return true;
    }
    return false;
}

// verifie si numero de client existe
bool numeroExiste(Clients *clients, int numero)
{
    if (trouverIndex(clients, numero) != -1)
    {

        return true;
    }
    return false;
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
