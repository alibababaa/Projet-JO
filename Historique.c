#include "Bibli.h"
const char* nomEpreuve[] = {
    "100m",
    "400m",
    "5000m",
    "marathon",
    "4*400m"
};
void afficherHistorique(Athlete athlete) {
    printf("Historique des entraînements pour %s :\n", athlete.nom);
    for (int i = 0; i < athlete.num_entrainement; i++) {
        printf("Date: %02d/%02d/%d, Épreuve: %s, Performance: %.2f\n",
               athlete.entrainements[i].date.jour,
               athlete.entrainements[i].date.mois,
               athlete.entrainements[i].date.annee,
               nomEpreuve[athlete.entrainements[i].epreuve],
               athlete.entrainements[i].temps);
    }
    printf("Nombre d'entraînements: %d\n", athlete.num_entrainement);


void chargerDonneesAthlete(Athlete* athlete, const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier != NULL) {
        printf("Chargement des données pour l'athlète %s...\n", athlete->nom);
        athlete->num_entrainement = 0;  // Initialiser le compteur d'entraînements à 0

        // Allocation dynamique de mémoire pour le tableau d'entraînements
        athlete->entrainements = malloc(MAX_ENTRAINEMENTS * sizeof(Entrainement));
        if (athlete->entrainements == NULL) {
            printf("Erreur d'allocation de mémoire pour les entraînements.\n");
            return;
        }

        char ligne[MAX_LONGUEUR_LIGNE];
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            char* token = strtok(ligne, ";");
            if (token != NULL) {
                Date date;
                if (sscanf(token, "%d/%d/%d", &date.jour, &date.mois, &date.annee) == 3) {
                    athlete->entrainements[athlete->num_entrainement].date = date;
                } else {
                    printf("Erreur de format de la date: %s\n", token);
                    continue;
                }

                token = strtok(NULL, ";");
                if (token != NULL) {
                    for (int i = 0; i < 5; i++) {
                        if (strcmp(token, nomEpreuve[i]) == 0) {
                            athlete->entrainements[athlete->num_entrainement].epreuve = i;
                            break;
                        }
                    }
                } else {
                    printf("Erreur de format de l'épreuve: %s\n", token);
                    continue;
                }

                token = strtok(NULL, ";");
                if (token != NULL) {
                    int heures, minutes, secondes, centiemes;
                    if (sscanf(token, "%d:%d:%d:%d", &heures, &minutes, &secondes, &centiemes) == 4) {
                        athlete->entrainements[athlete->num_entrainement].temps = heures * 3600 + minutes * 60 + secondes + centiemes / 100.0;
                    } else {
                        printf("Erreur de format du temps: %s\n", token);
                        continue;
                    }
                } else {
                    printf("Erreur de format du temps.\n");
                    continue;
                }

                athlete->num_entrainement++;
                if (athlete->num_entrainement >= MAX_ENTRAINEMENTS) {
                    printf("Nombre maximal d'entraînements atteint pour l'athlète %s.\n", athlete->nom);
                    break;
                }
            } else {
                printf("Token NULL\n");
            }
        }
        fclose(fichier);
        printf("Données pour l'athlète %s chargées avec succès.\n", athlete->nom);
    } else {
        printf("Impossible d'ouvrir le fichier %s pour l'athlète %s.\n", nom_fichier, athlete->nom);
    }
}

void libererMemoireAthlete(Athlete* athlete) {
    // Libération de la mémoire allouée pour les entraînements
    free(athlete->entrainements);
}
}
