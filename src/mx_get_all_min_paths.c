#include "pathfinder.h"

t_list *mx_get_all_min_paths(t_list *paths, int **matrix) {
    t_list *tmp = paths;
    t_list *all_min_paths = NULL;
    int min_weight = INF;
    int path_weight = 0;

    while (tmp) {
        path_weight = mx_get_path_weight((t_list *)tmp->data, matrix);
        if (path_weight < min_weight) 
            min_weight = path_weight;
        tmp = tmp->next;
    }
    tmp = paths;
    while (tmp) {
        if (mx_get_path_weight((t_list *)tmp->data, matrix) == min_weight) {
            mx_push_back(&all_min_paths, tmp->data);
        }
        tmp = tmp->next;
    }
    return all_min_paths;
}
