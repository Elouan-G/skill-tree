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

   protected:
    void printHelp() override;

   private:
    std::string state = "main";
    std::size_t stateStage = 0;

    void gotoMainMenu();
    void gotoViewMenu();
    void gotoNewMenu();
    void gotoEditMenu();
    void gotoDeleteMenu();

    /* Menu print utils */
   private:
    void printHelpMenuOptions();
    void printMainMenuOptions();
    void printViewMenuOptions();
    void printNewMenuOptions();
    void printEditMenuOptions();
    void printDeleteMenuOptions();
};