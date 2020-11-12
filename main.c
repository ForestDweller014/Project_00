#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "song_list.h"
#include "song_array.h"

int main() {

	printf("---------------------\nSONG LINKED LIST TEST\n---------------------\n");
	
	struct song_node *list = NULL;

	printf("\nTesting insert_front\n--------------------\n");
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
	
	printf("\nTesting random_node\n-------------------\n");
	print_song(random_node(list));
	
	printf("\nTesting free_list\n-----------------\n");
	list = free_list(list);

	printf("\nPrinting List\n-------------\n");
	print_list(list);

	printf("\n------------------\nSONG LIBRARY TEST\n------------------\n");
	
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
	add_song(library, "Barking at the Moon", "Ozzy Osbourne");
	add_song(library, "Crazy Train", "Ozzy Osbourne");
	add_song(library, "Free Bird", "Lynyrd Skynyrd");  
	add_song(library, "Random Song", "*Weird Name*");

	printf("\nPrinting Library\n----------------\n");
	print_library(library);

	printf("\nShuffled Playlist of 5 Songs\n----------------------------\n");
	srand(time(NULL));
	shuffle(library, 5);

	printf("\nTesting print_artist_songs on \"Ozzy Osbourne\"\n---------------------------------------------\n");
	print_artist_songs(library, "Ozzy Osbourne");

	printf("\nTesting search_song on \"Hotel California\"\n-----------------------------------------\n");
	print_song(search_song(library, "Hotel California", "The Eagles"));

	printf("\nTesting delete_song_from_library\n--------------------------------\n");
	delete_song_from_lib(library, "Take What You Want", "Post Malone");
	
	printf("\nPrinting Library\n----------------\n");
	print_library(library);
	
	printf("\nTesting clear_lib\n-----------------\n");
	clear_lib(library);
	
	printf("\nPrinting Library\n----------------\n");
	print_library(library);
	
	return 0;
}
