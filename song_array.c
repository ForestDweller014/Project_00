#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song_list.h"

int num_lists = 0;

void add_song(struct song_node **library, char *name, char *artist) {
	char c = *artist;
	if (c <= 122 && c >= 97) {
		if (!*(library + (c - 97))) {
			num_lists++;
		}
		*(library + (c - 97)) = insert_alphabetical(*(library + (c - 97)), name, artist);
	} else if (c <= 90 && c >= 65) {
		if (!*(library + (c - 65))) {
			num_lists++;
		}
		*(library + (c - 65)) = insert_alphabetical(*(library + (c - 65)), name, artist);
	} else {
		if (!*(library + 26)) {
			num_lists++;
		}
		*(library + 26) = insert_alphabetical(*(library + 26), name, artist);
	}
} 

void shuffle(struct song_node **library, int num) {
	struct song_node **tracker = library;
	int index = rand() % num_lists;
	int count = 0;
	int print_count = 0;
	while (1) {
		if (count == index) {
			struct song_node *rnode = random_node(*tracker);
			printf("Name: %s\n", rnode->name);
			printf("Artist: %s\n", rnode->artist);
			printf("\n");
			tracker = library - 1;
			index = rand() % num_lists;
			count = -1;
			print_count++;
			if (print_count == num) {
				return;
			}
		}
		count++; 
		tracker++;
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