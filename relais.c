#include <stdio.h>
#include <stdlib.h>
#include <string.h>


   
// Fonction pour vérifier s'il y a déjà un entrainement de relais à la date donnée
int verifierRelaisExistant(const char* nomFichier, struct Date date) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        return 0; // Pas de fichier, donc pas de relais existant
    }

    char buffer[256]; // proposition de chatgpt buffer==tableau de caractere 
    while (fgets(buffer, sizeof(buffer), fichier)) {
        int jour, mois, annee;
        char epreuve[20];
        if (sscanf(buffer, "Date: %d/%d/%d Epreuve: %s", &jour, &mois, &annee, epreuve) == 4) {
            if (jour == date.jour && mois == date.mois && annee == date.annee && strcmp(epreuve, "relais") == 0) {
                fclose(fichier);
                return 1; // Relais existant trouvé à cette date
            }
        }
    }

    fclose(fichier);
    return 0; // Aucun relais trouvé à cette date
}

// Fonction pour demander à l'utilisateur de créer un entrainement de relais
Entrainement* creerEntrainementRelais(struct Date date) {
    Entrainement* nouvelEntrainement = (Entrainement*)malloc(sizeof(Entrainement));
    if (!nouvelEntrainement) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }

    nouvelEntrainement->date = date;
    strcpy(nouvelEntrainement->epreuve, "relais");

    struct Heure temps;
    int verif;
    printf("Saisir le temps de l'athlete (heure:minutes:secondes:millisecondes) : ");
    verif = scanf("%d:%d:%d:%d", &temps.heure, &temps.minutes, &temps.secondes, &temps.millisecondes);

    // Vérifier les plages de valeurs pour chaque composante d'heure
    if (temps.heure < 0 || temps.heure > 23 ||
        temps.minutes < 0 || temps.minutes > 59 ||
        temps.secondes < 0 || temps.secondes > 59 ||
        temps.millisecondes < 0 || temps.millisecondes > 999 || verif != 4) {
        printf("Temps invalide. Veuillez vérifier les valeurs saisies.\n");
        free(nouvelEntrainement);
        return NULL;
    }

    nouvelEntrainement->temps = temps;

    printf("Quel etait la position de l'athlete (1-4) : ");
    verif = scanf("%d", &nouvelEntrainement->position);
    if (nouvelEntrainement->position < 1 || nouvelEntrainement->position > 4 || verif != 1) {
        printf("Erreur de saisie, veuillez saisir un chiffre entre 1 et 4\n");
        free(nouvelEntrainement);
        return NULL;
    }

    return nouvelEntrainement;
}

// 

    printf("Quel est le type d'épreuve : ");
    scanf("%s", nouvelEntrainement->epreuve);
    if (strcmp(nouvelEntrainement->epreuve, "relais") == 0) {
        // Vérifier s'il y a déjà un entrainement de relais à cette date
        if (verifierRelaisExistant(nomFichier, date)) {
            printf("Un entrainement de relais existe déjà pour cette date. Saisie annulée.\n");
            free(nouvelEntrainement);
            return NULL;
        }
        free(nouvelEntrainement);
        return creerEntrainementRelais(date);
    }

    if (strcmp(nouvelEntrainement->epreuve, "100m") != 0 &&
        strcmp(nouvelEntrainement->epreuve, "400m") != 0 &&
        strcmp(nouvelEntrainement->epreuve, "5000m") != 0 &&
        strcmp(nouvelEntrainement->epreuve, "marathon") != 0) {
        printf("Erreur de saisie\n");
        free(nouvelEntrainement);
        return NULL;
    }

    struct Heure temps;
    printf("Saisir le temps de l'athlete (heure:minutes:secondes:millisecondes) : ");
    verif = scanf("%d:%d:%d:%d", &temps.heure, &temps.minutes, &temps.secondes, &temps.millisecondes);

    // Vérifier les plages de valeurs pour chaque composante d'heure
    if (temps.heure < 0 || temps.heure > 23 ||
        temps.minutes < 0 || temps.minutes > 59 ||
        temps.secondes < 0 || temps.secondes > 59 ||
        temps.millisecondes < 0 || temps.millisecondes > 999 || verif != 4) {
        printf("Temps invalide. Veuillez vérifier les valeurs saisies.\n");
        free(nouvelEntrainement);
        return NULL;
    }

    nouvelEntrainement->temps = temps;
    nouvelEntrainement->date = date;
    nouvelEntrainement->position = -1; // Position non applicable

    return nouvelEntrainement;
}

