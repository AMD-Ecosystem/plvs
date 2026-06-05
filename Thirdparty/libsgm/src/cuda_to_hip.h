/*
 * CUDA to HIP compatibility header for libsgm
 * This header provides aliases so CUDA code compiles unchanged on HIP.
 */

#pragma once

#if defined(USE_HIP) || defined(__HIP_PLATFORM_AMD__)

#include <hip/hip_runtime.h>

// Runtime API - streams and events
#define cudaStream_t                    hipStream_t
#define cudaEvent_t                     hipEvent_t
#define cudaStreamCreate                hipStreamCreate
#define cudaStreamDestroy               hipStreamDestroy
#define cudaStreamSynchronize           hipStreamSynchronize
#define cudaStreamWaitEvent             hipStreamWaitEvent
#define cudaEventCreate                 hipEventCreate
#define cudaEventDestroy                hipEventDestroy
#define cudaEventRecord                 hipEventRecord

// Error handling
#define cudaError_t                     hipError_t
#define cudaSuccess                     hipSuccess
#define cudaGetLastError                hipGetLastError
#define cudaGetErrorString              hipGetErrorString

// Memory
#define cudaMalloc                      hipMalloc
#define cudaFree                        hipFree
#define cudaMemcpy                      hipMemcpy
#define cudaMemset                      hipMemset
#define cudaMemcpyHostToDevice          hipMemcpyHostToDevice
#define cudaMemcpyDeviceToHost          hipMemcpyDeviceToHost
#define cudaMemcpyDeviceToDevice        hipMemcpyDeviceToDevice

// For CUDA_VERSION checks, HIP uses HIP_VERSION which is structured differently.
// Define CUDA_VERSION as >= 9000 for sync shuffle semantics on HIP.
#ifndef CUDA_VERSION
#define CUDA_VERSION 11000
#endif

// Helper macro for error checking
#ifndef CudaSafeCall
#define CudaSafeCall(err) do { \
    hipError_t _err = (err); \
    if (_err != hipSuccess) { \
        printf("HIP error at %s:%d: %s\n", __FILE__, __LINE__, hipGetErrorString(_err)); \
    } \
} while(0)
#endif

#else

#include <cuda_runtime.h>

#ifndef CudaSafeCall
#define CudaSafeCall(err) do { \
    cudaError_t _err = (err); \
    if (_err != cudaSuccess) { \
        printf("CUDA error at %s:%d: %s\n", __FILE__, __LINE__, cudaGetErrorString(_err)); \
    } \
} while(0)
#endif

#endif
