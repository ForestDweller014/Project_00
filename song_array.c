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
	struct song_node **tracker = library;
	double probabilities[27];
	int i;
	for (i = 0; i < 27; i++) {
		probabilities[i] = (double)get_size(*tracker) / (double)num_songs;
		tracker++;
	}
	int j;
	for (j = 0; j < num; j++) {
		if (j) {
			printf("\n");
		}
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
		if (i) {
			printf("\n");
		}
		if (i == 26) {
			printf("List of songs with artist names that start with a non-alphabet symbol\n---------------------------------------------------------------------\n");
			print_by_letter(library, (char)(i + 97));
		} else {
			printf("List of songs with artist names that start with \"%c\"\n---------------------------------------------------\n", i + 97);
			print_by_letter(library, (char)(i + 97));
		}
	}
}

struct song_node *search_song(struct song_node **library, char *name, char *artist) {
	for (int i = 0; i < 27; i++) {
		struct song_node *found_song = find_artist_song(*(library + i), name, artist);
		if (found_song) {
			return found_song;
		}
	}
	return NULL;
}

void print_artist_songs(struct song_node **library, char *artist) {
    char c = *artist;
	struct song_node *curr_list;
	if (c <= 122 && c >= 97) {
		curr_list = *(library + (c - 97));
	} else if (c <= 90 && c >= 65) {
		curr_list = *(library + (c - 65));
	} else {
		curr_list = *(library + 26);
	}

	int a = 0;
  	while (curr_list) {
  		if (!strcmp(curr_list->artist, artist)) {
  			if (a) {
  				printf("\n");
  			}
  			a = 1;
  			print_song(curr_list);
  		}
  		curr_list = curr_list->next;
  	}
}

void delete_song_from_lib (struct song_node **library, char* name, char* artist) {
	char c = *artist;
	if (c <= 122 && c >= 97) {
		*(library + (c - 97)) = delete_song(*(library + (c - 97)), name);
	} else if (c <= 90 && c >= 65) {
		*(library + (c - 65)) = delete_song(*(library + (c - 65)), name);
	} else {
		*(library + 26) = delete_song(*(library + 26), name);
	}
}

void clear_lib(struct song_node **library) {
 	for (int i = 0; i < 27; i++) {
		struct song_node *curr_list = *(library + i);
		free_list(curr_list);
	}
}
