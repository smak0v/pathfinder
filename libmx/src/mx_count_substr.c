#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;

    if (!str || !sub)
        return -1;
    for (str = mx_strstr(str, sub); str != NULL; str = mx_strstr(str + 1, sub))
        count++;
    return count;
}
