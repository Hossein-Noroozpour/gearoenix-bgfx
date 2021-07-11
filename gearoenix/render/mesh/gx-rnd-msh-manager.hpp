#ifndef GEAROENIX_RENDER_MESH_MANAGER_HPP
#define GEAROENIX_RENDER_MESH_MANAGER_HPP
#include "../../core/cache/gx-cr-cache-file.hpp"
#include "../../core/sync/gx-cr-sync-end-caller.hpp"
#include "../gx-rnd-vertex.hpp"
#include "../texture/gx-rnd-txt-face.hpp"
#include <memory>

namespace gearoenix::platform::stream {
struct Stream;
}

namespace gearoenix::render {
struct Engine;
}

namespace gearoenix::render::mesh {
struct Builder;
struct Mesh;
struct Manager {
private:
    const Engine& e;
    std::weak_ptr<Mesh> icosphere;
    std::weak_ptr<Mesh> plate;
    std::weak_ptr<Mesh> cube;
    std::weak_ptr<Mesh> inward_cube;

public:
    explicit Manager(const Engine& e) noexcept;
    ~Manager() noexcept = default;
    [[nodiscard]] std::shared_ptr<Mesh> create_icosphere(core::sync::EndCaller<Mesh>& c) noexcept;
    [[nodiscard]] std::shared_ptr<Mesh> create_plate(core::sync::EndCaller<Mesh>& c) noexcept;
    [[nodiscard]] std::shared_ptr<Mesh> create_cube(core::sync::EndCaller<Mesh>& c) noexcept;
    [[nodiscard]] std::shared_ptr<Mesh> create_inward_cube(core::sync::EndCaller<Mesh>& c) noexcept;
    [[nodiscard]] std::shared_ptr<Mesh> create_face_square(texture::Face f, core::sync::EndCaller<Mesh>& c) noexcept;

    /// This function builds a builder object for the mesh later you can add another relative components to it and move it to a scene
    [[nodiscard]] std::shared_ptr<Builder> create_builder(
        std::string&& name,
        std::vector<PbrVertex>&& vertices,
        std::vector<std::uint32_t>&& indices) const noexcept;
};
}

#endif
