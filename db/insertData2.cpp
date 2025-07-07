#include "DBManager.hpp"
#include <vector>

int main() {
    std::vector<const char*> SQLinstructions;

    /* Activate foreign keys */
    SQLinstructions.push_back("PRAGMA foreign_keys = ON;");

    /* vertex_type data insertion */
    SQLinstructions.push_back("INSERT OR IGNORE INTO vertex_type (type_name, type_description) VALUES "
        /*1*/"('ROOT-USER', 'The root represents the users name, only one root is allowed per skill-tree.'),"
        /*2*/"('TRUNC-CATEGORY', 'The truncs represent the skill categories, they are connected to the root of their tree (main categories) or to another category (sub-categories).'),"
        /*3*/"('BRANCH-SKILL', 'Branches are skills, they are connected to a trunc (category, sub-category).'),"
        /*4*/"('LEAF-LEVEL', 'Leafes represent the mastery level of a skill, they are connected to a skill or to an inferior level.');"
    );

    /* vertices data insertion */
    SQLinstructions.push_back("INSERT OR IGNORE INTO vertices (vertex_name, vertex_type) VALUES "
        /*1*/"('RootTest2', 1),"
        /*2*/"('Beauty', 2),"
        /*3*/"('Cleverness', 2),"
        /*4*/"('Technical', 2),"
        /*5*/"('Sensibility', 2),"
        /*6*/"('Empathy', 3),"
        /*7*/"('Generosity', 3),"
        /*8*/"('Empathy Beginner', 4),"
        /*9*/"('Empathy Intermediate', 4),"
        /*10*/"('Empathy Expert', 4),"
        /*11*/"('Nice', 4),"
        /*12*/"('Super Nice', 4)"
        ";"
    );

    /* edges data insertion */
    SQLinstructions.push_back("INSERT OR IGNORE INTO edges (source_vertex, target_vertex) VALUES "
        "(1, 2),"
        "(1, 3),"
        "(3, 4),"
        "(3, 5),"
        "(5, 6),"
        "(5, 7),"
        "(6, 8),"
        "(6, 9),"
        "(6, 10),"
        "(7, 11),"
        "(7, 12)"
        ";"
    );

    /* Execute sql instruction list using DBManager */
    DBManager* dbManager = new DBManager("skill-tree.db");
    dbManager->executeSimpleQuery(SQLinstructions);
    delete dbManager;
    
    return 0;
}