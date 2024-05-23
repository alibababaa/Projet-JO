#include "Bibli.h"
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
