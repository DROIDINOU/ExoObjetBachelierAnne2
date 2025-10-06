#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "crudClients.h"
#include "outils.h"
#include "console.h"

/*_____________________________________________________
#         Fonctions utilitaires
#   suppression du saut de ligne
#   vider buffer
#   convertir struct en chaine
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

char *frequentationVersChaine(Frequentation f)
{
    switch (f)
    {
    case TRESREGULIER:
        return "Très régulier";
    case REGULIER:
        return "Régulier";
    case OCCASIONNEL:
        return "Occasionnel";
    default:
        return "Inconnu";
    }
}
