#ifndef CLIENTS_H
#define CLIENTS_H
#include "client.h"
#include "constantes.h"
/*===============================
  Définition de la structure Clients
================================*/
typedef struct
{
    Client tabClients[MAXCLIENTS];
    int countUsed;
} Clients;

/*===============================
  Prototypes
================================*/
void initClients(Clients *clients);
bool clientDansClientEstUtilise(const Clients *clients, int index);
void destroyClients(Clients *clients);

#endif
