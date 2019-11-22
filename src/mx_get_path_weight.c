#include "pathfinder.h"

int mx_get_path_weight(t_list *path, int **matrix) {
    int path_weight = 0;
    t_list *tmp = path;

    while (tmp && tmp->next) {
        path_weight += matrix[mx_atoi(tmp->data)][mx_atoi(tmp->next->data)];
        tmp = tmp->next;
    }
    return path_weight;
}
