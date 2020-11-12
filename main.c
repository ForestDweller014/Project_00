#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "song_list.h"
#include "song_array.h"

int main() {
	struct song_node *list = NULL;

	printf("Testing insert_front\n--------------------\n");
	list = insert_front(list, "Take What You Want", "Post Malone");
	list = insert_front(list, "While My Guitar Gently Weeps", "George Harrison");

	printf("\nTesting insert_alphabetical\n---------------------------\n");
	list = insert_alphabetical(list, "Test Dummy", "Post Malone");
	list = insert_alphabetical(list, "Soothsayer", "Buckethead");

	printf("\nPrinting List\n-------------\n");
	print_list(list);
	
	printf("\nTesting find_artist_song on \"Soothsayer\"\n----------------------------------------\n");
	print_song(find_artist_song(list, "Soothsayer", "Buckethead"));

	printf("\nTesting find_artist_song on \"Take What You Want\"\n------------------------------------------------\n");
	print_song(find_artist_song(list, "Take What You Want", "Post Malone"));
	
	printf("\nTesting find_first_artist_song on artist Post Malone\n----------------------------------------------------\n");
	print_song(find_first_artist_song(list, "Post Malone"));	
	
	printf("\nTesting delete_song on \"Test Dummy\"\n-----------------------------------\n");
	list = delete_song(list, "Test Dummy");

	printf("\nPrinting List\n-------------\n");
	print_list(list);
	
	printf("\nTesting free_list\n-----------------\n");
	list = free_list(list);

	printf("\nPrinting List\n-------------\n");
	print_list(list);

	struct song_node *library[27];
	int i;
	for (i = 0; i < 27; i++) {
		library[i] = NULL;
	}

	printf("\nTesting add_song\n----------------\n");
	add_song(library, "Take What You Want", "Post Malone");
	add_song(library, "Hotel California", "The Eagles");
	add_song(library, "While My Guitar Gently Weeps", "George Harrison");
	add_song(library, "Little Wing", "Jimi Hendrix"); 
	add_song(library, "Sweet Child O' Mine", "Guns N' Roses");
	add_song(library, "Soothsayer", "Buckethead");
	add_song(library, "95 Freestyle", "Big L");  
	add_song(library, "Mr. Crowley", "Ozzy Osbourne");
	add_song(library, "Free Bird", "Lynyrd Skynyrd");  
	add_song(library, "Random Song", "*Weird Name*");

	printf("\nPrinting Library\n----------------\n");
	print_library(library);

	printf("\nShuffled Playlist\n-----------------\n");
	srand(time(NULL));
	shuffle(library, 5);
	return 0;
}
