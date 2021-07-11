#ifndef GEAROENIX_RENDER_MATERIAL_MANAGER_HPP
#define GEAROENIX_RENDER_MATERIAL_MANAGER_HPP
#include "../../core/macro/gx-cr-mcr-getter-setter.hpp"
#include <typeindex>
#include <vector>

namespace gearoenix::render::material {
struct Manager final {
    GX_GET_CREF_PRV(std::vector<std::type_index>, registered_types)

public:
    void register_type(std::type_index) noexcept;
    [[nodiscard]] bool is_material(std::type_index t) const noexcept;

    template <typename T>
    void register_type() noexcept
    {
        register_type(std::type_index(typeid(T)));
    }

    template <typename T>
    [[nodiscard]] bool is_material() const noexcept
    {
        return is_material(std::type_index(typeid(T)));
    }
};
}

#endif