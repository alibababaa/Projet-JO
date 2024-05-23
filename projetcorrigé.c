#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Structure pour stocker les différentes épreuves
typedef enum {
    epreuveA, //"100m"
    epreuveB, //"400m",
    epreuveC, //"5000m",
    epreuveD, //"marathon",
    epreuveE  //"4*400m"
} Epreuve;

// Tableau de noms d'épreuves correspondant à l'énumération
const char* nomEpreuve[] = {
    "100m",
    "400m",
    "5000m",
    "marathon",
    "4*400m"
};

// Structure pour stocker la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour stocker les informations d'un entraînement
typedef struct {
    Date date;       // Date de l'épreuve
    Epreuve epreuve; // Type d'épreuve
    float temps;     // Temps de la performance
    int position;    // Utilisé uniquement pour le relais
} Entrainement;

// Structure pour stocker les informations d'un athlète
typedef struct {
    char nom[50];               // Nom de l'athlète
    Entrainement* entrainements; // Détails des entraînements spécifiques de l'athlète
    int num_entrainement;        // Nombre d'entraînements enregistrés
    float* temps;               // Temps pour chaque épreuve
} Athlete;

// Prototypes des fonctions
float Tempsmoyen();
void tabAthlete();
void copieinfo();
void afficherHistorique(Athlete athlete);
void meilleursAthlete(Athlete a, Athlete b, Athlete c, Athlete autres, Athlete* top3);
float evolutionPerformance(const char* nomFichier, const char* date1, const char* date2);
Entrainement creerNouvelEntrainement();
void sauvegarderEntrainement(const char* nomFichier, Entrainement entrainement);
Athlete* lireAthlete(const char* nomFichier);
void trouverMeilleursAthletes(const char* nomFichier, Athlete* meilleursAthletes[3]);

Athlete* lireAthlete(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    // Création d'un Athlete
    Athlete* athlete = (Athlete*)malloc(sizeof(Athlete));
    if (athlete == NULL) {
        printf("Erreur lors de l'allocation de la mémoire pour l'athlète\n");
        exit(1);
    }

    // Lecture du nom de l'athlète à partir du nom du fichier
    char nomAthlete[50];
    strcpy(nomAthlete, nomFichier);
    strtok(nomAthlete, ".");  // strtok: extrait le nom de l'athlète du nom du fichier (sépare en morceau grâce à un ".")
    strcpy(athlete->nom, nomAthlete);

    // Initialisation du tableau des temps
    athlete->temps = NULL;

    // Initialisation du nombre d'entraînements à 0
    athlete->num_entrainement = 0;

    // Lecture des données du fichier
    Entrainement entrainements[20]; // Supposant qu'il n'y a pas plus de 20 entraînements par athlète
    int i = 0;
    while (fscanf(fichier, "%d/%d/%d %d %f %d",
                  &entrainements[i].date.jour,
                  &entrainements[i].date.mois,
                  &entrainements[i].date.annee,
                  (int*)&entrainements[i].epreuve,
                  &entrainements[i].temps,
                  &entrainements[i].position) == 6) {
        i++;
    }
    athlete->num_entrainement = i;

    // Allocation de la mémoire pour le tableau des temps
    athlete->temps = (float*)malloc(i * sizeof(float));
    if (athlete->temps == NULL) {
        printf("Erreur lors de l'allocation de la mémoire pour les temps de l'athlète\n");
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

void trouverMeilleursAthletes(const char* nomFichier, Athlete* meilleursAthletes[3]) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    Athlete* meilleurs[5][3] = { NULL };

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
        }
        else if (meilleurs[index][1] == NULL || temps < meilleurs[index][1]->temps[0]) {
            meilleurs[index][2] = meilleurs[index][1];
            meilleurs[index][1] = lireAthlete(nomFichier);
        }
        else if (meilleurs[index][2] == NULL || temps < meilleurs[index][2]->temps[0]) {
            meilleurs[index][2] = lireAthlete(nomFichier);
        }
    }

    fclose(fichier);

    for (int i = 0; i < 3; i++) {
        meilleursAthletes[i] = meilleurs[0][i];
    }
}

void afficherHistorique(Athlete athlete) {
    printf("Historique des entraînements pour %s :\n", athlete.nom);
    for (int i = 0; i < athlete.num_entrainement; i++) {
        printf("Date: %02d/%02d/%d, Épreuve: %s, Performance: %.2f\n",
               athlete.entrainements[i].date.jour,
               athlete.entrainements[i].date.mois,
               athlete.entrainements[i].date.annee,
               nomEpreuve[athlete.entrainements[i].epreuve],
               athlete.entrainements[i].temps);
    }
}

void copieinfo() {
    Athlete athletes[100];
    int nb_athletes = 0;
    for (int i = 0; i < 100; i++) {
        char nom_fichier[100];
        sprintf(nom_fichier, "%d.txt", i + 1);
        FILE* fichier = fopen(nom_fichier, "r");
        if (fichier != NULL) {
            strcpy(athletes[nb_athletes].nom, nom_fichier);
            athletes[nb_athletes].num_entrainement = 0;
            char ligne[100];
            while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
                char* token = strtok(ligne, " ");
                if (token != NULL) {
                    Date date;
                    if (sscanf(token, "%d/%d/%d", &date.jour, &date.mois, &date.annee) == 3) {
                        // La date a été correctement lue et assignée à la structure date
                    }
                    else {
                        // Gérer les erreurs de format de la date
                    }

                    token = strtok(NULL, " ");
                    athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainement].epreuve = atoi(token);
                    token = strtok(NULL, " ");
                    athletes[nb_athletes].entrainements[athletes[nb_athletes].num_entrainement].temps = atof(token);
                    athletes[nb_athletes].num_entrainement++;
                }
            }
            fclose(fichier);
            nb_athletes++;
        }
    }

    for (int i = 0; i < nb_athletes; i++) {
        afficherHistorique(athletes[i]);
    }
}

