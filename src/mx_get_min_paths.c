#include "pathfinder.h"

t_list *mx_get_min_paths(t_list *all_paths, int **islands_m) {
    t_list *all_p = all_paths;
    t_list *all_m_p = NULL;
    t_list *min_paths = NULL;
    t_list *min = NULL;

    while (all_p) {
        all_m_p = mx_get_all_min_paths((t_list *)all_p->data, islands_m);
        min = all_m_p;
        if (min)
            while (min) {
                mx_push_back(&min_paths, (t_list *)min->data);
                min = min->next;
            }
        while(all_m_p)
            mx_pop_back(&all_m_p);
        all_p = all_p->next;
    }
    return min_paths;
}
