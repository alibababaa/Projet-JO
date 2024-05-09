// ChatGPT qui a utilisé le tri pour ressortir les 3 meilleures athletes
void meilleursAthlete(Athlete a, Athlete b, Athlete c, Athlete autres, Athlete *top3) {
    // Tableau pour stocker les 4 moyennes
    float moyennes[4] = {a.moyenne, b.moyenne, c.moyenne, autres.moyenne};

    // Tri des moyennes en ordre décroissant
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (moyennes[i] > moyennes[j]) {
                // Échanger les valeurs si la moyenne actuelle est supérieure à la suivante
                float temp = moyennes[i];
                moyennes[i] = moyennes[j];
                moyennes[j] = temp;
            }
        }
    }

    // Affectation des trois meilleures moyennes aux éléments de top3
    for (int i = 0; i < 3; i++) {
        top3[i].moyenne = moyennes[i];
    }
}

int main() {
    // Déclaration des athlètes avec leurs moyennes de temps
    Athlete a = {10.5};
    Athlete b = {11.2};
    Athlete c = {10.8};
    Athlete autres = {12.0};

    // Tableau pour stocker les trois meilleurs athlètes
    Athlete top3[3];

    // Appel de la fonction pour obtenir les trois meilleurs temps
    meilleursAthletes(a, b, c, autres, top3);

    // Affichage des trois meilleures moyennes de temps
    printf("Les trois meilleures moyennes de temps sont : %.2f, %.2f, %.2f\n", top3[0].moyenne, top3[1].moyenne, top3[2].moyenne);

    return 0;
}









//ChatGPT qui a réecrit la procédure de sorte à ce qu'il prenne en compte les données de chaque fichier
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h> // Ajouté pour FLT_MAX

// Structure pour représenter un athlète
typedef struct {
    char date[20];
    char discipline[20];
    float temps;
} Athlete;

// Fonction pour trouver les 3 meilleurs athlètes par discipline
void meilleursAthletes(const char *nomFichier, Athlete meilleursAthletes[3]) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Initialisation des meilleurs athlètes avec des temps très élevés
    for (int i = 0; i < 3; i++) {
        strcpy(meilleursAthletes[i].date, "");
        strcpy(meilleursAthletes[i].discipline, "");
        meilleursAthletes[i].temps = FLT_MAX;
    }

    // Lecture des données du fichier
    Athlete athlete;
    while (fscanf(fichier, "%s %s %f", athlete.date, athlete.discipline, &athlete.temps) == 3) {
        // Trouver les trois meilleurs athlètes pour chaque discipline
        for (int i = 0; i < 3; i++) {
            if (athlete.temps < meilleursAthletes[i].temps) {
                // Insérer l'athlète dans la position i et décaler les autres
                for (int j = 2; j > i; j--) {
                    strcpy(meilleursAthletes[j].date, meilleursAthletes[j - 1].date);
                    strcpy(meilleursAthletes[j].discipline, meilleursAthletes[j - 1].discipline);
                    meilleursAthletes[j].temps = meilleursAthletes[j - 1].temps;
                }
                strcpy(meilleursAthletes[i].date, athlete.date);
                strcpy(meilleursAthletes[i].discipline, athlete.discipline);
                meilleursAthletes[i].temps = athlete.temps;
                break;
            }
        }
    }

    fclose(fichier);
}

int main() {
    // Tableau pour stocker les 3 meilleurs athlètes par discipline
    Athlete meilleursAthletesParDiscipline[5][3];

    // Noms des fichiers pour chaque discipline
    const char *fichiers[] = {"discipline1.txt", "discipline2.txt", "discipline3.txt", "discipline4.txt", "discipline5.txt"};

    // Trouver les meilleurs athlètes pour chaque discipline
    for (int i = 0; i < 5; i++) {
        meilleursAthletes(fichiers[i], meilleursAthletesParDiscipline[i]);
    }

    // Afficher les meilleurs athlètes par discipline
    for (int i = 0; i < 5; i++) {
        printf("Meilleurs athlètes pour la discipline %d :\n", i+1);
        for (int j = 0; j < 3; j++) {
            printf("Date: %s, Discipline: %s, Temps: %.2f\n", meilleursAthletesParDiscipline[i][j].date, 
                                                                meilleursAthletesParDiscipline[i][j].discipline,
                                                                meilleursAthletesParDiscipline[i][j].temps);
        }
        printf("\n");
    }

    return 0;
}

















// Fonction pour avoir les 3 athlètes avec les meilleures moyennes de temps
void meilleursAthletes(Athlete a, Athlete b, Athlete c, Athlete autres, Athlete *top 3) {

        float moyenne[4]={a.moyenne, b.moyenne, c.moyenne, autres.moyenne};
        
        if (a.moyenne > autres.moyenne && b.moyenne > autres.moyenne && c.moyenne > autres.moyenne) {
                if(a.moyenne > b.moyenne) {
                        return a; }
                else if (b.moyenne > a.moyenne)
                        return b; }
                else if (b.moyenne > c.moyenne) {
                        return b; }
                else if (c.moyenne > b.moyenne) {
                        return c; }
                else if (a.moyenne > c.moyenne)
                        return a; }
                else { 
                        return c; }
        }
        else {
                
        }
          
}
  


