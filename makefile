#Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
LDFLAGS = 

#Cible principale
all: JO

#Règles de compilation
main.o: main.c Bibli.h
	$(CC) $(CFLAGS) -c $< -o $@

3meilleurathlètes.o: 3meilleurathlètes.c Bibli.h
	$(CC) $(CFLAGS) -c $< -o $@

Historique.o: Historique.c Bibli.h
	$(CC) $(CFLAGS) -c $< -o $@

nouvellentrainement.o: nouvellentrainement.c Bibli.h
	$(CC) $(CFLAGS) -c $< -o $@

resumePerformance.o: resumePerformance.c Bibli.h
	$(CC) $(CFLAGS) -c $< -o $@

relais.o: relais.c Bibli.h
	$(CC) $(CFLAGS) -c $< -o $@

sauvegarderEntrainement.o: sauvegarderEntrainement.c Bibli.h
	$(CC) $(CFLAGS) -c $< -o $@

#Cible d'édition de liens
JO: main.o 3meilleurathlètes.o Historique.o nouvellentrainement.o resumePerformance.o relais.o sauvegarderEntrainement.o 
	$(CC) $(LDFLAGS) $^ -o $@

#Règle de nettoyage
clean:
	rm -f *.o JO

.PHONY: all clean
