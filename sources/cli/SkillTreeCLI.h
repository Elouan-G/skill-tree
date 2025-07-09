#pragma once
#include "CLI.h"

class SkillTreeCLI final : public CLI {
   protected:
    SkillTreeCLI() = default;

   public:
    SkillTreeCLI(const SkillTreeCLI&) = delete;
    SkillTreeCLI& operator=(const SkillTreeCLI&) = delete;
    ~SkillTreeCLI() override = default;

    static SkillTreeCLI* getInstance() {
        if (!CLI::instance) {
            CLI::instance = new SkillTreeCLI();
        }
        return static_cast<SkillTreeCLI*>(CLI::instance);
    };

    void run() override;

   protected:
    void printHelp() override;

   private:
    void printMainMenu();
};