#include "gx-rnd-msh-manager.hpp"
#include "../../core/asset/gx-cr-asset-manager.hpp"
#include "../../math/gx-math-aabb.hpp"
#include "../gx-rnd-engine.hpp"
#include "gx-rnd-msh-builder.hpp"

gearoenix::render::mesh::Manager::Manager(const Engine& e) noexcept
    : e(e)
{
}

std::shared_ptr<gearoenix::render::mesh::Builder> gearoenix::render::mesh::Manager::create_builder(
    std::string&& name,
    std::vector<PbrVertex>&& vertices,
    std::vector<std::uint32_t>&& indices) const noexcept
{
    return std::shared_ptr<Builder>(new Builder(*e.get_world(), std::move(name), std::move(vertices), std::move(indices)));
}
