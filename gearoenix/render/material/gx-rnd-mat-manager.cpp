#include "gx-rnd-mat-manager.hpp"
#include <algorithm>

void gearoenix::render::material::Manager::register_type(const std::type_index t) noexcept
{
    if (is_material(t)) // Already has been registered
        return;
    registered_types.push_back(t);
    std::sort(registered_types.begin(), registered_types.end());
}

bool gearoenix::render::material::Manager::is_material(std::type_index t) const noexcept
{
    return std::binary_search(registered_types.begin(), registered_types.end(), t);
}
