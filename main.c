#include "Bibli.h"

int main(){
int verif;
int f;
printf("Bonjour\n");
printf ("Que voulez-vous faire?\n");
printf("1-entrer et sauvegarder les information d'un nouvel entrainement? \n 2-consulter l'historique des entrainement? \n 3-consulter les statistiques de performances des athletes?\n");
scanf("%d",&f);
do if (f==1){
    Entrainement nouvelentrainement;
char ajouterentrainement;
while(1){
nouvelentrainement = creerNouvelentrainement();
sauvegarderentrainement(&nouvelentrainement, nouvelentrainement);
char ajouterentrainement;
printf("voulez vous ajouter un nouvel entrainement ?/n");
verif= scanf("%c",&ajouterentrainement);
if(ajouterentrainement!=1){
    break;
}
printf("votre nouvel entrainement a bien été ajouter/n");
    
      }
      }else if(f==2){
            copieinfo();
    }
         else if(f==3){
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
      
            
for (int i = 0; i < 30; ++i) {
    free(meilleursAthletes[i]->temps);
    free(meilleursAthletes[i]);
}

// Libérer la mémoire pour le tableau de pointeurs vers Athlete
free(meilleursAthletes);

              
          
}

      else{
           printf("erreur saisie");
    }
             while(verif!=1);
  
return 0;
}
/** **/
