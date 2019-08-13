#include "active_3d_planning/module/trajectory_generator/segment_selector/greedy.h"
#include "active_3d_planning/tools/defaults.h"

#include <algorithm>
#include <random>
#include <vector>

namespace active_3d_planning {
namespace segment_selector {

// Greedy
ModuleFactoryRegistry::Registration<Greedy> Greedy::registration("Greedy");

Greedy::Greedy(PlannerI &planner) : SegmentSelector(planner) {}

bool Greedy::selectSegment(TrajectorySegment **result,
                           TrajectorySegment *root) {
  std::vector<TrajectorySegment *> candidates;
  if (leaves_only_) {
    root->getLeaves(&candidates);
  } else {
    root->getTree(&candidates);
  }
  *result = *std::max_element(candidates.begin(), candidates.end(),
                              TrajectorySegment::comparePtr);
  return true;
}

void Greedy::setupFromParamMap(Module::ParamMap *param_map) {
  setParam<bool>(param_map, "leaves_only", &leaves_only_, false);
}

} // namespace segment_selector
} // namespace active_3d_planning
