#ifndef CRUDCLIENTS_H
#define CRUDCLIENTS_H

#include <stdbool.h>
#include "constantes.h"
#include "client.h"
#include "clients.h"
#include "console.h"

bool ajouter(Clients *clients, int numero, char *nom,
             char *prenom, char *adresse, Frequentation frequentation);
bool supprimer(Clients *clients, int numero);
bool saisirInfosCrud(Console *c,
                     char *nom, size_t nomSize,
                     char *prenom, size_t prenomSize,
                     char *adresse, size_t adresseSize,
                     Frequentation *frequentation);
void afficherClientsConsole(Console *c, Clients *clients);
void afficherClientsTries(Console *c, Clients *clientsTries, Frequentation frequentation);
void trierClientsParFrequentation(Clients *clients, Clients *clientsTries, Frequentation frequentation);

#endif
