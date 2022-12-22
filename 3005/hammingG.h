#include <unordered_set>
#include <vector>
#include "hammingD.h"
#include "ItoB.h"

struct Graph {
    std::unordered_set<int>* adjacency_list;
    int num_vertices;
};

Graph hamming_graph(int n, int d) {
    Graph graph;
    graph.num_vertices = 1 << n;
    graph.adjacency_list = new std::unordered_set<int>[graph.num_vertices];

    for (int u = 0; u < graph.num_vertices; u++) {
        for (int v = u + 1; v < graph.num_vertices; v++) {
            std::vector<int> x = int_to_binary_vector(u, n);
            std::vector<int> y = int_to_binary_vector(v, n);
            int distance = hamming_distance(x, y);

            if (distance >= d) {
                graph.adjacency_list[u].insert(v);
                graph.adjacency_list[v].insert(u);
            }
        }
    }

    return graph;
}
