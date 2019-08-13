#ifndef ACTIVE_3D_PLANNING_CORE_GENERATOR_UPDATER_RECHECK_COLLISION_H
#define ACTIVE_3D_PLANNING_CORE_GENERATOR_UPDATER_RECHECK_COLLISION_H

#include "active_3d_planning/module/trajectory_generator.h"

namespace active_3d_planning {
namespace generator_updater {

// Recursively check wether the trajectories are still collision free
class RecheckCollision : public GeneratorUpdater {
public:
  RecheckCollision(PlannerI &planner);
  // override virtual functions
  bool updateSegments(TrajectorySegment *root) override;

  void setupFromParamMap(Module::ParamMap *param_map) override;

protected:
  static ModuleFactoryRegistry::Registration<RecheckCollision> registration;

  // methods
  bool isCollided(const EigenTrajectoryPointVector &trajectory);
  void checkSingle(TrajectorySegment *segment);
};

} // namespace generator_updater
} // namespace active_3d_planning
#endif // ACTIVE_3D_PLANNING_CORE_GENERATOR_UPDATER_RECHECK_COLLISION_H
