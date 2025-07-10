#include "SkillTreeTextGenerator.hpp"

#include <iostream>

SkillTreeTextGenerator::SkillTreeTextGenerator(std::unique_ptr<Vertices> v, std::unique_ptr<VerticesMap> vm,
                                               std::unique_ptr<Edges> e)
    : vertices(std::move(v)), verticesMap(std::move(vm)), edges(std::move(e)) {
    this->setSkillTreeText();
}

Vertex SkillTreeTextGenerator::getRoot() const {
    for (const auto& vertex : *vertices) {
        if (vertex.type == VertexType::ROOT) {
            return vertex;
        }
    }
    throw std::runtime_error("No root vertex found in the skill tree.");
}

std::string SkillTreeTextGenerator::getVertexStyle(const VertexType type) const {
    switch (type) {
        case VertexType::ROOT:
            return ", shape=\"diamond\", style=\"filled\", fillcolor=\"lightblue\"";
        case VertexType::CATEGORY:
            return ", shape=\"circle\", style=\"filled\", fillcolor=\"lightgreen\"";
        case VertexType::SKILL:
            return ", shape=\"ellipse\", style=\"filled\", fillcolor=\"lightyellow\"";
        case VertexType::LEVEL:
            return ", shape=\"box\", style=\"filled\", fillcolor=\"lightgray\"";
        default:
            return "";
    }
}

std::string SkillTreeTextGenerator::getVertexText(const Vertex& vertex) const {
    return "    node" + std::to_string(vertex.id) + " [label=\"" + vertex.value + "\"" +
           this->getVertexStyle(vertex.type) + "];\n";
}
std::string SkillTreeTextGenerator::getEdgeText(const Edge& edge) const {
    return "    node" + std::to_string(edge.source) + " -- node" + std::to_string(edge.target) + ";\n";
}

std::string SkillTreeTextGenerator::getHeaderText() const {
    return "graph " + this->getRoot().value + " {\n";
}

std::string SkillTreeTextGenerator::getVerticesText() const {
    std::string verticesText;
    for (const auto& vertex : *vertices) {
        verticesText += this->getVertexText(vertex);
    }
    return verticesText + "\n";
}

std::string SkillTreeTextGenerator::getEdgesText() const {
    std::string edgesText;
    for (const auto& edge : *edges) {
        edgesText += this->getEdgeText(edge);
    }
    return edgesText;
}

std::string SkillTreeTextGenerator::getFooterText() const {
    return "}\n";
}

void SkillTreeTextGenerator::setSkillTreeText() {
    this->skillTreeText = this->getHeaderText();
    this->skillTreeText += this->getVerticesText();
    this->skillTreeText += this->getEdgesText();
    this->skillTreeText += this->getFooterText();
}

void SkillTreeTextGenerator::printSkillTreeText() const {
    std::cout << this->skillTreeText << std::endl;
}