
#include <unordered_set>
#include <vector>
#include "hammingG.h"
std::unordered_set<int> maximal_clique(const Graph& graph) {
    std::unordered_set<int> clique;

    std::unordered_set<int> included;
    std::unordered_set<int> excluded;

    bron_kerbosch(graph, clique, included, excluded);

    return clique;
}

void bron_kerbosch(const Graph& graph,
    std::unordered_set<int>& clique,
    std::unordered_set<int>& included,
    std::unordered_set<int>& excluded) {
    if (included.empty() && excluded.empty()) {
        return;
    }

    int pivot = *excluded.begin();
    for (int v : included) {
        if (excluded.find(v) == excluded.end()) {
            pivot = v;
            break;
        }
    }

    for (int v : graph.adjacency_list[pivot]) {
        if (excluded.find(v) == excluded.end()) {
            included.insert(v);
            bron_kerbosch(graph, clique, included, excluded);

            if (included.size() > clique.size()) {
                clique = included;
            }

            included.erase(v);
            excluded.insert(v);
        }
    }
}