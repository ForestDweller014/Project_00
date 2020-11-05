prog: song_list.c song_array.c main.c
	gcc -o prog song_list.c song_array.c main.c

run:
	./prog