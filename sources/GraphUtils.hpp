#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace GraphUtils {
    /* Data structures/enums */
    enum class VertexType {
        ROOT = 1,
        CATEGORY = 2,
        SKILL = 3,
        LEVEL = 4
    };

    struct VertexData {
        VertexType type;
        std::string value;
    };
    typedef std::unordered_map<std::size_t, VertexData> Vertices;

    struct Edge {
        size_t source;
        size_t target;
    };
    typedef std::vector<Edge> Edges;

    /* Helper functions */
    VertexType fromString(const std::string& type);

    /* operator<< overloads */
    std::ostream& operator<<(std::ostream& os, const VertexType& type);
    std::ostream& operator<<(std::ostream& os, const VertexData& vertex);
    std::ostream& operator<<(std::ostream& os, const Edge& edge);
};