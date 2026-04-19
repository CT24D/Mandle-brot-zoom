# Mandle-brot-zoom
🌌 Mandelbrot GPU Explorer (FP64 Precision)
A high-performance fractal renderer built with C++ and Raylib that utilizes GLSL fragment shaders with double-precision (FP64) math for deep-space exploration of the Mandelbrot set.
### 🚀 Technical Highlights

    Double-Precision Rendering: Implements dvec2 and the GL_ARB_gpu_shader_fp64 extension to maintain visual stability at extreme zoom levels where standard 32-bit floats fail.
    Smooth Coloring Algorithm: Uses a log-log mapping (Smooth Iteration Count) to eliminate color banding and create fluid gradients.
    GPU Parallelization: Passes real-time uniforms (iTime, iResolution) from C++ to the GPU, calculating millions of iterations per second.
    Procedural Zoom: Features a non-linear exponential zoom centered on the mathematically complex Seahorse Valley (
    ).

### 🛠️ Stack

    Language: C++17
    Graphics API: OpenGL 4.0 Core (via Raylib)
    Shader Language: GLSL 400
    Math: Fractal Escape-Time Algorithm

### 📂 Project Structure

    main.cpp: Handles window initialization, shader loading, and uniform updates.
    default.frag: The fragment shader containing the FP64 Mandelbrot logic and smoothing math.
    README.md: Project documentation.

### ⚙️ Build and Run
##### Prerequisites

    A GPU that supports OpenGL 4.0+ and FP64 instructions.
    Raylib installed.

Compilation (Linux/GCC)
bash

g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o mandelbrot
./mandelbrot
