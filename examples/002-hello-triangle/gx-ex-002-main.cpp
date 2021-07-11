#include <gearoenix/core/gx-cr-application.hpp>
#include <gearoenix/platform/gx-plt-application.hpp>
#include <gearoenix/render/gx-rnd-engine.hpp>
#include <gearoenix/render/gx-rnd-vertex.hpp>
#include <gearoenix/render/material/gx-rnd-mat-pbr.hpp>
#include <gearoenix/render/mesh/gx-rnd-msh-builder.hpp>
#include <gearoenix/render/mesh/gx-rnd-msh-manager.hpp>
#include <gearoenix/render/scene/gx-rnd-scn-builder.hpp>
#include <gearoenix/render/scene/gx-rnd-scn-manager.hpp>

struct GameApp final : public gearoenix::core::Application {
    void initialize(gearoenix::platform::Application* plt_app) noexcept final
    {
        gearoenix::core::Application::initialize(plt_app);

        const auto scene_creator = render_engine->get_scene_manager()->create_builder();

        std::vector<gearoenix::render::PbrVertex> vertices(3);
        vertices[0].set_position(1.0f, 0.0f, 0.0f);
        vertices[1].set_position(0.0f, 1.0f, 0.0f);
        vertices[2].set_position(-1.0f, 0.0f, 0.0f);

        std::vector<std::uint32_t> indices = { 0, 1, 2 };

        auto mesh_builder = render_engine->get_mesh_manager()->create_builder("triangle", std::move(vertices), std::move(indices));
        mesh_builder->add_material(gearoenix::render::material::Pbr(*render_engine));

        scene_creator->add(std::move(mesh_builder));

        auto camera_builder = render_engine->get_camera_manager()->create_builder();
        camera_builder->get_transformation()->set_position(0.0f, 0.0f, 5.0f);

        scene_creator->add(std::move(camera_builder));
    }
};

GEAROENIX_START(GameApp)