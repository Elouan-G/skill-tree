#include "SkillTreeDBManager.hpp"
#include <iostream>

using namespace GraphUtils;

int main() {
    SkillTreeDBManager db;
    std::unique_ptr<std::vector<Vertex>> vertices = db.getVertices();
    for (Vertex& vertex : *vertices) {
        std::cout << "ID: " << vertex.id << ", Type: " << vertex.type << ", Value: " << vertex.value << std::endl;
    }
    return 0;
}