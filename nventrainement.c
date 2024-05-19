

// Structure pour représenter une date
struct Date {
    int jour;
    int mois;
    int années;
};

// Fonction pour demander à l'utilisateur de creer un entrainement
Entrainement* creerNouvelentrainement(){
Entrainement* nouvelentrainement;
    int verif;
    do {
        // Demander à l'utilisateur de saisir la date au format jour/mois/année
        printf("Entrez une date au format jour/mois/année ( : ");
        verif=scanf("%d/%d/%d", &date.jour, &date.mois, &date.annee);

        // Vérifier si la date est valide
        if ((date.jour >= 1 && date.jour <= 31) &&
            (date.mois >= 1 && date.mois <= 12) &&
            (date.annee >= 2020 && date.annee <= 2024)) {
            valid = 1; // La date est valide, sortir de la boucle
        } else {
            valid = 0;
            printf("Date invalide. Assurez-vous que le jour est entre 1 et 31, le mois est entre 1 et 12, et l'année est entre 2020 et 2024.\n");
        }
    } while (valid!=1||verif!=1);

printf("quel est le type d'épreuve/n");
scanf("%c",&epreuve);
if(epreuve!="100m"&&epreuve!="400m"&&epreuve!="5000m"&&epreuve!=relais&&epreuve!=marathon){
  printf("erreur de saisie/n");
}
else {
  return 0;
}

struct heure{
     int heure;
     int minutes;
     int secondes;
     int millisecondes;
}


printf("saisir le temps de l'athlete \n");
scanf("%d:%d:%d:%d",&temps.heure,&temps.minutes,&temps.secondes,&temps.millisecondes);

  // Vérifier les plages de valeurs pour chaque composante d'heure
    if (heures < 0 || heures > 23) {
        printf("Heure invalide. Les heures doivent être comprises entre 0 et 23.\n");
        return 0; // Retourner 0 pour indiquer une erreur de plage
    }
    if (minutes < 0 || minutes > 59) {
        printf("Minutes invalides. Les minutes doivent être comprises entre 0 et 59.\n");
        return 0; // Retourner 0 pour indiquer une erreur de plage
    }
    if (secondes < 0 || secondes > 59) {
        printf("Secondes invalides. Les secondes doivent être comprises entre 0 et 59.\n");
        return 0; // Retourner 0 pour indiquer une erreur de plage
    }
    if (millisecondes < 0 || millisecondes > 999) {
        printf("Millisecondes invalides. Les millisecondes doivent être comprises entre 0 et 999.\n");
        return 0; // Retourner 0 pour indiquer une erreur de plage
    }

 if(epreuve==relais){  // demande pour la position de l'athlete pour un relais
   printf("quel etait la position de l'athlete\n");
   scanf("d%",&position);
   if(position<1 && position>4){
     printf("erreur de saisie,veuillez saisir un chiffre entre 1 et 4\n");
   }
 }
return nouvelentrainement;
}

//fonction pour enregistrer le nouvel entrainement dans un fichier 
void sauvegarderentrainement(const char*nouvelentrainement,const Entrainement*entrainement) {
    FILE*fichier=fopen(nouvelentrainement.txt,"a")
    if(fichier=NULL){
       printf("erreur:impossible d'ouvrir le fichier\n");
       return;
    }
   fprintf(fichier,"Date:%d:%d:%d:%d",nouvelentrainement.date);
   fprintf(fichier,"epreuve:%c",nouvelentrainement.epreuve);
   fprintf(fichier,"Temps:"%f",nouvelentrainement.temps);
   fprintf(fichier,"position:%c",nouvelentrainement.position);
fclose(fichier);
printf("votre entrainement a bien été sauvegarder\n");
}

/**Fonction main
int main(){
Entrainement nouvelentrainement;
char ajouterenrainement;
while(1){
nouvelentrainement=creerNouvelentrainement;
sauvegarderentrainement(&nouvelentrainement);
char ajouterenrainement;
printf("voulez vous ajouter un nouvel entrainement ?\n 1=oui 2=non\n");
scanf("%c",&ajouterentrainement);
if(ajouterentrainement!=1){
    break;
}
printf("votre nouvel entrainement a bien été ajouter\n");
    
return 0;
}
}
**/



// CODE CORRIGE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures pour représenter une date et un entrainement
struct Date {
    int jour;
    int mois;
    int annee;
};

struct Heure {
    int heure;
    int minutes;
    int secondes;
    int millisecondes;
};

typedef struct {
    struct Date date;
    char epreuve[20];
    struct Heure temps;
    int position; // Utilisé uniquement pour les relais
} Entrainement;

// Fonction pour demander à l'utilisateur de créer un entrainement
Entrainement* creerNouvelEntrainement() {
    Entrainement* nouvelEntrainement = (Entrainement*)malloc(sizeof(Entrainement));
    if (!nouvelEntrainement) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }

    int valid, verif;
    struct Date date;
    do {
        // Demander à l'utilisateur de saisir la date au format jour/mois/année
        printf("Entrez une date au format jour/mois/année : ");
        verif = scanf("%d/%d/%d", &date.jour, &date.mois, &date.annee);

        // Vérifier si la date est valide
        if ((date.jour >= 1 && date.jour <= 31) &&
            (date.mois >= 1 && date.mois <= 12) &&
            (date.annee >= 2020 && date.annee <= 2024) && verif == 3) {
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

    struct Heure temps;
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
void sauvegarderEntrainement(const char* nomFichier, const Entrainement* entrainement) {
    FILE* fichier = fopen(nomFichier, "a");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier\n");
        return;
    }
    fprintf(fichier, "Date: %02d/%02d/%d\n", entrainement->date.jour, entrainement->date.mois, entrainement->date.annee);
    fprintf(fichier, "Epreuve: %s\n", entrainement->epreuve);
    fprintf(fichier, "Temps: %02d:%02d:%02d:%03d\n", entrainement->temps.heure, entrainement->temps.minutes, entrainement->temps.secondes, entrainement->temps.millisecondes);
    if (entrainement->position != -1) {
        fprintf(fichier, "Position: %d\n", entrainement->position);
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
}


    


 


        

     


