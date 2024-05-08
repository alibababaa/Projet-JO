// Fonction pour avoir les 3 athlètes avec les meilleures moyennes de temps
float compareAthlete(Athlete a, Athlete b, Athlete c, Athlete autres) {
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
