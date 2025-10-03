#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdbool.h>
#include <stddef.h>
#include "infoUtilisateur.h" // pour enum Info
#include "clients.h"

typedef struct
{
    int _dummy; // champ fictif pour l’instant
    // Vide pour l’instant (évolutif si un jour on veut ajouter FILE*, langue, etc.)
} Console;

// Initialisation
void initConsole(Console *c);

// Méthodes de lecture
bool lireEntierConsole(Console *c, int *valeur, const char *invite);
bool lireChaineConsole(Console *c, char *buffer, size_t taille, const char *invite);

// Méthodes de saisie avec message d’erreur
bool saisirEntierConsole(Console *c, int *valeur, const char *invite, Info messageErreur);
bool saisirChaineConsole(Console *c, char *buffer, size_t taille, const char *invite, Info messageErreur);
bool saisirInfosCrud(Console *c,
                     char *nom, size_t nomSize,
                     char *prenom, size_t prenomSize,
                     char *adresse, size_t adresseSize,
                     Frequentation *frequentation);
void afficherClientsConsole(Console *c, const Clients *clients);
void afficherMessageConsole(Console *c, const Info info);

#endif
