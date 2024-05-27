#include "Bibli.h"

// Convertit les heures, minutes, secondes et centièmes en une seule valeur en centièmes de seconde.
int convertionEnCentiemes(int heures, int minutes, int secondes, int centiemes) {
    return (heures * 3600 * 100) + (minutes * 60 * 100) + (secondes * 100) + centiemes;
}

// Convertit une valeur en centièmes de seconde en heures, minutes, secondes et centièmes pour l'affichage.
void convertionDesCentiemes(int totalCentiemes, int *heures, int *minutes, int *secondes, int *centiemes) {
    // Calcul des heures
    *heures = totalCentiemes / (3600 * 100);
    totalCentiemes %= 3600 * 100;

    // Calcul des minutes
    *minutes = totalCentiemes / (60 * 100);
    totalCentiemes %= 60 * 100;

    // Calcul des secondes
    *secondes = totalCentiemes / 100;

    // Calcul des centièmes de seconde
    *centiemes = totalCentiemes % 100;
}

// Fonction pour résumer les performances de l'athlète
void resumePerformance(const char *nomFichier) {
    // Variables pour stocker le meilleur temps, le pire temps, la somme des temps et le nombre de temps
    int meilleurtemps = INT_MAX;
    int piretemps = 0;
    int sommeTemps = 0;
    int nombreTemps = 0;

    // Ouverture du fichier en mode lecture
    FILE *fichier = fopen(nomFichier, "r");
    // Vérification si l'ouverture a réussi
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    // Lecture du fichier ligne par ligne
    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Suppression du caractère de nouvelle ligne en fin de ligne
        ligne[strcspn(ligne, "\n")] = '\0';

        // Variables pour stocker la date, la discipline et le temps
        char date[50], discipline[50], temps[50];
        // Extraction des informations à partir de la ligne lue
        if (sscanf(ligne, "%49[^;]; %49[^;]; %49[^\n]", date, discipline, temps) != 3) {
            printf("Ligne mal formée : %s\n", ligne);
            continue;
        }

        // Variables pour stocker les heures, minutes, secondes et centièmes de seconde
        int heures, minutes, secondes, centiemes;
        // Extraction des heures, minutes, secondes et centièmes de seconde à partir du temps
        if (sscanf(temps, "%d:%d:%d:%d", &heures, &minutes, &secondes, &centiemes) != 4) {
            printf("Format de temps invalide: %s\n", temps);
            continue;
        }

        // Conversion du temps en centièmes de seconde
        int tempsEnCentiemes = convertionEnCentiemes(heures, minutes, secondes, centiemes);
        // Mise à jour du meilleur temps
        if (tempsEnCentiemes < meilleurtemps) {
            meilleurtemps = tempsEnCentiemes;
        }
        // Mise à jour du pire temps
        if (tempsEnCentiemes > piretemps) {
            piretemps = tempsEnCentiemes;
        }
        // Ajout du temps à la somme des temps
        sommeTemps += tempsEnCentiemes;
        // Incrémentation du nombre de temps
        nombreTemps++;
    }

    // Fermeture du fichier
    fclose(fichier);

    // Vérification si des temps ont été trouvés
    if (nombreTemps == 0) {
        printf("Aucun temps trouvé pour l'athlète dans le fichier %s.\n", nomFichier);
        return;
    }

    // Calcul de la moyenne des temps
    int moyenneTemps = sommeTemps / nombreTemps;
    // Variables pour stocker les heures, minutes, secondes et centièmes de seconde
    int heures, minutes, secondes, centiemes;

    // Affichage du résumé des performances de l'athlète
    printf("Résumé des performances de l'athlète dans le fichier %s:\n", nomFichier);

    // Conversion du meilleur temps en heures, minutes, secondes et centièmes de seconde
    convertionDesCentiemes(meilleurtemps, &heures, &minutes, &secondes, &centiemes);
    printf("Meilleur temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);

    // Conversion du pire temps en heures, minutes, secondes et centièmes de seconde
    convertionDesCentiemes(piretemps, &heures, &minutes, &secondes, &centiemes);
    printf("Pire temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);

    // Conversion de la moyenne des temps en heures, minutes, secondes et centièmes de seconde
    convertionDesCentiemes(moyenneTemps, &heures, &minutes, &secondes, &centiemes);
    printf("Moyenne des temps = %02d:%02d:%02d:%02d\n", heures, minutes, secondes, centiemes);
}


