#pragma once

#ifdef EN_ENABLE_ASSERTS
#if EN_PLATFORM_WINDOWS
#define EN_ASSERT(x, ...) { if(!(x)) {EN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#define EN_CORE_ASSERT(x, ...) { if(!(x)) { EN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#elif EN_PLATFORM_LINUX
#define EN_ASSERT(x, ...) { if(!(x)) {EN_ERROR("Assertion Failed: {0}", __VA_ARGS__); EMBED_BREAKPOINT; }}
#define EN_CORE_ASSERT(x, ...) { if(!(x)) { EN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); EMBED_BREAKPOINT;}}
#endif

#endif


#define BIT(x) (1 << x)