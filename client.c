#include <string.h>
#include "client.h"

void initClient(Client *client, int numero,
                const char *nom,
                const char *prenom,
                const char *adresse)
{
    setNumero(client, numero);
    setNom(client, nom);
    setPrenom(client, prenom);
    setAdresse(client, adresse);
    setUsed(client, true);
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

bool isUsed(const Client *client)
{
    return client->used;
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
