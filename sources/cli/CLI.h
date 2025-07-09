#pragma once
#include <iostream>

/* Virtual Singleton, makes implementing a CLI easier. */
class CLI {
   protected:
    inline static CLI* instance;
    CLI() = default;

   public:
    CLI(const CLI&) = delete;
    CLI& operator=(const CLI&) = delete;
    virtual ~CLI() = default;

    static CLI* getInstance() {
        if (!instance) {
            std::cerr << "Error: Cannot instantiate abstract class CLI. Please implement getInstance() in a "
                         "subclass."
                      << std::endl;
            std::terminate();
        }
        return CLI::instance;
    }

    virtual void run() = 0;

   protected:
    virtual void printHelp() = 0;

    std::string getInput() {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }
    void print(const std::string& message) {
        std::cout << message << std::endl;
    }
    void printError(const std::string& error) {
        std::cerr << "Error: " << error << std::endl;
    }
};