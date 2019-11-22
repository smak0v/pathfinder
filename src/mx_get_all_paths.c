#include "pathfinder.h"

void mx_get_all_paths(int islands_c, t_graph *graph, t_list **all_paths) {
    t_list *tmp = NULL;

    for (int i = 0; i < islands_c; i++)
        for (int j = 0; j < islands_c; j++) {
            tmp = mx_get_all_paths_util(graph, i, j);
            mx_revers_list(&tmp);
            mx_push_back(all_paths, tmp);
        }
}
