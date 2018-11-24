#pragma once

#include "endianness.h"

#ifdef _WIN32
#define NOMINMAX // want std::min() & std::max() defined...
#include <windows.h>

#ifdef _MSC_VER // Visual Studio will complain for linking...
#pragma comment(lib, "WinMM") // for timeGetTime()
#endif

#else
#include <unistd.h> // sysctl, sysconf
#include <sys/time.h> // for timeGetTime()
#endif

#ifdef __APPLE__
#include <libkern/OSAtomic.h>
#endif // atomics

// Clang defines __has_feature
#ifndef __has_feature
#define __has_feature(x) 0
#endif // __has_feature


using uint8_t = unsigned char;
using uint16_t = unsigned short;
using uint32_t = unsigned int;
using int32_t = int;

#define INT32_C(x) (x)

// Assert an expression and return if false
#define ASSERT(exp)                          \
    if (!(exp)) { }

#define assert(exp)                          \
    if (!(exp)) { }

// Assert an expression and return the error if false
#define ASSERT_ERR(exp, err)                 \
    if (!(exp))                              \
        return err



#define SAFEDELETE(x) (delete[] x, x = nullptr)

#define PROHIBIT_COPY(__class)                   \
    private:                                        \
        __class(const __class&);                    \
        __class& operator=(const __class&)


static const char STR_SYSTEM_NAME[] = "SYSTEM";
static const char STR_ALLUSERS_NAME[] = "ALLUSERS";
static const char STR_REPLY_OK[] = "ANSWER_OK";
static const char STR_REPLY_AGAIN[] = "ANSWER_AGAIN";
static const char STR_REPLY_NEW_ROLE[] = "NEW_ROLE";