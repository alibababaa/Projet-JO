void tabAthlete( float tabathlete[n+1] , int* n ,tempsmoyen, athlete ){
  
  if (int i=0; i<n ; i++){
                         tabathlete[i]=tempsmoyen(athlete.(i+1));
                      }
           printf("%f";tabathlete[n+1]);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define MAX_ATHLETES 50
#define MAX_ENTRAINEMENTS 100
#define MAX_LONGUEUR_LIGNE 100

typedef struct {
    char date[MAX_LONGUEUR_LIGNE];
    char epreuve[MAX_LONGUEUR_LIGNE];
    float performance;
} Entrainement;

typedef struct {
    char nom[MAX_LONGUEUR_LIGNE];
    Entrainement entrainements[MAX_ENTRAINEMENTS];
    int nb_entrainements;
} Athlete;

void afficherHistorique(Athlete athlete) {
    printf("Historique des entraînements pour %s :\n", athlete.nom);
    for (int i = 0; i < athlete.nb_entrainements; i++) {
        printf("Date: %s, Épreuve: %s, Performance: %.2f\n", athlete.entrainements[i].date,
               athlete.entrainements[i].epreuve, athlete.entrainements[i].performance);
    }
}


void copieinfo(){
    for (int i = 0; i < MAX_ATHLETES; i++) {
        char nom_fichier[MAX_LONGUEUR_LIGNE];
        sprintf(nom_fichier, "athlete_%d.txt", i+1);
        FILE *fichier = fopen(nom_fichier, "r");
        if (fichier != NULL) {
            strcpy(athletes[nb_athletes].nom, nom_fichier);
            athletes[nb_athletes].nb_entrainements = 0;
            char ligne[MAX_LONGUEUR_LIGNE];
            while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
                char *token = strtok(ligne, " ");
                if (token != NULL) {
                    strcpy(athletes[nb_athletes].entrainements[athletes[nb_athletes].nb_entrainements].date, token);
                    token = strtok(NULL, " ");
                    strcpy(athletes[nb_athletes].entrainements[athletes[nb_athletes].nb_entrainements].epreuve, token);
                    token = strtok(NULL, " ");
                    athletes[nb_athletes].entrainements[athletes[nb_athletes].nb_entrainements].performance = atof(token);
                    athletes[nb_athletes].nb_entrainements++;
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
int main() {
    Athlete athletes[MAX_ATHLETES];
    int nb_athletes = 0;
    return 0;
}
