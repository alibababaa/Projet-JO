#include "Bibli.h"

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
    int num_entrainements;        // Nombre d'entrainements enregistrés
    float temps[];               // Temps pour chaque épreuves
} Athlete;

typedef struct {
    float meilleur; // Meilleur temps
    float pire;     // Pire temps
    float moyenne;  // Moyenne des temps
} Performances;

// Fonction qui récupère les temps des athletes et renvoie la moyenne de ces temps
float Tempsmoyen(const Athlete *athlete){
        float totalTemps=NULL;        // initialisation temps total 
        for(i=0,i<5,i++){              // boucle qui parcoure chaque épreuve
                totalTemps+=Athlete.temps[i];  // a chaque itération on ajoute le temps a totalTemps
                }
         return totalTemps/5;  // on renvoi les temps additionnés diviser par le nombre d'épreuves
}
        

void afficherHistorique(Athlete athlete) {
    printf("Historique des entraînements pour %s :\n", athlete.nom);
    for (int i = 0; i < athlete.num_entrainements; i++) {
        printf("Date: %s, Épreuve: %s, Performance: %.2f\n", athlete.entrainements[i].date,
               athlete.entrainements[i].epreuve, athlete.entrainements[i].performance);
    }
}
