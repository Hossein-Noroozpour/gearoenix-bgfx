#ifndef GEAROENIX_RENDER_MATERIAL_PBR_HPP
#define GEAROENIX_RENDER_MATERIAL_PBR_HPP
#include "../../core/ecs/gx-cr-ecs-component.hpp"
#include "../../core/sync/gx-cr-sync-end-caller.hpp"
#include "../../math/gx-math-vector-4d.hpp"
#include <bgfx/bgfx.h>

namespace gearoenix::render::material {
struct Pbr final : public core::ecs::Component {
private:
    struct Shader final {
        bgfx::ProgramHandle program;

        Shader() noexcept;
        ~Shader() noexcept;
    };
    static std::weak_ptr<Shader> shader_origin;
    std::shared_ptr<Shader> shader;
    bgfx::ProgramHandle program = BGFX_INVALID_HANDLE; // For better caching
    //GX_GET_CREF_PRV(std::shared_ptr<texture::Texture2D>, color_texture)
    //GX_GET_CREF_PRV(std::optional<math::Vec4<float>>, color_value)
    //GX_GET_CREF_PRV(std::shared_ptr<texture::Texture2D>, emission_texture)
    //GX_GET_CREF_PRV(std::optional<math::Vec3<float>>, emission_value)
    //GX_GET_CREF_PRV(std::shared_ptr<texture::Texture2D>, metallic_roughness_texture)
    //GX_GET_CREF_PRV(std::optional<math::Vec2<float>>, metallic_roughness_value)
    //GX_GET_CREF_PRV(std::shared_ptr<texture::Texture2D>, normal_texture)
    //GX_GET_CREF_PRV(std::optional<math::Vec3<float>>, normal_value)
    //GX_GETSET_PTR_PRV(texture::TextureCube, irradiance)
    //GX_GET_PTR_PRV(texture::TextureCube, radiance)
    //GX_GET_CREF_PRV(Uniform, uniform)
public:
    Pbr(Engine& e, const core::sync::EndCallerIgnored& end = GX_DEFAULT_IGNORED_END_CALLER) noexcept;
    void gpu_upload() noexcept;
    void set_metallic_factor(float f) noexcept;
    void set_roughness_factor(float f) noexcept;
    //void set_color(std::uint32_t code, const core::sync::EndCaller<core::sync::EndCallerIgnore>& end) noexcept;
    //void set_color(
    //    float r, float g, float b,
    //    const core::sync::EndCaller<core::sync::EndCallerIgnore>& end) noexcept;
    //void set_color(const math::Vec4<float>& c,
    //    const core::sync::EndCaller<core::sync::EndCallerIgnore>& end = GX_DEFAULT_IGNORED_END_CALLER) noexcept;
    //void set_color(const std::shared_ptr<texture::Texture2D>& color) noexcept;
    //void set_alpha(float) noexcept;
    //void set_radiance(texture::TextureCube*) noexcept;
};
}

#endif