#pragma once
#include <sqlite3.h>

#include <string>
#include <vector>

class DBManager {
   protected:
    sqlite3* db;

   private:
    DBManager(const DBManager&) = delete;
    DBManager& operator=(const DBManager&) = delete;

   public:
    DBManager(const std::string& dbName);
    ~DBManager();

    void executeSimpleQuery(const char* sql);
    void executeSimpleQuery(const std::vector<const char*>& sqlInstructions);
};