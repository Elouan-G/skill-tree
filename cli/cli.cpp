#include "execute_command.hpp"
#include "get_commands.hpp"
#include "state.hpp"
#include "utils.hpp"

auto get_commands = [](const CLIstate& state) -> std::string {
    std::string commands;
    if (state.currentMenu == MAIN)
        commands = get_commands_main();
    else if (state.currentMenu == VIEW)
        commands = get_commands_view();
    else if (state.currentMenu == CREATE)
        commands = get_commands_create();
    else if (state.currentMenu == EDIT)
        commands = get_commands_edit();
    else if (state.currentMenu == DELETE)
        commands = get_commands_delete();
    else
        handle_error("show_commands", "Undefined menu state: " + to_string(state.currentMenu));

    return commands;
};

auto execute_command = [](const CLIstate& state) -> CLIstate {
    CLIstate newState = state;

    if (state.currentCommand.empty())
        handle_error("execute_command", "No command found in state.");
    else if (state.currentCommand.back() == "exit")
        newState = handle_exit(state);
    else if (state.currentMenu == MAIN)
        newState = execute_command_main(state);
    else if (state.currentMenu == VIEW)
        newState = execute_command_view(state);
    else if (state.currentMenu == CREATE)
        newState = execute_command_create(state);
    else if (state.currentMenu == EDIT)
        newState = execute_command_edit(state);
    else if (state.currentMenu == DELETE)
        newState = execute_command_delete(state);
    else
        handle_error("execute_command", "Undefined behavior." + to_string(state));

    return newState;
};

int main() {
    say_hello();
    CLIstate state;

    while (state.isRunning) {
        print(get_commands(state));

        state = read_input(state);

        state = execute_command(state);
    }

    say_goodbye();
    return 0;
}