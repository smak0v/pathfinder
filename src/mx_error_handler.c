#include "pathfinder.h"

void mx_error_handler(t_error error, char *filename, char *text) {
    switch (error) {
        case INVALID_ARGUMENTS_COUNT:
            mx_print_error("usage: ./pathfinder [filename]\n");
            break;
        case FILE_DOES_NOT_EXISTS:
            mx_gener("error: file ", mx_strdup(filename), " does not exist\n");
            break;
        case FILE_IS_EMPTY:
            mx_gener("error: file ", mx_strdup(filename), " is empty\n");
            break;
        case INVALID_FIRST_LINE:
            mx_print_error("error: line 1 isn't valid\n");
            break;
        case INVALID_LINE:
            mx_gener("error: line ", text, " isn't valid\n");
            break;
        case INVALID_ISLANDS_COUNT:
            mx_print_error("error: invalid number of islands\n");
            break;
    }
}
