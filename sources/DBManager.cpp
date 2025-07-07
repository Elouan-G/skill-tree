#include "DBManager.hpp"
#include <iostream>

DBManager::DBManager(const std::string& dbName) {
    if (sqlite3_open(dbName.c_str(), &this->db)) {
        std::cerr << "Error opening DB\n";
        throw std::runtime_error("Database connection failed");
    }
}

void DBManager::executeSimpleQuery(const char* sql) {
    char* errMsg = nullptr;
    if (sqlite3_exec(this->db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
        throw std::runtime_error("SQL execution failed");
    }
}

void DBManager::executeSimpleQuery(const std::vector<const char*>& sqlInstructions) {
    char* errMsg = nullptr;
    for (const char* sql : sqlInstructions) {
        if (sqlite3_exec(this->db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "SQL error: " << errMsg << "\n";
            sqlite3_free(errMsg);
        }
    }
}

DBManager::~DBManager() {
    if (this->db) {
        sqlite3_close(this->db);
    }
}