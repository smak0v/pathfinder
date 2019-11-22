#include "pathfinder.h"

void mx_del_islands(char ***islands, int edges_count) {
    for (int i = 0; i < edges_count; i++) {
        for (int j = 0; j < 2; j++) {
            free(islands[i][j]);
            islands[i][j] = NULL;
        }
        free(islands[i]);
        islands[i] = NULL;
    }
    free(islands);
    islands = NULL;
}
