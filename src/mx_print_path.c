#include "pathfinder.h"

static void print_boundary();
static void print_path(char **islands_set, t_list *path);
static void print_route(char **islands_set, t_list *path);
static void print_distance(int **matrix, int weight, t_list *path);

void mx_print_path(char **islands_set, t_list *path, int w, int **matrix) {
    print_boundary();
    mx_printstr("Path: ");
    print_path(islands_set, path);
    mx_printstr("Route: ");
    print_route(islands_set, path);
    mx_printstr("Distance: ");
    print_distance(matrix, w, path);
    print_boundary();
}

static void print_path(char **islands_set, t_list *path) {
    t_list *tmp = path;

    while (tmp->next)
        tmp = tmp->next;
    mx_printstr(islands_set[mx_atoi(path->data)]);
    mx_printstr(" -> ");
    mx_printstr(islands_set[mx_atoi(tmp->data)]);
    mx_printchar('\n');
}

static void print_route(char **islands_set, t_list *path) {
    t_list *tmp = path;

    while (tmp->next) {
        mx_printstr(islands_set[mx_atoi(tmp->data)]);
        mx_printstr(" -> ");
        tmp = tmp->next;
    }
    mx_printstr(islands_set[mx_atoi(tmp->data)]);
    mx_printchar('\n');
}

static void print_distance(int **matrix, int weight, t_list *path) {
    t_list *tmp = path;
    char *str_weight = mx_itoa(weight);
    char *element = NULL;

    while (tmp->next->next) {
        element = mx_itoa(matrix[mx_atoi(tmp->data)][mx_atoi(tmp->next->data)]);
        mx_printstr(element);
        mx_strdel(&element);
        mx_printstr(" + ");
        tmp = tmp->next;
    }
    element = mx_itoa(matrix[mx_atoi(tmp->data)][mx_atoi(tmp->next->data)]);
    if ((mx_list_size(path) > 2) && element) {
        mx_printstr(element);
        mx_printstr(" = ");
    }
    mx_printstr(str_weight);
    mx_printchar('\n');
    mx_strdel(&element);
    mx_strdel(&str_weight);
}

static void print_boundary() {
    for (int i = 0; i < 40; i++)
        mx_printchar('=');
    mx_printchar('\n');
}
