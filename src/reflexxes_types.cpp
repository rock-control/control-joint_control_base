#include "reflexxes_types.hpp"

namespace trajectory_generation {

/** Debug: Input parameters of the reflexxes OTG algorithm*/
ReflexxesInputParameters::ReflexxesInputParameters(const size_t dof){
        selection_vector.resize(dof, base::NaN<u_int8_t>());
        current_position_vector.resize(dof, base::NaN<double>());
        current_velocity_vector.resize(dof, base::NaN<double>());
        current_acceleration_vector.resize(dof, base::NaN<double>());
        max_position_vector.resize(dof, base::NaN<double>());
        min_position_vector.resize(dof, base::NaN<double>());
        max_velocity_vector.resize(dof, base::NaN<double>());
        max_acceleration_vector.resize(dof, base::NaN<double>());
        max_jerk_vector.resize(dof, base::NaN<double>());
        target_position_vector.resize(dof, base::NaN<double>());
        target_velocity_vector.resize(dof, base::NaN<double>());
        min_synchronization_time = base::NaN<double>();
        override_value = base::NaN<double>();
}

/** Debug: Output parameters of the reflexxes OTG algorithm*/
ReflexxesOutputParameters::ReflexxesOutputParameters(const size_t dof){
        new_position_vector.resize(dof, base::NaN<int>());
        new_velocity_vector.resize(dof, base::NaN<double>());
        new_acceleration_vector.resize(dof, base::NaN<double>());
        execution_times.resize(dof, base::NaN<double>());
        position_values_at_target_velocity.resize(dof, base::NaN<double>());
        dof_with_greatest_execution_time = base::NaN<int>();
        synchronization_time = base::NaN<double>();
        current_override_value = base::NaN<double>();
        a_new_calculation_was_performed = false;
        trajectory_is_phase_synchronized = false;
        override_filter_is_active = false;
        trajectory_exceeds_target_position = false;
}

}

