#ifndef GEAROENIX_RENDER_SCENE_SCENE_HPP
#define GEAROENIX_RENDER_SCENE_SCENE_HPP
#include "../../core/ecs/gx-cr-ecs-component.hpp"
#include "../../core/ecs/gx-cr-ecs-entity.hpp"
#include <vector>

namespace gearoenix::render::engine {
struct Engine;
}

namespace gearoenix::render::gltf {
struct Loader;
}

namespace gearoenix::render::scene {
struct Scene final : public core::ecs::Component {
    GX_GET_CREF_PRV(std::vector<core::ecs::Entity::id_t>, entities)
    GX_GET_CREF_PRV(std::vector<core::ecs::Entity::id_t>, meshes)
    GX_GET_CREF_PRV(std::vector<core::ecs::Entity::id_t>, camera)

private:
    void add_entity(core::ecs::Entity::id_t e) noexcept;

public:
    Scene() noexcept;
    ~Scene() noexcept final;
    Scene(Scene&&) noexcept;
    void update() noexcept;
    void add_mesh(core::ecs::Entity::id_t m) noexcept;
    void add_camera(core::ecs::Entity::id_t c) noexcept;
};
}
#endif
