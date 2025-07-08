#include <memory>

#include "GraphUtils.hpp"
#include "SkillTreeDBManager.hpp"
#include "SkillTreeTextGenerator.hpp"

using namespace GraphUtils;

int main() {
    SkillTreeDBManager db;
    std::unique_ptr<Vertices> vertices = db.getVertices();
    std::unique_ptr<VerticesMap> verticesMap = db.getVerticesMap();
    std::unique_ptr<Edges> edges = db.getEdges();
    SkillTreeGenerator generator(std::move(vertices), std::move(verticesMap), std::move(edges));
    generator.printSkillTreeText();
    return 0;
}