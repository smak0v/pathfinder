#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
 	char *new_str = NULL;
 	char *new_str_copy = NULL;
 	char *tmp = NULL;
 	int sub_str_count = 0;
 	int all_sub_str_length = 0;

 	if (!str || !sub || !replace)
 		return NULL;
 	sub_str_count = mx_count_substr(str, sub);
 	all_sub_str_length = sub_str_count * mx_strlen(sub);
 	new_str = mx_strnew(mx_strlen(str) - all_sub_str_length + (mx_strlen(replace) * sub_str_count));
 	new_str_copy = new_str;
 	while (*str && *str != '\0') {
 		if (!mx_strstr(str, sub))
 			return mx_strdup(str);
 		if (str != mx_strstr(str, sub)) {
 			mx_strncpy(new_str, str, 1);
 			new_str++;
 			str++;
 		}
 		if (str == mx_strstr(str, sub)) {
 			tmp = mx_strdup(replace);
 			mx_strcat(new_str, tmp);
 			mx_strdel(&tmp);
 			str += mx_strlen(sub);
 			new_str += mx_strlen(replace);
 		}
 	}
 	return new_str_copy;
 }
