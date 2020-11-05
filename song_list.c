#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song_list.h"

struct song_node *new_song(char *name, char *artist) {
	struct song_node *new_s = malloc(sizeof(struct song_node));
	strncpy(new_s->name, name, sizeof(new_s->name));
	strncpy(new_s->artist, artist, sizeof(new_s->artist));
	new_s->next = NULL;
	return new_s;
}

struct song_node *insert_front (struct song_node *song, char *name, char* artist) {
	printf ("Adding %s, by %s\n", name, artist);
	struct song_node *new_s = new_song (name, artist);
	new_s->next = song;
	
	return new_s;
}

struct song_node *insert_alphabetical(struct song_node *curr_list, char *name, char *artist) {
	printf ("Alphabetically adding %s, by %s\n", name, artist);
	struct song_node *new_s = new_song(name, artist);

	if (!curr_list) {
		new_s->next = NULL;
		return new_s;
	}

	struct song_node *head = curr_list;
	struct song_node *behind_tracker = curr_list;
	struct song_node *tracker = curr_list->next;

	while (tracker) {
		if (strcmp(name, tracker->name) < 0) {
			behind_tracker->next = new_s;
			new_s->next = tracker;
			return head; 
		} else {
			behind_tracker = behind_tracker->next;
			tracker = tracker->next;
		}
	}

	behind_tracker->next = new_s;
	new_s->next = NULL;
	return head;
}

void print_song(struct song_node *song) {
	printf("Name: %s\n", song->name);
	printf("Artist: %s\n", song->artist);
	printf("\n");
}

void print_list(struct song_node *curr_list) {
	while(curr_list) {
		print_song (curr_list);
		curr_list = curr_list->next;
	}
}

void free_song (struct song_node *song) {
	printf ("Deleting %s\n", song->name);
	free (song);
}

struct song_node *find_artist_song (struct song_node *front, char *name, char *artist) {
	printf ("Finding %s, by %s\n", name, artist);
	while (front) {
		if (!strcmp(front->artist, artist) && !strcmp(front->name, name)) {
			printf ("Song found\n");
			return front;
			break;
		}
		front = front->next;
		if (!front)
			printf ("Song not found\n");
	}
}

struct song_node *find_first_artist_song (struct song_node *front, char *artist) {
	printf ("Finding first song by %s\n", artist);
	while (front) {
		if (!strcmp(front->artist, artist)) {
			printf ("First song is %s\n", front->name);
			return front;
			break;
		}
		front = front->next;
		if (!front)
			printf ("Artist not found\n");
	}
}

//This could probably be better optimized, it works though
struct song_node *delete_song (struct song_node *front, char *search_name) {
	if (!strcmp(front->name, search_name)) {
		struct song_node *new_front = front->next;
		free_song (front);
		return new_front;
	}
	else {
		struct song_node *current_song, *previous_song;
		current_song = front;
			
		while (current_song) {
			if (!strcmp(current_song->name, search_name)) {
				previous_song->next = current_song->next;
				free_song (current_song);
				break;
			}
			previous_song = current_song;
			current_song = current_song->next;
		}
	}
	return front;
}

struct song_node *free_list (struct song_node *song) {
	int songs_deleted = 0;
	printf ("Deleting Library\n");
	
	while (song) {
		struct song_node *next_s = song->next;
		free (song);
		song = next_s;
		songs_deleted++;
	}
	printf ("Songs deleted: %d\n", songs_deleted);
}
