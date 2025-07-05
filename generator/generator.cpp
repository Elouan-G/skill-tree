#include "SkillTreeDBManager.hpp"
#include <iostream>
#include <memory>

using namespace GraphUtils;

int main() {
    SkillTreeDBManager db;
    std::unique_ptr<Vertices> vertices = db.getVertices();
    std::unique_ptr<Edges> edges = db.getEdges();
    for (Edge edge : *edges) {
        std::cout << "[" << edge.source << ";" << edge.target << "] " << (*vertices)[edge.source] << ";" << (*vertices)[edge.target] << std::endl;
    }
    return 0;
}