#include "SkillTreeDBManager.hpp"
#include <string>

std::unique_ptr<std::vector<Vertex>> SkillTreeDBManager::getVertices() {
    std::unique_ptr<std::vector<Vertex>> vertices = std::make_unique<std::vector<Vertex>>();
    const char* sql = "SELECT vertices.vertex_id, vertex_type.type_name, vertices.vertex_name FROM vertices INNER JOIN vertex_type ON vertices.vertex_type = vertex_type.type_id;";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(this->db, sql, -1, &stmt, nullptr);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::size_t id = sqlite3_column_int(stmt, 0);
        std::string type = static_cast<std::string>(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        std::string value = static_cast<std::string>(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));

        VertexType vtype = fromString(type);
        vertices->push_back(Vertex{id, vtype, value});
    }
    sqlite3_finalize(stmt);
    return std::move(vertices);
}