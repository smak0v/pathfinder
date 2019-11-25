#include "pathfinder.h"

void mx_check_all_lines(char **file_lines, char *file_str) {
    if (!mx_check_first_line(file_lines[0])) {
        mx_error_handler(INVALID_FIRST_LINE, NULL, NULL);
        mx_del_strarr(&file_lines);
        mx_strdel(&file_str);
        exit(-1);
    }
    for (int i = 1; i < mx_get_arr_length(file_lines); i++)
        if (!mx_is_line_correct(file_lines[i])) {
            mx_error_handler(INVALID_LINE, NULL, mx_itoa(i + 1));
            mx_del_strarr(&file_lines);
            mx_strdel(&file_str);
            exit(-1);
        }
}
