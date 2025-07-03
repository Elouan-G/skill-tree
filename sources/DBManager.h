#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <string>

class DBManager {
private:
    sqlite3* db;

public:
    DBManager(const std::string& dbName);
    ~DBManager();
    DBManager(const DBManager&) = delete;
    DBManager& operator=(const DBManager&) = delete;

    void executeSQL(const char* sql);
    void executeSQL(const std::vector<const char*>& sqlInstructions);
};