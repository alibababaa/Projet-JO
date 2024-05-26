#include "Bibli.h"
Entrainement creerNouvelEntrainement() {
    Entrainement nouvelEntrainement;
    int valid, verif;
    Date date;
    do {
        // Demander à l'utilisateur de saisir la date au format jour/mois/année
        printf("Entrez une date au format jour/mois/année : ");
        verif = scanf("%d/%d/%d", &date.jour, &date.mois, &date.annee);

        // Vérifier si la date est valide
        if ((date.jour >= 1 && date.jour <= 31) &&
            (date.mois >= 1 && date.mois <= 12) &&
            (date.annee >= 2020 && date.annee <= 2024) && verif == 3) {
            valid = 1; // La date est valide, sortir de la boucle
        }
        else {
            valid = 0;
            printf("Date invalide. Assurez-vous que le jour est entre 1 et 31, le mois est entre 1 et 12, et l'année est entre 2020 et 2024.\n");
        }
    } while (!valid);

    nouvelEntrainement.date = date;

    printf("Quel est le type d'épreuve (0:100m, 1:400m, 2:5000m, 3:marathon, 4:4*400m) : ");
    int epreuve;
    verif = scanf("%d", &epreuve);
    if (epreuve < 0 || epreuve > 4 || verif != 1) {
        printf("Erreur de saisie\n");
        exit(1);
    }

    nouvelEntrainement.epreuve = (Epreuve)epreuve;

    if (nouvelEntrainement.epreuve == epreuveE) {
        // Vérifier s'il y a déjà un entrainement de relais à cette date
        if (verifierRelaisExistant("entrainements.txt", date)) {
            printf("Un entrainement de relais existe déjà pour cette date. Saisie annulée.\n");
            return creerNouvelEntrainement();
        } else {
            Entrainement* relaisEntrainement = creerEntrainementRelais(date);
            if (relaisEntrainement == NULL) {
                return creerNouvelEntrainement();
            }
            nouvelEntrainement = *relaisEntrainement;
            free(relaisEntrainement);
        }
    } else {
        printf("Saisir le temps de l'athlete (en secondes) : ");
        verif = scanf("%f", &nouvelEntrainement.temps);

        if (verif != 1) {
            printf("Erreur de saisie\n");
            exit(1);
        }

        nouvelEntrainement.position = -1; // Position non applicable
    }

    return nouvelEntrainement;
}

