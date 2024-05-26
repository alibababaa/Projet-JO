#include "Bibli.h"

#define NOMBRE_ATHLETES 30
#define MAX_NOM_ATHLETE 50


// Fonction pour trier les temps dans un tableau en utilisant le tri par insertion
void trier_temps(Temps temps[], int n) {
    int i, j;
    Temps temp;
    for (i = 1; i < n; i++) {
        temp = temps[i];
        j = i - 1;
        while (j >= 0 && (temps[j].heures > temp.heures ||
                (temps[j].heures == temp.heures && temps[j].minutes > temp.minutes) ||
                (temps[j].heures == temp.heures && temps[j].minutes == temp.minutes && temps[j].secondes > temp.secondes) ||
                (temps[j].heures == temp.heures && temps[j].minutes == temp.minutes && temps[j].secondes == temp.secondes && temps[j].centiemes > temp.centiemes))) {
            temps[j + 1] = temps[j];
            j = j - 1;
        }
        temps[j + 1] = temp;
    }
}

// Fonction pour vérifier si un athlète a déjà été affiché
int est_deja_affiche(const char *nom, char deja_affiche[][MAX_NOM_ATHLETE], int nombre_affiches) {
    for (int i = 0; i < nombre_affiches; i++) {
        if (strcmp(nom, deja_affiche[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Fonction pour afficher les 3 athlètes les plus rapides d'une discipline en évitant les duplications
void afficher_3_plus_rapides(Temps temps[], int n, char deja_affiche[][MAX_NOM_ATHLETE], int *nombre_affiches) {
    int affiches = 0;
    for (int i = 0; i < n && affiches < 3; i++) {
        // Afficher seulement si l'athlète n'a pas déjà été affiché
        if (!est_deja_affiche(temps[i].nom, deja_affiche, *nombre_affiches)) {
            printf("%s - Temps : %02d:%02d:%02d:%02d\n", temps[i].nom, temps[i].heures, temps[i].minutes, temps[i].secondes, temps[i].centiemes);
            // Ajouter le nom de l'athlète à la liste des noms déjà affichés
            strcpy(deja_affiche[*nombre_affiches], temps[i].nom);
            (*nombre_affiches)++;
            affiches++;
        }
    }
    printf("\n");
}



    

