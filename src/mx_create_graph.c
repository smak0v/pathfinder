#include "pathfinder.h"

t_graph *mx_create_graph(int vertices_count) {
    t_graph *graph = (t_graph *)malloc(1 * sizeof(t_graph));

    graph->vertices_count = vertices_count;
    graph->adjacency_lists = malloc(vertices_count * sizeof(t_adjacency_list));
    for (int i = 0; i < vertices_count; i++)
        graph->adjacency_lists[i].head = NULL;
    return graph;
}
