CC = gcc
CFLAGS = -Wall -I../include
LDFLAGS = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS = main.o menu.o music.o text.o

game: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o game
%.o: ../src/%.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(OBJS) game