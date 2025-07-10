#pragma once

#include "cli_utils.hpp"
#include "skill_tree_utils.hpp"
#include "state.hpp"

/* MAIN menu */
auto change_menu = [](const CLIstate& state, const MenuList& newMenu) {
    CLIstate newState = state;
    newState.currentMenu = newMenu;
    return newState;
};

auto execute_command_main = [](const CLIstate& state) {
    CLIstate newState = state;

    if (state.currentCommand.size() > 1)
        handle_error("execute_command_main", "More than one command.");
    else if (to_menu(state.currentCommand[0]) != UNKNOWN)
        newState = change_menu(state, to_menu(state.currentCommand[0]));
    else
        handle_unknown_command(state);

    return newState;
};
/*-----------*/
/* VIEW MENU */
/*-----------*/
/* LIST COMMAND */
auto get_skill_tree_list = []() {
    std::string out = "\nSkill Tree(s):\n";
    std::vector<std::string> skillTreeList = get_skill_tree_list_from_db();
    for (const auto& skillTreeName : skillTreeList) {
        out += "  - " + skillTreeName + "\n";
    }
    out = out.back() == '\n' ? out.substr(0, out.size() - 1) : out;
    return out;
};

/* GENERATE COMMAND */
auto isTree = [](const std::string& treeName) {
    std::vector<std::string> skillTreeList = get_skill_tree_list_from_db();
    for (const auto& name : skillTreeList)
        if (name == treeName) return true;

    return false;
};

auto execute_command_generate = [](const CLIstate& state) {
    CLIstate newState = state;
    if (isTree(state.currentCommand[1])) {
        generate_skill_tree_image(state.currentCommand[1]);
        print("Skill tree '" + state.currentCommand[1] + "' generated and opened successfully.");
    } else {
        print("Skill tree '" + state.currentCommand[1] + "' does not exist.");
        handle_unknown_command(state);
    }
    return newState;
};

/* VIEW MENU */
auto execute_command_view = [](const CLIstate& state) {
    CLIstate newState = state;
    if (state.currentCommand.size() == 1 && state.currentCommand[0] == "list")
        print(get_skill_tree_list());
    else if (state.currentCommand.size() == 2 && state.currentCommand[0] == "generate")
        newState = execute_command_generate(state);
    else
        handle_unknown_command(state);

    return newState;
};

/*-------------*/
/* CREATE MENU */
/*-------------*/
/* CREATE MENU */
auto execute_command_create = [](const CLIstate& state) {
    CLIstate newState = state;
    return newState;
};

/*-----------*/
/* EDIT MENU */
/*-----------*/
/* EDIT menu */
auto execute_command_edit = [](const CLIstate& state) {
    CLIstate newState = state;
    return newState;
};

/*-------------*/
/* DELETE MENU */
/*-------------*/
/* DELETE menu */
auto execute_command_delete = [](const CLIstate& state) {
    CLIstate newState = state;
    return newState;
};