#include "pathfinder.h"

static void check_argc(int argc);
static void check_file_str(char *file_str, char *filename);
static void pathfinding(char **lines, char **set, char ***i, char *str);

int main(int argc, char *argv[]) {
    char *file_str = NULL;
    char **lines = NULL;
    char **islands_set = NULL;
    char ***islands = NULL;

    check_argc(argc);
    file_str = mx_file_to_str(argv[1]);
    check_file_str(file_str, argv[1]);
    lines = mx_strsplit(file_str, '\n');
    mx_check_all_lines(lines, file_str);
    islands_set = malloc(sizeof(char *) * (mx_atoi(lines[0]) + 1));
    for (int i = 0; i < mx_atoi(lines[0]) + 1; i++)
        islands_set[i] = NULL;
    islands = mx_get_islands(mx_get_arr_length(lines) - 1, lines, islands_set);
    if (mx_atoi(lines[0]) != mx_get_arr_length(islands_set)) {
        mx_error_handler(INVALID_ISLANDS_COUNT, NULL, NULL);
        exit(-1);
    }
    pathfinding(lines, islands_set, islands, file_str);
    return 0;
}

static void check_argc(int argc) {
    if (argc != 2) {
        mx_error_handler(INVALID_ARGUMENTS_COUNT, NULL, NULL);
        exit(-1);
    }
}

static void check_file_str(char *file_str, char *filename) {
    if (mx_get_file_length(filename) == 0) {
        mx_error_handler(FILE_IS_EMPTY, filename, NULL);
        exit(-1);
    }
    if (file_str == NULL) {
        mx_error_handler(FILE_DOES_NOT_EXISTS, filename, NULL);
        exit(-1);
    }
}

static void pathfinding(char **lines, char **set, char ***i, char *str) {
    int **ar = mx_get_islands_matrix(lines, set, mx_get_arr_length(lines) - 1);
    t_graph *graph = mx_create_graph(mx_atoi(lines[0]));
    t_list *all_paths = NULL;
    t_list *min_paths = NULL;
    t_list *n = mx_add_edges(graph, lines, set, i);

    mx_get_all_paths(mx_atoi(lines[0]), graph, &all_paths);
    min_paths = mx_get_min_paths(all_paths, ar);
    mx_print_all_paths(min_paths, set, ar);
    mx_del_islands(i, mx_get_arr_length(lines) - 1);
    mx_del_strarr(&lines);
    mx_del_intarr(&ar, mx_get_arr_length(set));
    mx_del_strarr(&set);
    mx_del_lists(all_paths, min_paths, n);
    mx_del_graph(graph);
    mx_strdel(&str);
}
