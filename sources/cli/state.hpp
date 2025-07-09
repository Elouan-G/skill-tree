#pragma once
#include <string>
#include <vector>

enum MenuList { MAIN, VIEW, CREATE, EDIT, DELETE, UNKNOWN };

struct CLIstate {
    bool isRunning = true;
    MenuList currentMenu = MAIN;
    std::vector<std::string> currentCommand;
};

auto to_menu(const std::string& menuStr) -> MenuList {
    if (menuStr == "main") return MAIN;
    if (menuStr == "view") return VIEW;
    if (menuStr == "create") return CREATE;
    if (menuStr == "edit") return EDIT;
    if (menuStr == "delete")
        return DELETE;
    else
        return UNKNOWN;
}

std::string to_string(const MenuList& menu) {
    switch (menu) {
        case MAIN:
            return "main";
        case VIEW:
            return "view";
        case CREATE:
            return "create";
        case EDIT:
            return "edit";
        case DELETE:
            return "delete";
        case UNKNOWN:
            return "unknown";
    }

    return "unknown";
};

auto operator+(const MenuList& menu, const std::string& str) -> std::string {
    return to_string(menu) + str;
}

auto operator+(const std::string& str, const MenuList& menu) -> std::string {
    return str + to_string(menu);
}

std::string to_string(const CLIstate& state) {
    std::string result = "CLIstate { isRunning: " + std::to_string(state.isRunning) + ", currentMenu: '" +
                         state.currentMenu + "', currentCommand: [";
    for (const auto& cmd : state.currentCommand) {
        result += "'" + cmd + "', ";
    }
    result += "] }";
    return result;
};