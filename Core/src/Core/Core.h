#pragma once

#if defined(__linux__)
    #ifdef APP_BUILD_DLL
        #define APPLICATION_API __attribute__((visibility("default")))
    #else
        #define APPLICATION_API
    #endif
#elif defined(_WIN32)
    #ifdef APP_BUILD_DLL
        #define APPLICATION_API __declspec(dllexport)
    #else
        #define APPLICATION_API __declspec(dllimport)
    #endif
#else
    #error App only supports Windows and Linux
#endif

#define BIT(x) (1 << x)
