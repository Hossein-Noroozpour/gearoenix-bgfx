#include "gx-plt-application.hpp"
#include "../core/gx-cr-application.hpp"
#include "../render/gx-rnd-engine.hpp"
#include <bgfx/examples/common/bgfx_utils.h>
#include <bgfx/examples/common/imgui/imgui.h>

gearoenix::platform::Application::Application(
    const char* const name,
    const char* const description,
    const char* const url,
    core::Application* const core_app) noexcept
    : entry::AppI(name, description, url)
#ifdef GX_DEBUG_MODE
    , debug_state(BGFX_DEBUG_TEXT)
#endif
    , reset_state(BGFX_RESET_VSYNC)
    , core_application(core_app)
    , render_engine(new render::Engine(*this))
{
}

gearoenix::platform::Application::~Application() noexcept = default;

void gearoenix::platform::Application::init(
    const std::int32_t argc, const char* const* const argv,
    const std::uint32_t win_width, const std::uint32_t win_height)
{
    window_width = win_width;
    window_height = win_height;

    Args args(argc, argv);

    bgfx::Init init;
    init.type = args.m_type;
    init.vendorId = args.m_pciId;
    init.resolution.width = window_width;
    init.resolution.height = window_height;
    init.resolution.reset = reset_state;
    bgfx::init(init);

    bgfx::setDebug(debug_state);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0);

    imguiCreate();

    render_engine->initialize();
    core_application->initialize(this);
}

int gearoenix::platform::Application::shutdown()
{
    core_application = nullptr;
    render_engine = nullptr;
    imguiDestroy();
    bgfx::shutdown();
    return 0;
}

bool gearoenix::platform::Application::update()
{
    if (!entry::processEvents(window_width, window_height, debug_state, reset_state, &mouse_state)) {
        std::uint8_t mouse_button_state = mouse_state.m_buttons[entry::MouseButton::Left] ? IMGUI_MBUT_LEFT : 0;
        mouse_button_state |= mouse_state.m_buttons[entry::MouseButton::Right] ? IMGUI_MBUT_RIGHT : 0;
        mouse_button_state |= mouse_state.m_buttons[entry::MouseButton::Middle] ? IMGUI_MBUT_MIDDLE : 0;
        imguiBeginFrame(
            mouse_state.m_mx, mouse_state.m_my, mouse_button_state, mouse_state.m_mz,
            static_cast<std::uint16_t>(window_width), static_cast<std::uint16_t>(window_height));
        showExampleDialog(this);

        render_engine->gui_update();
        core_application->gui_update();

        imguiEndFrame();

        bgfx::setViewRect(0, 0, 0, static_cast<std::uint16_t>(window_width), static_cast<std::uint16_t>(window_height));
        bgfx::touch(0);
        bgfx::dbgTextClear();
        bgfx::dbgTextPrintf(0, 1, 0x0f, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.");

        bgfx::dbgTextPrintf(80, 1, 0x0f, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
        bgfx::dbgTextPrintf(80, 2, 0x0f, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");

        const bgfx::Stats* stats = bgfx::getStats();
        bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.", stats->width, stats->height, stats->textWidth, stats->textHeight);

        render_engine->update();
        core_application->update();

        bgfx::frame();

        return true;
    }

    return false;
}
