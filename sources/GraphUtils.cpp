#include "GraphUtils.hpp"
#include <iostream>

namespace GraphUtils {
    VertexType fromString(const std::string& type) {
        if (type == "ROOT" || type == "ROOT-USER") return VertexType::ROOT;
        else if (type == "CATEGORY" || type == "TRUNC-CATEGORY") return VertexType::CATEGORY;
        else if (type == "SKILL" || type == "BRANCH-SKILL") return VertexType::SKILL;
        else if (type == "LEVEL" || type == "LEAF-LEVEL") return VertexType::LEVEL;
        throw "Unknown vertex type: " +  type;
    }

    std::ostream& operator<<(std::ostream& os, const VertexType& type) {
    switch (type) {
        case VertexType::ROOT: os << "ROOT"; break;
        case VertexType::CATEGORY: os << "CATEGORY"; break;
        case VertexType::SKILL: os << "SKILL"; break;
        case VertexType::LEVEL: os << "LEVEL"; break;
        default: os << "UNKNOWN";
    }
    return os;
};

};