#include "SkillTreeDBManager.hpp"
#include <iostream>
#include <memory>

using namespace GraphUtils;

int main() {
    SkillTreeDBManager db;
    std::unique_ptr<Vertices> vertices = db.getVertices();
    std::unique_ptr<Edges> edges = db.getEdges();
    std::cout << "SkillTreeV:" << vertices->size() << std::endl;
    std::cout << "SkillTreeE:" << edges->size() << std::endl;
    return 0;
}