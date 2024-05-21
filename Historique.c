#include"Bibli.h"

void afficherHistorique(Athlete athlete) {
    printf("Historique des entraînements pour %s :\n", athlete.nom);
    for (int i = 0; i < athlete.num_entrainement; i++) {
        printf("Date: %s, Épreuve: %s, Performance: %.2f\n", athlete.entrainements[i].date,
               athlete.entrainements[i].epreuve, athlete.entrainements[i].temps);
    }
}

void copieinfo(){
Athlete athletes[100];
    int nb_athletes = 0;
    for (int i = 0; i < 100; i++) {
        char nom_fichier[100];
        sprintf(nom_fichier, "%s.txt", i+1);
        FILE *fichier = fopen(nom_fichier, "r");
        if (fichier != NULL) {
            strcpy(athletes[nb_athletes].nom, nom_fichier);
            athletes[nb_athletes].num_entrainement = 0;
            char ligne[100];
            while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
                char *token = strtok(ligne, " ");
             if (token != NULL) {
    Date date;
    if (sscanf(token, "%d-%d-%d", &date.jour, &date.mois, &date.années) == 3) {
        // La date a été correctement lue et assignée à la structure date
    } else {
        // Gérer les erreurs de format de la date
    }
}

                    token = strtok(NULL, " ");
                    strcpy(athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainement].epreuve, token);
                    token = strtok(NULL, " ");
                    athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainement].temps = atof(token);
                    athletes[nb_athletes].num_entrainement++;
                }
            }
            fclose(fichier);
            nb_athletes++;
        }
    

    for (int i = 0; i < nb_athletes; i++) {
        afficherHistorique(athletes[i]);
    }
}
