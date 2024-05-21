/**#include "Bibli.h"

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
    char tabAthlete[50];
    strcpy(tabAthlete, nomFichier);
    strtok(tabAthlete, ".");         // strtok: extrait le nom de l'athlète du nom du fichier (sépare en morceau grâce à un ".")
    strcpy(athlete->nom, tabAthlete);

    // Initialisation du tableau des temps
    athlete->temps = NULL;

    // Initialisation du nombre d'entraînements à 0
    athlete->num_entrainement = 0;

    // Lecture des données du fichier
    Entrainement entrainements[20]; // Supposant qu'il n'y a pas plus de 20 entraînements par athlète
    int i = 0;
    while (fscanf(fichier, "%s %c %c %c %c %c %f %d", entrainements[i].date, &entrainements[i].epreuve->epreuveA, 
                                                   &entrainements[i].epreuve->epreuveB, &entrainements[i].epreuve->epreuveC,
                                                   &entrainements[i].epreuve->epreuveD, &entrainements[i].epreuve->epreuveE, 
                                                   &entrainements[i].temps, &entrainements[i].position) == 8) {
        i++;
    }
    athlete->num_entrainement = i;

    // Allocation de la mémoire pour le tableau des temps
    athlete->temps = (float *)malloc(i * sizeof(float));
    if (athlete->temps == NULL) {
        printf("Erreur lors de l'allocation de la mémoire pour les temps de l'athlète");
        exit(1);
    }

    // Stockage des temps dans le tableau des temps
    for (int j = 0; j < i; j++) {
        athlete->temps[j] = entrainements[j].temps;
    }

    // Fermeture du fichier
    fclose(fichier);

    return athlete;
}

// Fonction pour trouver les 3 meilleurs athlètes par discipline (chatgpt)
void trouverMeilleursAthletes(const char *nomFichier, Athlete *meilleursAthletes[3]) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    // Tableau pour stocker les meilleurs athlètes pour chaque épreuve
    Athlete *meilleurs[5][3] = {NULL};

    // Lecture des données du fichier
    Epreuve epreuve;
    while (fscanf(fichier, "%d-%d-%d %d %f %d", &epreuve.annee, &epreuve.mois, &epreuve.jour, 
                                                &epreuve, &Entrainement.temps, &entrainement.position) == 6) {
        // Parcours de chaque épreuve et comparaison avec les meilleurs temps
        int index = epreuve; // Conversion de l'épreuve en indice pour le tableau
        if (meilleurs[index][0] == NULL || entrainement.temps < meilleurs[index][0]->temps) {
            meilleurs[index][2] = meilleurs[index][1];
            meilleurs[index][1] = meilleurs[index][0];
            meilleurs[index][0] = lireAthlete(nomFichier); // Supposons que vous avez une fonction lireAthlete qui lit un athlète à partir du fichier
        } else if (meilleurs[index][1] == NULL || entrainement.temps < meilleurs[index][1]->temps) {
            meilleurs[index][2] = meilleurs[index][1];
            meilleurs[index][1] = lireAthlete(nomFichier);
        } else if (meilleurs[index][2] == NULL || entrainement.temps < meilleurs[index][2]->temps) {
            meilleurs[index][2] = lireAthlete(nomFichier);
        }
    }

    // Assignation des meilleurs athlètes à la sortie de la fonction
    // Vous devrez adapter cette partie en fonction de votre structure de données et de votre algorithme
    // Supposons que vous stockiez les athlètes dans un tableau
    meilleursAthletes[0] = meilleurs[0][0];
    meilleursAthletes[1] = meilleurs[1][0];
    meilleursAthletes[2] = meilleurs[2][0];

  


    // Fermeture du fichier
    fclose(fichier);

    // Copie des 3 meilleurs athlètes dans le tableau de sortie
    for (int i = 0; i < 3; i++) {
        meilleursAthletes[i] = meilleurs[0][i];
    }
}

/** int main() {
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
            printf("Athlète : %s, Temps : %.2f\n", meilleursAthletes[j]->nom, meilleursAthletes[j]->temps[0]);
        }
        printf("\n");
    }

    // Libération de la mémoire allouée pour les Athletes
    for (int i = 0; i < 30; i++) {
        free(Athlete[i].temps);
        free(athletes[i].entrainements);
        free(athletes[i]);
    }

    return 0;
}

float relais[6]
**/


#include "Bibli.h"

Athlete *lireAthlete(const char *nomFichier) {
    // Votre implémentation de la fonction lireAthlete
}

void trouverMeilleursAthletes(const char *nomFichier, Athlete *meilleursAthletes[3]){
    FILE *fichier = fopen(fichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    Athlete *meilleurs[5][3] = {NULL};

    char date[11];
    int epreuve;
    float temps;
    int position;

    while (fscanf(fichier, "%s %d %f %d", date, &epreuve, &temps, &position) == 4) {
        int index = epreuve;
        if (meilleurs[index][0] == NULL || temps < meilleurs[index][0]->temps[0]) {
            meilleurs[index][2] = meilleurs[index][1];
            meilleurs[index][1] = meilleurs[index][0];
            meilleurs[index][0] = lireAthlete(nomFichier);
        } else if (meilleurs[index][1] == NULL || temps < meilleurs[index][1]->temps[0]) {
            meilleurs[index][2] = meilleurs[index][1];
            meilleurs[index][1] = lireAthlete(nomFichier);
        } else if (meilleurs[index][2] == NULL || temps < meilleurs[index][2]->temps[0]) {
            meilleurs[index][2] = lireAthlete(nomFichier);
        }
    }

    fclose(fichier);

    for (int i = 0; i < 3; i++) {
        meilleursAthletes[i] = meilleurs[0][i];
    }



    // Copie des 3 meilleurs athlètes dans le tableau de sortie
    for (int i = 0; i < 3; i++) {
        meilleursAthletes[i] = meilleurs[0][i];
    }

}























