#pragma once
#include <string>
#include <tracing/mesh_type.h>

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

extern "C" EXPORT bool trace2(const char *filename_prefix);

bool trace(const std::string& filename_prefix, TraceMesh& traceTrimesh);
