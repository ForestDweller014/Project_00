struct song_node {char name[100]; char artist[100]; struct song_node *next;};
void add_song(struct song_node **catalog, char *name, char *artist);
void print_catalog(struct song_node **catalog);