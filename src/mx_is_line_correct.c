#include "pathfinder.h"

static bool check_bridge_length(int i, char *line);

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
    if (i - i_copy == 1 || line[i] != ',')
        return false;
    i++;
    if (!check_bridge_length(i, line))
        return false;
    return true;
}

static bool check_bridge_length(int i, char *line) {
    int j = 0;

    while (line[i] != '\n') {
        if (!mx_isdigit(line[i]))
            return false;
        i++;
        j++;
    }
    return (j == 0) ? false : true;
}
