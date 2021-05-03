#ifndef GEAROENIX_PLATFORM_BGFX_APPLICATION_HPP
#define GEAROENIX_PLATFORM_BGFX_APPLICATION_HPP
#include "../gx-plt-build-configuration.hpp"
#ifdef GX_PLATFORM_INTERFACE_BGFX
#include "../gx-plt-application.hpp"
#include <bgfx/examples/common/common.h>
#include <memory>

namespace gearoenix::core {
struct Application;
}

namespace gearoenix::platform {
struct Application final : public entry::AppI {
    GX_GET_REF_PRV(BaseApplication, base)
private:
    entry::MouseState mouse_state;
    std::uint32_t debug_state = 0;
    std::uint32_t reset_state = 0;

public:
    Application(const char* name, const char* description, const char* url, core::Application* core_app) noexcept;
    ~Application() noexcept final;
    void init(std::int32_t argc, const char* const* argv, std::uint32_t window_width, std::uint32_t window_height) final;
    int shutdown() final;
    bool update() final;
};
}

#endif
#endif