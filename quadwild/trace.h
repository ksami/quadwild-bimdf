#pragma once
#include <string>
#include <tracing/mesh_type.h>

extern "C" __declspec(dllexport) bool trace2(const char *filename_prefix);

bool trace(const std::string& filename_prefix, TraceMesh& traceTrimesh);
