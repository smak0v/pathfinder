#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	if ((str == NULL) || (sub == NULL))
		return -2;
	if (mx_strstr(str, sub) != NULL)
		return mx_strstr(str, sub) - (char *)str;
	return -1;
}
