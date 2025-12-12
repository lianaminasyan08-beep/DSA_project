#include <stdio.h>
#include <stdlib.h>
#include "graph/c_graph.h"

void print_path(const char* traversal_name, int* path, int path_len) {
    printf("  %s Traversal Path: ", traversal_name);
    for (int i = 0; i < path_len; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    free(path);
}

int main() {
    printf("--- Graph Module Demo ---\n\n");

    // 1. Diagram of a sample graph
    printf("1. Sample Graph Diagram:\n\n");
    printf("    Vertices: 1, 2, 3, 4, 5\n");
    printf("    Edges:\n");
    printf("      - 1 -> 2 (Weight: 1.0)\n");
    printf("      - 1 -> 3 (Weight: 1.0)\n");
    printf("      - 2 -> 4 (Weight: 1.0)\n");
    printf("      - 2 -> 5 (Weight: 1.0)\n");
    printf("      - 3 -> 5 (Weight: 1.0)\n\n");
    printf("    Visual Representation:\n\n");
    printf("          (1)\n");
    printf("         /   \\\n");
    printf("       (2)---(3)\n");
    printf("      / \\   /\n");
    printf("    (4) (5)\n\n");


    // Create the graph
    c_graph_t* graph = graph_create(0); // Undirected
    graph_add_vertex(graph, 1);
    graph_add_vertex(graph, 2);
    graph_add_vertex(graph, 3);
    graph_add_vertex(graph, 4);
    graph_add_vertex(graph, 5);
    graph_add_edge(graph, 1, 2, 1.0);
    graph_add_edge(graph, 1, 3, 1.0);
    graph_add_edge(graph, 2, 4, 1.0);
    graph_add_edge(graph, 2, 5, 1.0);
    graph_add_edge(graph, 3, 5, 1.0);

    // 2. BFS Traversal Results
    printf("2. BFS Traversal Results (Start: 1, End: 4):\n\n");
    int bfs_path_len = 0;
    int* bfs_path = graph_bfs(graph, 1, 4, &bfs_path_len);
    if (bfs_path) {
        print_path("BFS", bfs_path, bfs_path_len);
    } else {
        printf("  No BFS path found.\n");
    }
    printf("\n");

    // 3. DFS Traversal Results
    printf("3. DFS Traversal Results (Start: 1):\n\n");
    int dfs_path_len = 0;
    int* dfs_path = graph_dfs(graph, 1, &dfs_path_len);
    if (dfs_path) {
        print_path("DFS", dfs_path, dfs_path_len);
    } else {
        printf("  No DFS path found.\n");
    }
    printf("\n");

    graph_destroy(graph);

    return 0;
}
