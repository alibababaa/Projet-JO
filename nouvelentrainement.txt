

// Structure pour représenter une date
struct Date {
    int jour;
    int mois;
    int années;
};

// Fonction pour demander à l'utilisateur de creer un entrainement
Entrainement creerNouvelentrainement(){
Entrainement nouvelentrainement;
    do {
        // Demander à l'utilisateur de saisir la date au format jour/mois/année
        printf("Entrez une date au format jour/mois/année ( : ");
        scanf("%d/%d/%d", &date.jour, &date.mois, &date.annee);

        // Vérifier si la date est valide
        if ((date.jour >= 1 && date.jour <= 31) &&
            (date.mois >= 1 && date.mois <= 12) &&
            (date.annee >= 2020 && date.annee <= 2024)) {
            valid = 1; // La date est valide, sortir de la boucle
        } else {
            printf("Date invalide. Assurez-vous que le jour est entre 1 et 31, le mois est entre 1 et 12, et l'année est entre 2020 et 2024.\n");
        }
    } while (!valid);

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


printf("saisir le temps de l'athlete /n");
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
   printf("quel etait la position de l'athlete/n");
   scanf("d%",&position);
   if(position<1 && position>4){
     printf("erreur de saisie,veuillez saisir un chiffre entre 1 et 4/n");
   }
 }
return nouvelentrainement;
}

//fonction pour enregistrer le nouvel entrainement dans un fichier 
void sauvegarderentrainement(const char*nouvelentrainement.txt,const Entrainement*entrainement) {
    FILE*fichier=fopen(nouvelentrainement.txt,"a")
    if(fichier=NULL){
       printf("erreur:impossible d'ouvrir le fichier"/n);
       return;
    }
   fprintf(fichier,"Date:%d:%d:%d:%d",nouvelentrainement.date);
   fprintf(fichier,"epreuve:%c",nouvelentrainement.epreuve);
   fprintf(fichier,"Temps:"%f",nouvelentrainement.temps);
   fprintf(fichier,"position:%c",nouvelentrainement.position);
fclose(fichier);
printf("votre entrainement a bien été sauvegarder/n");
}

//Fonction main
int main(){
Entrainement nouvelentrainement;
char ajouterenrainement;
while(1){
nouvelentrainement=creernouvelentrainement;
sauvegarderentrainement(&nouvelentrainement);
char ajouterenrainement;
printf("voulez vous ajouter un nouvel entrainement ?/n");
scanf("%c",&ajouterentrainement);
if(ajouterentrainement!="oui"){
    break;
}
printf("votre nouvel entrainement a bien été ajouter/n");
    
return 0;
}
}


    


 


        

     



