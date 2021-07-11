#include "gx-rnd-vertex.hpp"

bgfx::VertexLayout gearoenix::render::PbrVertex::bgfx_layout;
gearoenix::render::PbrVertex::_Initializer gearoenix::render::PbrVertex::_initializer;

gearoenix::render::PbrVertex::PbrVertex(const math::Vec3<float>& position, const math::Vec3<float>& normal, const math::Vec4<float>& tangent, const math::Vec2<float>& uv) noexcept
    : position(position)
    , normal(normal)
    , tangent(tangent)
    , uv(uv)
{
}

gearoenix::render::PbrVertex::PbrVertex(platform::stream::Stream& f) noexcept
{
    read(f);
}

void gearoenix::render::PbrVertex::read(platform::stream::Stream& f) noexcept
{
    position.read(f);
    normal.read(f);
    tangent.read(f);
    uv.read(f);
}

void gearoenix::render::PbrVertex::set_position(const float x, const float y, const float z) noexcept
{
    position.x = x;
    position.y = y;
    position.z = z;
}

gearoenix::render::PbrVertex::_Initializer::_Initializer() noexcept
{
    PbrVertex::bgfx_layout
        .begin()
        .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
        .add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float, true)
        .add(bgfx::Attrib::Tangent, 4, bgfx::AttribType::Float, true)
        .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
        .end();
}
