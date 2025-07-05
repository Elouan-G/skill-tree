#include "SkillTreeDBManager.hpp"
#include <iostream>
#include <memory>

using namespace GraphUtils;

int main() {
    SkillTreeDBManager db;
    std::unique_ptr<VerticesMap> verticesMap = db.getVerticesMap();
    std::unique_ptr<Edges> edges = db.getEdges();
    for (Edge edge : *edges) {
        std::cout << edge << " " << (*verticesMap)[edge.source] << ";" << (*verticesMap)[edge.target] << std::endl;
    }
    std::cout << std::endl;
    std::unique_ptr<Vertices> vertices = db.getVertices();
    for (Vertex vertex : *vertices) {
        std::cout << vertex << std::endl;
    }
    return 0;
}