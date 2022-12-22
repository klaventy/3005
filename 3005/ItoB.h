#include <vector>

std::vector<int> int_to_binary_vector(int x, int n) {
    std::vector<int> v;
    while (x > 0) {
        v.push_back(x % 2);
        x /= 2;
    }
    while (v.size() < n) {
        v.push_back(0);
    }
    std::reverse(v.begin(), v.end());
    return v;
}