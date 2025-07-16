#include <vector>

#include "DBManager.hpp"

int main() {
    std::vector<const char*> SQLinstructions;

    /* Activate foreign keys */
    SQLinstructions.push_back("PRAGMA foreign_keys = ON;");

    /* vertex_type table creation */
    SQLinstructions.push_back(
        "CREATE TABLE IF NOT EXISTS vertex_type("
        "type_id INTEGER PRIMARY KEY,"
        "type_name VARCHAR(100) UNIQUE NOT NULL,"
        "type_description TEXT);");

    /* vertices table creation */
    SQLinstructions.push_back(
        "CREATE TABLE IF NOT EXISTS vertices("
        "vertex_id INTEGER PRIMARY KEY,"
        "vertex_name VARCHAR(100) NOT NULL,"
        "vertex_type INTEGER NOT NULL,"
        "FOREIGN KEY(vertex_type) REFERENCES vertex_type(type_id));");

    /* edges table creation */
    SQLinstructions.push_back(
        "CREATE TABLE IF NOT EXISTS edges("
        "source_vertex INTEGER NOT NULL,"
        "target_vertex INTEGER NOT NULL,"
        "tree_id INTEGER NOT NULL,"
        "FOREIGN KEY(tree_id) REFERENCES vertices(vertex_id),"
        "FOREIGN KEY(source_vertex) REFERENCES vertices(vertex_id),"
        "FOREIGN KEY(target_vertex) REFERENCES vertices(vertex_id),"
        "PRIMARY KEY(source_vertex, target_vertex));");

    /* trees table creation */
    SQLinstructions.push_back(
        "CREATE TRIGGER IF NOT EXISTS check_tree_before_insert "
        "BEFORE INSERT ON edges "
        "FOR EACH ROW "
        "BEGIN "
        "  SELECT CASE "
        "    WHEN (SELECT vertex_type.type_name FROM vertex_type INNER JOIN vertices ON vertex_type.type_id "
        "= vertices.vertex_type WHERE vertices.vertex_id = NEW.tree_id) != 'ROOT-USER' "
        "    THEN RAISE(ABORT, 'Each edge must reference a root vertex as tree_id.') "
        "  END; "
        "END;");

    /* Execute sql instruction list using DBManager */
    DBManager* dbManager = new DBManager("skill-tree.db");
    dbManager->executeSimpleQuery(SQLinstructions);
    delete dbManager;

    return 0;
}