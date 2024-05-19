all: JO

main.o: main.c Bibli.h
	gcc -c $< -o $@

3bestatlhetes.o: 3bestatlhetes.c Bibli.h
	gcc -c $< -o $@

Historique.o: Historique.c Bibli.h
	gcc -c $< -o $@

nventrainement.o: nventrainement.c Bibli.h
	gcc -c $< -o $@

relais.o: relais.c Bibli.h
	gcc -c $< -o $@

JO: main.o 3bestatlhetes.o Historique.o nventrainement.o relais.o
	gcc $^ -o $@
