#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char result[5];

    if (c < 0x080) {
        result[0] = (c >> 0 & 0x7F) | 0x00;
		result[1] = '\0';
		result[2] = '\0';
		result[3] = '\0';
		result[4] = '\0';
	} else if (c < 0x0800) {
		result[0] = (c >> 6 & 0x1F) | 0xC0;
		result[1] = (c >> 0 & 0x3F) | 0x80;
		result[2] = '\0';
		result[3] = '\0';
		result[4] = '\0';
	} else if (c < 0x010000) {
		result[0] = (c >> 12 & 0x0F) | 0xE0;
		result[1] = (c >> 6 & 0x3F) | 0x80;
		result[2] = (c >> 0 & 0x3F)| 0x80;
		result[3] = '\0';
		result[4] = '\0';
	} else if (c < 0x110000) {
		result[0] = (c >> 18 & 0x07) | 0xF0;
		result[1] = (c >> 12 & 0x3F) | 0x80;
		result[2] = (c >> 6 & 0x3F) | 0x80;
		result[3] = (c >> 0 & 0x3F) | 0x80;
		result[4] = '\0';
	}
	mx_printstr(result);
}
