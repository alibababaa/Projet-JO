#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour stocker les informations d'un entraînement
typedef struct {
    char date[20];
    char event[20];
    float time;
    int position; // Utilisé uniquement pour le relais
} Training;

// Structure pour stocker les informations d'un athlète
typedef struct {
    char name[50];
    Training *trainings;
    int num_trainings;
} Athlete;

// Fonction pour ajouter un nouvel entraînement
void addTraining(Athlete *athlete) {
    athlete->trainings = realloc(athlete->trainings, (athlete->num_trainings + 1) * sizeof(Training));
    Training *newTraining = &(athlete->trainings[athlete->num_trainings]);
    
    printf("Date de l'entraînement (jj/mm/aaaa): ");
    scanf("%s", newTraining->date);
    printf("Type d'épreuve: ");
    scanf("%s", newTraining->event);
    printf("Temps réalisé (en secondes): ");
    scanf("%f", &newTraining->time);
    
    // Pour le relais, demander la position de l'athlète
    if (strcmp(newTraining->event, "relais") == 0) {
        printf("Position de l'athlète dans le relais (1 à 4): ");
        scanf("%d", &newTraining->position);
    }
    
    athlete->num_trainings++;
    printf("Entraînement ajouté avec succès.\n");
}

// Fonction pour afficher l'historique des entraînements d'un athlète
void displayTrainingHistory(Athlete athlete) {
    printf("Historique des entraînements pour %s:\n", athlete.name);
    for (int i = 0; i < athlete.num_trainings; i++) {
        printf("Date: %s, Épreuve: %s, Temps: %.2f secondes", 
               athlete.trainings[i].date, 
               athlete.trainings[i].event, 
               athlete.trainings[i].time);
        if (strcmp(athlete.trainings[i].event, "relais") == 0) {
            printf(", Position dans le relais: %d", athlete.trainings[i].position);
        }
        printf("\n");
    }
}

int main() {
    Athlete athlete;
    athlete.num_trainings = 0;
    
    printf("Nom de l'athlète: ");
    scanf("%s", athlete.name);
    
    // Simulation de l'ajout de quelques entraînements
    addTraining(&athlete);
    addTraining(&athlete);
    
    displayTrainingHistory(athlete);
    
    return 0;
}

