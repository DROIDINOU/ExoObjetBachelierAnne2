#ifndef MENU_H
#define MENU_H
#include "crudClients.h"
#include "clients.h"

typedef enum
{
    QUITTER = 0,
    AJOUTER = 1,
    SUPPRIMER = 2,
    AFFICHER = 3
} ChoixMenu;

void lancerMenuCrudClients(Clients *clients);

#endif
