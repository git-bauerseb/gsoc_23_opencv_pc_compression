#include <iostream>

#include "quantizer.h"
#include "pointcloud.h"

int main() {

    pc_comp::PointCloud pc;
    pc.addPoint({0.0f, 0.0f, 0.0f});
    pc.addPoint({1.0f, 0.0f, 0.0f});
    pc.addPoint({0.0f, 0.0f, 1.0f});
    pc.addPoint({1.0f, 0.0f, 1.0f});
    pc.addPoint({0.0f, 1.0f, 0.0f});
    pc.addPoint({1.0f, 1.0f, 0.0f});
    pc.addPoint({0.0f, 1.0f, 1.0f});
    pc.addPoint({1.0f, 1.0f, 1.0f});

    float maxRange = 0;

    int num_points = std::distance(pc.point_cloud().begin(), pc.point_cloud().end());

    for (auto it = pc.point_cloud().begin(); it != pc.point_cloud().end(); it++) {
        maxRange = std::max(std::abs(it->x()), maxRange);
        maxRange = std::max(std::abs(it->y()), maxRange);
        maxRange = std::max(std::abs(it->z()), maxRange);
    }

    // Number of quantization bits used for compression
    // Higher values -> Better quality
    // Lower value -> worse quality
    int quantBits = 11;

    pc_comp::Quantizer qu{maxRange, (1 << quantBits) - 1};


    // Quantize all points
    std::vector<pc_comp::Vec3u> quantized;
    quantized.reserve(num_points);
    int idx = 0;
    for (auto it = pc.point_cloud().begin(); it != pc.point_cloud().end(); it++,  idx++) {
        uint32_t xQ = qu(it->x());
        uint32_t yQ = qu(it->y());
        uint32_t zQ = qu(it->z());
        quantized[idx].x() = xQ;
        quantized[idx].y() = yQ;
        quantized[idx].z() = zQ;
    }


    return 0;
}