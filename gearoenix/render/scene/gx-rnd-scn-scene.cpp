#include "gx-rnd-scn-scene.hpp"

gearoenix::render::scene::Scene::Scene(
    engine::Engine* const,
    const std::size_t scene_index,
    const core::sync::EndCallerIgnored& c) noexcept
    : core::ecs::Component(this)
{
    std::sort(entities.begin(), entities.end());
}

gearoenix::render::scene::Scene::~Scene() noexcept = default;

gearoenix::render::scene::Scene::Scene(Scene&&) noexcept = default;

void gearoenix::render::scene::Scene::update() noexcept
{
}
