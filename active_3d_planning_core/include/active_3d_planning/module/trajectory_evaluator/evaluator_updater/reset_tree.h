#ifndef ACTIVE_3D_PLANNING_EVALUATOR_UPDATER_RESET_TREE_H
#define ACTIVE_3D_PLANNING_EVALUATOR_UPDATER_RESET_TREE_H

#include "active_3d_planning/module/module_factory.h"
#include "active_3d_planning/module/trajectory_evaluator.h"

namespace active_3d_planning {
namespace evaluator_updater {
// Discard all segments and start from scratch
class ResetTree : public EvaluatorUpdater {
public:
  ResetTree(PlannerI &planner);
  // override virtual functions
  bool updateSegments(TrajectorySegment *root) override;

  void setupFromParamMap(Module::ParamMap *param_map) override;

protected:
  static ModuleFactoryRegistry::Registration<ResetTree> registration;
};
} // namespace evaluator_updater
} // namespace active_3d_planning
#endif // ACTIVE_3D_PLANNING_EVALUATOR_UPDATER_RESET_TREE_H
