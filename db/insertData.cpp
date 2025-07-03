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

    /* vertice_type data insertion */
    SQLinstructions.push_back(
        "INSERT OR IGNORE INTO vertice_type (type_name, type_description) VALUES "
        "('ROOT-USER', 'The root represents the users name, only one root is allowed per skill-tree.'),"
        "('TRUNC-CATEGORY', 'The truncs represent the skill categories, they are connected to the root of their tree (main categories) or to another category (sub-categories).'),"
        "('BRANCH-SKILL', 'Branches are skills, they are connected to a trunc (category, sub-category).'),"
        "('LEAF-LEVEL', 'Leafes represent the mastery level of a skill, they are connected to a skill or to an inferior level.');"
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