#pragma once
#include "GraphUtils.hpp"
#include <vector>
#include <memory>
#include <string>

using namespace GraphUtils;

class SkillTreeGenerator {
private:
    std::unique_ptr<Vertices> vertices;
    std::unique_ptr<VerticesMap> verticesMap;
    std::unique_ptr<Edges> edges;
    std::string skillTreeText;

    Vertex getRoot() const;
    std::string getVertexStyle(const VertexType type) const;
    std::string getVertexText(const Vertex& vertex) const;
    std::string getEdgeText(const Edge& edge) const;
    std::string getHeaderText() const;
    std::string getVerticesText() const;
    std::string getEdgesText() const;
    std::string getFooterText() const;
    void setSkillTreeText();
    
public:
    SkillTreeGenerator( std::unique_ptr<Vertices> v,
                        std::unique_ptr<VerticesMap> vm,
                        std::unique_ptr<Edges> e);
    ~SkillTreeGenerator() = default;

    void printSkillTreeText() const;
};