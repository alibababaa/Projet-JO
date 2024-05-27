#include "Bibli.h"

const char* nomEpreuve[] = {
    "100m",
    "400m",
    "5000m",
    "marathon",
    "4*400m"
};

int main() {
 
    int choix;
    printf("Bonjour\n");
    printf("Que voulez-vous faire?\n");
    printf("1- Entrer et sauvegarder les informations d'un nouvel entrainement?\n");
   // printf("2- Consulter l'historique des entrainements?\n");
    printf("3- Consulter les statistiques de performances des athlètes?\n");
    scanf("%d", &choix);

   
    if (choix == 1) {
        while (1) {
            Entrainement nouvelEntrainement = creerNouvelEntrainement();
            sauvegarderEntrainement("entrainements.txt", nouvelEntrainement);

            char ajouterEntrainement[4]; // Utiliser un tableau de char pour stocker la réponse
            printf("Voulez-vous ajouter un nouvel entraînement (oui/non) ? ");
            scanf("%3s", ajouterEntrainement); // Lire au maximum 3 caractères pour éviter le dépassement de tampon

            if (strcmp(ajouterEntrainement, "oui") != 0) {
                break;
            }
    

    }
    }
   /** else if (choix == 2) {
       printf("Début du programme...\n");
    printf("Chargement des données des athlètes...\n");

    int nb_athletes = 0;
        
    // Demande à l'entraîneur de saisir le nombre d'athlètes
    printf("Combien d'athlètes voulez-vous charger ? (maximum 30) : ");
    scanf("%d", &nb_athletes);
    getchar(); // Pour absorber le caractère de nouvelle ligne restant dans le tampon
        
    if (nb_athletes > NOMBRE_ATHLETES) {
        printf("Le nombre d'athlètes dépasse le maximum autorisé (%d).\n", NOMBRE_ATHLETES);
        return 1;
    }

    Athlete athletes[NOMBRE_ATHLETES];
        
    // Demande à l'entraîneur de saisir le nom de chaque athlète
    for (int i = 0; i < nb_athletes; i++) {
        printf("Entrez le nom de l'athlète %d : ", i + 1);
        fgets(athletes[i].nom, sizeof(athletes[i].nom), stdin);
        // Supprimer le caractère de nouvelle ligne (\n) à la fin du nom
        athletes[i].nom[strcspn(athletes[i].nom, "\n")] = '\0';
    }

    // Chargement des données pour chaque athlète
    for (int i = 0; i < nb_athletes; i++) {
        char nom_fichier[100];
        sprintf(nom_fichier, "%s.txt", athletes[i].nom);
        chargerDonneesAthlete(&athletes[i], nom_fichier);
    }

    // Afficher les entraînements chargés pour chaque athlète
    for (int i = 0; i < nb_athletes; i++) {
        printf("\nEntraînements de l'athlète %s:\n", athletes[i].nom);
        for (int j = 0; j < athletes[i].num_entrainement; j++) {
            Entrainement e = athletes[i].entrainements[j];
            printf("Entraînement %d : Date: %02d/%02d/%04d, Épreuve: %s, Temps: %.2f\n",
                   j + 1, e.date.jour, e.date.mois, e.date.annee, e.epreuve, e.temps);
        }
    }

  
       //copieinfo();
       
        printf("Fin du programme.\n");
   }    
    **/
    else if (choix == 3) {
        int stat;
        printf("Que voulez-vous voir? \n");
        printf("1- Voir les 3 meilleurs athlètes \n");
        printf("2- Voir un résumé des performances des athlètes \n");
        scanf("%d", &stat);
        if(stat == 1) {
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
    /**if(stat == 2) {
        // Liste des prénoms des athlètes
        char *prenoms[] = {"Ademo", "Adlaurent", "Ali", "Bolt", "Brandon", "Clovis", "Etienne", "Fujitora", "Gourcuff", "Ilyes", "Jimmy", "Kevin", "Krilin", "Lemaître", "Locqman", "Mandzukic", "Messi", "Mkadir", "Mobutu", "Morant", "Neji", "Pablo", "Pirlo", "Robben", "Samy", "Sneijder", "Stephen", "Sylvestre", "Yann",  "Riman"};
        
        
        int nombreAthletes = sizeof(prenoms) / sizeof(prenoms[0]);

        int athleteResume;
        char nomFichier[100];

        printf("De quel athlète voulez-vous le résumé ?\n");
        for (int i = 0; i < nombreAthletes; i++) {
            printf("%d: %s\n", i + 1, prenoms[i]);
        }

        printf("Entrez le numéro correspondant à l'athlète: ");
        scanf("%d", &athleteResume);

        if (athleteResume < 1 || athleteResume > nombreAthletes) {
            printf("Erreur de saisie de numéro.\n");
            return 1;
        }

        snprintf(nomFichier, sizeof(nomFichier), "%s.txt", prenoms[athleteResume - 1]);

        resumePerformance(nomFichier);

        return 0;
        

        
    }
    }
}
**/

    }
}

  
     

    
