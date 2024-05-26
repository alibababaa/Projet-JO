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

int main() {
    FILE *fichier;
    char ligne[100];
    const char delimiteur[] = "; ";
    Temps relais[NOMBRE_ATHLETES], m_100[NOMBRE_ATHLETES], marathon[NOMBRE_ATHLETES], m_400[NOMBRE_ATHLETES], m_5000[NOMBRE_ATHLETES];
    int relais_count = 0, m_100_count = 0, marathon_count = 0, m_400_count = 0, m_5000_count = 0;

    // Liste des fichiers à traiter
    char *fichiers[] = {"Ademo.txt", "Adlaurent.txt", "Ali.txt", "Bolt.txt", "Brandon.txt", "Clovis.txt", "Etienne.txt", "Fujitora.txt", "Gourcuff.txt", "Ilyes.txt", "Jimmy.txt", "Kevin.txt", "Lemaitre.txt", "Locqman.txt", "Mandzukic.txt", "Messi.txt", "Mkadir.txt", "Mobutu.txt", "Morant.txt", "Neji.txt", "Pablo.txt", "Pirlo.txt", "Robben.txt", "Samy.txt", "Sneijder.txt", "Stephen.txt", "Sylvestre.txt", "Yann.txt", "Krilin.txt", "Riman.txt"};

    for (int i = 0; i < NOMBRE_ATHLETES; i++) {
        fichier = fopen(fichiers[i], "r");

        // Vérifier si l'ouverture du fichier a réussi
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
            } else if (strcmp(discipline, "400m") == 0) {
                if (m_400_count < NOMBRE_ATHLETES) {
                    strcpy(m_400[m_400_count].nom, fichiers[i]);
                    m_400[m_400_count].heures = heures;
                    m_400[m_400_count].minutes = minutes;
                    m_400[m_400_count].secondes = secondes;
                    m_400[m_400_count].centiemes = centiemes;
                    m_400_count++;
                } else {
                    fprintf(stderr, "Nombre maximum d'athlètes pour la discipline 400m atteint.\n");
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

    // Tableau pour garder une trace des athlètes déjà affichés
    char deja_affiche[NOMBRE_ATHLETES][MAX_NOM_ATHLETE];
    int nombre_affiches = 0;

    // Afficher les 3 athlètes les plus rapides dans chaque discipline en évitant les duplications
    printf("Relais :\n");
    afficher_3_plus_rapides(relais, relais_count, deja_affiche, &nombre_affiches);

    printf("100m :\n");
    afficher_3_plus_rapides(m_100, m_100_count, deja_affiche, &nombre_affiches);

    printf("Marathon :\n");
    afficher_3_plus_rapides(marathon, marathon_count, deja_affiche, &nombre_affiches);

    printf("400m :\n");
    afficher_3_plus_rapides(m_400, m_400_count, deja_affiche, &nombre_affiches);

    printf("5000m :\n");
    afficher_3_plus_rapides(m_5000, m_5000_count, deja_affiche, &nombre_affiches);

    return 0;
}
