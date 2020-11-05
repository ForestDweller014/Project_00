struct song_node {char name[100]; char artist[100]; struct song_node *next;};
struct song_node *insert_alphabetical(struct song_node *curr_list, char *name, char *artist);
void print_list(struct song_node *curr_list);