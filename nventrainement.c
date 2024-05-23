#include"Bibli.h"
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


/**
Entrainement* creerNouvelEntrainement() {
    Entrainement* nouvelEntrainement = (Entrainement*)malloc(sizeof(Entrainement));
    if (!nouvelEntrainement) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }

    int valid, verif;
    Date date;
    do {
        // Demander à l'utilisateur de saisir la date au format jour/mois/année
        printf("Entrez une date au format jour/mois/année : ");
        verif = scanf("%d/%d/%d", &date.jour, &date.mois, &date.années);

        // Vérifier si la date est valide
        if ((date.jour >= 1 && date.jour <= 31) &&
            (date.mois >= 1 && date.mois <= 12) &&
            (date.années >= 2020 && date.années <= 2024) && verif == 3) {
            valid = 1; // La date est valide, sortir de la boucle
        } else {
            valid = 0;
            printf("Date invalide. Assurez-vous que le jour est entre 1 et 31, le mois est entre 1 et 12, et l'année est entre 2020 et 2024.\n");
        }
    } while (!valid);

    nouvelEntrainement->date = date;

    printf("Quel est le type d'épreuve : ");
    scanf("%s", nouvelEntrainement->epreuve);
    if (strcmp(nouvelEntrainement->epreuve, "100m") != 0 &&
        strcmp(nouvelEntrainement->epreuve, "400m") != 0 &&
        strcmp(nouvelEntrainement->epreuve, "5000m") != 0 &&
        strcmp(nouvelEntrainement->epreuve, "relais") != 0 &&
        strcmp(nouvelEntrainement->epreuve, "marathon") != 0) {
        printf("Erreur de saisie\n");
        free(nouvelEntrainement);
        return NULL;
    }

     heure temps;
    printf("Saisir le temps de l'athlete (heure:minutes:secondes:millisecondes) : ");
    verif = scanf("%d:%d:%d:%d", &temps.heure, &temps.minutes, &temps.secondes, &temps.millisecondes);

    // Vérifier les plages de valeurs pour chaque composante d'heure
    if (temps.heure < 0 || temps.heure > 23 ||
        temps.minutes < 0 || temps.minutes > 59 ||
        temps.secondes < 0 || temps.secondes > 59 ||
        temps.millisecondes < 0 || temps.millisecondes > 999 || verif != 4) {
        printf("Temps invalide. Veuillez vérifier les valeurs saisies.\n");
        free(nouvelEntrainement);
        return NULL;
    }

    nouvelEntrainement->temps = temps;

    if (strcmp(nouvelEntrainement->epreuve, "relais") == 0) {
        printf("Quel etait la position de l'athlete : ");
        verif = scanf("%d", &nouvelEntrainement->position);
        if (nouvelEntrainement->position < 1 || nouvelEntrainement->position > 4 || verif != 1) {
            printf("Erreur de saisie, veuillez saisir un chiffre entre 1 et 4\n");
            free(nouvelEntrainement);
            return NULL;
        }
    } else {
        nouvelEntrainement->position = -1; // Position non applicable
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
    fprintf(fichier, "Date: %02d/%02d/%d\n", entrainement.date.jour, entrainement.date.mois, entrainement.date.annee);
    fprintf(fichier, "Epreuve: %s\n", entrainement.epreuve);
    fprintf(fichier, "Temps: %02d:%02d:%02d:%03d\n", entrainement.temps.heure, entrainement.temps.minutes, entrainement.temps.secondes, entrainement.temps.millisecondes);
    if (entrainement.position != -1) {
        fprintf(fichier, "Position: %d\n", entrainement.position);
    }
    fclose(fichier);
    printf("Votre entrainement a bien été sauvegardé\n");
}

// Fonction main
int main() {
    char ajouterEntrainement;
    do {
        Entrainement* nouvelEntrainement = creerNouvelEntrainement();
        if (nouvelEntrainement != NULL) {
            sauvegarderEntrainement("entrainement.txt", nouvelEntrainement);
            free(nouvelEntrainement);
        }
        printf("Voulez-vous ajouter un nouvel entrainement ? (1=oui 2=non) : ");
        scanf(" %c", &ajouterEntrainement); // Ajout d'un espace pour ignorer les espaces blancs
    } while (ajouterEntrainement == '1');

    return 0;
}**/


    

    


 


        

     


