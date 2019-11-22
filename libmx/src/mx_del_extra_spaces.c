#include "libmx.h"

static int get_str_length_without_extra_spaces(const char *str) {
	int length = 0;
	int str_lenght = mx_strlen(str);

	for(int i = 0; i < str_lenght; i++) {
		if (mx_isspace(str[i])) {
			length++;
			while(mx_isspace(str[i])) {
				i++;
			}
		}
		if (!mx_isspace(str[i]))
			length++;
	}
	return length;
}

char *mx_del_extra_spaces(const char *str) {
	char *new_str = NULL;
	char *trimmed_str = NULL;
	int length = 0;

	if (!str)
		return NULL;
	trimmed_str = mx_strtrim(str);
	length = get_str_length_without_extra_spaces(trimmed_str);
	new_str = mx_strnew(length);
	for(int i = 0, j = 0; i < mx_strlen(trimmed_str); ) {
		if (!mx_isspace(trimmed_str[i])) {
			new_str[j] = trimmed_str[i];
			i++;
			j++;
		}
		if (mx_isspace(trimmed_str[i])) {
			new_str[j] = ' ';
			j++;
			while(mx_isspace(trimmed_str[i]))
				i++;
		}
	}
	mx_strdel(&trimmed_str);
	return new_str;
}
