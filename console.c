#include <stdio.h>
#include <string.h>
#include "console.h"
#include "affichage.h"
#include "outils.h"

void initConsole(Console *c)
{
    (void)c; // rien à initialiser pour l’instant
}

bool lireEntierConsole(Console *c, int *valeur, const char *invite)
{
    (void)c;
    char ligne[32];

    if (invite && invite[0] != '\0')
        printf("%s", invite);

    if (!fgets(ligne, sizeof ligne, stdin))
        return false;

    if (strchr(ligne, '\n') == NULL)
        viderBuffer();

    return sscanf(ligne, "%d", valeur) == 1;
}

bool lireChaineConsole(Console *c, char *buffer, size_t taille, const char *invite)
{
    (void)c;
    if (invite && invite[0] != '\0')
        printf("%s", invite);

    if (!fgets(buffer, taille, stdin))
        return false;

    if (strchr(buffer, '\n') == NULL)
        viderBuffer();

    supprimerSautLigne(buffer);
    return buffer[0] != '\0'; // on refuse une chaîne vide
}

bool saisirEntierConsole(Console *c, int *valeur, const char *invite, Info messageErreur)
{
    if (!lireEntierConsole(c, valeur, invite))
    {
        afficherMessageInfo(messageErreur);
        return false;
    }
    return true;
}

bool saisirChaineConsole(Console *c, char *buffer, size_t taille, const char *invite, Info messageErreur)
{
    if (!lireChaineConsole(c, buffer, taille, invite))
    {
        afficherMessageInfo(messageErreur);
        return false;
    }
    return true;
}

bool saisirNomPrenomAdresseConsole(Console *c,
                                   char *nom, size_t nomSize,
                                   char *prenom, size_t prenomSize,
                                   char *adresse, size_t adresseSize)
{
    if (!saisirChaineConsole(c, nom, nomSize,
                             "Veuillez entrer le nom du client: ", INFONOMINVALIDE))
        return false;

    if (!saisirChaineConsole(c, prenom, prenomSize,
                             "Veuillez entrer le prenom du client: ", INFOPRENOMINVALIDE))
        return false;

    if (!saisirChaineConsole(c, adresse, adresseSize,
                             "Veuillez entrer l'adresse du client: ", INFOADRESSEINVALIDE))
        return false;

    return true;
}
