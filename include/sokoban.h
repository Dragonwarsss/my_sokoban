/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

typedef struct s_game game_t;
typedef struct s_vector vector_t;
typedef struct s_object object_t;
typedef struct s_pos pos_t;

struct s_pos {
    int pos;
};

struct s_vector {
    int x;
    int y;
};

struct s_object {
    vector_t player;
    vector_t *pos_storage;
    vector_t *pos_box;
    int nb_storage;
    int nb_box;
};

struct s_game {
    char *save;
    object_t *obj;
};

void print_usage(void);
int check_dir(char *path);
int check_map(char *map);
int check_args(int ac, char **av);

int count_obj(char *map);
int count_box(char *map);
int count_storage(char *map);
int get_storage_pos(char *map);

game_t *init_game(char *path);
object_t *init_object(char *map);
void reset(game_t *g);
void free_everything(game_t *g);

void set_player_pos(object_t *obj, char *map);
void store_location(object_t *obj, char *map);
void store_box_location(object_t *obj, char *map);

int run_game(game_t *g);
int is_win(vector_t *p, int n);
int is_lose(object_t *obj);

void move_player(game_t *g);
void move_up(game_t *g);
void move_down(game_t *g);
void move_right(game_t *g);
void move_left(game_t *g);
void move_up2(game_t *g);
void move_down2(game_t *g);
void move_right2(game_t *g);
void move_left2(game_t *g);

void move_box_up(object_t *obj, int x, int y);
void move_box_down(object_t *obj, int x, int y);
void move_box_left(object_t *obj, int x, int y);
void move_box_right(object_t *obj, int x, int y);

void draw_storage(vector_t *pos, int nb_storage);

#endif
