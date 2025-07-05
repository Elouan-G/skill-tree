#include "GraphUtils.hpp"
#include <iostream>

namespace GraphUtils {
    /* Helper functions */
    VertexType fromString(const std::string& type) {
        if (type == "ROOT" || type == "ROOT-USER") return VertexType::ROOT;
        else if (type == "CATEGORY" || type == "TRUNC-CATEGORY") return VertexType::CATEGORY;
        else if (type == "SKILL" || type == "BRANCH-SKILL") return VertexType::SKILL;
        else if (type == "LEVEL" || type == "LEAF-LEVEL") return VertexType::LEVEL;
        throw std::runtime_error("Unknown vertex type: " +  type);
    }

    /* operator<< overloads */
    std::ostream& operator<<(std::ostream& os, const VertexType& type) {
        switch (type) {
            case VertexType::ROOT: os << "ROOT"; break;
            case VertexType::CATEGORY: os << "CATEGORY"; break;
            case VertexType::SKILL: os << "SKILL"; break;
            case VertexType::LEVEL: os << "LEVEL"; break;
            default: os << "UNKNOWN";
        }
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const VertexData& vertex) {
        os << "Vertex(Type: " << vertex.type << ", Value: " << vertex.value << ")";
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << "Edge(Source: " << edge.source << ", Target: " << edge.target << ")";
        return os;
    }
};