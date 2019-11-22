#include "pathfinder.h"

static void fill_set(char **set, int *j, char *island, int islands_c);
static void check_line(char *i_1, char *i_2, int length_of_bridge, int i);

char ***mx_get_islands(int edges_count, char **file_lines, char **set) {
    char ***islands = (char ***)malloc(edges_count * sizeof(char **));
    char *i_1 = NULL;
    char *i_2 = NULL;
    int length_of_bridge = 0;
    int islands_count = mx_atoi(file_lines[0]);

    for (int i = 0; i < edges_count; i++)
        islands[i] = (char **)malloc(2 * sizeof(char *));
    for (int i = 0, j = 0; i < edges_count; i++) {
        mx_parse_line(file_lines[i + 1], &i_1, &i_2, &length_of_bridge);
        check_line(i_1, i_2, length_of_bridge, i);
        fill_set(set, &j, i_1, islands_count);
        fill_set(set, &j, i_2, islands_count);
        islands[i][0] = mx_strdup(i_1);
        islands[i][1] = mx_strdup(i_2);
        mx_strdel(&i_1);
        mx_strdel(&i_2);
        length_of_bridge = 0;
    }
    return islands;
}

static void check_line(char *i_1, char *i_2, int length_of_bridge, int i) {
    if ((mx_strcmp(i_1, i_2) == 0) && (length_of_bridge != 0)) {
        mx_error_handler(INVALID_LINE, NULL, mx_itoa(i + 1));
        mx_strdel(&i_1);
        mx_strdel(&i_2);
        exit(-1);
    }
}

static void fill_set(char **set, int *j, char *island, int islands_c) {
    if(!mx_check_str_set(set, island, islands_c)) {
        set[*j] = mx_strdup(island);
        *j += 1;
    }
}
