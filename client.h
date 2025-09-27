#ifndef CLIENT_H
#define CLIENT_H

#include <stdbool.h>
#include "constantes.h"

/*===============================
  Définition de la structure Client
================================*/
typedef struct
{
    int numero;
    char nom[NOMTAILLE + 1];
    char prenom[PRENOMTAILLE + 1];
    char adresse[ADRESSETAILLE + 1];
    bool used;
} Client;

void initClient(Client *client, int numero,
                const char *nom,
                const char *prenom,
                const char *adresse);
/*===============================
  Getters
================================*/
int getNumero(const Client *client);
const char *getNom(const Client *client);
const char *getPrenom(const Client *client);
const char *getAdresse(const Client *client);
bool isUsed(const Client *client);

/*===============================
  Setters
================================*/
void setNumero(Client *client, int numero);
void setNom(Client *client, const char *nom);
void setPrenom(Client *client, const char *prenom);
void setAdresse(Client *client, const char *adresse);
void setUsed(Client *client, bool used);

#endif
