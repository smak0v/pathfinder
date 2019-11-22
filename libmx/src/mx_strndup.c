#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	char *result = NULL;

	if ((int)n < 0) {
		result = mx_strnew(mx_strlen(s1));
		mx_strncpy(result, s1, mx_strlen(s1));
	} else {
		result = mx_strnew(n);
		mx_strncpy(result, s1, n);
	}
	return result;
}
