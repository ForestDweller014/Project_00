#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song_list.h"

int num_songs = 0;

void add_song(struct song_node **library, char *name, char *artist) {
	char c = *artist;
	if (c <= 122 && c >= 97) {
		*(library + (c - 97)) = insert_alphabetical(*(library + (c - 97)), name, artist);
	} else if (c <= 90 && c >= 65) {
		*(library + (c - 65)) = insert_alphabetical(*(library + (c - 65)), name, artist);
	} else {
		*(library + 26) = insert_alphabetical(*(library + 26), name, artist);
	}
	num_songs++;
} 

int discrete(double *probabilities) {
	double sum = 0;
	int i;
	double random = (double)rand() / ((double)RAND_MAX + 1);
	for (i = 0; i < 27; i++) {
		sum += *(probabilities + i);
		if (random < sum) {
			return i;
		}
	}
	return -1;
}

void shuffle(struct song_node **library, int num) {
	printf("Shuffled Playlist\n-----------------\n");
	struct song_node **tracker = library;
	double probabilities[27];
	int i;
	for (i = 0; i < 27; i++) {
		probabilities[i] = (double)get_size(*tracker) / (double)num_songs;
		tracker++;
	}
	int j;
	for (j = 0; j < num; j++) {
		int index = discrete(probabilities);
		print_song(random_node(*(library + index)));
	}
}

void print_by_letter(struct song_node **library, char c) {
	print_list(*(library + c - 97));
}

void print_library(struct song_node **library) {
	int i;
	for (i = 0; i < 27; i++) {
		if (i == 26) {
			printf("List of songs with artist names that start with a non-alphabet symbol\n---------------------------------------------------------------------\n");
			print_by_letter(library, (char)(i + 97));
		} else {
			printf("List of songs with artist names that start with \"%c\"\n---------------------------------------------------\n", i + 97);
			print_by_letter(library, (char)(i + 97));
		}
	}
}