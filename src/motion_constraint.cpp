#include "motion_constraint.hpp"

namespace trajectory_generation {

MotionConstraint::MotionConstraint(){
    max.position      = base::unset<float>();
    min.position      = base::unset<float>();
    max.speed         = base::unset<float>();
    max.acceleration  = base::unset<float>();
    max_jerk          = base::unset<float>();
}

void MotionConstraint::validate() const{
#ifdef USING_REFLEXXES_TYPE_IV
    if(!hasMaxPosition())
        throw std::invalid_argument("Motion Constraints: Maximum position is invalid");
    if(!hasMinPosition())
        throw std::invalid_argument("Motion Constraints: Minimum position is invalid");
    if(max.position <= min.position)
        throw std::invalid_argument("Motion Constraints: Max. position has to be > min. position");
#endif
    if(!hasMaxVelocity())
        throw std::invalid_argument("Motion Constraints: Maximum speed is invalid");
    if(!hasMaxAcceleration())
        throw std::invalid_argument("Motion Constraints: Maximum acceleration is invalid");
    if(!hasMaxJerk())
        throw std::invalid_argument("Motion Constraints: Maximum jerk is invalid");
    if(max.speed <= 0)
        throw std::invalid_argument("Motion Constraints: Max. speed has to be > 0");
    if(max.acceleration <= 0)
        throw std::invalid_argument("Motion Constraints: Max. acceleration has to be > 0");
    if(max_jerk <= 0)
        throw std::invalid_argument("Motion Constraints: Max. jerk has to be > 0");
}

void MotionConstraint::applyDefaultIfUnset(const MotionConstraint& default_constraints){
    if(!hasMaxPosition())
        max.position = default_constraints.max.position;
    if(!hasMinPosition())
        min.position = default_constraints.min.position;
    if(!hasMaxVelocity())
        max.speed = default_constraints.max.speed;
    if(!hasMaxAcceleration())
        max.acceleration = default_constraints.max.acceleration;
    if(!hasMaxJerk())
        max_jerk = default_constraints.max_jerk;
}
}

