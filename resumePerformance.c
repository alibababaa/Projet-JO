/**#include "Bibli.h"


// Convertit les heures, minutes, secondes et centièmes en une seule valeur en centièmes de seconde.
int convertionEnCentiemes(int heures, int minutes, int secondes, int centiemes) {
    return (heures * 3600 * 100) + (minutes * 60 * 100) + (secondes * 100) + centiemes;
}

// Convertit une valeur en centièmes de seconde en heures, minutes, secondes et centièmes pour l'affichage.
void convertionDesCentiemes(int totalCentiemes, int *heures, int *minutes, int *secondes, int *centiemes) {
    *heures = totalCentiemes / (3600 * 100);
    totalCentiemes %= 3600 * 100;
    *minutes = totalCentiemes / (60 * 100);
    totalCentiemes %= 60 * 100;
    *secondes = totalCentiemes / 100;
    *centiemes = totalCentiemes % 100;
}

void resumePerformance(const char *nomFichier) {
    int meilleurtemps = INT_MAX;
    int piretemps = 0;
    int sommeTemps = 0;
    int nombreTemps = 0;

    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        exit(1);
    }

    char ligne[100];
    const char delimiteur[] = ";";
    // fgets lit une ligne à partir d'un flux de données.
    while (fgets(ligne, sizeof(ligne), fichier)) {
        char *token = strtok(ligne, delimiteur);

        // Ignorer la première colonne (date)
        token = strtok(NULL, delimiteur);

        // Ignorer la deuxième colonne (discipline)
        token = strtok(NULL, delimiteur);

        // Extraire le temps (heure:minute:seconde:centième)
        token = strtok(NULL, delimiteur);
        int heures, minutes, secondes, centiemes;
        if (sscanf(token, "%d:%d:%d:%d", &heures, &minutes, &secondes, &centiemes) != 4) {
            printf("Format de temps invalide dans le fichier %s.\n", nomFichier);
            continue;
        }

        int tempsEnCentiemes = convertionEnCentiemes(heures, minutes, secondes, centiemes);
        if (tempsEnCentiemes < meilleurtemps) {
            meilleurtemps = tempsEnCentiemes;
        }
        if (tempsEnCentiemes > piretemps) {
            piretemps = tempsEnCentiemes;
        }
        sommeTemps += tempsEnCentiemes;
        nombreTemps++;
    }

    fclose(fichier);

    if (nombreTemps == 0) {
        printf("Aucun temps trouvé pour l'athlète dans le fichier %s.\n", nomFichier);
        return;
    }

    int moyenneTemps = sommeTemps / nombreTemps;
    int heures, minutes, secondes, centiemes;

    printf("Résumé des performances de l'athlète dans le fichier %s:\n", nomFichier);

    convertionDesCentiemes(meilleurtemps, &heures, &minutes, &secondes, &centiemes);
    printf("Meilleur temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);

    convertionDesCentiemes(piretemps, &heures, &minutes, &secondes, &centiemes);
    printf("Pire temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);

    convertionDesCentiemes(moyenneTemps, &heures, &minutes, &secondes, &centiemes);
    printf("Moyenne des temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);
}

int main() {
    // Liste des prénoms des athlètes
    char *prenoms[] = {
        "Ademo", "Adlaurent", "Ali", "Bolt", "Brandon", "Clovis", "Etienne", "Fujitora",
        "Gourcuff", "Ilyes", "Jimmy", "Kevin", "Krilin", "Lemaître", "Locqman", "Mandzukic",
        "Messi", "Mkadir", "Mobutu", "Morant", "Neji", "Pablo", "Pirlo", "Robben",
        "Samy", "Sneijder", "Stephen", "Sylvestre", "Yann",  "Riman"};
        
    int nombreAthletes = sizeof(prenoms) / sizeof(prenoms[0]);

    int athleteResume;
    char nomFichier[100];

    printf("De quel athlète voulez-vous le résumé ?\n");
    for (int i = 0; i < nombreAthletes; i++) {
        printf("%d: %s\n", i + 1, prenoms[i]);
    }

    printf("Entrez le numéro correspondant à l'athlète: ");
    scanf("%d", &athleteResume);

    if (athleteResume < 1 || athleteResume > nombreAthletes) {
        printf("Erreur de saisie de numéro.\n");
        return 1;
    }

    snprintf(nomFichier, sizeof(nomFichier), "%s.txt", prenoms[athleteResume - 1]);

    resumePerformance(nomFichier);

    return 0;
}**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Convertit les heures, minutes, secondes et centièmes en une seule valeur en centièmes de seconde.
int convertionEnCentiemes(int heures, int minutes, int secondes, int centiemes) {
    return (heures * 3600 * 100) + (minutes * 60 * 100) + (secondes * 100) + centiemes;
}

// Convertit une valeur en centièmes de seconde en heures, minutes, secondes et centièmes pour l'affichage.
void convertionDesCentiemes(int totalCentiemes, int *heures, int *minutes, int *secondes, int *centiemes) {
    *heures = totalCentiemes / (3600 * 100);
    totalCentiemes %= 3600 * 100;
    *minutes = totalCentiemes / (60 * 100);
    totalCentiemes %= 60 * 100;
    *secondes = totalCentiemes / 100;
    *centiemes = totalCentiemes % 100;
}

void resumePerformance(const char *nomFichier) {
    int meilleurtemps = INT_MAX;
    int piretemps = 0;
    int sommeTemps = 0;
    int nombreTemps = 0;

    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        exit(1);
    }

    char ligne[100];
    const char delimiteur[] = ";";
    // fgets lit une ligne à partir d'un flux de données.
    while (fgets(ligne, sizeof(ligne), fichier)) {
        char *token = strtok(ligne, delimiteur);

        // Ignorer la première colonne (date)
        token = strtok(NULL, delimiteur);

        // Ignorer la deuxième colonne (discipline)
        token = strtok(NULL, delimiteur);

        // Extraire le temps (heure:minute:seconde:centième)
        token = strtok(NULL, delimiteur);
        int heures, minutes, secondes, centiemes;
        if (sscanf(token, "%d:%d:%d:%d", &heures, &minutes, &secondes, &centiemes) != 4) {
            printf("Format de temps invalide dans le fichier %s.\n", nomFichier);
            continue;
        }

        int tempsEnCentiemes = convertionEnCentiemes(heures, minutes, secondes, centiemes);
        if (tempsEnCentiemes < meilleurtemps) {
            meilleurtemps = tempsEnCentiemes;
        }
        if (tempsEnCentiemes > piretemps) {
            piretemps = tempsEnCentiemes;
        }
        sommeTemps += tempsEnCentiemes;
        nombreTemps++;
    }

    fclose(fichier);

    if (nombreTemps == 0) {
        printf("Aucun temps trouvé pour l'athlète dans le fichier %s.\n", nomFichier);
        return;
    }

    int moyenneTemps = sommeTemps / nombreTemps;
    int heures, minutes, secondes, centiemes;

    printf("Résumé des performances de l'athlète dans le fichier %s:\n", nomFichier);

    convertionDesCentiemes(meilleurtemps, &heures, &minutes, &secondes, &centiemes);
    printf("Meilleur temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);

    convertionDesCentiemes(piretemps, &heures, &minutes, &secondes, &centiemes);
    printf("Pire temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);

    convertionDesCentiemes(moyenneTemps, &heures, &minutes, &secondes, &centiemes);
    printf("Moyenne des temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);
}

int main() {
    // Liste des prénoms des athlètes
    const char *prenoms[] = {
        "Ademo", "Adlaurent", "Ali", "Bolt", "Brandon", "Clovis", "Etienne", "Fujitora",
        "Gourcuff", "Ilyes", "Jimmy", "Kevin", "Krilin", "Lemaître", "Locqman", "Mandzukic",
        "Messi", "Mkadir", "Mobutu", "Morant", "Neji", "Pablo", "Pirlo", "Robben",
        "Samy", "Sneijder", "Stephen", "Sylvestre", "Yann", "Riman"
    };
    int nombreAthletes = sizeof(prenoms) / sizeof(prenoms[0]);

    int athleteResume;
    char nomFichier[100];

    printf("De quel athlète voulez-vous le résumé ?\n");
    for (int i = 0; i < nombreAthletes; i++) {
        printf("%d: %s\n", i + 1, prenoms[i]);
    }

    printf("Entrez le numéro correspondant à l'athlète: ");
    scanf("%d", &athleteResume);

    if (athleteResume < 1 || athleteResume > nombreAthletes) {
        printf("Erreur de saisie de numéro.\n");
        return 1;
    }

    snprintf(nomFichier, sizeof(nomFichier), "%s.txt", prenoms[athleteResume - 1]);

    resumePerformance(nomFichier);

    return 0;
}





















    
















    


