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

// sous fonction de lireChaine
bool lireChaine(const char *invite, char *buffer, size_t taille);
// sous fonction de lireEntier
bool lireEntier(const char *invite, int *valeur);
// Vide stdin si l'utilisateur a tapé trop de caractères
// Lit un entier avec message d'erreur si invalide
bool saisirEntier(const char *invite, int *valeur, Info messageErreur);
// Lit une chaîne avec message d'erreur si invalide
bool saisirChaine(const char *invite, char *buffer, size_t taille, Info messageErreur);
// Saisir nom, prénom et adresse avec messages d'erreur si invalide
bool saisirNomPrenomAdresse(char *nom, size_t nomSize,
                            char *prenom, size_t prenomSize,
                            char *adresse, size_t adresseSize);

#endif
