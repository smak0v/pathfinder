#include "pathfinder.h"

void mx_del_graph(t_graph *graph) {
    free(graph->adjacency_lists);
    graph->adjacency_lists = NULL;
    free(graph);
    graph = NULL;
}
