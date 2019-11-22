#include "pathfinder.h"

t_list *mx_add_edges(t_graph *graph, char **lines, char **set, char ***i) {
    t_list *n = NULL;

    for (int j = 0; j < mx_get_arr_length(lines) - 1; j++)
        mx_add_edge(graph, mx_get_i(set, i[j][0]), mx_get_i(set, i[j][1]), &n);
    return n;
}
