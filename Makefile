CC = gcc

Files = scripts/frame.c scripts/game_of_life.c scripts/control.c

Flags = 

Name = main

all:
	mkdir -p build
	$(CC) $(Flags) $(Files) -o build/$(Name) -lncurses