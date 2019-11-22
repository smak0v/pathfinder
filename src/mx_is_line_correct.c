#include "pathfinder.h"

bool mx_is_line_correct(char *line) {
    int i = 0;
    int i_copy = 0;

    while (mx_isalpha(line[i]))
        i++;
    if (i == 0 || line[i] != '-')
        return false;
    i_copy = i;
    i++;
    while (mx_isalpha(line[i]))
        i++;
    if (i - i_copy == 0 || line[i] != ',')
        return false;
    i++;
    while (line[i] != '\0') {
        if (!mx_isdigit(line[i]))
            return false;
        i++;
    }
    return true;
}
