#ifndef OUTILS_H
#define OUTILS_H
// Inclusion des bibliothèques nécessaires
#include <stdbool.h>
// Inclusion des fichiers d'en-tête du projet
#include "crudClients.h"
#include "infoUtilisateur.h"

/*_____________________________________________________
#         Prototypes des fonctions utilitaires
______________________________________________________*/

int supprimerSautLigne(char *s);
int viderBuffer(void);
const char *frequentationToString(Frequentation f);
#endif
