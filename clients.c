#include "clients.h"

/*======================================================================
  Initialisation d’un client (via les setters)
  destruction des clients (via les setters)
 ======================================================================*/
void initClients(Clients *clients)
{
    clients->countUsed = 0;
    for (int i = 0; i < MAXCLIENTS; i++)
    {
        setUsed(&clients->tabClients[i], false);
    }
}

bool clientDansClientEstUtilise(const Clients *clients, int index)
{
    if (index < 0 || index >= MAXCLIENTS)
        return false;
    return isUsed(&clients->tabClients[index]);
}
void destroyClients(Clients *clients)
{
    clients->countUsed = 0;
    for (int i = 0; i < MAXCLIENTS; i++)
    {
        setUsed(&clients->tabClients[i], false);
    }
}