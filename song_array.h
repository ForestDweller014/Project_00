void add_song(struct song_node **library, char *name, char *artist);
void print_by_letter(struct song_node **library, char c);
void print_library(struct song_node **library);
void shuffle(struct song_node **library, int num);
void print_artist_songs(struct song_node **library, char *artist);
struct song_node *search_song(struct song_node **library, char *name, char *artist);
//void delete_song(struct song_node **library, char *name, char *artist);
struct song_node **clear_lib(struct song_node **library);