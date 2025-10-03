#ifndef INFOUTILISATEUR_H
#define INFOUTILISATEUR_H

// Définitions des types d'informations à afficher à l'utilisateur
typedef enum
{
    INFOERROR = 0,                  // message d'erreur générique
    INFOSUCCES = 1,                 // succès générique
    INFOSUCCESAJOUT = 2,            // succès après ajout
    INFOSUCCESSSUPPRESSION = 3,     // succès après suppression
    INFOCHOIXCRUD = 4,              // affiche le menu CRUD
    INFOINVITECOMMANDE = 5,         // invite "Votre choix: "
    INFOERRORCHOIXINEXISTANT = 6,   // "Ce choix n'existe pas"
    INFONOMINVALIDE = 7,            // "Nom invalide"
    INFOPRENOMINVALIDE = 8,         // "Prénom invalide"
    INFOADRESSEINVALIDE = 9,        // "Adresse invalide"
    INFONUMEROINVALIDE = 11,        // "Numéro invalide"
    INFONUMEROEXIST = 12,           // "Numéro déjà existant."
    INFOERRORSUPPRESSION = 13,      // "erreur lors de la suppression."
    INFOERREURLISTINGPLEIN = 14,    // "Le listing est plein."
    INFOERRORINCONNUE = 15,         // "Erreur inconnue."
    INFOAUREVOIR = 16,              // "Au revoir!"
    INFOFREQUENTATIONINVALIDE = 17, // "Fréquentation invalide."
    INFOCHOIXTRIAGE = 18            // "Choix de triage"

} Info;

#endif
