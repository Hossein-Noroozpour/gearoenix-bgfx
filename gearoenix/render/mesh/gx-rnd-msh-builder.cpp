#include "gx-rnd-msh-builder.hpp"
#include "../../core/ecs/gx-cr-ecs-world.hpp"
#include "../../platform/gx-plt-log.hpp"

gearoenix::render::mesh::Builder::Builder(
    core::ecs::World& world,
    const std::string& name,
    std::vector<PbrVertex>&& vertices,
    std::vector<std::uint32_t>&& indices,
    const core::sync::EndCallerIgnored& end) noexcept
    : entity_builder(world.create_shared_builder())
{
    core::ecs::EntityBuilder& eb = entity_builder->get_builder();
    eb.add_component(Mesh(name, std::move(vertices), std::move(indices), end));
    eb.set_name(name);
    // TODO I have to add transformation component here later.
}

gearoenix::render::mesh::Builder::~Builder() noexcept
{
    const core::ecs::EntityBuilder& b = entity_builder->get_builder();
    const Mesh& m = b.get_component<Mesh>().value();
    if (!m.get_material().has_value())
        GX_LOG_F("Mesh '" << b.get_name().value() << "' does not have material component, please add its component.")
}