#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	unsigned long nbr_copy = nbr;
	int hex_length = 0;
	int i = 0;
	char *hex_number;
	int reminder;

	if (nbr == 0) {
		hex_number = mx_strnew(1);
		hex_number = "0";
		return hex_number;
	}
	while (nbr_copy) {
		hex_length++;
		nbr_copy /= 10;
	}
	hex_number = mx_strnew(hex_length);
	while (nbr % 16) {
		reminder = nbr % 16;
		nbr /= 16;
		if (reminder >= 0 && reminder <= 9)
			hex_number[i] = reminder + 48;
		else if (reminder >= 10 && reminder <= 15)
			hex_number[i] = reminder + 87;
		i++;
	}
	mx_str_reverse(hex_number);
	return hex_number;
}
