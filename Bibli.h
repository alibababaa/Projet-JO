#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


// Structure pour stocker les differentes épreuves 
typedef struct{
        char epreuveA;    //100m
        char epreuveB;    //400m
        char epreuveC;    //5000m
        char epreuveD;    //marathon
        char epreuveE;    //4*400m
} Epreuve;

// Structure pour stocker les informations d'un entraînement
typedef struct {
    char date[11];       // Date de l'épreuve
    Epreuve epreuve[20]; // Type d'épreuve
    float temps;         // Temps de la performance
    int position;        // Utilisé uniquement pour le relais
} Entrainement;

// Structure pour stocker les informations d'un athlète
typedef struct {
    char nom[50];               // Nom de l'athlète
    Entrainement *entrainements; // Détails d'un entraînement spécifique de l'athlète
    int num_entrainement;        // Nombre d'entrainements enregistrés
    float temps[];               // Temps pour chaque épreuves
} Athlete;

typedef struct {
    float meilleur; // Meilleur temps
    float pire;     // Pire temps
    float moyenne;  // Moyenne des temps
} Performances;
typedef struct {
     int heure;
     int minutes;
     int secondes;
     int millisecondes;
}heure;
typedef struct  {
    int jour;
    int mois;
    int années;
}Date;

// prototype des fonctions
float Tempsmoyen();
void tabAthlete();
void copieinfo();
void afficherHistorique(Athlete athlete) ;
void meilleursAthlete(Athlete a, Athlete b, Athlete c, Athlete autres, Athlete *top3) ;
    // Tableau pour stocker les 4 moyennes
float evolutionPerformance(const char *nomFichier, const char *date1, const char *date2) ;
Entrainement creerNouvelentrainement();
void sauvegarderentrainement(const char*nouvelentrainement,const Entrainement*entrainement);
