#include "pathfinder.h"

static int get_line_length(char *line);
static void check_length(int length, char *file_str, int counter);
static void check_lines(int counter, char *file_str, char *copy_file_str);

void mx_validate_file_str(char *file_str) {
    char *copy_file_str = file_str;
    int counter = 0;
    int length = 0;

    while ((*copy_file_str) && (*copy_file_str != '\0')) {
        length = get_line_length(copy_file_str);
        check_length(length, file_str, counter);
        check_lines(counter, file_str, copy_file_str);
        counter++;
        copy_file_str += length + 1;
    }
}

static int get_line_length(char *line) {
    char *copy_line = line;
    int length = 0;

    while ((*copy_line != '\0') && (*copy_line != '\n')) {
        length++;
        copy_line++;
    }
    return length;
}

static void check_length(int length, char *file_str, int counter) {
    if (!length) {
        mx_error_handler(INVALID_LINE, NULL, mx_itoa(counter + 1));
        mx_strdel(&file_str);
        exit(-1);
    }
}

static void check_lines(int counter, char *file_str, char *copy_file_str) {
    if (counter == 0) {
        if (!mx_check_first_line(file_str)) {
            mx_error_handler(INVALID_FIRST_LINE, NULL, NULL);
            mx_strdel(&file_str);
            exit(-1);
        }
    } else {
        if (!mx_is_line_correct(copy_file_str)) {
            mx_error_handler(INVALID_LINE, NULL, mx_itoa(counter + 1));
            mx_strdel(&file_str);
            exit(-1);
        }
    }
}
