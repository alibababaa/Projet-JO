// Fonction évolution de la perf entre deux entrainemetns que le coach a choisi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un entraînement
typedef struct {
    char date[20];
    float temps;
} Entrainement;

// Fonction pour calculer l'évolution des performances entre deux entraînements
float evolutionPerformance(const char *nomFichier, const char *date1, const char *date2) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lecture des données du fichier
    Entrainement entrainement;
    float temps1 = -1, temps2 = -1;
    while (fscanf(fichier, "%s %f", entrainement.date, &entrainement.temps) == 2) {
        // Vérifier si la date correspond à date1 ou date2
        if (strcmp(entrainement.date, date1) == 0) {
            temps1 = entrainement.temps;
        } else if (strcmp(entrainement.date, date2) == 0) {
            temps2 = entrainement.temps;
        }
    }

    fclose(fichier);

    // Vérifier si les deux dates ont été trouvées dans le fichier
    if (temps1 == -1 || temps2 == -1) {
        printf("Les deux dates d'entraînement doivent être présentes dans le fichier.\n");
        exit(EXIT_FAILURE);
    }

    // Calculer l'évolution des performances
    return temps2 - temps1;
}

int main(int argc, char *argv[]) {

    FILE* fichier = NULL;

    char nomFichier[50], date1[20], date2[20];

    printf("Entrez le nom du fichier contenant les données des entraînements : ");
    scanf("%s", nomFichier);

    printf("Entrez la première date d'entraînement (jj/mm/aaaa) : ");
    scanf("%s", date1);

    printf("Entrez la deuxième date d'entraînement (jj/mm/aaa) : ");
    scanf("%s", date2);

    // Calcul de l'évolution des performances
    float evolution = evolutionPerformance(nomFichier, date1, date2);

    // Affichage de l'évolution des performances
    printf("Evolution des performances entre les deux entraînements : %.2f\n", evolution);

    return 0;
}


















