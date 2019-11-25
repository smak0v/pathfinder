#include "libmx.h"

static int get_number_length(int number);
static char *get_zero_value();
static char *get_min_int_value();

char *mx_itoa(int number) {
    int length = get_number_length(number);
    char *str_integer = NULL;

    if ((number != 0) && (number != -2147483648)) {
        if (number < 0)
            str_integer = mx_strnew(length + 1);
        else
            str_integer = mx_strnew(length);
        for (int i = 0; i < length; i++) {
            if (number < 0) {
                str_integer[length] = '-';
                number *= -1;
            }
            str_integer[i] = (number % 10) + 48;
            number /= 10;
        }
        mx_str_reverse(str_integer);
        return str_integer;
    }
    return (number == 0) ? get_zero_value() : get_min_int_value();
}

static int get_number_length(int number) {
    int length = 0;
    int copy_number = number;

    while(copy_number) {
        length++;
        copy_number /= 10;
    }
    return length;
}

static char *get_zero_value() {
    char *str_integer = mx_strnew(1);

    mx_strcpy(str_integer, "0");
    return str_integer;
}

static char *get_min_int_value() {
    char *str_integer = mx_strnew(11);

    mx_strcpy(str_integer, "-2147483648");
    return str_integer;
}
