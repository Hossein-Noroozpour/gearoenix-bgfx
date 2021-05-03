#ifndef GEAROENIX_PLATFORM_BGFX_MAIN_ENTRY_HPP
#define GEAROENIX_PLATFORM_BGFX_MAIN_ENTRY_HPP
#include "../gx-plt-build-configuration.hpp"
#ifdef GX_PLATFORM_INTERFACE_BGFX
#include "../../core/gx-cr-build-configuration.hpp"
#define ENTRY_CONFIG_IMPLEMENT_MAIN 1
#include <bgfx/examples/common/common.h>

#define GEAROENIX_START(ApplicationMainClass)                                 \
    using _gearoenix_platform_Application = gearoenix::platform::Application; \
    ENTRY_IMPLEMENT_MAIN(                                                     \
        _gearoenix_platform_Application,                                      \
        GX_ENGINE_NAME,                                                       \
        GX_APPLICATION_NAME,                                                  \
        "https://www.gearoenix.com",                                          \
        new ApplicationMainClass());

#endif
#endif