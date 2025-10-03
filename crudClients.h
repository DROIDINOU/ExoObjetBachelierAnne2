#ifndef CRUDCLIENTS_H
#define CRUDCLIENTS_H

#include <stdbool.h>
#include "constantes.h"
#include "client.h"
#include "clients.h"

bool estPlein(const Clients *clients);
bool numeroExiste(const Clients *clients, int numero);
bool ajouter(Clients *clients, int numero, const char *nom,
             const char *prenom, const char *adresse, Frequentation frequentation);
bool supprimer(Clients *clients, int numero);

#endif
