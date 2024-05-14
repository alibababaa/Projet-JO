#include "Bibli.h"

// Fonction pour lire les données d'un fichier et initialiser un Athlete
Athlete *lireAthlete(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    // Création d'un Athlete
    Athlete *athlete = (Athlete *)malloc(sizeof(Athlete));
    if (athlete == NULL) {
        printf("Erreur lors de l'allocation de la mémoire pour l'athlète");
        exit(1);
    }


    // Lecture du nom de l'athlète à partir du nom du fichier
    char nomAthlete[50];
    strcpy(nomAthlete, nomFichier);
    strtok(nomAthlete, ".");         // strtok: extrait le nom de l'athlète du nom du fichier (sépare en morceau grâce à un ".")
    strcpy(athlete.nom, nomAthlete);

    // Initialisation du tableau des temps
    athlete.temps = NULL;

    // Initialisation du nombre d'entraînements à 0
    athlete.num_entrainements = 0;

    // Lecture des données du fichier
    Entrainement entrainements[20]; // Supposant qu'il n'y a pas plus de 20 entraînements par athlète
    int i = 0;
    while (fscanf(fichier, "%s %c %c %c %c %c %f %d", entrainements[i].date, &entrainements[i].epreuve.epreuveA, 
                                                   &entrainements[i].epreuve.epreuveB, &entrainements[i].epreuve.epreuveC,
                                                   &entrainements[i].epreuve.epreuveD, &entrainements[i].epreuve.epreuveE, 
                                                   &entrainements[i].temps, &entrainements[i].position) == 8) {
        i++;
    }
    athlete.num_entrainements = i;

    // Allocation de la mémoire pour le tableau des temps
    athlete.temps = (float *)malloc(i * sizeof(float));
    if (athlete.temps == NULL) {
        printf("Erreur lors de l'allocation de la mémoire pour les temps de l'athlète");
        exit(1);
    }

    // Stockage des temps dans le tableau des temps
    for (int j = 0; j < i; j++) {
        athlete.temps[j] = entrainements[j].temps;
    }

    // Fermeture du fichier
    fclose(fichier);

    return athlete;
}

// Fonction pour trouver les 3 meilleurs athlètes par discipline
void trouverMeilleursAthletes(const char *nomFichier, Athlete *meilleursAthletes[3]) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    // Tableau pour stocker les meilleurs athlètes pour chaque épreuve
    Athlete *meilleurs[5][3] = {NULL};

    // Lecture des données du fichier
    Entrainement entrainement;
    while (fscanf(fichier, "%s %c %c %c %c %c %f %d", entrainement.date, &entrainement.epreuve.epreuveA, 
                                                   &entrainement.epreuve.epreuveB, &entrainement.epreuve.epreuveC,
                                                   &entrainement.epreuve.epreuveD, &entrainement.epreuve.epreuveE, 
                                                   &entrainement.temps, &entrainement.position) == 8) {
        // Parcours de chaque épreuve et comparaison avec les meilleurs temps
        if (meilleurs[0][0] == NULL || entrainement.temps < meilleurs[0][0].temps[0]) {
            meilleurs[0][2] = meilleurs[0][1];
            meilleurs[0][1] = meilleurs[0][0];
            meilleurs[0][0] = lireAthlete(nomFichier);
        } else if (meilleurs[0][1] == NULL || entrainement.temps < meilleurs[0][1].temps[0]) {
            meilleurs[0][2] = meilleurs[0][1];
            meilleurs[0][1] = lireAthlete(nomFichier);
        } else if (meilleurs[0][2] == NULL || entrainement.temps < meilleurs[0][2].temps[0]) {
            meilleurs[0][2] = lireAthlete(nomFichier);
        }
    }

    // Fermeture du fichier
    fclose(fichier);

    // Copie des 3 meilleurs athlètes dans le tableau de sortie
    for (int i = 0; i < 3; i++) {
        meilleursAthletes[i] = meilleurs[0][i];
    }
}

