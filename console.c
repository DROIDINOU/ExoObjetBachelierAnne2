#include <stdio.h>
#include <string.h>
#include "console.h"
#include "outils.h"
#include <stdlib.h>

// initialisation console vide
void initConsole(Console *c)
{
    c->_vide = 0;
    // (void)c; pourrait aussi faire l'affaire
}

/*---------------------------------------------------------------
# Sous fonctions  de saisirEntierConsole et saisirchaineConsole
-----------------------------------------------------------------/*/

bool lireEntierConsole(Console *c, int *valeur, char *invite)
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

bool lireChaineConsole(Console *c, char *buffer, size_t taille, char *invite)
{
    (void)c;
    if (invite && invite[0] != '\0')
        printf("%s", invite);

    if (!fgets(buffer, taille, stdin))
        return false;

    if (strchr(buffer, '\n') == NULL)
        viderBuffer();

    supprimerSautLigne(buffer);
    return buffer[0] != '\0';
}

/*---------------------------------------------------------------
# Saisie des entiers et saisie des chaines
# Sous fonctions de saisirInfosCrud
-----------------------------------------------------------------/*/
// saisie entier
bool saisirEntierConsole(Console *c, int *valeur, char *invite, Info messageErreur)
{
    if (!lireEntierConsole(c, valeur, invite))
    {
        afficherMessageConsole(c, messageErreur);
        return false;
    }
    return true;
}
// saisir chaine
bool saisirChaineConsole(Console *c, char *buffer, size_t taille, char *invite, Info messageErreur)
{
    if (!lireChaineConsole(c, buffer, taille, invite))
    {
        afficherMessageConsole(c, messageErreur);
        return false;
    }
    return true;
}

/*_________________________________________________________________
# FONCTIONS PRICIPALES
# affichage messages utilisateurs
# affichage liste des clients
# affichage tri
__________________________________________________________________/*/

/*======================================================================
  Affichage des messages d info / erreurs
 ======================================================================*/
void afficherMessageConsole(Console *c, Info info)

{
    (void)c;
    switch (info)
    {

    case INFOSUCCES:
        printf("✅ Opération réussie.\n");
        break;
    case INFOSUCCESAJOUT:
        printf("✅ Ajout OK.\n");
        break;
    case INFOSUCCESSSUPPRESSION:
        printf("✅ Suppression OK.\n");
        break;
    case INFOCHOIXCRUD:
        printf("🔄\n1) Ajouter  2) Supprimer  3) Afficher 4=Trier par fréquence  0) Quitter\n");
        break;
    case INFOCHOIXTRIAGE:
        printf("🔄\n trier par : 1=Très régulier  2=Régulier  3=Occasionnel\n");
        break;
    case INFOINVITECOMMANDE:
        printf("Votre choix: ");
        break;
    case INFOAUREVOIR:
        printf("Fin du CRUD!\n");
        break;
    case INFOERROR:
        printf("❌ Choix invalide.\n");
        break;
    case INFOERRORCHOIXINEXISTANT:
        printf("❌ Ce choix n'existe pas dans le menu.\n");
        break;
    case INFONOMINVALIDE:
        printf("❌ Nom invalide.\n");
        break;
    case INFOFREQUENTATIONINVALIDE:
        printf("❌ Fréquentation invalide.\n");
        break;
    case INFOPRENOMINVALIDE:
        printf("❌ Prénom invalide.\n");
        break;
    case INFOADRESSEINVALIDE:
        printf("❌ Adresse invalide.\n");
        break;
    case INFONUMEROINVALIDE:
        printf("❌ Numéro invalide.\n");
        break;
    case INFOERREURLISTINGPLEIN:
        printf("❌ Le listing est plein.\n");
        break;
    case INFONUMEROEXIST:
        printf("❌ Numéro déjà existant.\n");
        break;
    case INFOERRORSUPPRESSION:
        printf("❌ Numéro de client introuvable.\n");
        break;
    case INFOERRORINCONNUE:
        printf("❌ Erreur inconnue.\n");
        break;
    default:
        printf("❓ Message inconnu.\n");
        break;
    }
}
