#ifndef GEAROENIX_PLATFORM_APPLICATION_HPP
#define GEAROENIX_PLATFORM_APPLICATION_HPP
#include "../core/macro/gx-cr-mcr-getter-setter.hpp"
#include "gx-plt-build-configuration.hpp"
#include "gx-plt-main-entry.hpp"
#include <memory>

namespace gearoenix::core {
struct Application;
}

namespace gearoenix::render {
struct Engine;
}

namespace gearoenix::platform {
struct Application final : public entry::AppI {
private:
    entry::MouseState mouse_state;
    std::uint32_t debug_state = 0;
    std::uint32_t reset_state = 0;
    GX_GET_VAL_PRV(std::uint32_t, window_width, 1000)
    GX_GET_VAL_PRV(std::uint32_t, window_height, 500)
    GX_GET_UPTR_PRV(core::Application, core_application)
    GX_GET_UPTR_PRV(render::Engine, render_engine)

public:
    Application(const char* name, const char* description, const char* url, core::Application* core_app) noexcept;
    ~Application() noexcept final;
    void init(std::int32_t argc, const char* const* argv, std::uint32_t window_width, std::uint32_t window_height) final;
    int shutdown() final;
    bool update() final;
};
}

#endif