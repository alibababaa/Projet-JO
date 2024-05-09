// Fonction pour avoir les 3 athlètes avec les meilleures moyennes de temps
float compareAthlete(Athlete a, Athlete b, Athlete c, Athlete autres, Athlete *top 3) {
        if (a.moyenne > autres.moyenne && b.moyenne > autres.moyenne && c.moyenne > autres.moyenne) {
                if(a.moyenne > b.moyenne) {
                        return a; }
                else if (b.moyenne > a.moyenne)
                        return b; }
                else if (b.moyenne > c.moyenne) {
                        return b; }
                else if (c.moyenne > b.moyenne) {
                        return c; }
                else if (a.moyenne > c.moyenne)
                        return a; }
                else { 
                        return c; }
        }
        else {
                
        }
          
}
  

// Ce que ChatGPT m'a écrit quand je lui ai demandé de corrigé le code au dessus
Athlete compareAthlete(Athlete a, Athlete b, Athlete c, Athlete autres) {
    if (a.moyenne > autres.moyenne && b.moyenne > autres.moyenne && c.moyenne > autres.moyenne) {
        if (a.moyenne > b.moyenne) {
            if (a.moyenne > c.moyenne) {
                return a;
            } else {
                return c;
            }
        } else {
            if (b.moyenne > c.moyenne) {
                return b;
            } else {
                return c;
            }
        }
    } else {
        return autres;
    }
}



// ChatGPT qui a utilisé le tri pour ressortir les 3 meilleures athletes
void compareAthlete(Athlete a, Athlete b, Athlete c, Athlete autres, Athlete *top3) {
    // Tableau pour stocker les 4 moyennes
    float moyennes[4] = {a.moyenne, b.moyenne, c.moyenne, autres.moyenne};

    // Tri des moyennes en ordre décroissant
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (moyennes[i] < moyennes[j]) {
                // Échanger les valeurs si la moyenne actuelle est inférieure à la suivante
                float temp = moyennes[i];
                moyennes[i] = moyennes[j];
                moyennes[j] = temp;
            }
        }
    }

    // Affectation des trois meilleures moyennes aux éléments de top3
    for (int i = 0; i < 3; i++) {
        top3[i].moyenne = moyennes[i];
    }
}

int main() {
    // Déclaration des athlètes avec leurs moyennes de temps
    Athlete a = {10.5};
    Athlete b = {11.2};
    Athlete c = {10.8};
    Athlete autres = {12.0};

    // Tableau pour stocker les trois meilleurs athlètes
    Athlete top3[3];

    // Appel de la fonction pour obtenir les trois meilleurs temps
    meilleursAthletes(a, b, c, autres, top3);

    // Affichage des trois meilleures moyennes de temps
    printf("Les trois meilleures moyennes de temps sont : %.2f, %.2f, %.2f\n", top3[0].moyenne, top3[1].moyenne, top3[2].moyenne);

    return 0;
}
