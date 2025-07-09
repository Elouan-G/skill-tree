#pragma once
#include "CLI.hpp"

class SkillTreeCLI : public CLI {
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

   private:
    void printHelp() override;

   protected:
    void printHelpMenuOptions();
    void printMainMenuOptions();
    void printViewMenuOptions();
    void printNewMenuOptions();
    void printEditMenuOptions();
    void printDeleteMenuOptions();
};