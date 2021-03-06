#ifndef MOTION_CONSTRAINT_HPP
#define MOTION_CONSTRAINT_HPP

#include <base/NamedVector.hpp>
#include <base/Float.hpp>

namespace joint_control_base {

/** Motion constraints to define the dynamic behavior of the trajectories generated by this component*/
struct MotionConstraint{

    struct upperLimit{
        double position;     /** Maximum joint or Cartesian position. In rad or m. (only reflexxes TypeIV, has to be > min. position!) */
        double speed;        /** Maximum joint or Cartesian velocity. In rad/s or m/s. (has to be > 0) */
        double acceleration; /** Maximum joint or Cartesian acceleration. In rad/ss or m/ss. (has to be > 0) */
    };
    struct lowerLimit{
        double position;     /** Minimum joint or Cartesian position. In rad or m. (only reflexxes TypeIV, has to be < max. position!) */
    };
    double max_jerk;         /** Maximum joint or Cartesian jerk (derivative of acceleration). In rad/sss or m/sss. (has to be > 0) */
    upperLimit max;
    lowerLimit min;

    MotionConstraint();

    bool hasMaxPosition() const {return !base::isUnset(max.position);}
    bool hasMinPosition() const {return !base::isUnset(min.position);}
    bool hasMaxVelocity() const {return !base::isUnset(max.speed);}
    bool hasMaxAcceleration() const {return !base::isUnset(max.acceleration);}
    bool hasMaxJerk() const {return !base::isUnset(max_jerk);}

    void validatePositionLimits() const;
    void validateVelocityLimit() const;
    void validateAccelerationLimit() const;
    void validateJerkLimit() const;
    void applyDefaultIfUnset(const MotionConstraint& default_constraints);
};

/** For backward compatibility */
typedef MotionConstraint JointMotionConstraints;

/** Named vector of MotionConstraints, i.e. motion constraints for all the joints of a robot*/
struct MotionConstraints : base::NamedVector<MotionConstraint>{
};

/** For backward compatibility */
typedef MotionConstraints JointsMotionConstraints;

}

#endif

