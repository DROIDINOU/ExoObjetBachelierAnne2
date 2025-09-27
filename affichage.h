#ifndef AFFICHAGECLIENTS_H
#define AFFICHAGECLIENTS_H

#include <stdbool.h>
#include "crudClients.h"
#include "infoUtilisateur.h"

void afficherClients(const Clients *clients);
void afficherMessageInfo(const Info info);
#endif
