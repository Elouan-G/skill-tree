#include "GraphUtils.h"
#include <vector>

using namespace GraphUtils;

class SkillTreeGenerator {
private:
    std::vector<Vertex>* vertices;
    std::vector<Edge>* edges;

public:
    SkillTreeGenerator(std::vector<Vertex>* vertices, std::vector<Edge>* edges)
        : vertices(vertices), edges(edges) {};
    ~SkillTreeGenerator() {
        delete vertices;
        delete edges;
    };
    SkillTreeGenerator(const SkillTreeGenerator&) = delete;
    SkillTreeGenerator& operator=(const SkillTreeGenerator&) = delete;
};