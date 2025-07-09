#include "SkillTreeCLI.h"

void SkillTreeCLI::run() {
    print("Welcome to the Skill Tree CLI!");
    print("Type 'help' for a list of commands.");

    while (true) {
        std::string input = getInput();
        if (input == "exit") {
            break;
        } else if (input == "help") {
            printHelp();
        } else if (input == "menu") {
            printMainMenu();
        } else {
            printError("Unknown command: " + input);
        }
    }
}

void SkillTreeCLI::printHelp() {
    print("Available commands:");
    print("  help - Show this help message");
    print("  exit - Exit the CLI");
    print("  menu - View the main menu");
}

void SkillTreeCLI::printMainMenu() {
    print("Main Menu:");
    print("  view - View Skill Tree");
    print("  new  - New Skill Tree");
    print("  edit - Edit Skill Tree");
    print("  del  - Delete Skill Tree");
}