/**#include"Bibli.h"
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
// Fonction pour charger les données d'un athlète à partir d'un fichier
void chargerDonneesAthlete(Athlete* athlete, const char* nom_fichier) {
    // Ouverture du fichier en mode lecture
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier != NULL) {
        printf("Chargement des données pour l'athlète %s...\n", athlete->nom);
        athlete->num_entrainement = 0;  // Initialiser le compteur d'entraînements à 0

        char ligne[MAX_LONGUEUR_LIGNE];
        // Lire chaque ligne du fichier
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            char* token = strtok(ligne, " ");  // Extraire le premier token (la date)
            if (token != NULL) {
                Date date;
                // Utiliser sscanf pour lire la date au format jj/mm/aaaa
                if (sscanf(token, "%d/%d/%d", &date.jour, &date.mois, &date.annee) == 3) {
                    athlete->entrainements[athlete->num_entrainement].date = date;
                    printf("Date : %d/%d/%d\n", date.jour, date.mois, date.annee);
                } else {
                    printf("Erreur de format de la date.\n");
                    continue; // Passer à la ligne suivante si le format de la date est incorrect
                }

                // Extraire le token suivant pour l'épreuve
                token = strtok(NULL, " ");
                if (token != NULL) {
                    // Copier l'épreuve dans la structure Entrainement
                    strcpy(athlete->entrainements[athlete->num_entrainement].epreuve, token);
                    printf("Épreuve : %s\n", athlete->entrainements[athlete->num_entrainement].epreuve);
                } else {
                    printf("Erreur de format de l'épreuve.\n");
                    continue; // Passer à la ligne suivante si l'épreuve est manquante
                }

                // Extraire le token suivant pour le temps
                token = strtok(NULL, " ");
                if (token != NULL) {
                    // Convertir le temps en flottant et le stocker
                    athlete->entrainements[athlete->num_entrainement].temps = atof(token);
                    printf("Temps : %.2f\n", athlete->entrainements[athlete->num_entrainement].temps);
                } else {
                    printf("Erreur de format du temps.\n");
                    continue; // Passer à la ligne suivante si le temps est manquant
                }

                // Incrémenter le compteur d'entraînements de l'athlète
                athlete->num_entrainement++;
            }
        }
        // Fermer le fichier après la lecture
        fclose(fichier);
        printf("Données pour l'athlète %s chargées avec succès.\n", athlete->nom);
    } else {
        // Message d'erreur si le fichier ne peut pas être ouvert
        printf("Impossible d'ouvrir le fichier %s pour l'athlète %s.\n", nom_fichier, athlete->nom);
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    Athlete athlete;
    strcpy(athlete.nom, "Athlete 1");
    chargerDonneesAthlete(&athlete, "athlete1.txt");
    return 0;
}
**/
