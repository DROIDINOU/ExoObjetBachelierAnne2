#ifndef CLIENT_H
#define CLIENT_H

#include <stdbool.h>
#include "constantes.h"

/*===============================
  Définition de la structure Client
================================*/
typedef enum
{
  NONDEFINI = 0,
  TRESREGULIER = 1,
  REGULIER = 2,
  OCCASIONNEL = 3
} Frequentation;

typedef struct
{
  int numero;
  char nom[NOMTAILLE + 1];
  char prenom[PRENOMTAILLE + 1];
  char adresse[ADRESSETAILLE + 1];
  bool used;
  Frequentation frequentation;
} Client;

/*===============================
  Initialisation & Reset
================================*/
void initClient(Client *client, int numero,
                char *nom,
                char *prenom,
                char *adresse,
                Frequentation frequentation);

void resetClient(Client *client);

/*===============================
  Setters
================================*/
void setNumero(Client *client, int numero);
void setNom(Client *client, char *nom);
void setPrenom(Client *client, char *prenom);
void setAdresse(Client *client, char *adresse);
void setUsed(Client *client, bool used);
void setFrequentation(Client *client, Frequentation frequentation);

/*===============================
  Getters
================================*/
int getNumero(Client *client);
char *getNom(Client *client);
char *getPrenom(Client *client);
char *getAdresse(Client *client);
bool isUsedClient(Client *client);
Frequentation getFrequentation(Client *client);

#endif
