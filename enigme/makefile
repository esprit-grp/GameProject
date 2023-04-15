game: enigme_fichier.o bounding_box.o main.o 
	gcc enigme_fichier.o bounding_box.o main.o -o game -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer

main.o: main.c 
	gcc -c main.c -g 

enigme_fichier.o: enigme_fichier.c 
	gcc -c enigme_fichier.c -g

bounding_box.o: bounding_box.c bounding_box.h
	gcc -c bounding_box.c -g

