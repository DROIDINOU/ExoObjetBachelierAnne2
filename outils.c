#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "crudClients.h"
#include "outils.h"
#include "affichage.h"
#include "console.h"

/*_____________________________________________________
#         Fonctions utilitaires
#   suppression du saut de ligne, lecture chaîne et entier
#   vider buffer
#   lireChaine, lireEntier
#   saisirChaine, saisirEntier
______________________________________________________*/

// Supprime le \n final de fgets et remplace par \0
int supprimerSautLigne(char *s)
{
    size_t n = strlen(s);
    if (n && s[n - 1] == '\n')
        s[n - 1] = '\0';
}

// Vide stdin si l'utilisateur a tapé trop de caractères
int viderBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // on jette le reste
}
