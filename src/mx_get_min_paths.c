#include "pathfinder.h"

t_list *mx_get_min_paths(t_list *all_paths, int **islands_m) {
    t_list *all_min_paths = NULL;
    t_list *min_paths = NULL;
    t_list *min = NULL;

    while (all_paths) {
        all_min_paths = mx_get_all_min_paths((t_list *)all_paths->data, islands_m);
        min = all_min_paths;
        if (min)
            while (min) {
                mx_push_back(&min_paths, (t_list *)min->data);
                min = min->next;
            }
        while(all_min_paths)
            mx_pop_back(&all_min_paths);
        all_paths = all_paths->next;
    }
    return min_paths;
}
