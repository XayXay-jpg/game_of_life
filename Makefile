CC = gcc

Files = scripts/frame.c scripts/game_of_life.c scripts/control.c

Flags = -Werror -Wextra -Wall -std=c23

Name = main

all:
	mkdir -p build
	$(CC) $(Flags) $(Files) -o build/$(Name) -lncurses

clean:
	rm -rf build

rebuild:
	clean all