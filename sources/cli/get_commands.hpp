#pragma once

#include <string>

auto get_commands_main = []() {
    std::string out =
        "\nMAIN menu:\n"
        "  exit   - Terminates the program, unsaved changes are lost\n"
        "  main   - Main menu\n"
        "  view   - View menu\n"
        "  create - Create menu\n"
        "  edit   - Edit menu\n"
        "  delete - Delete menu\n"
        "v";
    return out;
};

auto get_commands_view = []() {
    std::string out =
        "\nVIEW menu:\n"
        "  exit   - Terminates the program, unsaved changes are lost\n"
        "v";
    return out;
};

auto get_commands_create = []() {
    std::string out =
        "\nCREATE menu:\n"
        "  exit   - Terminates the program, unsaved changes are lost\n"
        "v";
    return out;
};

auto get_commands_edit = []() {
    std::string out =
        "\nEDIT menu:\n"
        "  exit   - Terminates the program, unsaved changes are lost\n"
        "v";
    return out;
};

auto get_commands_delete = []() {
    std::string out =
        "\nDELETE menu:\n"
        "  exit   - Terminates the program, unsaved changes are lost\n"
        "v";
    return out;
};