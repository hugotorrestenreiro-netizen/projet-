CC = gcc
CFLAGS = -Wall -Wextra -g 
LDFLAGS = -lSDL2

EXEC = mon_jeu

SRC = game.c physic.c renderer.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)