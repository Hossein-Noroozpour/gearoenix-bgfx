#ifndef GEAROENIX_RENDER_MESH_BUILDER_HPP
#define GEAROENIX_RENDER_MESH_BUILDER_HPP
#include "../../core/ecs/gx-cr-ecs-entity.hpp"
#include "../../core/sync/gx-cr-sync-end-caller.hpp"
#include "../gx-rnd-vertex.hpp"
#include "gx-rnd-msh-mesh.hpp"
#include <memory>
#include <typeindex>

namespace gearoenix::core::ecs {
struct World;
}

namespace gearoenix::render::mesh {
struct Builder final {
    friend struct Manager;

private:
    const std::shared_ptr<core::ecs::EntitySharedBuilder> entity_builder;

    explicit Builder(
        core::ecs::World& world,
        const std::string& name,
        std::vector<PbrVertex>&& vertices,
        std::vector<std::uint32_t>&& indices,
        const core::sync::EndCallerIgnored& end = GX_DEFAULT_IGNORED_END_CALLER) noexcept;

public:
    Builder(Builder&&) = delete;
    Builder(const Builder&) = delete;
    Builder& operator=(Builder&&) = delete;
    Builder& operator=(const Builder&) = delete;
    ~Builder() noexcept;

    template <typename T>
    void add_material(T&& mat) noexcept
    {
        auto& b = entity_builder->get_builder();
        b.get_component<Mesh>().value().set_material(mat.get_type_index());
        b.add_component(std::move(mat));
    }
};
}
#endif
