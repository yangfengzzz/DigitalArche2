// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "../src.common/bvh3.h"
#include "../src.common/triangle_mesh3.h"

#include <benchmark/benchmark.h>
#include <fstream>
#include <random>

using vox::TriangleMesh3;
using vox::Triangle3;
using vox::BoundingBox3D;
using vox::Vector3D;
using vox::Ray3D;

class Bvh3 : public ::benchmark::Fixture {
public:
    std::mt19937 rng{0};
    std::uniform_real_distribution<> dist{0.0, 1.0};
    TriangleMesh3 triMesh;
    vox::Bvh3<Triangle3> queryEngine;
    
    void SetUp(const ::benchmark::State&) {
        std::ifstream file("../resources/bunny.obj");
        
        if (file) {
            triMesh.readObj(&file);
            file.close();
        }
        
        std::vector<Triangle3> triangles;
        std::vector<BoundingBox3D> bounds;
        for (size_t i = 0; i < triMesh.numberOfTriangles(); ++i) {
            auto tri = triMesh.triangle(i);
            triangles.push_back(tri);
            bounds.push_back(tri.boundingBox());
        }
        
        queryEngine.build(triangles, bounds);
    }
    
    Vector3D makeVec() { return Vector3D(dist(rng), dist(rng), dist(rng)); }
    
    static double distanceFunc(const Triangle3& tri, const Vector3D& pt) {
        return tri.closestDistance(pt);
    }
    
    static bool intersectsFunc(const Triangle3& tri, const Ray3D& ray) {
        return tri.intersects(ray);
    }
};

BENCHMARK_DEFINE_F(Bvh3, Nearest)(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(queryEngine.nearest(makeVec(), distanceFunc));
    }
}

BENCHMARK_REGISTER_F(Bvh3, Nearest);

BENCHMARK_DEFINE_F(Bvh3, RayIntersects)(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(queryEngine.intersects(
                                                        Ray3D(makeVec(), makeVec().normalized()), intersectsFunc));
    }
}

BENCHMARK_REGISTER_F(Bvh3, RayIntersects);