int main() {
    // Noms des fichiers des athlètes
    const char *nomsFichiers[] = {
        "Ademo.txt", "Adlaurent.txt", "Ali.txt", "Bolt.txt", "Brandon.txt", "Clovis.txt", "Etienne.txt", "Fujitora.txt", "Gourcuff.txt", "Ilyes.txt", 
        "Jimmy.txt", "Kevin.txt", "Lemaitre.txt", "Locqman.txt", "Mandzukic.txt", "Messi.txt", "Mkadir.txt", "Mobutu.txt", "Morant.txt", "Neji.txt",
        "Pablo.txt", "Pirlo.txt", "Robben.txt", "Samy.txt", "Sneijder.txt", "Stephen.txt", "Sylvestre.txt", "Yann.txt", "krilin.txt", "riman.txt"
    };

    // Tableau pour stocker les 3 meilleurs athlètes par discipline
    Athlete *meilleursAthletes[3];

    // Trouver les meilleurs athlètes pour chaque discipline
    for (int i = 0; i < 5; i++) {
        trouverMeilleursAthletes(nomsFichiers[i], meilleursAthletes);
        printf("Meilleurs athlètes pour la discipline %d :\n", i+1);
        for (int j = 0; j < 3; j++) {
            printf("Athlète : %s, Temps : %.2f\n", meilleursAthletes[j].nom, meilleursAthletes[j].temps[0]);
        }
        printf("\n");
    }

    // Libération de la mémoire allouée pour les Athletes
    for (int i = 0; i < 30; i++) {
        free(athletes[i].temps);
        free(athletes[i].entrainements);
        free(athletes[i]);
    }

    return 0;
}









#include "Bibli.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *fichiers[] = {"Ademo.txt", "Adlaurent.txt", "Ali.txt", "Boulon.txt", "Brandon.txt", "Clovis.txt", "Etienne.txt", "Fujitora.txt", "Gourcuff.txt", "Ilyes.txt", "Jimmy.txt", "Kevin.txt", "Lemaître.txt", "Locqman.txt", "Mandzukic.txt", "Messi.txt", "Mkadir.txt", "Mobutu.txt", "Morant.txt", "Neji.txt", "Pablo.txt", "Pirlo.txt", "Robben.txt", "Samy.txt", "Sneijder.txt", "Stephen.txt", "Sylvestre.txt", "Yann.txt", "krilin.txt", "riman.txt"};
    char delimiteur[] = ";";
    char ligne[100];
    char *token;
    int heures_total = 0, minutes_total = 0, secondes_total = 0, centiemes_total = 0;
    int nombre_lignes = 0;

    for (int i = 0; i < sizeof(fichiers) / sizeof(fichiers[0]); i++) {
        FILE *fichier = fopen(fichiers[i], "r");

        // Vérifier si l'ouverture a réussi
        if (fichier == NULL) {
            printf("Impossible d'ouvrir le fichier %s.\n", fichiers[i]);
            continue; // Passer au fichier suivant en cas d'échec d'ouverture
        }

        // Réinitialiser les totaux pour chaque fichier
        heures_total = 0;
        minutes_total = 0;
        secondes_total = 0;
        centiemes_total = 0;
        nombre_lignes = 0;

        // Lire chaque ligne du fichier
        while (fgets(ligne, sizeof(ligne), fichier)) {
            // Utilisation de strtok() pour diviser la ligne en sous-chaînes
            token = strtok(ligne, delimiteur);

            // Ignorer les deux premières colonnes
            token = strtok(NULL, delimiteur);
            token = strtok(NULL, delimiteur);

            // Extraire le temps (heure:minute:seconde:centième) de la troisième colonne
            token = strtok(NULL, delimiteur);
            sscanf(token, "%d:%d:%d:%d", &heures_total, &minutes_total, &secondes_total, &centiemes_total);

            // Calculer la somme totale des temps
            nombre_lignes++;
        }

        // Fermer le fichier
        fclose(fichier);

        // Calculer la moyenne des temps pour le fichier actuel
        int heures_moyenne = heures_total / nombre_lignes;
        int minutes_moyenne = minutes_total / nombre_lignes;
        int secondes_moyenne = secondes_total / nombre_lignes;
        int centiemes_moyenne = centiemes_total / nombre_lignes;

        printf("Moyenne des temps pour le fichier %s : %02d:%02d:%02d:%02d\n", fichiers[i], heures_moyenne, minutes_moyenne, secondes_moyenne, centiemes_moyenne);
    }

    return 0;
}




























