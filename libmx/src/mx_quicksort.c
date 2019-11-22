#include "libmx.h"

static void swap(char **s1, char **s2) {
	char *tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int mx_quicksort(char **arr, int left, int right) {
	int shifts_number = 0;
	int middle;
	char *pivot;
	int i;
	int j;

	if (!arr)
		return -1;
	if (left < right) {
		middle = left + (right - left) / 2;
		pivot = arr[middle];
		i = left;
		j = right;
		while (i <= j) {
			while (mx_strlen(arr[i]) < mx_strlen(pivot))
				i++;
			while (mx_strlen(arr[j]) > mx_strlen(pivot))
				j--;
			if (i <= j) {
				if ((i != j) && (mx_strlen(arr[i]) != mx_strlen(arr[j]))) {
					swap(&arr[i], &arr[j]);
					shifts_number++;
				}
				i++;
				j--;
			}
		}
		shifts_number += mx_quicksort(arr, left, j);
		shifts_number += mx_quicksort(arr, i, right);
	}
	return shifts_number;
}
