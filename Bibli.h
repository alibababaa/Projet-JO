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
//void copieinfo();
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








