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
void detruireClients(Clients *clients);
int getCountUsed(Clients *clients);
Client *getClientAt(Clients *clients, int index);
void incrementCountUsed(Clients *clients);
void decrementCountUsed(Clients *clients);
int trouverEspaceLibre(Clients *clients);
int trouverIndex(Clients *clients, int numero);
bool estPlein(Clients *clients);
bool numeroExiste(Clients *clients, int numero);

#endif
