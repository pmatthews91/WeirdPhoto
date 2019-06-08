#pragma once

extern "C" _declspec(dllexport) void generate_image(const char* filename, int renderType);
extern "C" _declspec(dllexport) void generate_video(int renderType);