#include "DBManager.h"
#include <vector>

int main() {
    std::vector<const char*> SQLinstructions;

    /* Activate foreign keys */
    SQLinstructions.push_back("PRAGMA foreign_keys = ON;");

    /* vertex_type table creation */
    SQLinstructions.push_back("CREATE TABLE IF NOT EXISTS vertex_type("
        "type_id INTEGER PRIMARY KEY,"
        "type_name VARCHAR(100) UNIQUE NOT NULL,"
        "type_description TEXT);"
    );

    /* vertices table creation */
    SQLinstructions.push_back("CREATE TABLE IF NOT EXISTS vertices("
        "vertex_id INTEGER PRIMARY KEY,"
        "vertex_name VARCHAR(100) NOT NULL,"
        "vertex_type INTEGER NOT NULL,"
        "FOREIGN KEY(vertex_type) REFERENCES vertex_type(type_id));"
    );

    /* edges table creation */
    SQLinstructions.push_back("CREATE TABLE IF NOT EXISTS edges("
        "source_vertex INTEGER NOT NULL,"
        "target_vertex INTEGER NOT NULL,"
        "FOREIGN KEY(source_vertex) REFERENCES vertices(vertex_id),"
        "FOREIGN KEY(target_vertex) REFERENCES vertices(vertex_id),"
        "PRIMARY KEY(source_vertex, target_vertex));"
    );

    /* Execute sql instruction list using DBManager */
    DBManager* dbManager = new DBManager("skill-tree.db");
    dbManager->executeSQL(SQLinstructions);
    delete dbManager;

    return 0;
}