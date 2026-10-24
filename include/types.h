#pragma once

// Fixed-width integer types.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

// Three fixed-point components (12 fractional bits).
typedef struct Vec3 {
    /* 0 */ s32 x;
    /* 4 */ s32 y;
    /* 8 */ s32 z;
} Vec3;
