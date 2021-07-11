#include "gx-rnd-mat-pbr.hpp"
#include "../../core/asset/gx-cr-asset-manager.hpp"
#include "../../platform/gx-plt-application.hpp"
//#include "../texture/gx-rnd-txt-manager.hpp"
//#include "../texture/gx-rnd-txt-texture-2d.hpp"
//#include "../texture/gx-rnd-txt-texture-cube.hpp"
#include "../gx-rnd-engine.hpp"
#include "gx-rnd-mat-manager.hpp"
#include <bgfx/examples/common/bgfx_utils.h>

gearoenix::render::material::Pbr::Shader::Shader() noexcept
    : program(loadProgram("pbr-vs", "pbr-fs"))
{
}

gearoenix::render::material::Pbr::Shader::~Shader() noexcept
{
    bgfx::destroy(program);
}

std::weak_ptr<gearoenix::render::material::Pbr::Shader> gearoenix::render::material::Pbr::shader_origin;

gearoenix::render::material::Pbr::Pbr(Engine& e, const core::sync::EndCallerIgnored& end) noexcept
    : core::ecs::Component(this)
{
    e.get_material_manager()->register_type(type_index);
    if (auto s = shader_origin.lock()) {
        shader = std::move(s);
    } else {
        shader_origin = shader = std::shared_ptr<Shader>(new Shader());
    }
    program = shader->program;
}

gearoenix::render::material::Pbr::~Pbr() noexcept = default;

//
//void gearoenix::render::material::Pbr::Pbr::update() noexcept
//{
//    uniform_buffers->update(uniform);
//}
//
//gearoenix::render::material::Material* gearoenix::render::material::Pbr::clone() const noexcept
//{
//    return new Pbr(*this);
//}
//
//void gearoenix::render::material::Pbr::set_metallic_factor(const float f) noexcept
//{
//    uniform.metallic_factor = f;
//}
//
//void gearoenix::render::material::Pbr::set_roughness_factor(const float f) noexcept
//{
//    uniform.roughness_factor = f;
//}
//
//void gearoenix::render::material::Pbr::set_color(
//    const std::uint32_t code, const core::sync::EndCaller<core::sync::EndCallerIgnore>& end) noexcept
//{
//    set_color(math::Vec4(
//                  float(code >> 24U) / 255.0f,
//                  float((code >> 16U) & 255U) / 255.0f,
//                  float((code >> 8U) & 255U) / 255.0f,
//                  float(code & 255U) / 255.0f),
//        end);
//}
//
//void gearoenix::render::material::Pbr::set_color(
//    const float r, const float g, const float b,
//    const core::sync::EndCaller<core::sync::EndCallerIgnore>& end) noexcept
//{
//    set_color(math::Vec4(r, g, b, 1.0f), end);
//}
//
//void gearoenix::render::material::Pbr::set_color(const math::Vec4<float>& c,
//    const core::sync::EndCaller<core::sync::EndCallerIgnore>& end) noexcept
//{
//    core::sync::EndCaller<texture::Texture2D> call_txt_2d([end](const std::shared_ptr<texture::Texture2D>&) {});
//    auto* const txt_mgr = e->get_platform_application()->get_asset_manager()->get_texture_manager();
//    color_texture = txt_mgr->get_2d(c, call_txt_2d);
//    color_value = c;
//}
//
//void gearoenix::render::material::Pbr::set_color(const std::shared_ptr<texture::Texture2D>& c) noexcept
//{
//    color_texture = c;
//    color_value = std::nullopt;
//}
//
//void gearoenix::render::material::Pbr::set_alpha(const float a) noexcept
//{
//    uniform.alpha = a;
//}
//
//void gearoenix::render::material::Pbr::set_radiance(gearoenix::render::texture::TextureCube* const t) noexcept
//{
//    radiance = t;
//    uniform.radiance_lod_coefficient = static_cast<float>(
//        engine::Configuration::compute_runtime_reflection_radiance_levels(
//            static_cast<int>(t->get_aspect() - 1)));
//}
