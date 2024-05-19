#include "Bibli.h"

#define NOMBRE_ATHLETES 30

typedef struct {
    char nom[50];
    int heures;
    int minutes;
    int secondes;
    int centiemes;
} Temps;


//Tri par insertion de temps
void trier_temps(Temps temps[], int n) {
    // Tri par insertion
    int i, j;
    Temps temp;
    for (i = 1; i < n; i++) {
        temp = temps[i];
        j = i - 1;
        while (j >= 0 && (temps[j].heures > temp.heures || (temps[j].heures == temp.heures && (temps[j].minutes > temp.minutes || (temps[j].minutes == temp.minutes && (temps[j].secondes > temp.secondes || (temps[j].secondes == temp.secondes && temps[j].centiemes > temp.centiemes))))))) {
            temps[j + 1] = temps[j];
            j = j - 1;
        }
        temps[j + 1] = temp;
    }
}

// Affiche 3 athlètes les plus rapides à partir d'un tableau de temps
void afficher_3_plus_rapides(Temps temps[], int n) {
    printf("Les 3 athlètes les plus rapides :\n");
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%s - Temps : %02d:%02d:%02d:%02d \n", temps[i].nom, temps[i].heures, temps[i].minutes, temps[i].secondes, temps[i].centiemes);
    }
    printf("\n");
}


int main() {
    FILE *fichier;
    char ligne[100];
    char delimiteur[] = ";";
    Temps relais[NOMBRE_ATHLETES], m_100[NOMBRE_ATHLETES], marathon[NOMBRE_ATHLETES], m_400[NOMBRE_ATHLETES], m_5000[NOMBRE_ATHLETES];
    int relais_compteur = 0, m_100_compteur = 0, marathon_compteur = 0, m_400_compteur = 0, m_5000_compteur = 0;

    char *fichiers[] = {"Ademo.txt", "Adlaurent.txt", "Ali.txt", "Boulon.txt", "Brandon.txt", "Clovis.txt", "Etienne.txt", "Fujitora.txt", "Gourcuff.txt", "Ilyes.txt", "Jimmy.txt", "Kevin.txt", "Lemaître.txt", "Locqman.txt", "Mandzukic.txt", "Messi.txt", "Mkadir.txt", "Mobutu.txt", "Morant.txt", "Neji.txt", "Pablo.txt", "Pirlo.txt", "Robben.txt", "Samy.txt", "Sneijder.txt", "Stephen.txt", "Sylvestre.txt", "Yann.txt", "krilin.txt", "riman.txt"};


    // Ouverture et lecture de fichier, extrait la donnée temps des fichiers et les stocke dans le tableau approprié
    for (int i = 0; i < 30; i++) {
        fichier = fopen(fichiers[i], "r");

        // Vérifier si l'ouverture a réussi
        if (fichier == NULL) {
            printf("Impossible d'ouvrir le fichier %s.\n", fichiers[i]);
            continue; // Passer au fichier suivant en cas d'échec d'ouverture
        }

        // Lire chaque ligne du fichier
        while (fgets(ligne, sizeof(ligne), fichier)) {
            // Utilisation de strtok() pour diviser la ligne en sous-chaînes
            char *token = strtok(ligne, delimiteur);

            // Ignorer la première colonne (nom de l'athlète)
            token = strtok(NULL, delimiteur);

            // Extraire la discipline
            char discipline[20];
            strcpy(discipline, token);

            // Extraire le temps (heure:minute:seconde:centième)
            token = strtok(NULL, delimiteur);
            int heures, minutes, secondes, centiemes;
            sscanf(token, "%d:%d:%d:%d", &heures, &minutes, &secondes, &centiemes);

            // Stocker le temps dans le tableau correspondant à la discipline
            if (strcmp(discipline, "relais") == 0) {
                strcpy(relais[relais_compteur].nom, fichiers[i]);
                relais[relais_compteur].heures = heures;
                relais[relais_compteur].minutes = minutes;
                relais[relais_compteur].secondes = secondes;
                relais[relais_compteur].centiemes = centiemes;
                relais_compteur++;
            } 
             else if (strcmp(discipline, "100m") == 0) {
                strcpy(m_100[m_100_compteur].nom, fichiers[i]);
                m_100[m_100_compteur].heures = heures;
                m_100[m_100_compteur].minutes = minutes;
                m_100[m_100_compteur].secondes = secondes;
                m_100[m_100_compteur].centiemes = centiemes;
                m_100_compteur++;
            } 
            else if (strcmp(discipline, "marathon") == 0) {
                strcpy(marathon[marathon_compteur].nom, fichiers[i]);
                marathon[marathon_compteur].heures = heures;
                marathon[marathon_compteur].minutes = minutes;
                marathon[marathon_compteur].secondes = secondes;
                marathon[marathon_compteur].centiemes = centiemes;
                marathon_compteur++;
            } 
            else if (strcmp(discipline, "4*400m") == 0) {
                strcpy(m_400[m_400_compteur].nom, fichiers[i]);
                m_400[m_400_compteur].heures = heures;
                m_400[m_400_compteur].minutes = minutes;
                m_400[m_400_compteur].secondes = secondes;
                m_400[m_400_compteur].centiemes = centiemes;
                m_400_compteur++;
            } 
            else if (strcmp(discipline, "5000m") == 0) {
                strcpy(m_5000[m_5000_compteur].nom, fichiers[i]);
                m_5000[m_5000compteur].heures = heures;
                m_5000[m_5000_compteur].minutes = minutes;
                m_5000[m_5000_compteur].secondes = secondes;
                m_5000[m_5000_compteur].centiemes = centiemes;
                m_5000_compteur++;
            }
        }

        // Fermer le fichier
        fclose(fichier);
    }

    // Trier les temps dans chaque tableau par ordre croissant
    trier_temps(relais, relais_compteur);
    trier_temps(m_100, m_100_compteur);
    trier_temps(marathon, marathon_compteur);
    trier_temps(m_400, m_400_compteur);
    trier_temps(m_5000, m_5000_compteur);

    // Afficher les 3 athlètes les plus rapides dans chaque discipline
    printf("Relais :\n");
    afficher_3_plus_rapides(relais, relais_compteur);

    printf("100m :\n");
    afficher_3_plus_rapides(m_100, m_100_compteur);

    printf("Marathon :\n");
    afficher_3_plus_rapides(marathon, marathon_compteur);

    printf("4*400m :\n");
    afficher_3_plus_rapides(m_400, m_400_compteur);

    printf("5000m :\n");
    afficher_3_plus_rapides(m_5000, m_5000_compteur);

    return 0;
}

















