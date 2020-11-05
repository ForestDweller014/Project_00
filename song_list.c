#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song_list.h"

struct song_node *new_song(char *name, char *artist) {
	struct song_node *new_s = malloc(sizeof(struct song_node));
	strncpy(new_s->name, name, sizeof(new_s->name));
	strncpy(new_s->artist, artist, sizeof(new_s->artist));
	return new_s;
}

struct song_node *insert_alphabetical(struct song_node *curr_list, char *name, char *artist) {
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

void print_list(struct song_node *curr_list) {
	while(curr_list) {
		printf("Name: %s\n", curr_list->name);
		printf("Artist: %s\n", curr_list->artist);
		printf("\n");
		curr_list = curr_list->next;
	}
}