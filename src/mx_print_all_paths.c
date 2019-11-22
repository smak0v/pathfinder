#include "pathfinder.h"

void mx_print_all_paths(t_list *paths, char **set, int **islands_arr) {
    t_list *indexes = NULL;
    t_list *p = paths;
    int weight = 0;

    while (p) {
        indexes = (t_list *)p->data;
        weight = mx_get_path_weight(indexes, islands_arr);
        mx_print_path(set, indexes, weight, islands_arr);
        p = p->next;
    }
}
