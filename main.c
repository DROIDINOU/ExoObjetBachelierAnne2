/*Fichier d'en-tête*/
#include "menu.h"
#include "clients.h"
#include "console.h"

int main(void)
{
    // declaration
    Clients clients;
    Console c;
    Clients clientsTries;
    // initialisation
    initClients(&clients);
    initClients(&clientsTries);
    initConsole(&c);
    // Actions
    lancerMenuCrudClients(&clients, &c, &clientsTries);
    // destruction
    detruireClients(&clients);
    detruireClients(&clientsTries);
    return 0;
}