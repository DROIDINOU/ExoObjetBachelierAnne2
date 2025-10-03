#include <string.h>
#include "client.h"

/*===============================
  Initialisation d’un client
/*===============================*/

void initClient(Client *client, int numero,
                const char *nom,
                const char *prenom,
                const char *adresse,
                Frequentation frequentation)
{
    setNumero(client, numero);
    setNom(client, nom);
    setPrenom(client, prenom);
    setAdresse(client, adresse);
    setUsed(client, true);
    setFrequentation(client, frequentation);
}

/*===============================
  Reset d’un client
/*===============================*/
void resetClient(Client *client)
{
    client->numero = 0;
    client->nom[0] = '\0';
    client->prenom[0] = '\0';
    client->adresse[0] = '\0';
    client->used = false;
    client->frequentation = NONDEFINI;
}

/*===============================
  Setters
================================*/
void setNumero(Client *client, int numero)
{
    client->numero = numero;
}

void setNom(Client *client, const char *nom)
{
    strncpy(client->nom, nom, NOMTAILLE);
    client->nom[NOMTAILLE] = '\0'; // sécurité
}

void setPrenom(Client *client, const char *prenom)
{
    strncpy(client->prenom, prenom, PRENOMTAILLE);
    client->prenom[PRENOMTAILLE] = '\0';
}

void setAdresse(Client *client, const char *adresse)
{
    strncpy(client->adresse, adresse, ADRESSETAILLE);
    client->adresse[ADRESSETAILLE] = '\0';
}

void setUsed(Client *client, bool used)
{
    client->used = used;
}

void setFrequentation(Client *client, Frequentation frequentation)
{
    client->frequentation = frequentation;
}

/*===============================
  Getters
================================*/
int getNumero(const Client *client)
{
    return client->numero;
}

const char *getNom(const Client *client)
{
    return client->nom;
}

const char *getPrenom(const Client *client)
{
    return client->prenom;
}

const char *getAdresse(const Client *client)
{
    return client->adresse;
}

Frequentation getFrequentation(const Client *client)
{
    return client->frequentation;
}

bool isUsed(const Client *client)
{
    return client->used;
}
