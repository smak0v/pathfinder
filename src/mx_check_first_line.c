#include "pathfinder.h"

bool mx_check_first_line(char *file_str) {
    for (int i = 0; (i < mx_strlen(file_str)) && (file_str[i] != '\n'); i++)
        if (!mx_isdigit(file_str[i]))
            return false;
    return true;
}
