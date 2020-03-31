#ifndef CONSTRAINED_JOINTS_CMD_HPP
#define CONSTRAINED_JOINTS_CMD_HPP

#include <base/commands/Joints.hpp>
#include "MotionConstraint.hpp"

namespace joint_control_base {

/** Named vector of Joints command with motion constraints, i.e. constrained commands for all the joints of a robot*/
struct ConstrainedJointsCmd : public base::commands::Joints{
    std::vector<MotionConstraint> motion_constraints;
    void validate() const{
        if(names.size() != size())
            throw std::invalid_argument("Invalid target: Size of name vector should be same as element vector");
        if(!motion_constraints.empty() && motion_constraints.size() != size())
            throw std::invalid_argument("Invalid target: If not empty, motion constraints must have same size as target element vector");
    }
};

}

#endif

