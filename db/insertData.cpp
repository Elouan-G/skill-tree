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
    SQLinstructions.push_back("INSERT OR IGNORE INTO vertice_type (type_name, type_description) VALUES "
        /*1*/"('ROOT-USER', 'The root represents the users name, only one root is allowed per skill-tree.'),"
        /*2*/"('TRUNC-CATEGORY', 'The truncs represent the skill categories, they are connected to the root of their tree (main categories) or to another category (sub-categories).'),"
        /*3*/"('BRANCH-SKILL', 'Branches are skills, they are connected to a trunc (category, sub-category).'),"
        /*4*/"('LEAF-LEVEL', 'Leafes represent the mastery level of a skill, they are connected to a skill or to an inferior level.');"
    );

    /* vertices data insertion */
    SQLinstructions.push_back("INSERT OR IGNORE INTO vertices (vertice_name, vertice_type) VALUES "
        /*1*/"('ROOT', 1),"
        /*2*/"('CATa', 2),"
        /*3*/"('CATb', 2),"
        /*4*/"('SUBCATa', 2),"
        /*5*/"('SKILLa', 3),"
        /*6*/"('SKILLb', 3),"
        /*7*/"('LVLa1', 4),"
        /*8*/"('LVLb1', 4),"
        /*9*/"('LVLb2', 4);"
    );

    /* edges data insertion */
    SQLinstructions.push_back("INSERT OR IGNORE INTO edges (source_vertice, target_vertice) VALUES "
        /*CATa*/
        "(1, 2),"
        "(2, 4),"
        "(4, 5),"
        "(5, 7),"
        
        /*CATb*/
        "(1, 3),"
        "(3, 6),"
        "(6, 8),"
        "(8, 9);"
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