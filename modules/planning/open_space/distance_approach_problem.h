/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/*
 * @file
 */

#pragma once

#include <algorithm>
#include <iomanip>
#include <utility>
#include <vector>

#include "Eigen/Dense"
#include "IpIpoptApplication.hpp"
#include "IpSolveStatistics.hpp"

#include "modules/common/time/time.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/planning/open_space/distance_approach_ipopt_interface.h"
#include "modules/planning/proto/planning.pb.h"

namespace apollo {
namespace planning {

class DistanceApproachProblem {
 public:
  explicit DistanceApproachProblem(

      const PlannerOpenSpaceConfig& planner_open_space_config);

  virtual ~DistanceApproachProblem() = default;

  bool Solve(const Eigen::MatrixXd& x0, const Eigen::MatrixXd& xF,
             const Eigen::MatrixXd& last_time_u, const std::size_t& horizon,
             const float& ts, const Eigen::MatrixXd& ego,
             const Eigen::MatrixXd& xWS, const Eigen::MatrixXd& uWS,
             const std::vector<double>& XYbounds,
             const std::size_t& obstacles_num,
             const Eigen::MatrixXd& obstacles_edges_num,
             const Eigen::MatrixXd& obstacles_A,
             const Eigen::MatrixXd& obstacles_b, Eigen::MatrixXd* state_result,
             Eigen::MatrixXd* control_result, Eigen::MatrixXd* time_result,
             Eigen::MatrixXd* dual_l_result, Eigen::MatrixXd* dual_n_result);

 private:
  PlannerOpenSpaceConfig planner_open_space_config_;
};

}  // namespace planning
}  // namespace apollo
