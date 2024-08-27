/*
 *   Copyright (c) 2022 HiPeRT SRL
 *   All rights reserved.
 */
#pragma once
// visit: https://eigen.tuxfamily.org/dox/TopicPreprocessorDirectives.html

// if defined, any request from inside the Eigen to allocate memory from the heap results in an
// assertion failure. This is useful to check that some routine does not allocate memory
// dynamically. Not defined by default.
// #define EIGEN_NO_MALLOC 1

// Must be a power of two, or 0. Defines an upper bound on the memory boundary in bytes on which
// dynamically and statically allocated data may be aligned by Eigen. If not defined, a default
// value is automatically computed based on architecture, compiler, and OS. This option is typically
// used to enforce binary compatibility between code/libraries compiled with different SIMD options.
// For instance, one may compile AVX code and enforce ABI compatibility with existing SSE code by
// defining EIGEN_MAX_ALIGN_BYTES=16. In the other way round, since by default AVX implies 32 bytes
// alignment for best performance, one can compile SSE code to be ABI compatible with AVX code by
// defining EIGEN_MAX_ALIGN_BYTES=32.
// #define EIGEN_MAX_ALIGN_BYTES 0

// isables/enables vectorization with unaligned stores. Default is 1 (enabled). If set to 0
// (disabled), then expression for which the destination cannot be aligned are not vectorized (e.g.,
// unaligned small fixed size vectors or matrices)
#define EIGEN_UNALIGNED_VECTORIZE 1

// defines the maximum bytes for a buffer to be allocated on the stack. For internal temporary
// buffers, dynamic memory allocation is employed as a fall back. For fixed-size matrices or arrays,
// exceeding this threshold raises a compile time assertion. Use 0 to set no limit. Default is 128
// KB.
#define EIGEN_STACK_ALLOCATION_LIMIT 10485760 // 10mb

#include <Eigen/Dense>
