#include "pathfinder.h"

void mx_generate_error(char *first_part, char *text, char *second_part) {
    int len1 = mx_strlen(first_part);
    int len2 = mx_strlen(text);
    int len3 = mx_strlen(second_part);
    char *error = mx_strnew(len1 + len2 + len3);

    mx_strcat(error, first_part);
    mx_strcat(error, text);
    mx_strcat(error, second_part);
    mx_print_error(error);
    mx_strdel(&text);
    mx_strdel(&error);
}
