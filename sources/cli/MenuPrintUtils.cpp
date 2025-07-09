#include "SkillTreeCLI.hpp"

void SkillTreeCLI::printHelpMenuOptions() {
    print("  help - Show the current available commands");
    print("  exit - Exit the CLI (cancels all unsaved changes !)");
    print("  menu - Go to the main menu (cancels all unsaved changes !)");

    if (state == "main") {
        printMainMenuOptions();
    } else if (state == "view") {
        printViewMenuOptions();
    } else if (state == "new") {
        printNewMenuOptions();
    } else if (state == "edit") {
        printEditMenuOptions();
    } else if (state == "delete") {
        printDeleteMenuOptions();
    }
}

void SkillTreeCLI::printMainMenuOptions() {
    print("  view - View Skill Tree");
    print("  new  - New Skill Tree");
    print("  edit - Edit Skill Tree");
    print("  del  - Delete Skill Tree");
}

void SkillTreeCLI::printViewMenuOptions() {
    print("  list - List all skills");
    print("  detail - View skill details");
}

void SkillTreeCLI::printNewMenuOptions() {
    print("  create - Create a new skill");
    print("  import - Import skills from a file");
}

void SkillTreeCLI::printEditMenuOptions() {
    print("  modify - Modify an existing skill");
    print("  move - Move a skill to a different position");
}

void SkillTreeCLI::printDeleteMenuOptions() {
    print("  remove - Remove a skill");
    print("  clear - Clear the entire skill tree");
}