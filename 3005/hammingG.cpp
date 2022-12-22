#include "hammingG.h"

Graph hamming_graph(int n, int d) {
    Graph graph;
    graph.num_vertices = 1 << n;
    graph.adjacency_list = new std::unordered_set<int>[graph.num_vertices];

    for (int i = 0; i < graph.num_vertices; i++) {
        for (int j = i + 1; j < graph.num_vertices; j++) {
            std::vector<int> v = int_to_binary_vector(i, n);
            std::vector<int> w = int_to_binary_vector(j, n);
            int distance = hamming_distance(v, w);

            if (distance >= d) {
                graph.adjacency_list[i].insert(j);
                graph.adjacency_list[j].insert(i);
            }
        }
    }

    return graph;
}
