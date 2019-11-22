#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

// Constants
#define INF 50000000

// Enums
typedef enum e_error {
    INVALID_ARGUMENTS_COUNT,
    FILE_DOES_NOT_EXISTS,
    FILE_IS_EMPTY,
    INVALID_FIRST_LINE,
    INVALID_LINE,
    INVALID_ISLANDS_COUNT
} t_error;

// Structures
typedef struct s_node {
    int vertex;
    struct s_node *next;
} t_node;

typedef struct s_adjacency_list {
    struct s_node *head;
} t_adjacency_list;

typedef struct s_graph {
    int vertices_count;
    struct s_adjacency_list *adjacency_lists;
} t_graph;

typedef struct s_bfs {
    struct s_graph *graph;
    int dst;
    int *visited;
    int *path;
    int path_index;
    t_list *paths;
    int const_src;
} t_bfs;

// Functions
void mx_error_handler(t_error error, char *filename, char *text);
void mx_generr(char *first_part, char *text, char *second_part);
void mx_check_all_lines(char **file_lines, char *file_str);
bool mx_check_first_line(char *file_str);
bool mx_is_line_correct(char *line);
void mx_parse_line(char *line, char **i_1, char **i_2, int *bridge);
bool mx_check_str_set(char **set, char *element, int set_size);
int mx_get_i(char **set, const char *element);
char ***mx_get_islands(int edges_count, char **file_lines, char **set);
int **mx_get_islands_matrix(char **lines, char **islands_set, int edges);
t_graph *mx_create_graph(int vertices_count);
void mx_del_graph(t_graph *graph);
t_node *mx_create_adjacency_node(int vertex);
void mx_add_edge(t_graph *graph, int src, int dst, t_list **nodes);
t_list *mx_add_edges(t_graph *graph, char **lines, char **set, char ***i);
void mx_get_all_paths(int islands_c, t_graph *graph, t_list **all_paths);
t_list *mx_get_all_paths_util(t_graph *graph, int src, int dst);
int mx_get_path_weight(t_list *path, int **matrix);
t_list *mx_get_all_min_paths(t_list *paths, int **matrix);
t_list *mx_get_min_paths(t_list *all_paths, int **islands_m);
void mx_print_path(char **islands_set, t_list *path, int w, int **matrix);
void mx_print_all_paths(t_list *paths, char **set, int **islands_arr);
void mx_del_lists(t_list *all_paths, t_list *min_paths, t_list *nodes);
void mx_del_islands(char ***islands, int edges_count);

#endif
