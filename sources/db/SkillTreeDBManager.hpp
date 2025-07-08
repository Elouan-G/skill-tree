#pragma once
#include <memory>

#include "DBManager.hpp"
#include "GraphUtils.hpp"

using namespace GraphUtils;

class SkillTreeDBManager final : public DBManager {
   private:
    SkillTreeDBManager(const SkillTreeDBManager&) = delete;
    SkillTreeDBManager& operator=(const SkillTreeDBManager&) = delete;

   public:
    SkillTreeDBManager() : DBManager("db/skill-tree.db"){};
    ~SkillTreeDBManager() = default;

    std::unique_ptr<Vertices> getVertices();
    std::unique_ptr<VerticesMap> getVerticesMap();
    std::unique_ptr<Edges> getEdges();
};