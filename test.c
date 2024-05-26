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

// Définition de la structure Temps pour stocker les informations de temps des athlètes
typedef struct {
    char nom[MAX_NOM_ATHLETE];
    int heures;
    int minutes;
    int secondes;
    int centiemes;
} Temps;

typedef struct {
    int heure;
    int minutes;
    int secondes;
    int millisecondes;
} Heure;

// Structure pour stocker les différentes épreuves
typedef enum {
    epreuveA, //"100m"
    epreuveB, //"400m",
    epreuveC, //"5000m",
    epreuveD, //"marathon",
    epreuveE  //"4*400m"
} Epreuve;

// Structure pour stocker la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour stocker les informations d'un entraînement
typedef struct {
    Date date;       // Date de l'épreuve
    Epreuve epreuve; // Type d'épreuve
    float temps;     // Temps de la performance
    int position;    // Utilisé uniquement pour le relais
} Entrainement;

// Structure pour stocker les informations d'un athlète
typedef struct {
    char nom[50];               // Nom de l'athlète
    Entrainement* entrainements; // Détails des entraînements spécifiques de l'athlète
    int num_entrainement;        // Nombre d'entraînements enregistrés
    float* temps;               // Temps pour chaque épreuve
} Athlete;

// Prototypes des fonctions
extern const char* nomEpreuve[];
float Tempsmoyen();
void tabAthlete();
void copieinfo();
void afficherHistorique(Athlete athlete);
//void meilleursAthlete(Athlete a, Athlete b, Athlete c, Athlete autres, Athlete* top3);
//float evolutionPerformance(const char* nomFichier, const char* date1, const char* date2);
Entrainement creerNouvelEntrainement();
void sauvegarderEntrainement(const char* nomFichier, Entrainement entrainement);
//Athlete* lireAthlete(const char* nomFichier);
//void trouverMeilleursAthletes(const char* nomFichier, Athlete* meilleursAthletes[3]);
int verifierRelaisExistant(const char* nomFichier, Date date);
Entrainement* creerEntrainementRelais(Date date);
void chargerDonneesAthlete(Athlete* athlete, const char* nom_fichier);
void trier_temps(Temps temps[], int n);
int est_deja_affiche(const char *nom, char deja_affiche[][MAX_NOM_ATHLETE], int nombre_affiches);
void afficher_3_plus_rapides(Temps temps[], int n, char deja_affiche[][MAX_NOM_ATHLETE], int *nombre_affiches);
int convertionEnCentiemes(int heures, int minutes, int secondes, int centiemes);
void convertionDesCentiemes(int totalCentiemes, int *heures, int *minutes, int *secondes, int *centiemes);
void resumePerformance(const char *nomFichier);

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
            athletes[nb_athletes].entrainements = malloc(MAX_ENTRAINEMENTS * sizeof(Entrainement));
            char ligne[100];
            while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
                char* token = strtok(ligne, " ");
                if (token != NULL) {
                    Date date;
                    if (sscanf(token, "%d/%d/%d", &date.jour, &date.mois, &date.annee) == 3) {
                        athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainement].date = date;
                    } else {
                        // Gérer les erreurs de format de la date
                        continue;
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
        athlete->entrainements = malloc(MAX_ENTRAINEMENTS * sizeof(Entrainement));

        char ligne[MAX_LONGUEUR_LIGNE];
        // Lire chaque ligne du fichier
        while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
            char* token = strtok(ligne, " ");  // Extraire le premier token (la date)
            if (token != NULL) {
                Date date;
                // Utiliser sscanf pour lire la date au format jj/mm/aaaa
                if (sscanf(token, "%d/%d/%d", &date.jour, &date.mois, &date.annee) == 3) {
                    athlete->entrainements[athlete->num_entrainement].date = date;
                } else {
                    printf("Erreur de format de la date.\n");
                    continue; // Passer à la ligne suivante si le format de la date est incorrect
                }

                // Extraire le token suivant pour l'épreuve
                token = strtok(NULL, " ");
                if (token != NULL) {
                    athlete->entrainements[athlete->num_entrainement].epreuve = atoi(token);
                } else {
                    printf("Erreur de format de l'épreuve.\n");
                    continue; // Passer à la ligne suivante si l'épreuve est manquante
                }

                // Extraire le token suivant pour le temps
                token = strtok(NULL, " ");
                if (token != NULL) {
                    athlete->entrainements[athlete->num_entrainement].temps = atof(token);
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

int main() {
    printf("Début du programme...\n");
    printf("Chargement des données des athlètes...\n");

    int nb_athletes = 0;
    
    // Demande à l'entraîneur de saisir le nombre d'athlètes
    printf("Combien d'athlètes voulez-vous charger ? (maximum 30) : ");
    scanf("%d", &nb_athletes);
    getchar(); // Pour absorber le caractère de nouvelle ligne restant dans le tampon
    
    if (nb_athletes > NOMBRE_ATHLETES) {
        printf("Le nombre d'athlètes dépasse le maximum autorisé (%d).\n", NOMBRE_ATHLETES);
        return 1;
    }

    Athlete athletes[NOMBRE_ATHLETES];
    
    // Demande à l'entraîneur de saisir le nom de chaque athlète
    for (int i = 0; i < nb_athletes; i++) {
        printf("Entrez le nom de l'athlète %d : ", i + 1);
        fgets(athletes[i].nom, sizeof(athletes[i].nom), stdin);
        // Supprimer le caractère de nouvelle ligne (\n) à la fin du nom
        athletes[i].nom[strcspn(athletes[i].nom, "\n")] = '\0';
    }

    // Chargement des données pour chaque athlète
    for (int i = 0; i < nb_athletes; i++) {
        char nom_fichier[100];
        sprintf(nom_fichier, "%s.txt", athletes[i].nom);
        chargerDonneesAthlete(&athletes[i], nom_fichier);
    }

    // Afficher les entraînements chargés pour chaque athlète
    for (int i = 0; i < nb_athletes; i++) {
        printf("\nEntraînements de l'athlète %s:\n", athletes[i].nom);
        for (int j = 0; j < athletes[i].num_entrainement; j++) {
            Entrainement e = athletes[i].entrainements[j];
            printf("Entraînement %d : Date: %02d/%02d/%04d, Épreuve: %s, Temps: %.2f\n",
                   j + 1, e.date.jour, e.date.mois, e.date.annee, nomEpreuve[e.epreuve], e.temps);
        }
    }

    // Libérer la mémoire allouée pour les entraînements
    for (int i = 0; i < nb_athletes; i++) {
        free(athletes[i].entrainements);
    }

    printf("Fin du programme.\n");
    return 0;
}

