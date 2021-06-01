#ifndef GEAROENIX_RENDER_SCENE_BUILDER_HPP
#define GEAROENIX_RENDER_SCENE_BUILDER_HPP
#include "../../core/macro/gx-cr-mcr-getter-setter.hpp"
#include <memory>

namespace gearoenix::core::ecs {
struct World;
struct EntitySharedBuilder;
}

namespace gearoenix::render::scene {
struct Builder final {
    friend struct Manager;

    GX_GET_CREF_PRV(std::shared_ptr<core::ecs::EntitySharedBuilder>, entity_builder)

private:
    explicit Builder(core::ecs::World& world) noexcept;

public:
    Builder(Builder&&) = delete;
    Builder(const Builder&) = delete;
    Builder& operator=(Builder&&) = delete;
    Builder& operator=(const Builder&) = delete;
    ~Builder() noexcept;
};
}

#endif