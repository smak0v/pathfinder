#include "pathfinder.h"

static void get_all_paths(t_bfs *bfs, int src);
static void free_bfs_data(int *path, int *visited, t_bfs *bfs);

t_list *mx_get_all_paths_util(t_graph *graph, int src, int dst) {
    int *path = (int *)malloc(graph->vertices_count * sizeof(int));
    int *visited = (int *)malloc(graph->vertices_count * sizeof(int));
    t_bfs *bfs = (t_bfs *)malloc(1 * sizeof(t_bfs));
    t_list *paths = NULL;

    for (int i = 0; i < graph->vertices_count; i++)
        visited[i] = 0;
    bfs->graph = graph;
    bfs->dst = dst;
    bfs->visited = visited;
    bfs->path = path;
    bfs->path_index = 0;
    bfs->paths = paths;
    bfs->const_src = src;
    get_all_paths(bfs, src);
    free_bfs_data(visited, path, bfs);
    return bfs->paths;
}

static void get_all_paths(t_bfs *bfs, int src) {
    t_list *indexes = NULL;
    char *str = NULL;

    bfs->visited[src] = 1;
    bfs->path[bfs->path_index] = src;
    bfs->path_index++;
    if ((src == bfs->dst) && (bfs->path_index != 1)) {
        for (int i = 0; i < bfs->path_index; i++) {
            str = mx_itoa(bfs->path[i]);
            mx_push_back(&indexes, mx_strdup(str));
            mx_strdel(&str);
        }
        mx_push_back(&bfs->paths, indexes);
    } else {
        for (t_node *n = bfs->graph->adjacency_lists[src].head; n; n = n->next)
            if ((!bfs->visited[n->vertex]) && (bfs->dst > bfs->const_src))
                get_all_paths(bfs, n->vertex);
    }
    bfs->path_index--;
    bfs->visited[src] = 0;
}

static void free_bfs_data(int *path, int *visited, t_bfs *bfs) {
    mx_intdel(&path);
    mx_intdel(&visited);
    free(bfs);
    bfs = NULL;
}
