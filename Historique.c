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
void chargerDonneesAthletes(Athlete athletes[], char* nom_fichier) {
    printf("Début du chargement des données des athlètes...\n");

    for (int i = 0; i < 100; i++) {
        char nom_fichier[100];
        sprintf(nom_fichier, "%d.txt", i + 1);
        FILE* fichier = fopen(nom_fichier, "r");
        if (fichier != NULL) {
            printf("Fichier %s ouvert avec succès.\n", nom_fichier);
            // Extrait le nom de l'athlète du nom du fichier
            char nom_athlete[50];
            sscanf(nom_fichier, "%[^.]", nom_athlete);
            strcpy(athletes[*nom_athlete].nom, nom_athlete);
            athletes[*nb_athletes].num_entrainement = 0;
            char ligne[100];
            while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
                printf("Ligne lue : %s\n", ligne);
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
                    athletes[*nb_athletes].entrainements[athletes[*nb_athletes].num_entrainement].epreuve = atoi(token);
                    printf("Epreuve : %d\n", athletes[*nb_athletes].entrainements[athletes[*nb_athletes].num_entrainement].epreuve);
                    
                    token = strtok(NULL, " ");
                    athletes[*nb_athletes].entrainements[athletes[*nb_athletes].num_entrainement].temps = atof(token);
                    printf("Temps : %f\n", athletes[*nb_athletes].entrainements[athletes[*nb_athletes].num_entrainement].temps);
                    
                    athletes[*nb_athletes].num_entrainement++;
                }
            }
            fclose(fichier);
            (*nb_athletes)++;
            printf("Fichier %s fermé.\n", nom_fichier);
        }
    }

    printf("Fin du chargement des données des athlètes.\n");
}
