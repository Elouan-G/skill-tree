#pragma once
#include "GraphUtils.hpp"
#include <vector>
#include <memory>

using namespace GraphUtils;

class SkillTreeGenerator {
private:
    std::unique_ptr<std::vector<Vertex>> vertices;
    std::unique_ptr<std::vector<Edge>> edges;

    SkillTreeGenerator(const SkillTreeGenerator&) = delete;
    SkillTreeGenerator& operator=(const SkillTreeGenerator&) = delete;
    
public:
    SkillTreeGenerator::SkillTreeGenerator(std::unique_ptr<std::vector<Vertex>> v,
                                       std::unique_ptr<std::vector<Edge>> e)
        : vertices(std::move(v)), edges(std::move(e)) {};
    ~SkillTreeGenerator() = default;
    
};