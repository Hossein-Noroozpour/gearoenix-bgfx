#ifndef GEAROENIX_RENDER_MESH_MESH_HPP
#define GEAROENIX_RENDER_MESH_MESH_HPP
#include "../../core/ecs/gx-cr-ecs-component.hpp"
#include "../../core/ecs/gx-cr-ecs-entity.hpp"
#include "../../core/macro/gx-cr-mcr-getter-setter.hpp"
#include "../../core/sync/gx-cr-sync-end-caller.hpp"
#include "../../math/gx-math-aabb.hpp"
#include "../gx-rnd-vertex.hpp"
#include "../material/gx-rnd-mat-translucency-mode.hpp"
#include <bgfx/bgfx.h>
#include <memory>
#include <optional>
#include <typeindex>

namespace gearoenix::core::ecs {
struct EntitySharedBuilder;
}

namespace gearoenix::render::mesh {
struct Mesh final : public core::ecs::Component {
    GX_GET_CREF_PRV(math::Aabb3, origin)
    GX_GET_CREF_PRV(math::Aabb3, updated)
    GX_GETSET_VAL_PRV(material::TranslucencyMode, translucency, material::TranslucencyMode::Opaque)
    GX_GET_VAL_PRV(bool, is_shadow_caster, true)
    GX_GET_VAL_PRV(bgfx::VertexBufferHandle, vbo, BGFX_INVALID_HANDLE)
    GX_GET_VAL_PRV(bgfx::IndexBufferHandle, ibo, BGFX_INVALID_HANDLE)
    GX_GETSET_VAL_PRV(std::optional<std::type_index>, material, std::nullopt)

public:
    Mesh(
        const std::string& name,
        std::vector<PbrVertex>&& vertices,
        std::vector<std::uint32_t>&& indices,
        const core::sync::EndCallerIgnored& c = GX_DEFAULT_IGNORED_END_CALLER) noexcept;
    Mesh(Mesh&&) noexcept = default;
    Mesh(const Mesh&) = delete;
    Mesh& operator=(Mesh&&) = delete;
    Mesh& operator=(const Mesh&) = delete;
    ~Mesh() noexcept final;
};
}
#endif
