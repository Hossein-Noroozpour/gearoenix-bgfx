#include "gx-rnd-scn-scene.hpp"

void gearoenix::render::scene::Scene::add_entity(core::ecs::Entity::id_t e) noexcept
{
}

gearoenix::render::scene::Scene::Scene() noexcept
    : core::ecs::Component(this)
{
    std::sort(entities.begin(), entities.end());
}

gearoenix::render::scene::Scene::~Scene() noexcept = default;

gearoenix::render::scene::Scene::Scene(Scene&&) noexcept = default;

void gearoenix::render::scene::Scene::update() noexcept
{
}
