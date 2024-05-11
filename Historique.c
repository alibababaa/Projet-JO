#include"Bibli.h"

void afficherHistorique(Athlete athlete) {
    printf("Historique des entraînements pour %s :\n", athlete.nom);
    for (int i = 0; i < athlete.num_entrainements; i++) {
        printf("Date: %s, Épreuve: %s, Performance: %.2f\n", athlete.entrainements[i].date,
               athlete.entrainements[i].epreuve, athlete.entrainements[i].performance);
    }
}

void copieinfo(){
Athlete athletes[MAX_ATHLETES];
    int nb_athletes = 0;
    for (int i = 0; i < MAX_ATHLETES; i++) {
        char nom_fichier[MAX_LONGUEUR_LIGNE];
        sprintf(nom_fichier, "%s.txt", i+1);
        FILE *fichier = fopen(nom_fichier, "r");
        if (fichier != NULL) {
            strcpy(athletes[nb_athletes].nom, nom_fichier);
            athletes[nb_athletes].num_entrainements = 0;
            char ligne[MAX_LONGUEUR_LIGNE];
            while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
                char *token = strtok(ligne, " ");
                if (token != NULL) {
                    strcpy(athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainements].date, token);
                    token = strtok(NULL, " ");
                    strcpy(athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainements].epreuve, token);
                    token = strtok(NULL, " ");
                    athletes[nb_athletes].entrainements[athletes[nb_athletes].nb_entrainements].temps = atof(token);
                    athletes[nb_athletes].num_entrainements++;
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
