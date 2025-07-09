#include <memory>
#include <string>
#include <vector>

#include "GraphUtils.hpp"
#include "SkillTreeDBManager.hpp"

using namespace GraphUtils;

auto get_skill_tree_list_from_db = []() {
    SkillTreeDBManager db;
    std::unique_ptr<Vertices> vertices = db.getVertices();

    std::vector<std::string> skillTreeList;
    for (const Vertex& vertex : *vertices) {
        if (vertex.type == VertexType::ROOT) {
            skillTreeList.push_back(vertex.value);
        }
    }

    return skillTreeList;
};