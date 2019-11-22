#include "pathfinder.h"

void mx_add_edge(t_graph *graph, int src, int dst, t_list **nodes) {
    t_node *node = mx_create_adjacency_node(dst);

    node->next = graph->adjacency_lists[src].head;
    graph->adjacency_lists[src].head = node;
    mx_push_back(nodes, node);

    node = mx_create_adjacency_node(src);
    node->next = graph->adjacency_lists[dst].head;
    graph->adjacency_lists[dst].head = node;
    mx_push_back(nodes, node);
}
