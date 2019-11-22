#include "libmx.h"

char *mx_itoa(int number) {
	int length = 0;
	int i = 0;
	int copy_number = number;
	char *str_integer;

	if (number == 0) {
		str_integer = mx_strnew(1);
		mx_strcpy(str_integer, "0");
		return str_integer;
	}
	if (number == -2147483648) {
		str_integer = mx_strnew(11);
		mx_strcpy(str_integer, "-2147483648");
		return str_integer;
	}
	while(copy_number) {
		length++;
		copy_number /= 10;
	}
	if (number < 0)
		str_integer = mx_strnew(length + 1);
	else
		str_integer = mx_strnew(length);
	for (; i < length; i++) {
		if (number < 0) {
			str_integer[length] = '-';
			number *= -1;
		}
		str_integer[i] = (number % 10) + 48;
		number /= 10;
	}
	mx_str_reverse(str_integer);
	str_integer[i + 1] = '\0';
	return str_integer;
}
