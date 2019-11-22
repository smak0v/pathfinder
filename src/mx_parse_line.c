#include "pathfinder.h"

void mx_parse_line(char *line, char **i_1, char **i_2, int *bridge) {
    int dash_index = mx_get_char_index(line, '-');
    int comma_index = mx_get_char_index(line, ',');
    char *bridge_length = NULL;
    int number_length = 0;
    char *line_copy = line;

    *i_1 = mx_strnew(dash_index);
    mx_strncpy(*i_1, line, dash_index);
    *i_2 = mx_strnew(comma_index - 1 - dash_index);
    mx_strncpy(*i_2, line + dash_index + 1, comma_index - 1 - dash_index);
    line_copy = line + comma_index + 1;
    while (*line_copy != '\0') {
        number_length++;
        line_copy++;
    }
    bridge_length = mx_strnew(number_length);
    mx_strncpy(bridge_length, line + comma_index + 1, number_length);
    *bridge = mx_atoi(bridge_length);
    mx_strdel(&bridge_length);
}
