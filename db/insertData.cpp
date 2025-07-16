#include <vector>

#include "DBManager.hpp"

int main() {
    std::vector<const char*> SQLinstructions;

    /* Activate foreign keys */
    SQLinstructions.push_back("PRAGMA foreign_keys = ON;");

    /* vertex_type data insertion */
    SQLinstructions.push_back(
        "INSERT OR IGNORE INTO vertex_type (type_name, type_description) VALUES "
        /*1*/
        "('ROOT-USER', 'The root represents the users name, only one root is allowed per "
        "skill-tree.'),"
        /*2*/
        "('TRUNC-CATEGORY', 'The truncs represent the skill categories, they are connected to the "
        "root of their tree (main categories) or to another category (sub-categories).'),"
        /*3*/
        "('BRANCH-SKILL', 'Branches are skills, they are connected to a trunc (category, "
        "sub-category).'),"
        /*4*/
        "('LEAF-LEVEL', 'Leafes represent the mastery level of a skill, they are connected to a "
        "skill or to an inferior level.');");

    /* vertices data insertion */
    SQLinstructions.push_back(
        "INSERT OR IGNORE INTO vertices (vertex_name, vertex_type) VALUES "
        /*1*/
        "('RootTest', 1),"
        /*2*/
        "('CATa', 2),"
        /*3*/
        "('CATb', 2),"
        /*4*/
        "('SUBCATa', 2),"
        /*5*/
        "('SKILLa', 3),"
        /*6*/
        "('SKILLb', 3),"
        /*7*/
        "('LVLa1', 4),"
        /*8*/
        "('LVLb1', 4),"
        /*9*/
        "('LVLb2', 4);");

    /* edges data insertion */
    SQLinstructions.push_back(
        "INSERT OR IGNORE INTO edges (source_vertex, target_vertex, tree_id) VALUES "
        /*CATa*/
        "(1, 2, 1),"
        "(2, 4, 1),"
        "(4, 5, 1),"
        "(5, 7, 1),"

        /*CATb*/
        "(1, 3, 1),"
        "(3, 6, 1),"
        "(6, 8, 1),"
        "(8, 9, 1);");

    /* Execute sql instruction list using DBManager */
    DBManager* dbManager = new DBManager("skill-tree.db");
    dbManager->executeSimpleQuery(SQLinstructions);
    delete dbManager;

    return 0;
}