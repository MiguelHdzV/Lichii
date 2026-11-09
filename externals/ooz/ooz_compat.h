// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later

// Portable replacement for ooz's Windows stdafx.h (x86-64 only: the decoder uses SSE2).
#pragma once

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

namespace ooz {
typedef unsigned char byte;
typedef unsigned char uint8;
typedef unsigned int uint32;
typedef uint64_t uint64;
typedef int64_t int64;
typedef signed int int32;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned int uint;
} // namespace ooz

#if !defined(_MSC_VER)
#define __forceinline inline __attribute__((always_inline))
#define __int64 long long
static inline unsigned char _BitScanReverse(unsigned long* index, unsigned long mask) {
    if (!mask) {
        return 0;
    }
    *index = 31 - __builtin_clz(static_cast<unsigned>(mask));
    return 1;
}
static inline unsigned char _BitScanForward(unsigned long* index, unsigned long mask) {
    if (!mask) {
        return 0;
    }
    *index = __builtin_ctz(static_cast<unsigned>(mask));
    return 1;
}
#ifndef _byteswap_ulong
#define _byteswap_ulong __builtin_bswap32
#endif
#ifndef _byteswap_uint64
#define _byteswap_uint64 __builtin_bswap64
#endif
#ifndef _byteswap_ushort
#define _byteswap_ushort __builtin_bswap16
#endif
#ifndef _rotl
#define _rotl(v, s) __builtin_rotateleft32((v), (s))
#endif
#endif
