#include "pathfinder.h"

int mx_get_i(char **set, const char *element) {
    if (set) {
        for (int i = 0; i < mx_get_arr_length(set); i++)
            if (mx_strcmp(set[i], element) == 0)
                return i;
            return -1;
    }
    return -2;
}
