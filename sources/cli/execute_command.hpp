#pragma once

#include "state.hpp"
#include "utils.hpp"

auto change_menu = [](const CLIstate& state, const MenuList& newMenu) {
    CLIstate newState = state;
    newState.currentMenu = newMenu;
    newState.currentCommand.clear();
    return newState;
};

auto execute_command_main = [](const CLIstate& state) {
    CLIstate newState = state;

    if (state.currentCommand.size() > 1)
        handle_error("execute_command_main", "More than one command.");
    else if (to_menu(state.currentCommand[0]) != UNKNOWN)
        newState = change_menu(state, to_menu(state.currentCommand[0]));
    else
        newState = handle_unknown_command(state);
    return newState;
};

auto execute_command_view = [](const CLIstate& state) {
    CLIstate newState = state;
    return newState;
};

auto execute_command_create = [](const CLIstate& state) {
    CLIstate newState = state;
    return newState;
};

auto execute_command_edit = [](const CLIstate& state) {
    CLIstate newState = state;
    return newState;
};

auto execute_command_delete = [](const CLIstate& state) {
    CLIstate newState = state;
    return newState;
};