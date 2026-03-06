CC = gcc

Files = scripts/game.c scripts/game_of_life.c scripts/control.c

Flags = 

Name = main

all:
	$(CC) $(Flags) $(Files) -o $(Name) -lncurses