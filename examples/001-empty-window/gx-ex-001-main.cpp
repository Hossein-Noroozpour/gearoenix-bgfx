#include <gearoenix/core/gx-cr-application.hpp>

struct GameApp final : public gearoenix::core::Application {
public:
    GameApp() noexcept = default;
};

GEAROENIX_START(GameApp)