#include "SkillTreeCLI.h"

int main() {
    SkillTreeCLI* cli = SkillTreeCLI::getInstance();
    cli->run();
    delete cli;
    return 0;
}