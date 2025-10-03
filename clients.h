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
void destroyClients(Clients *clients);
void trierClientsParFrequentation(const Clients *clients, Clients *clientsTries, Frequentation frequentation);
#endif
