#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "song_list.h"

struct song_node *new_song(char *name, char *artist) {
	struct song_node *new_s = malloc(sizeof(struct song_node));
	strncpy(new_s->name, name, sizeof(new_s->name));
	strncpy(new_s->artist, artist, sizeof(new_s->artist));
	return new_s;
}

struct song_node *insert_front(struct song_node *song, char *name, char* artist) {
	struct song_node *new_s = new_song (name, artist);
	new_s->next = song;
	
	return new_s;
}

struct song_node *insert_alphabetical(struct song_node *curr_list, char *name, char *artist) {
	struct song_node *new_s = new_song(name, artist);

	if (!curr_list) {
		new_s->next = NULL;
		return new_s;
	}

	int cmp = strcmp(artist, curr_list->artist);
	if ((cmp < 0) || (!cmp && (strcmp(name, curr_list->name) < 0))) {
		new_s->next = curr_list;
		return new_s;
	}	

	struct song_node *head = curr_list;
	struct song_node *behind_tracker = curr_list;
	struct song_node *tracker = curr_list->next;

	while (tracker) {
		int cmp = strcmp(artist, tracker->artist);
		if ((cmp < 0) || (!cmp && (strcmp(name, tracker->name) < 0))) {
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

int get_size(struct song_node *curr_list) {
	int size = 0;
	while (curr_list) {
		size++;
		curr_list = curr_list->next;
	}
	return size;
}

struct song_node *random_node(struct song_node *curr_list) {
	int size = get_size(curr_list);
	srand(time(NULL));
	int index = rand() % size;
	int count = 0;
	while (curr_list) {
		if (count == index) {
			return curr_list;
		}
		count++;
		curr_list = curr_list->next;
	}
	return NULL;
}

void print_song(struct song_node *song) {
	if (song) {
		printf("Name: %s\n", song->name);
		printf("Artist: %s\n", song->artist);
	}
}

void print_list(struct song_node *curr_list) {
	int a = 0;
	while(curr_list) {
		if (a) {
			printf("\n");
		}
		a = 1;
		print_song(curr_list);
		curr_list = curr_list->next;
	}
}

void free_song(struct song_node *song) {
	printf ("Deleting %s by %s\n", song->name, song->artist);
	free(song);
}

struct song_node *find_artist_song(struct song_node *front, char *name, char *artist) { 
	while (front) {
		if (!strcmp(front->artist, artist) && !strcmp(front->name, name)) {
			return front;
			break;
		}
		front = front->next;
	}
	return NULL;
}

struct song_node *find_first_artist_song(struct song_node *front, char *artist) {
	while (front) {
		if (!strcmp(front->artist, artist)) {
			return front;
			break;
		}
		front = front->next;
	}
	return NULL;
}

struct song_node *delete_song(struct song_node *front, char *search_name) {
	if (!strcmp(front->name, search_name)) {
		struct song_node *new_front = front->next;
		free_song(front);
		return new_front;
	}
	else {
		struct song_node *current_song, *previous_song;
		current_song = front;
			
		while (current_song) {
			if (!strcmp(current_song->name, search_name)) {
				previous_song->next = current_song->next;
				free_song(current_song);
				break;
			}
			previous_song = current_song;
			current_song = current_song->next;
		}
	}
	return front;
}

struct song_node *free_list(struct song_node *song) {
	while (song) {
		struct song_node *next_s = song->next;
		free_song(song);
		song = next_s;
	}
	return NULL;
}
