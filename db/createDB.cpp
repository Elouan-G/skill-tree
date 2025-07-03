#include <iostream>
#include <sqlite3.h>
#include <vector>

int main() {
    sqlite3* db;
    char* errMsg = nullptr;

    if (sqlite3_open("skill-tree.db", &db)) {
        std::cerr << "Error opening DB\n";
        return 1;
    }

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

    /* SQL instructions execution */
    for (const char* sql : SQLinstructions) {
        if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "SQL error: " << errMsg << "\n";
            sqlite3_free(errMsg);
        }
    }

    sqlite3_close(db);
    return 0;
}