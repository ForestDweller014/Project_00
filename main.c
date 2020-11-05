#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"

int main() {
	struct song_node *catalog[27];
	int i;
	for (i = 0; i < 27; i++) {
		catalog[i] = NULL;
	}
	add_song(catalog, "Take What You Want", "Post Malone");
	add_song(catalog, "Big Poppa", "Biggie Smalls");
	add_song(catalog, "While My Guitar Gently Weeps", "George Harrison");
	add_song(catalog, "Fade to Black", "Metallica");
	add_song(catalog, "Don't Cry", "Guns N' Roses");
	add_song(catalog, "Soothsayer", "Buckethead");
	add_song(catalog, "Chosen One", "Polo G");
	add_song(catalog, "Mr. Crowley", "Ozzy Osbourne");
	add_song(catalog, "Sicko Mode", "Travis Scott");
	add_song(catalog, "Black", "*Grizzly*");
	print_catalog(catalog);
	return 0;
}