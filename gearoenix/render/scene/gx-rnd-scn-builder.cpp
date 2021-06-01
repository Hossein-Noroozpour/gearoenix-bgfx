#include "gx-rnd-scn-builder.hpp"
#include "../../core/ecs/gx-cr-ecs-world.hpp"

gearoenix::render::scene::Builder::Builder(core::ecs::World& world) noexcept
    : entity_builder(world.create_shared_builder())
{
}

gearoenix::render::scene::Builder::~Builder() noexcept = default;
