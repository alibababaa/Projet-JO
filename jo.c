#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour stocker les informations d'un entraînement
typedef struct {
    char date[20]; // Date de l'épreuve
    char epreuve[20]; // Type d'épreuve
    float temps; // Temps de la performance
    int position; // Utilisé uniquement pour le relais
} Entrainement;

// Structure pour stocker les informations d'un athlète
typedef struct {
    char name[50]; 
    Entrainement *entrainements; // Détails d'un entraînement spécifique de l'athlète
    int num_entrainement; // Nombre d'entrainements enregistrés
} Athlete;

// Structure pour stocker les differentes épreuves 
typedef struct{
        char epreuveA;    //100m
        char epreuveB;    //400m
        char epreuveC;    //5000m
        char epreuveD;    //marathon
        char epreuveE;    //4*400m
}Epreuve;


