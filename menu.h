#ifndef MENU_H
#define MENU_H
#include "crudClients.h"
#include "clients.h"
#include "console.h"

typedef enum
{
    QUITTER = 0,
    AJOUTER = 1,
    SUPPRIMER = 2,
    AFFICHER = 3,
    TRIER = 4
} ChoixMenu;

void lancerMenuCrudClients(Clients *clients, Console *c, Clients *clientsTries);
void lancerMenuTrierClientsParFrequentation(Clients *clients, Console *c, Clients *clientsTries);

#endif
