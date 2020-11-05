#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song_list.h"

void add_song(struct song_node **library, char *name, char *artist) {
	char c = *artist;
	if (c <= 122 && c >= 97) {
		*(library + (c - 97)) = insert_alphabetical(*(library + (c - 97)), name, artist);
	} else if (c <= 90 && c >= 65) {
		*(library + (c - 65)) = insert_alphabetical(*(library + (c - 65)), name, artist);
	} else {
		*(library + 26) = insert_alphabetical(*(library + 26), name, artist);
	}
} 

void print_by_letter(struct song_node **library, char c) {
	print_list(*(library + c - 97));
}

void print_library(struct song_node **library) {
	int i;
	for (i = 0; i < 27; i++) {
		if (i == 26) {
			printf("List of songs that start with a non-alphabet symbol\n---------------------------------------------------\n");
			print_by_letter(library, (char)(i + 97));
		} else {
			printf("List of songs that start with \"%c\"\n---------------------------------\n", i + 97);
			print_by_letter(library, (char)(i + 97));
		}
	}
}