Entrainement creerNouvelEntrainement() {
    Entrainement nouvelEntrainement;
    int valid, verif;
    Date date;
    do {
        // Demander à l'utilisateur de saisir la date au format jour/mois/année
        printf("Entrez une date au format jour/mois/année : ");
        verif = scanf("%d/%d/%d", &date.jour, &date.mois, &date.annee);

        // Vérifier si la date est valide
        if ((date.jour >= 1 && date.jour <= 31) &&
            (date.mois >= 1 && date.mois <= 12) &&
            (date.annee >= 2020 && date.annee <= 2024) && verif == 3) {
            valid = 1; // La date est valide, sortir de la boucle
        }
        else {
            valid = 0;
            printf("Date invalide. Assurez-vous que le jour est entre 1 et 31, le mois est entre 1 et 12, et l'année est entre 2020 et 2024.\n");
        }
    } while (!valid);

    nouvelEntrainement.date = date;

    printf("Quel est le type d'épreuve (0:100m, 1:400m, 2:5000m, 3:marathon, 4:4*400m) : ");
    int epreuve;
    scanf("%d", &epreuve);
    nouvelEntrainement.epreuve = (Epreuve)epreuve;

    if (epreuve < 0 || epreuve > 4) {
        printf("Erreur de saisie\n");
        exit(1);
    }

    printf("Saisir le temps de l'athlete (en secondes) : ");
    scanf("%f", &nouvelEntrainement.temps);

    if (nouvelEntrainement.epreuve == epreuveE) {
        printf("Quelle était la position de l'athlete : ");
        verif = scanf("%d", &nouvelEntrainement.position);
        if (nouvelEntrainement.position < 1 || nouvelEntrainement.position > 4 || verif != 1) {
            printf("Erreur de saisie, veuillez saisir un chiffre entre 1 et 4\n");
            exit(1);
        }
    }
    else {
        nouvelEntrainement.position = -1; // Position non applicable
    }

    return nouvelEntrainement;
}

// Fonction pour enregistrer le nouvel entrainement dans un fichier
void sauvegarderEntrainement(const char* nomFichier, Entrainement entrainement) {
    FILE* fichier = fopen(nomFichier, "a");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier\n");
        return;
    }
    fprintf(fichier, "%02d/%02d/%d %d %.2f %d\n",
            entrainement.date.jour,
            entrainement.date.mois,
            entrainement.date.annee,
            entrainement.epreuve,
            entrainement.temps,
            entrainement.position);
    fclose(fichier);
    printf("Votre entrainement a bien été sauvegardé\n");
}

int main() {
    int choix;
    printf("Bonjour\n");
    printf("Que voulez-vous faire?\n");
    printf("1- Entrer et sauvegarder les informations d'un nouvel entrainement?\n");
    printf("2- Consulter l'historique des entrainements?\n");
    printf("3- Consulter les statistiques de performances des athlètes?\n");
    scanf("%d", &choix);

    if (choix == 1) {
        while (1) {
            Entrainement nouvelEntrainement = creerNouvelEntrainement();
            sauvegarderEntrainement("entrainements.txt", nouvelEntrainement);
            char ajouterEntrainement;
            printf("Voulez-vous ajouter un nouvel entrainement (y/n) ? ");
            scanf(" %c", &ajouterEntrainement); // Espace avant %c pour consommer le caractère de nouvelle ligne
            if (ajouterEntrainement != 'y') {
                break;
            }
        }
    }
    else if (choix == 2) {
        copieinfo();
    }
    else if (choix == 3) {
        // Noms des fichiers des athlètes
        const char* nomsFichiers[] = {
            "Ademo.txt", "Adlaurent.txt", "Ali.txt", "Bolt.txt", "Brandon.txt", "Clovis.txt", "Etienne.txt", "Fujitora.txt", "Gourcuff.txt", "Ilyes.txt",
            "Jimmy.txt", "Kevin.txt", "Lemaitre.txt", "Locqman.txt", "Mandzukic.txt", "Messi.txt", "Mkadir.txt", "Mobutu.txt", "Morant.txt", "Neji.txt",
            "Pablo.txt", "Pirlo.txt", "Robben.txt", "Samy.txt", "Sneijder.txt", "Stephen.txt", "Sylvestre.txt", "Yann.txt", "krilin.txt", "riman.txt"
        };

        // Tableau pour stocker les 3 meilleurs athlètes par discipline
        Athlete* meilleursAthletes[3];

        // Trouver les meilleurs athlètes pour chaque discipline
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 30; j++) {
                trouverMeilleursAthletes(nomsFichiers[j], meilleursAthletes);
            }
            printf("Meilleurs athlètes pour la discipline %d :\n", i + 1);
            for (int j = 0; j < 3; j++) {
                printf("Athlète : %s, Temps : %.2f\n", meilleursAthletes[j]->nom, meilleursAthletes[j]->temps[i]);
            }
            printf("\n");
        }

        // Libération de la mémoire allouée pour les Athletes
        for (int i = 0; i < 3; i++) {
            free(meilleursAthletes[i]->temps);
            free(meilleursAthletes[i]);
        }
    }
    else {
        printf("Erreur de saisie\n");
    }

    return 0;
}
