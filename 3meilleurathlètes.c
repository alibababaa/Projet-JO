#include "Bibli.h"


#define NOMBRE_ATHLETES 30

typedef struct {
    char nom[50];
    int heures;
    int minutes;
    int secondes;
    int centiemes;
} Temps;

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

void afficher_3_plus_rapides(Temps temps[], int n) {
    printf("Les 3 athlètes les plus rapides :\n");
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%s - Temps : %02d:%02d:%02d:%02d\n", temps[i].nom, temps[i].heures, temps[i].minutes, temps[i].secondes, temps[i].centiemes);
    }
    printf("\n");
}

int main() {
    FILE *fichier;
    char ligne[100];
    const char delimiteur[] = ";";
    Temps relais[NOMBRE_ATHLETES], m_100[NOMBRE_ATHLETES], marathon[NOMBRE_ATHLETES], m_400[NOMBRE_ATHLETES], m_5000[NOMBRE_ATHLETES];
    int relais_count = 0, m_100_count = 0, marathon_count = 0, m_400_count = 0, m_5000_count = 0;

    char *fichiers[] = {"Ademo.txt", "Adlaurent.txt", "Ali.txt", "Boulon.txt", "Brandon.txt", "Clovis.txt", "Etienne.txt", "Fujitora.txt", "Gourcuff.txt", "Ilyes.txt", "Jimmy.txt", "Kevin.txt", "Lemaître.txt", "Locqman.txt", "Mandzukic.txt", "Messi.txt", "Mkadir.txt", "Mobutu.txt", "Morant.txt", "Neji.txt", "Pablo.txt", "Pirlo.txt", "Robben.txt", "Samy.txt", "Sneijder.txt", "Stephen.txt", "Sylvestre.txt", "Yann.txt", "krilin.txt", "riman.txt"};

    for (int i = 0; i < NOMBRE_ATHLETES; i++) {
        fichier = fopen(fichiers[i], "r");

        // Vérifier si l'ouverture a réussi
        if (fichier == NULL) {
            fprintf(stderr, "Impossible d'ouvrir le fichier %s.\n", fichiers[i]);
            continue; // Passer au fichier suivant en cas d'échec d'ouverture
        }

        // Lire chaque ligne du fichier
        while (fgets(ligne, sizeof(ligne), fichier)) {
            // Utilisation de strtok() pour diviser la ligne en sous-chaînes
            char *token = strtok(ligne, delimiteur);

            // Ignorer la première colonne (date)
            token = strtok(NULL, delimiteur);

            // Extraire la discipline
            char discipline[20];
            if (token == NULL) continue; // Protection contre les lignes mal formées
            strcpy(discipline, token);

            // Extraire le temps (heure:minute:seconde:centième)
            token = strtok(NULL, delimiteur);
            if (token == NULL) continue; // Protection contre les lignes mal formées
            int heures, minutes, secondes, centiemes;
            if (sscanf(token, "%d:%d:%d:%d", &heures, &minutes, &secondes, &centiemes) != 4) {
                fprintf(stderr, "Format de temps invalide dans le fichier %s.\n", fichiers[i]);
                continue; // Passer à la ligne suivante en cas de format de temps invalide
            }

            // Stocker le temps dans le tableau correspondant à la discipline
            if (strcmp(discipline, "relais") == 0) {
                if (relais_count < NOMBRE_ATHLETES) {
                    strcpy(relais[relais_count].nom, fichiers[i]);
                    relais[relais_count].heures = heures;
                    relais[relais_count].minutes = minutes;
                    relais[relais_count].secondes = secondes;
                    relais[relais_count].centiemes = centiemes;
                    relais_count++;
                } else {
                    fprintf(stderr, "Nombre maximum d'athlètes pour la discipline relais atteint.\n");
                }
            } else if (strcmp(discipline, "100m") == 0) {
                if (m_100_count < NOMBRE_ATHLETES) {
                    strcpy(m_100[m_100_count].nom, fichiers[i]);
                    m_100[m_100_count].heures = heures;
                    m_100[m_100_count].minutes = minutes;
                    m_100[m_100_count].secondes = secondes;
                    m_100[m_100_count].centiemes = centiemes;
                    m_100_count++;
                } else {
                    fprintf(stderr, "Nombre maximum d'athlètes pour la discipline 100m atteint.\n");
                }
            } else if (strcmp(discipline, "marathon") == 0) {
                if (marathon_count < NOMBRE_ATHLETES) {
                    strcpy(marathon[marathon_count].nom, fichiers[i]);
                    marathon[marathon_count].heures = heures;
                    marathon[marathon_count].minutes = minutes;
                    marathon[marathon_count].secondes = secondes;
                    marathon[marathon_count].centiemes = centiemes;
                    marathon_count++;
                } else {
                    fprintf(stderr, "Nombre maximum d'athlètes pour la discipline marathon atteint.\n");
                }
            } else if (strcmp(discipline, "4*400m") == 0) {
                if (m_400_count < NOMBRE_ATHLETES) {
                    strcpy(m_400[m_400_count].nom, fichiers[i]);
                    m_400[m_400_count].heures = heures;
                    m_400[m_400_count].minutes = minutes;
                    m_400[m_400_count].secondes = secondes;
                    m_400[m_400_count].centiemes = centiemes;
                    m_400_count++;
                } else {
                    fprintf(stderr, "Nombre maximum d'athlètes pour la discipline 4*400m atteint.\n");
                }
            } else if (strcmp(discipline, "5000m") == 0) {
                if (m_5000_count < NOMBRE_ATHLETES) {
                    strcpy(m_5000[m_5000_count].nom, fichiers[i]);
                    m_5000[m_5000_count].heures = heures;
                    m_5000[m_5000_count].minutes = minutes;
                    m_5000[m_5000_count].secondes = secondes;
                    m_5000[m_5000_count].centiemes = centiemes;
                    m_5000_count++;
                } else {
                    fprintf(stderr, "Nombre maximum d'athlètes pour la discipline 5000m atteint.\n");
                }
            }
        }

        // Fermer le fichier
        fclose(fichier);
    }

    // Trier les temps dans chaque tableau par ordre croissant
    trier_temps(relais, relais_count);
    trier_temps(m_100, m_100_count);
    trier_temps(marathon, marathon_count);
    trier_temps(m_400, m_400_count);
    trier_temps(m_5000, m_5000_count);

    // Afficher les 3 athlètes les plus rapides dans chaque discipline
    printf("Relais :\n");
    afficher_3_plus_rapides(relais, relais_count);

    printf("100m :\n");
    afficher_3_plus_rapides(m_100, m_100_count);

    printf("Marathon :\n");
    afficher_3_plus_rapides(marathon, marathon_count);

    printf("4*400m :\n");
    afficher_3_plus_rapides(m_400, m_400_count);

    printf("5000m :\n");
    afficher_3_plus_rapides(m_5000, m_5000_count);

    return 0;
}


