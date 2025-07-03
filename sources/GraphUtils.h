#include <string>

namespace GraphUtils {
    enum class VertexType {
        ROOT = 1,
        CATEGORY = 2,
        SKILL = 3,
        LEVEL = 4
    };

    struct Vertex {
        std::size_t id;
        VertexType type;
        std::string value;
    };

    struct Edge {
        std::size_t source;
        std::size_t target;
    };
};