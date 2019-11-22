#include "pathfinder.h"

t_node *mx_create_adjacency_node(int vertex) {
    t_node *node = (t_node *)malloc(1 * sizeof(t_node));

    node->vertex = vertex;
    node->next = NULL;
    return node;
}
