prog: song.c main.c
	gcc -o prog song.c main.c

run:
	./prog