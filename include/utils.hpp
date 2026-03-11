#pragma once

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

} // namespace vidar::utils
