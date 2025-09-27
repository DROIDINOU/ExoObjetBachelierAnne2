#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "crudClients.h"
#include "outils.h"
#include "affichage.h"

/*_____________________________________________________
#         Fonctions utilitaires
#   suppression du saut de ligne, lecture chaîne et entier
#   vider buffer
#   lireChaine, lireEntier
#   saisirChaine, saisirEntier
______________________________________________________*/

// Supprime le \n final de fgets et remplace par \0
static int supprimerSautLigne(char *s)
{
    size_t n = strlen(s);
    if (n && s[n - 1] == '\n')
        s[n - 1] = '\0';
}

// Vide stdin si l'utilisateur a tapé trop de caractères
static int viderBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // on jette le reste
}

// sous fonction de lireEntier
// verifie que l invite n est pas NULL ou vide
// lit une ligne avec fgets
// vide stdin si la ligne n est pas finie
// convertit en entier avec sscanf
// retourne true si ok false si erreur
bool lireEntier(const char *invite, int *valeur)
{
    char ligne[32];
    // afficher l'invite si pas NULL et pas vide
    // cela ne devrait pas arrivé car on l'utilise toujours avec une invite
    if (invite && invite[0] != '\0')
        printf("%s", invite);

    // si erreur de lecture retourner false
    if (!fgets(ligne, sizeof ligne, stdin))
        return false;

    // Si la ligne n’est pas finie (pas de \n), vider stdin
    if (strchr(ligne, '\n') == NULL)
        viderBuffer();
    // convertir en entier

    return sscanf(ligne, "%d", valeur) == 1;
}

// sous fonction de lireChaine
// verifie que l invite n est pas NULL ou vide
// lit une ligne avec fgets
// vide stdin si la ligne n est pas finie
// supprime le \n final
// retourne true si ok false si erreur ou chaîne vide
bool lireChaine(const char *invite, char *buffer, size_t taille)
{
    // afficher l'invite si pas NULL et pas vide
    // cela ne devrait pas arrivé car on l'utilise toujours avec une invite
    if (invite && invite[0] != '\0')
        printf("%s", invite);
    // si erreur de lecture retourner false
    if (!fgets(buffer, taille, stdin))
        return false;

    // Si la ligne n’est pas finie (pas de \n), vider stdin
    if (strchr(buffer, '\n') == NULL)
        viderBuffer();
    // supprimer le \n final
    supprimerSautLigne(buffer);
    return buffer[0] != '\0'; // on refuse une chaîne vide
}

// Lecture sécurisée d'un entier avec message d'erreur
bool saisirEntier(const char *invite, int *valeur, Info messageErreur)
{
    if (!lireEntier(invite, valeur))
    {
        afficherMessageInfo(messageErreur);
        return false;
    }
    return true;
}

// Lecture sécurisée d'une chaîne avec message d'erreur
bool saisirChaine(const char *invite, char *buffer, size_t taille, Info messageErreur)
{
    if (!lireChaine(invite, buffer, taille))
    {
        afficherMessageInfo(messageErreur);
        return false;
    }
    return true;
}
// Saisir nom, prénom et adresse avec messages d'erreur si invalide
bool saisirNomPrenomAdresse(char *nom, size_t nomSize,
                            char *prenom, size_t prenomSize,
                            char *adresse, size_t adresseSize)
{
    if (!saisirChaine("Veuillez entrer le nom du client: ",
                      nom, nomSize, INFONOMINVALIDE))
        return false;

    if (!saisirChaine("Veuillez entrer le prenom du client: ",
                      prenom, prenomSize, INFOPRENOMINVALIDE))
        return false;

    if (!saisirChaine("Veuillez entrer l'adresse du client: ",
                      adresse, adresseSize, INFOADRESSEINVALIDE))
        return false;

    return true;
}
