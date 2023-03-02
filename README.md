# Point Cloud Compression

This repository contains code for octree-based point cloud compression. It is based on the paper "Geometric Compression For Interactive Transmission" by Olivier Devillers and Pierre-Marie Gandoin.

The goal of this code is to provide a minimal working implementation of point cloud compression for the OpenCV Google Summer of Code 2023 project idea (see [here](https://github.com/opencv/opencv/wiki/GSoC_2023#idea-point-cloud-compression)).

## Build

```
mkdir build
cd build
cmake ..
make
```

## Todo

- Quantize floating-point point cloud into integers with coordinates 0 to 2^b
- Recursive splitting of cells and output number of points in left sub-cell