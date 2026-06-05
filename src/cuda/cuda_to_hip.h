/*
 * CUDA to HIP compatibility header for PLVS
 * This header provides aliases so CUDA code compiles unchanged on HIP.
 * On CUDA builds, it includes cuda_runtime.h and is otherwise a no-op.
 */

#pragma once

#if defined(USE_HIP) || defined(__HIP_PLATFORM_AMD__)

#include <hip/hip_runtime.h>

// Runtime API
#define cudaMalloc                      hipMalloc
#define cudaMallocManaged               hipMallocManaged
#define cudaFree                        hipFree
#define cudaMemcpy                      hipMemcpy
#define cudaMemcpyAsync                 hipMemcpyAsync
#define cudaMemcpyToSymbol              hipMemcpyToSymbol
#define cudaMemcpyHostToDevice          hipMemcpyHostToDevice
#define cudaMemcpyDeviceToHost          hipMemcpyDeviceToHost
#define cudaMemcpyDeviceToDevice        hipMemcpyDeviceToDevice
#define cudaMemset                      hipMemset
#define cudaMemsetAsync                 hipMemsetAsync

// Streams
#define cudaStream_t                    hipStream_t
#define cudaStreamCreate                hipStreamCreate
#define cudaStreamDestroy               hipStreamDestroy
#define cudaStreamSynchronize           hipStreamSynchronize
#define cudaStreamAttachMemAsync        hipStreamAttachMemAsync

// Device synchronization
#define cudaDeviceSynchronize           hipDeviceSynchronize
#define cudaGetLastError                hipGetLastError

// Error types
#define cudaError_t                     hipError_t
#define cudaSuccess                     hipSuccess
#define cudaGetErrorString              hipGetErrorString

// Memory attach flags
#define cudaMemAttachGlobal             hipMemAttachGlobal

#else

#include <cuda_runtime.h>

#endif
