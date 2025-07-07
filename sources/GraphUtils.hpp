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

    struct Vertex {
        size_t id;
        VertexType type;
        std::string value;
    };
    typedef std::vector<Vertex> Vertices;
    typedef std::unordered_map<std::size_t, Vertex> VerticesMap;

    struct Edge {
        size_t source;
        size_t target;
    };
    typedef std::vector<Edge> Edges;

    /* Helper functions */
    VertexType fromString(const std::string& type);

    /* operator<< overloads */
    std::ostream& operator<<(std::ostream& os, const VertexType& type);
    std::ostream& operator<<(std::ostream& os, const Vertex& vertex);
    std::ostream& operator<<(std::ostream& os, const Edge& edge);
};