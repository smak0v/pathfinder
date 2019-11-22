#include "pathfinder.h"

int **create_matrix(char **islands_set);

int **mx_get_islands_matrix(char **lines, char **islands_set, int edges) {
    char **file_lines_copy = lines + 1;
    int **matrix = create_matrix(islands_set);
    char *island_1 = NULL;
    char *island_2 = NULL;
    int length_of_bridge = 0;

    for (int i = 0, j = 0, k = 0; i < edges; i++) {
        mx_parse_line(*file_lines_copy, &island_1, &island_2, &length_of_bridge);
        j = mx_get_set_element_index(islands_set, island_1);
        k = mx_get_set_element_index(islands_set, island_2);
        matrix[j][k] = length_of_bridge;
        matrix[k][j] = length_of_bridge;
        mx_strdel(&island_1);
        mx_strdel(&island_2);
        length_of_bridge = 0;
        file_lines_copy++;
    }
    return matrix;
}

int **create_matrix(char **islands_set) {
    int **matrix = malloc(mx_get_arr_length(islands_set) * sizeof(int *));

    for (int i = 0; i < mx_get_arr_length(islands_set); i++)
        matrix[i] = (int *)malloc(mx_get_arr_length(islands_set) * sizeof(int));
    for (int i = 0; i < mx_get_arr_length(islands_set); i++)
        for(int j = 0; j < mx_get_arr_length(islands_set); j++)
            matrix[i][j] = INF;
    return matrix;
}
