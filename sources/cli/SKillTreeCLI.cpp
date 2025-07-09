#include "SkillTreeCLI.hpp"

void SkillTreeCLI::run() {
    print("Welcome to the Skill Tree CLI!");
    print("Type 'help' for a list of commands.");

    while (true) {
        std::string input = getInput();
        if (input == "exit") {
            break;
        } else if (input == "help" || input == "?" || input == "h") {
            printHelp();
        } else if (input == "menu" || input == "main" || input == "m") {
            gotoMainMenu();
        } else if (input == "view" || input == "v") {
            gotoViewMenu();
        } else if (input == "new" || input == "create" || input == "n") {
            gotoNewMenu();
        } else if (input == "edit" || input == "modify" || input == "e") {
            gotoEditMenu();
        } else if (input == "del" || input == "delete" || input == "d") {
            gotoDeleteMenu();
        } else {
            printError("Unknown command: " + input);
        }
    }

    print("Exiting Skill Tree CLI, unsaved changes were cancelled. Goodbye!");
}

/* Displayed content depends on state and stage. */
void SkillTreeCLI::printHelp() {
    print("Available commands: (state-" + state + ";stage-" + std::to_string(stateStage) + ")");
    printHelpMenuOptions();
}

void SkillTreeCLI::gotoMainMenu() {
    state = "main";
    stateStage = 0;
    print("Main Menu:");
    printMainMenuOptions();
}

void SkillTreeCLI::gotoViewMenu() {
    state = "view";
    stateStage = 0;
    print("View Menu:");
    printViewMenuOptions();
}

void SkillTreeCLI::gotoNewMenu() {
    state = "new";
    stateStage = 0;
    print("New Menu:");
    printNewMenuOptions();
}

void SkillTreeCLI::gotoEditMenu() {
    state = "edit";
    stateStage = 0;
    print("Edit Menu:");
    printEditMenuOptions();
}

void SkillTreeCLI::gotoDeleteMenu() {
    state = "delete";
    stateStage = 0;
    print("Delete Menu:");
    printDeleteMenuOptions();
}