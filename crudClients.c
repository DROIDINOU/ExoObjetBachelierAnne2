#include <string.h>
#include "client.h"      // contient les prototypes des getters/setters + initClient
#include "crudClients.h" // contient Clients + prototypes du CRUD
#include "affichage.h"

/*======================================================================
  Fonctions privées
 ======================================================================*/

// Cherche une case libre dans le tableau
static int trouverEspaceLibre(const Clients *clients)
{
    for (int i = 0; i < MAXCLIENTS; ++i)
    {
        if (!isUsed(&clients->tabClients[i])) // utilisation du getter
            return i;
    }
    return -1;
}

// Trouve un client par son numéro
static int trouverIndex(const Clients *clients, int numero)
{
    for (int i = 0; i < MAXCLIENTS; ++i)
    {
        if (isUsed(&clients->tabClients[i]) &&
            getNumero(&clients->tabClients[i]) == numero) // getters
        {
            return i;
        }
    }
    return -1;
}

/*======================================================================
  Fonctions de vérification
 ======================================================================*/

bool estPlein(const Clients *clients)
{
    if (clients->countUsed >= MAXCLIENTS)
    {
        afficherMessageInfo(INFOERREURLISTINGPLEIN);
        return true;
    }
    return false;
}

bool numeroExiste(const Clients *clients, int numero)
{
    if (trouverIndex(clients, numero) != -1)
    {
        afficherMessageInfo(INFONUMEROEXIST);
        return true;
    }
    return false;
}

/*======================================================================
  Fonctions CRUD
 ======================================================================*/

bool ajouter(Clients *clients, int numero,
             const char *nom, const char *prenom, const char *adresse)
{
    int idx = trouverEspaceLibre(clients);
    if (idx == -1)
    {
        return false; // pas de case libre
    }

    // Initialiser le client avec les setters
    initClient(&clients->tabClients[idx], numero, nom, prenom, adresse);

    clients->countUsed++;
    return true;
}

bool supprimer(Clients *clients, int numero)
{
    int idx = trouverIndex(clients, numero);
    if (idx == -1)
    {
        afficherMessageInfo(INFOERRORSUPPRESSION);
        return false;
    }

    setUsed(&clients->tabClients[idx], false); // setter au lieu de .used = false
    clients->countUsed--;
    return true;
}
