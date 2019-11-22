#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
	char *line = NULL;
	char buf = '\0';
	int bytes_count = 0;
	int i = 0;
	int bytes = 0;

	if (fd < 0)
		return -1;
	*lineptr = mx_strnew(buf_size);
	if (buf_size == 0)
		return 0;
	bytes = read(fd, &buf, sizeof(buf));
	while (bytes > 0) {
		line = mx_strnew(buf_size);
		for (i = 0; (i < buf_size) && (bytes > 0); i++) {
			if (buf == delim) {
				line[i] = '\0';
				*lineptr = mx_strjoin(*lineptr, line);
				free(line);
				return bytes_count;
			}
			line[i] = buf;
			bytes_count++;
			bytes = read(fd, &buf, sizeof(buf));
		}
		*lineptr = mx_strjoin(*lineptr, line);
		free(line);
	}
	return bytes_count;
}
