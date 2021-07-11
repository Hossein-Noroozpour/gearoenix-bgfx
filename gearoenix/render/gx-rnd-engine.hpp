#ifndef GEAROENIX_RENDER_ENGINE_ENGINE_HPP
#define GEAROENIX_RENDER_ENGINE_ENGINE_HPP
#include "../core/macro/gx-cr-mcr-getter-setter.hpp"
#include "gx-rnd-limitations.hpp"
#include <chrono>
#include <memory>

namespace gearoenix::core {
struct FunctionLoader;
}

namespace gearoenix::core::ecs {
struct World;
}

namespace gearoenix::physics {
struct Engine;
}

namespace gearoenix::platform {
struct Application;
}

namespace gearoenix::render::material {
struct Manager;
}

namespace gearoenix::render::mesh {
struct Mesh;
struct Manager;
}

namespace gearoenix::render::scene {
struct Manager;
}

namespace gearoenix::render {
struct Engine final {
    GX_GET_CRRF_PRV(platform::Application, platform_application)
    // GX_GET_UPTR_PRT(physics::Engine, physics_engine)
    GX_GET_CREF_PRV(Limitations, limitations)
    GX_GET_VAL_PRV(unsigned int, frames_count, 2)
    GX_GET_VAL_PRV(unsigned int, frame_number, 0)
    GX_GET_VAL_PRV(unsigned int, next_frame_number, 1)
    GX_GET_VAL_PRV(unsigned int, previous_frame_number, 1)
    GX_GET_VAL_PRV(unsigned int, frame_number_from_start, static_cast<decltype(frame_number)>(-1))
    GX_GET_VAL_PRV(double, delta_time, 0.0f)
    GX_GET_UPTR_PRV(scene::Manager, scene_manager)
    GX_GET_UPTR_PRV(mesh::Manager, mesh_manager)
    GX_GET_UPTR_PRV(material::Manager, material_manager)
    GX_GET_UPTR_PRV(core::ecs::World, world)
    GX_GET_CREF_PRV(std::chrono::time_point<std::chrono::high_resolution_clock>, last_frame_time)

public:
    explicit Engine(const platform::Application& platform_application) noexcept;
    ~Engine() noexcept;
    void initialize() noexcept;
    void gui_update() noexcept;
    void update() noexcept;
    void upload_imgui_fonts() noexcept;
};
}
#endif
