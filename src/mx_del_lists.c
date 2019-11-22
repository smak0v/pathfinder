#include "pathfinder.h"

static void del_list(t_list *list);
static void del_2d_list(t_list *list);
static void del_all_paths_list(t_list *list);
static void del_nodes_list(t_list *list);

void mx_del_lists(t_list *all_paths, t_list *min_paths, t_list *nodes) {
    del_all_paths_list(all_paths);
    del_list(min_paths);
    del_nodes_list(nodes);
}

static void del_all_paths_list(t_list *list) {
    t_list *tmp1 = list;
    t_list *tmp2 = NULL;
    t_list *tmp3 = NULL;

    while (tmp1) {
        tmp2 = (t_list *)tmp1->data;
        while (tmp2) {
            tmp3 = (t_list *)tmp2->data;
            while (tmp3) {
                free(tmp3->data);
                tmp3->data = NULL;
                mx_pop_front(&tmp3);
            }
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    tmp1 = list;
    del_2d_list(tmp1);
    del_list(list);
}

static void del_2d_list(t_list *list) {
    t_list *tmp2 = NULL;

    while (list) {
        tmp2 = (t_list *)list->data;
        del_list(tmp2);
        list = list->next;
    }
}

static void del_list(t_list *list) {  
    while (list)
        mx_pop_back(&list);
}

static void del_nodes_list(t_list *list) {
    t_node *node = NULL;
    t_list *first = list;

    while (first) {
        node = (t_node *)first->data;
        free(node);
        node = NULL;
        mx_pop_front(&first);
    }
}
