all: JO

main.o: main.c Bibli.h
	gcc -c $< -o $@

3meilleurathlètes.o: 3meilleurathlètes.c Bibli.h
	gcc -c $< -o $@

Historique.o: Historique.c Bibli.h
	gcc -c $< -o $@

nouvelentrainement.o: nouvelentrainement.c Bibli.h
	gcc -c $< -o $@

relais.o: relais.c Bibli.h
	gcc -c $< -o $@

JO: main.o 3meilleurathlètes.o Historique.o nouvelentrainement.o relais.o
	gcc $^ -o $@
