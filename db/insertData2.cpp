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
        /*10*/
        "('RootTest2', 1),"
        /*11*/
        "('Beauty', 2),"
        /*12*/
        "('Cleverness', 2),"
        /*13*/
        "('Technical', 2),"
        /*14*/
        "('Sensibility', 2),"
        /*15*/
        "('Empathy', 3),"
        /*16*/
        "('Generosity', 3),"
        /*17*/
        "('Empathy Beginner', 4),"
        /*18*/
        "('Empathy Intermediate', 4),"
        /*19*/
        "('Empathy Expert', 4),"
        /*20*/
        "('Nice', 4),"
        /*21*/
        "('Super Nice', 4),"
        /*22*/
        "('Test Skill', 3)"
        ";");

    /* edges data insertion */
    SQLinstructions.push_back(
        "INSERT OR IGNORE INTO edges (source_vertex, target_vertex, tree_id) VALUES "
        "(10, 11, 10),"
        "(10, 12, 10),"
        "(12, 13, 10),"
        "(12, 14, 10),"
        "(14, 15, 10),"
        "(14, 16, 10),"
        "(15, 17, 10),"
        "(15, 18, 10),"
        "(15, 19, 10),"
        "(16, 20, 10),"
        "(16, 21, 10),"
        "(13, 22, 10),"
        "(22, 8, 10),"
        "(22, 9, 10)"
        ";");

    /* Execute sql instruction list using DBManager */
    DBManager* dbManager = new DBManager("skill-tree.db");
    dbManager->executeSimpleQuery(SQLinstructions);
    delete dbManager;

    return 0;
}