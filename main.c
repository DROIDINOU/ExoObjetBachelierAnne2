/*Fichier d'en-tête*/
#include "menu.h"
#include "crudClients.h"
#include "client.h"
#include "console.h"
#

// TODO ENCAPSULATION ET ABSTRACTION
// TODO Exercice réalisé en programmation procédurale,
// TODO avec un tableau statique de clients (MAXCLIENTS = 20).
// TODO NB : Plus tard, avec malloc/free et l'encapsulation,
// TODO on pourrait améliorer la modularité en cachant la structure
// TODO Clients dans crudClients.c et fournir uniquement une interface (getters/setters).
// TODO Mais ici, one garde la structure client publique.

int main(void)
{
    Clients clients;
    Console c;
    // Initialisation propre
    initClients(&clients);
    initConsole(&c);
    lancerMenuCrudClients(&clients, &c);
    return 0;
}
