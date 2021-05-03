#include "gx-rnd-scn-manager.hpp"
#include "../../core/ecs/gx-cr-ecs-world.hpp"
#include "../../core/sync/gx-cr-sync-work-waiter.hpp"
#include "../engine/gx-rnd-eng-engine.hpp"
#include "gx-rnd-scn-scene.hpp"

gearoenix::render::scene::Manager::Manager(engine::Engine* const e) noexcept
    : e(e)
    , io_worker(new core::sync::WorkWaiter())
{
}

gearoenix::render::scene::Manager::~Manager() noexcept = default;