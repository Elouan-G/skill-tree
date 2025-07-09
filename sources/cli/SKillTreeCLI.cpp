#include "SkillTreeCLI.hpp"

void SkillTreeCLI::run() {
    print("Welcome to the Skill Tree CLI!");
    print("Type 'help' for a list of commands.");

    while (true) {
        std::string input = getInput();
        if (input == "exit" || input == "quit") {
            break;
        } else if (input == "help" || input == "?") {
            printHelp();
        } else if (input == "menu" || input == "main") {
            // gotoMainMenu();
        } else if (stage) {
        } else if (input == "view" || input == "list") {
            // gotoViewMenu();
        } else if (input == "new" || input == "create") {
            // gotoNewMenu();
        } else if (input == "edit" || input == "modify") {
            // gotoEditMenu();
        } else if (input == "del" || input == "delete") {
            // gotoDeleteMenu();
        } else {
            printError("Unknown command: " + input);
        }
    }

    print("Exiting Skill Tree CLI, unsaved changes were cancelled. Goodbye!");
}

/* Displayed content depends on state and stage. */
void SkillTreeCLI::printHelp() {
    print("Available commands:");
    printHelpMenuOptions();
}
