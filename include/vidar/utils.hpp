#ifndef VIDAR_UTILS_HPP
#define VIDAR_UTILS_HPP

#include <string>

namespace vidar::utils {

std::string greet(const std::string& name);

/** Updates the variable with a new value if it is different from the current value.
 *  @param variable The variable to update.
 *  @param new_value The new value to assign to the variable.
 *  @return true if the variable was updated, false otherwise.
 */
template<typename T>
bool update(T& variable, const T& new_value) {
    if (variable != new_value) {
        variable = new_value;
        return true;
    }
    return false;
}

/**
 * Checks if a value is within a specified closedinterval [lower_bound, upper_bound].
 * @param value The value to check.
 * @param lower_bound The lower bound of the interval.
 * @param upper_bound The upper bound of the interval.
 * @return true if the value is within the interval, false otherwise.
 */
template<typename T>
bool in_interval(const T& value, const T& lower_bound, const T& upper_bound) {
    return lower_bound <= value && value <= upper_bound;
}

/**
 * Checks if a value is within a specified half open interval [lower_bound, upper_bound).
 * @param value The value to check.
 * @param lower_bound The lower bound of the interval.
 * @param upper_bound The upper bound of the interval.
 * @return true if the value is within the interval, false otherwise.
 */
template<typename T>
bool in_interval_open(const T& value, const T& lower_bound, const T& upper_bound) {
    return lower_bound <= value && value < upper_bound;
}

} // namespace vidar::utils

#endif // VIDAR_UTILS_HPP