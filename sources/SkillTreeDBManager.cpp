#include "SkillTreeDBManager.hpp"

std::unique_ptr<Vertices> SkillTreeDBManager::getVertices() {
    std::unique_ptr<Vertices> vertices = std::make_unique<Vertices>();
    const char* sql = "SELECT vertices.vertex_id, vertex_type.type_name, vertices.vertex_name FROM vertices INNER JOIN vertex_type ON vertices.vertex_type = vertex_type.type_id;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(this->db, sql, -1, &stmt, nullptr);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::size_t id = sqlite3_column_int(stmt, 0);
        VertexData vertexData {
            .type = fromString(static_cast<std::string>(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)))),
            .value = static_cast<std::string>(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)))
        };
        (*vertices)[id] = vertexData;
    }
    sqlite3_finalize(stmt);
    return std::move(vertices);
}

std::unique_ptr<Edges> SkillTreeDBManager::getEdges() {
    std::unique_ptr<std::vector<Edge>> edges = std::make_unique<std::vector<Edge>>();
    const char* sql = "SELECT source_vertex, target_vertex FROM edges;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(this->db, sql, -1, &stmt, nullptr);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::size_t source = sqlite3_column_int(stmt, 0);
        std::size_t target = sqlite3_column_int(stmt, 1);
        edges->push_back(Edge{source, target});
    }
    sqlite3_finalize(stmt);
    return std::move(edges);
}