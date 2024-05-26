#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRAINEMENTS 100     // Nombre maximum d'entraînements qu'un athlète peut avoir
#define MAX_LONGUEUR_LIGNE 100    // Longueur maximale d'une ligne lue dans le fichier
#define NOMBRE_ATHLETES 30
#define MAX_NOM_ATHLETE 50

// Définition de la structure Date pour stocker les informations de date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Définition de la structure Temps pour stocker les informations de temps des athlètes
typedef struct {
    int heures;
    int minutes;
    int secondes;
    int centiemes;
} Temps;

// Structure pour stocker les différentes épreuves
typedef enum {
    epreuveA, //"100m"
    epreuveB, //"400m",
    epreuveC, //"5000m",
    epreuveD, //"marathon",
    epreuveE  //"4*400m"
} Epreuve;

const char* nomEpreuve[] = {
    "100m",
    "400m",
    "5000m",
    "marathon",
    "4*400m"
};

// Structure pour stocker les informations d'un entraînement
typedef struct {
    Date date;       // Date de l'épreuve
    Epreuve epreuve; // Type d'épreuve
    float temps;     // Temps de la performance
    int position;    // Utilisé uniquement pour le relais
} Entrainement;

// Structure pour stocker les informations d'un athlète
typedef struct {
    char nom[MAX_NOM_ATHLETE];               // Nom de l'athlète
    Entrainement entrainements[MAX_ENTRAINEMENTS]; // Détails des entraînements spécifiques de l'athlète
    int num_entrainement;        // Nombre d'entraînements enregistrés
} Athlete;

// Prototypes des fonctions
void afficherHistorique(Athlete athlete);
void chargerDonneesAthlete(Athlete* athlete, const char* nom_fichier);

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
}

void chargerDonneesAthlete(Athlete* athlete, const char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier != NULL) {
        printf("Chargement des données pour l'athlète %s...\n", athlete->nom);
        athlete->num_entrainement = 0;  // Initialiser le compteur d'entraînements à 0

        char ligne[MAX_LONGUEUR_LIGNE];
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            char* token = strtok(ligne, ";");
            if (token != NULL) {
                Date date;
                if (sscanf(token, "%d/%d/%d", &date.jour, &date.mois, &date.annee) == 3) {
                    athlete->entrainements[athlete->num_entrainement].date = date;
                } else {
                    printf("Erreur de format de la date: %s\n", token);
                    continue; // Passer à la ligne suivante si le format de la date est incorrect
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
                    continue; // Passer à la ligne suivante si l'épreuve est manquante
                }

                token = strtok(NULL, ";");
                if (token != NULL) {
                    int heures, minutes, secondes, centiemes;
                    if (sscanf(token, "%d:%d:%d:%d", &heures, &minutes, &secondes, &centiemes) == 4) {
                        athlete->entrainements[athlete->num_entrainement].temps = heures * 3600 + minutes * 60 + secondes + centiemes / 100.0;
                    } else {
                        printf("Erreur de format du temps: %s\n", token);
                        continue; // Passer à la ligne suivante si le temps est incorrect
                    }
                } else {
                    printf("Erreur de format du temps.\n");
                    continue; // Passer à la ligne suivante si le temps est manquant
                }

                athlete->num_entrainement++;
            }
        }
        fclose(fichier);
        printf("Données pour l'athlète %s chargées avec succès.\n", athlete->nom);
    } else {
        printf("Impossible d'ouvrir le fichier %s pour l'athlète %s.\n", nom_fichier, athlete->nom);
    }
}

int main() {
    printf("Début du programme...\n");
    printf("Chargement des données des athlètes...\n");

    int nb_athletes = 0;
    printf("Combien d'athlètes voulez-vous charger ? (maximum 30) : ");
    scanf("%d", &nb_athletes);
    getchar(); // Pour absorber le caractère de nouvelle ligne restant dans le tampon

    if (nb_athletes > NOMBRE_ATHLETES) {
        printf("Le nombre d'athlètes dépasse le maximum autorisé (%d).\n", NOMBRE_ATHLETES);
        return 1;
    }

    Athlete athletes[NOMBRE_ATHLETES];

    for (int i = 0; i < nb_athletes; i++) {
        printf("Entrez le nom de l'athlète %d : ", i + 1);
        fgets(athletes[i].nom, sizeof(athletes[i].nom), stdin);
        athletes[i].nom[strcspn(athletes[i].nom, "\n")] = '\0';
    }

    for (int i = 0; i < nb_athletes; i++) {
        char nom_fichier[100];
        sprintf(nom_fichier, "%s.txt", athletes[i].nom);
        chargerDonneesAthlete(&athletes[i], nom_fichier);
    }

    for (int i = 0; i < nb_athletes; i++) {
        afficherHistorique(athletes[i]);
    }

    printf("Fin du programme.\n");

    return 0;
}
