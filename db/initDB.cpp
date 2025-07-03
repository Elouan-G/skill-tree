#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    char* errMsg = nullptr;

    if (sqlite3_open("skillTree.db", &db)) {
        std::cerr << "Error opening DB\n";
        return 1;
    }

    const char* sql = "CREATE TABLE IF NOT EXISTS category(id INTEGER PRIMARY KEY, category TEXT);";
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
    return 0;
}