#ifndef GEAROENIX_CORE_APPLICATION_HPP
#define GEAROENIX_CORE_APPLICATION_HPP
#include "../platform/gx-plt-application.hpp"
#include "gx-cr-build-configuration.hpp"
#include "gx-cr-types.hpp"
#include <memory>

namespace gearoenix::render::engine {
struct Engine;
}

namespace gearoenix::platform {
struct Application;
}

namespace gearoenix::core::event {
struct Event;
}

namespace gearoenix::core {
struct Application {
public:
protected:
    platform::Application* platform_application = nullptr;
    render::engine::Engine* render_engine = nullptr;

public:
    Application() noexcept;
    virtual ~Application() noexcept;
    virtual void update() noexcept;
};
}
#endif
