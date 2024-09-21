#pragma once

#include <triangle_mesh_type.h>
#include <mesh_manager.h>
#include <vcg/space/box3.h>
#include <tracing/mesh_type.h>

#include <load_save.h>
#include <mesh_types.h>
#include <smooth_mesh.h>
#include <quad_from_patches.h>
#include <quad_mesh_tracer.h>

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

struct Parameters {
    Parameters() :
        remesh(true),
        sharpAngle(35),
        alpha(0.02),
        scaleFact(1),
        hasFeature(false),
        hasField(false)
    {

    }

    bool remesh;
    float sharpAngle;
    float alpha;
    float scaleFact;
    bool hasFeature;
    bool hasField;
};

extern "C" EXPORT void remeshAndField2(
    const Parameters &parameters,
    const char *meshFilename,
    const char *sharpFilename,
    const char *fieldFilename);

void remeshAndField(
        FieldTriMesh& trimesh,
        const Parameters& parameters,
        const std::string& meshFilename,
        const std::string& sharpFilename,
        const std::string& fieldFilename);


void quadrangulate(
        const std::string& path,
        TriangleMesh& trimeshToQuadrangulate,
        PolyMesh& quadmesh,
        std::vector<std::vector<size_t>>& trimeshPartitions,
        std::vector<std::vector<size_t>>& trimeshCorners,
        std::vector<std::pair<size_t,size_t>>& trimeshFeatures,
        std::vector<size_t>& trimeshFeaturesC,
        std::vector<std::vector<size_t>> quadmeshPartitions,
        std::vector<std::vector<size_t>> quadmeshCorners,
        std::vector<int> ilpResult,
        const Parameters& parameters);

bool loadConfigFile(const std::string& filename, Parameters& parameters);


typename TriangleMesh::ScalarType avgEdge(const TriangleMesh &trimesh);
