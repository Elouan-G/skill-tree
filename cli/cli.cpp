#include "SkillTreeCLI.hpp"

int main() {
    SkillTreeCLI* cli = SkillTreeCLI::getInstance();
    cli->run();
    delete cli;
    return 0;
}