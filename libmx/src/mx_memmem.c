#include "libmx.h"

static bool compare(unsigned char *big, unsigned char *little);

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	unsigned char *p_big;
	unsigned char *p_little;

	if ((big_len < little_len) || (little_len == 0) || (big_len == 0))
		return NULL;
	p_big = (unsigned char *)big;
	p_little = (unsigned char *)little;
	while (*p_big) {
		if ((*p_big == *p_little) && (compare(p_big, p_little)))
			return (unsigned char *)p_big;
		p_big++;
	}
	return NULL;
}

static bool compare(unsigned char *big, unsigned char *little) {
	while (*big && *little) {
		if (*big != *little)
			return false;
		big++;
		little++;
	}
	return true;
}
