#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define MAX_ENTRAINEMENTS 100     // Nombre maximum d'entraînements qu'un athlète peut avoir
#define MAX_LONGUEUR_LIGNE 100    // Longueur maximale d'une ligne lue dans le fichier
#define NOMBRE_ATHLETES 30
#define MAX_NOM_ATHLETE 50

typedef struct {
    int heures;
    int minutes;
    int secondes;
    int centiemes;
} Temps;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef enum {
    epreuveA, // "100m"
    epreuveB, // "400m"
    epreuveC, // "5000m"
    epreuveD, // "marathon"
    epreuveE  // "4*400m"
} Epreuve;

typedef struct {
    Date date;
    Epreuve epreuve;
    float temps;
    int position;
} Entrainement;

typedef struct {
    char nom[50];
    Entrainement* entrainements;
    int num_entrainement;
} Athlete;

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
}

void chargerDonneesAthlete(Athlete* athlete, const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier != NULL) {
        athlete->num_entrainement = 0;
        char ligne[MAX_LONGUEUR_LIGNE];

        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            if (athlete->num_entrainement >= MAX_ENTRAINEMENTS) break;

            Entrainement e;
            if (sscanf(ligne, "%d/%d/%d %d %f %d",
                       &e.date.jour, &e.date.mois, &e.date.annee,
                       (int*)&e.epreuve, &e.temps, &e.position) == 6) {
                athlete->entrainements[athlete->num_entrainement++] = e;
            } else {
                printf("Erreur de format dans le fichier %s\n", nom_fichier);
            }
        }
        fclose(fichier);
    } else {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
    }
}

int main() {
    printf("Début du programme...\n");

    int nb_athletes;
    printf("Combien d'athlètes voulez-vous charger ? (maximum 30) : ");
    scanf("%d", &nb_athletes);
    getchar(); // Pour consommer le caractère de nouvelle ligne restant

    if (nb_athletes > NOMBRE_ATHLETES) {
        printf("Le nombre d'athlètes dépasse le maximum autorisé (%d).\n", NOMBRE_ATHLETES);
        return 1;
    }

    Athlete athletes[NOMBRE_ATHLETES];
    for (int i = 0; i < nb_athletes; i++) {
        printf("Entrez le nom de l'athlète %d : ", i + 1);
        fgets(athletes[i].nom, sizeof(athletes[i].nom), stdin);
        athletes[i].nom[strcspn(athletes[i].nom, "\n")] = '\0'; // Supprimer le '\n' à la fin
        athletes[i].entrainements = (Entrainement*)malloc(MAX_ENTRAINEMENTS * sizeof(Entrainement));
    }

    for (int i = 0; i < nb_athletes; i++) {
        char nom_fichier[100];
        sprintf(nom_fichier, "%s.txt", athletes[i].nom);
        chargerDonneesAthlete(&athletes[i], nom_fichier);
    }

    for (int i = 0; i < nb_athletes; i++) {
        printf("\nEntraînements de l'athlète %s:\n", athletes[i].nom);
        afficherHistorique(athletes[i]);
        free(athletes[i].entrainements); // Libération de la mémoire allouée
    }

    printf("Fin du programme.\n");
    return 0;
}
