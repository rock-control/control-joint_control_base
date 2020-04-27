#include <boost/test/unit_test.hpp>
#include <joint_control_base/MotionConstraint.hpp>
#include <joint_control_base/ConstrainedJointsCmd.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(motion_constraint){
    joint_control_base::MotionConstraint constraint;
    BOOST_CHECK(constraint.hasMaxPosition() == false);
    BOOST_CHECK(constraint.hasMinPosition() == false);
    BOOST_CHECK(constraint.hasMaxVelocity() == false);
    BOOST_CHECK(constraint.hasMaxAcceleration() == false);
    BOOST_CHECK(constraint.hasMaxJerk() == false);

    BOOST_CHECK_THROW(constraint.validatePositionLimits(), std::invalid_argument);
    BOOST_CHECK_THROW(constraint.validateAccelerationLimit(), std::invalid_argument);
    BOOST_CHECK_THROW(constraint.validateJerkLimit(), std::invalid_argument);
    BOOST_CHECK_THROW(constraint.validateVelocityLimit(), std::invalid_argument);

    joint_control_base::MotionConstraint default_constraint;
    default_constraint.max.position = (double)rand()/RAND_MAX;
    default_constraint.min.position = (double)rand()/RAND_MAX;
    default_constraint.max.speed= (double)rand()/RAND_MAX;
    default_constraint.max.acceleration = (double)rand()/RAND_MAX;
    default_constraint.max_jerk = (double)rand()/RAND_MAX;
    constraint.applyDefaultIfUnset(default_constraint);

    BOOST_CHECK(constraint.max.position == default_constraint.max.position);
    BOOST_CHECK(constraint.min.position == default_constraint.min.position);
    BOOST_CHECK(constraint.max.speed == default_constraint.max.speed);
    BOOST_CHECK(constraint.max.acceleration == default_constraint.max.acceleration);
    BOOST_CHECK(constraint.max_jerk == default_constraint.max_jerk);
}

BOOST_AUTO_TEST_CASE(constrained_joints_cmd){
    joint_control_base::ConstrainedJointsCmd cmd;
    BOOST_CHECK(cmd.empty() == true);

    cmd.names.push_back(("joint_1"));
    BOOST_CHECK_THROW(cmd.validate(),std::invalid_argument);
    cmd.elements.push_back(base::JointState());
    BOOST_CHECK_NO_THROW(cmd.validate());

    joint_control_base::MotionConstraint constraint;
    constraint.max.position = (double)rand()/RAND_MAX;
    constraint.min.position = (double)rand()/RAND_MAX;
    constraint.max.speed= (double)rand()/RAND_MAX;
    constraint.max.acceleration = (double)rand()/RAND_MAX;
    constraint.max_jerk = (double)rand()/RAND_MAX;
    cmd.motion_constraints.push_back(constraint);
    BOOST_CHECK_NO_THROW(cmd.validate());


    cmd.motion_constraints.push_back(constraint);
    BOOST_CHECK_THROW(cmd.validate(), std::invalid_argument);
}

