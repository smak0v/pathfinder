#include "libmx.h"

bool mx_is_equal_lists(t_list *a, t_list *b) {
    while (a && b) {
        if (mx_strcmp(a->data, b->data) != 0)
            return false;
        a = a->next;
        b = b->next;
    }
    return !a && !b;
}
