#include "Bibli.h"

int verifierRelaisExistant(const char* nomFichier, Date date) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        return 0; // Pas de fichier, donc pas de relais existant
    }

    char buffer[256]; // Utilisation d'un buffer pour lire les lignes du fichier
    while (fgets(buffer, sizeof(buffer), fichier)) {
        int jour, mois, annee;
        int epreuve;
        if (sscanf(buffer, "%d/%d/%d %d", &jour, &mois, &annee, &epreuve) == 4) {
            if (jour == date.jour && mois == date.mois && annee == date.annee && epreuve == epreuveE) {
                fclose(fichier);
                return 1; // Relais existant trouvé à cette date
            }
        }
    }

    fclose(fichier);
    return 0; // Aucun relais trouvé à cette date
}

Entrainement* creerEntrainementRelais(Date date) {
    Entrainement* nouvelEntrainement = (Entrainement*)malloc(sizeof(Entrainement));
    if (!nouvelEntrainement) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }

    nouvelEntrainement->date = date;
    nouvelEntrainement->epreuve = epreuveE;

    Heure temps;
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

    nouvelEntrainement->temps = temps.heure * 3600 + temps.minutes * 60 + temps.secondes + temps.millisecondes / 1000.0;

    printf("Quelle était la position de l'athlete (1-4) : ");
    verif = scanf("%d", &nouvelEntrainement->position);
    if (nouvelEntrainement->position < 1 || nouvelEntrainement->position > 4 || verif != 1) {
        printf("Erreur de saisie, veuillez saisir un chiffre entre 1 et 4\n");
        free(nouvelEntrainement);
        return NULL;
    }

    return nouvelEntrainement;
}
