#include "gx-rnd-msh-mesh.hpp"

static struct VertexCallBackData final {
    std::vector<gearoenix::render::PbrVertex> vertices;
    gearoenix::core::sync::EndCallerIgnored end;
};

static void gx_vertex_data_callback(void* const, void* const data_ptr) noexcept
{
    auto* const vd = reinterpret_cast<VertexCallBackData*>(data_ptr);
    delete vd;
}

static struct IndexCallBackData final {
    std::vector<std::uint32_t> indices;
    gearoenix::core::sync::EndCallerIgnored end;
};

static void gx_index_data_callback(void* const, void* const data_ptr) noexcept
{
    auto* const vd = reinterpret_cast<IndexCallBackData*>(data_ptr);
    delete vd;
}

gearoenix::render::mesh::Mesh::Mesh(
    const std::string& name,
    std::vector<PbrVertex>&& vertices,
    std::vector<std::uint32_t>&& indices,
    const core::sync::EndCallerIgnored& c) noexcept
    : core::ecs::Component(this)
{
    for (const auto& vertex : vertices) {
        origin.put_without_update(math::Vec3<double>(vertex.position));
    }

    origin.update();
    updated = origin;

    auto* const v_data = new VertexCallBackData {
        .vertices = std::move(vertices),
        .end = c,
    };

    vbo = bgfx::createVertexBuffer(
        bgfx::makeRef(v_data->vertices.data(), v_data->vertices.size() * sizeof(PbrVertex), gx_vertex_data_callback, v_data),
        PbrVertex::bgfx_layout);
    const auto vbo_name = name + "-vertices";
    bgfx::setName(vbo, vbo_name.c_str(), vbo_name.size());

    auto* const i_data = new IndexCallBackData {
        .indices = std::move(indices),
        .end = c,
    };

    ibo = bgfx::createIndexBuffer(
        bgfx::makeRef(i_data->indices.data(), i_data->indices.size() * sizeof(std::uint32_t), gx_index_data_callback, i_data));
    const auto ibo_name = name + "-indices";
    bgfx::setName(ibo, ibo_name.c_str(), ibo_name.size());
}

gearoenix::render::mesh::Mesh::Mesh(Mesh&& o) noexcept
    : core::ecs::Component(this)
    , origin(o.origin)
    , updated(o.updated)
    , translucency(o.translucency)
    , is_shadow_caster(o.is_shadow_caster)
    , vbo(o.vbo)
    , ibo(o.ibo)
    , material(o.material)
{
    o.vbo = BGFX_INVALID_HANDLE;
    o.ibo = BGFX_INVALID_HANDLE;
}

gearoenix::render::mesh::Mesh::~Mesh() noexcept
{
    if (bgfx::isValid(ibo))
        bgfx::destroy(ibo);
    if (bgfx::isValid(vbo))
        bgfx::destroy(vbo);
}
