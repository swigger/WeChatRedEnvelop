#pragma once
#include <stdint.h>

#ifdef __cplusplus
#define extc extern "C"
#else
#define extc
#endif

extc int64_t GetTickCount64b();
