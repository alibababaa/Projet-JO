#include"Bibli.h"
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
     printf("Nom de l'athlète: %s\n", athlete.nom);
    printf("Nombre d'entraînements: %d\n", athlete.num_entrainement);
}

void copieinfo() {
    Athlete athletes[100];
    int nb_athletes = 0;
    for (int i = 0; i < 100; i++) {
        char nom_fichier[100];
        sprintf(nom_fichier, "%d.txt", i + 1);
        FILE* fichier = fopen(nom_fichier, "r");
        if (fichier != NULL) {
            strcpy(athletes[nb_athletes].nom, nom_fichier);
            athletes[nb_athletes].num_entrainement = 0;
            char ligne[100];
            while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
                char* token = strtok(ligne, " ");
                if (token != NULL) {
                    Date date;
                    if (sscanf(token, "%d/%d/%d", &date.jour, &date.mois, &date.annee) == 3) {
                        // La date a été correctement lue et assignée à la structure date
                    }
                    else {
                        // Gérer les erreurs de format de la date
                    }

                    token = strtok(NULL, " ");
                    athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainement].epreuve = atoi(token);
                    token = strtok(NULL, " ");
                    athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainement].temps = atof(token);
                    athletes[nb_athletes].num_entrainement++;
                }
            }
            fclose(fichier);
            nb_athletes++;
        }
    }

    for (int i = 0; i < nb_athletes; i++) {
        afficherHistorique(athletes[i]);
    }
}
void chargerDonneesAthlete(Athlete* athlete, const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier != NULL) {
        printf("Chargement des données pour l'athlète %s...\n", athlete->nom);
        athlete->num_entrainement = 0;
        char ligne[100];
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            char* token = strtok(ligne, " ");
            if (token != NULL) {
                Date date;
                if (sscanf(token, "%d/%d/%d", &date.jour, &date.mois, &date.annee) == 3) {
                    printf("Date : %d/%d/%d\n", date.jour, date.mois, date.annee);
                }
                else {
                    printf("Erreur de format de la date.\n");
                }

                token = strtok(NULL, " ");
                athlete->entrainements[athlete->num_entrainement].epreuve = atoi(token);
                printf("Epreuve : %d\n", athlete->entrainements[athlete->num_entrainement].epreuve);
                
                token = strtok(NULL, " ");
                athlete->entrainements[athlete->num_entrainement].temps = atof(token);
                printf("Temps : %f\n", athlete->entrainements[athlete->num_entrainement].temps);
                
                athlete->num_entrainement++;
            }
        }
        fclose(fichier);
        printf("Données pour l'athlète %s chargées avec succès.\n", athlete->nom);
    }
    else {
        printf("Impossible d'ouvrir le fichier %s pour l'athlète %s.\n", nom_fichier, athlete->nom);
    }
}
