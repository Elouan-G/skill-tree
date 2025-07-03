#include "DBManager.h"
#include <vector>

int main() {
    std::vector<const char*> SQLinstructions;

    /* Activate foreign keys */
    SQLinstructions.push_back("PRAGMA foreign_keys = ON;");

    /* vertice_type table creation */
    SQLinstructions.push_back("CREATE TABLE IF NOT EXISTS vertice_type("
        "type_id INTEGER PRIMARY KEY,"
        "type_name VARCHAR(100) UNIQUE NOT NULL,"
        "type_description TEXT);"
    );

    /* vertices table creation */
    SQLinstructions.push_back("CREATE TABLE IF NOT EXISTS vertices("
        "vertice_id INTEGER PRIMARY KEY,"
        "vertice_name VARCHAR(100) NOT NULL,"
        "vertice_type INTEGER NOT NULL,"
        "FOREIGN KEY(vertice_type) REFERENCES vertice_type(type_id));"
    );

    /* edges table creation */
    SQLinstructions.push_back("CREATE TABLE IF NOT EXISTS edges("
        "source_vertice INTEGER NOT NULL,"
        "target_vertice INTEGER NOT NULL,"
        "FOREIGN KEY(source_vertice) REFERENCES vertices(vertice_id),"
        "FOREIGN KEY(target_vertice) REFERENCES vertices(vertice_id),"
        "PRIMARY KEY(source_vertice, target_vertice));"
    );

    /* Execute sql instruction list using DBManager */
    DBManager* dbManager = new DBManager("skill-tree.db");
    dbManager->executeSQL(SQLinstructions);
    delete dbManager;

    return 0;
}