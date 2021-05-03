#include "gx-rnd-engine.hpp"
#include "../core/ecs/gx-cr-ecs-world.hpp"
#include "../platform/gx-plt-application.hpp"
#include "scene/gx-rnd-scn-manager.hpp"

gearoenix::render::Engine::Engine(const platform::Application& platform_application) noexcept
    : platform_application(platform_application)
    , scene_manager(new scene::Manager(*this))
    , world(new core::ecs::World())
    , last_frame_time(std::chrono::high_resolution_clock::now())
{
}

gearoenix::render::Engine::~Engine() noexcept = default;

void gearoenix::render::Engine::initialize() noexcept
{
    (void)this; // For suppressing warnings
}

void gearoenix::render::Engine::gui_update() noexcept
{
}

void gearoenix::render::Engine::update() noexcept
{
    const std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> delta_time_duration = now - last_frame_time;
    delta_time = delta_time_duration.count();
    last_frame_time = now;
    previous_frame_number = frame_number_from_start % frames_count;
    ++frame_number_from_start;
    frame_number = frame_number_from_start % frames_count;
    next_frame_number = (frame_number_from_start + 1) % frames_count;
    world->update();
    // physics_engine->update();
}
