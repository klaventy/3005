#include <vector>

int hamming_distance(const std::vector<int>& v, const std::vector<int>& w) {
    if (v.size() != w.size()) {
        return -1;
    }

    int distance = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] != w[i]) {
            distance++;
        }
    }

    return distance;
}