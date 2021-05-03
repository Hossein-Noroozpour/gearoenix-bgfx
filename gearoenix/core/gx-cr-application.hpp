#ifndef GEAROENIX_CORE_APPLICATION_HPP
#define GEAROENIX_CORE_APPLICATION_HPP

namespace gearoenix::render {
struct Engine;
}

namespace gearoenix::platform {
struct Application;
}

namespace gearoenix::core {
struct Application {
public:
protected:
    platform::Application* platform_application = nullptr;
    render::Engine* render_engine = nullptr;

public:
    Application() noexcept;
    virtual ~Application() noexcept;
    virtual void initialize(platform::Application* platform_application) noexcept;
    virtual void gui_update() noexcept;
    virtual void update() noexcept;
};
}
#endif
