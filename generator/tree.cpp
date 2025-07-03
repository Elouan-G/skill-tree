#include <iostream>
#include <vector>

int main() {
    std::vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    
    std::cout << "graph tree {\n";
    for (auto& [u, v] : edges)
        std::cout << "  " << u << " -- " << v << ";\n";
    std::cout << "}\n";
}