#ifndef SONG_H
#define SONG_H

struct song_node {
	char name[100]; 
	char artist[100]; 
	struct song_node *next;
};

struct song_node *new_song(char *name, char *artist);

struct song_node *insert_front (struct song_node *, char*, char*);

struct song_node *insert_alphabetical (struct song_node *curr_list, char *name, char *artist);

void print_song (struct song_node *);

void print_list (struct song_node *curr_list);

void free_song (struct song_node *);

struct song_node *find_artist_song (struct song_node *, char *, char *);

struct song_node *find_first_artist_song (struct song_node *, char *);

struct song_node *delete_song (struct song_node *, char *);

struct song_node *free_list (struct song_node *);

struct song_node *random_node(struct song_node *curr_list);

#endif
