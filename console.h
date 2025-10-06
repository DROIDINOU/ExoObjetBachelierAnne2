#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdbool.h>
#include <stddef.h>
#include "clients.h"

// Définitions des types d'informations à afficher à l'utilisateur
typedef enum
{
    INFOERROR = 0,                  // message d'erreur générique
    INFOSUCCES = 1,                 // succès générique
    INFOSUCCESAJOUT = 2,            // succès après ajout
    INFOSUCCESSSUPPRESSION = 3,     // succès après suppression
    INFOCHOIXCRUD = 4,              // affiche le menu CRUD
    INFOINVITECOMMANDE = 5,         // invite "Votre choix: "
    INFOERRORCHOIXINEXISTANT = 6,   // "Ce choix n'existe pas"
    INFONOMINVALIDE = 7,            // "Nom invalide"
    INFOPRENOMINVALIDE = 8,         // "Prénom invalide"
    INFOADRESSEINVALIDE = 9,        // "Adresse invalide"
    INFONUMEROINVALIDE = 11,        // "Numéro invalide"
    INFONUMEROEXIST = 12,           // "Numéro déjà existant."
    INFOERRORSUPPRESSION = 13,      // "erreur lors de la suppression."
    INFOERREURLISTINGPLEIN = 14,    // "Le listing est plein."
    INFOERRORINCONNUE = 15,         // "Erreur inconnue."
    INFOAUREVOIR = 16,              // "Au revoir!"
    INFOFREQUENTATIONINVALIDE = 17, // "Fréquentation invalide."
    INFOCHOIXTRIAGE = 18            // "Choix de triage"

} Info;

typedef struct
{
    int _vide; // champ fictif pour l’instant
    // Vide pour l’instant (évolutif si un jour on veut ajouter FILE*, langue, etc.)
} Console;

// Initialisation
void initConsole(Console *c);

// Méthodes de lecture
bool lireEntierConsole(Console *c, int *valeur, char *invite);
bool lireChaineConsole(Console *c, char *buffer, size_t taille, char *invite);

// Méthodes de saisie avec message d’erreur
bool saisirEntierConsole(Console *c, int *valeur, char *invite, Info messageErreur);
bool saisirChaineConsole(Console *c, char *buffer, size_t taille, char *invite, Info messageErreur);
void afficherMessageConsole(Console *c, Info info);

#endif
