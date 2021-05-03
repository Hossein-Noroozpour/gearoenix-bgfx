#include "gx-cr-application.hpp"
#include "../platform/gx-plt-application.hpp"

gearoenix::core::Application::Application() noexcept = default;

gearoenix::core::Application::~Application() noexcept = default;

void gearoenix::core::Application::initialize(platform::Application* const plt_app) noexcept
{
    platform_application = plt_app;
    render_engine = plt_app->get_render_engine();
}

void gearoenix::core::Application::gui_update() noexcept
{
}

void gearoenix::core::Application::update() noexcept
{
}
