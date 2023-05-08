CC = gcc
CFLAGS = -Wall -I../include
LDFLAGS = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS = main.o menu.o music.o text.o stars.o settings.o start.o enemy.o enigme_fichier.o bounding_box.o background.o perso.o

game: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o game

%.o: ../src/%.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(OBJS) game
