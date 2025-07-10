#pragma once
#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include "GraphUtils.hpp"
#include "SkillTreeDBManager.hpp"
#include "SkillTreeTextGenerator.hpp"
#include "cli_utils.hpp"

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

auto make_skill_tree_text_file = [](const std::string& dotFileName) {
    SkillTreeDBManager db;
    std::unique_ptr<Vertices> vertices = db.getVertices();
    std::unique_ptr<VerticesMap> verticesMap = db.getVerticesMap();
    std::unique_ptr<Edges> edges = db.getEdges();
    SkillTreeTextGenerator generator(std::move(vertices), std::move(verticesMap), std::move(edges));
    std::ofstream dotFile(dotFileName);
    dotFile << generator.getSkillTreeText();
};

auto make_skill_tree_image_file = [](const std::string& dotFileName, const std::string& imageFileName) {
    const std::string command = "dot -Tpng " + dotFileName + " -o " + imageFileName;
    int result = std::system(command.c_str());
    if (result != 0) {
        handle_error("make_skill_tree_image_file", "Failed to generate skill tree image using dot.");
    }
};

auto open_file_with_default_app = [](const std::string& fileName) {
    const std::string command = "xdg-open " + fileName;  // For Linux
    // const std::string command = "open " + fileName; // For macOS
    // const std::string command = "start " + fileName; // For Windows
    int result = std::system(command.c_str());
    if (result != 0) {
        handle_error("open_file_with_default_app",
                     "Failed to open file with default application : " + fileName);
    }
};

auto generate_skill_tree_image = [](const std::string& treeName) {
    const std::string dotFileName = treeName + "_skill-tree.dot";
    make_skill_tree_text_file(dotFileName);
    const std::string imageFileName = treeName + "_skill-tree.png";
    make_skill_tree_image_file(dotFileName, imageFileName);
    open_file_with_default_app(imageFileName);
};