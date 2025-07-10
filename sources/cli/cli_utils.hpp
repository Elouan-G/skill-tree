#pragma once

#include <cstddef>
#include <iostream>
#include <string>

#include "state.hpp"

auto print(const std::string& message) {
    std::cout << message << std::endl;
}

auto read_input = [](const CLIstate& state) {
    CLIstate newState = state;
    newState.currentCommand.clear();
    std::string command;
    std::getline(std::cin, command);
    command += ' ';
    while (command.length() > 0 && command[0] != ' ') {
        newState.currentCommand.push_back(command.substr(0, command.find(' ')));
        command.erase(0, command.find(' ') + 1);
    }
    return newState;
};

auto say_hello = []() { print("Hello, welcome to the skill-tree CLI program!"); };

auto say_goodbye = []() { print("\n\n\nGoodbye! See you next time!"); };

auto get_full_command = [](const CLIstate& state) {
    std::string fullCommand;
    for (const auto& command : state.currentCommand) {
        fullCommand += command + " ";
    }
    return fullCommand;
};

auto handle_unknown_command = [](const CLIstate& state) {
    std::cerr << "Unknown command: " << get_full_command(state) << std::endl;
};

auto handle_exit = [](const CLIstate& state) {
    CLIstate newState = state;
    newState.isRunning = false;
    return newState;
};

auto handle_error = [](const std::string functionName, const std::string& errorMessage) {
    std::cerr << "Error (" << functionName << ") : " << errorMessage << std::endl;
    std::terminate();
};