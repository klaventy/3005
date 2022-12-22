#include <iostream>
#include <unordered_set>
#include <vector>
#include "maxClique.h"

int main() {
	
	int n, d;
	std::cout << "Enter the value of n: ";
	std::cin >> n;
	std::cout << "Enter the value of d: ";
	std::cin >> d;

	Graph graph = hamming_graph(n, d);

	std::unordered_set<int> clique = maximal_clique(graph);

	std::cout << "The size of the maximal clique is: " << clique.size() << std::endl;

	return 0;
}