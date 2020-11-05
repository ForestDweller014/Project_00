#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song_list.h"
#include "song_array.h"

int main() {
	struct song_node *library[27];
	int i;
	for (i = 0; i < 27; i++) {
		library[i] = NULL;
	}
	add_song(library, "Take What You Want", "Post Malone");
	add_song(library, "Big Poppa", "Biggie Smalls");
	add_song(library, "While My Guitar Gently Weeps", "George Harrison");
	add_song(library, "Fade to Black", "Metallica");
	add_song(library, "Don't Cry", "Guns N' Roses");
	add_song(library, "Soothsayer", "Buckethead");
	add_song(library, "Chosen One", "Polo G");
	add_song(library, "Mr. Crowley", "Ozzy Osbourne");
	add_song(library, "Sicko Mode", "Travis Scott");
	add_song(library, "Black", "*Grizzly*");
	print_library(library);
	return 0;
}