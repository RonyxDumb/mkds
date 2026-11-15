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

#ifndef NULL
    #define NULL ((void *) 0)
#endif

// A 0/1 flag; the same as s32 here, so only code already typed s32 uses it.
typedef s32 BOOL;
#define TRUE 1
#define FALSE 0

// Whole number to fixed-point and back (12 fraction bits).
#define TO_FIXED12(x) ((x) << 12)
#define FROM_FIXED12(x) ((x) >> 12)
// A positive fraction num/den as fixed-point, rounded to the nearest step (negate it for a negative one).
#define FIXED12_RATIO(num, den) ((s32) ((((num) * 0x2000) + (den)) / ((den) * 2)))

#define MUL_FIXED12_ROUNDED(a, b) ((s32) (((s64) (a) * (b) + 0x800) >> 12))
#define MUL_FIXED12_NO_ROUND(a, b) ((s32) (((s64) (a) * (b)) >> 12))
#define MUL_FIXED24_NO_ROUND(a, b) ((s32) (((s64) (a) * (b)) >> 24))

// Sum of two, three or four fixed-point products, shifted down to 12 fractional bits.
#define DOT2_FIXED12(a0, b0, a1, b1) (((s64) (a0) * (b0) + (s64) (a1) * (b1)) >> 12)
#define DOT3_FIXED12(a0, b0, a1, b1, a2, b2) (((s64) (a0) * (b0) + (s64) (a1) * (b1) + (s64) (a2) * (b2)) >> 12)
#define DOT4_FIXED12(a0, b0, a1, b1, a2, b2, a3, b3)                                                                   \
    (((s64) (a0) * (b0) + (s64) (a1) * (b1) + (s64) (a2) * (b2) + (s64) (a3) * (b3)) >> 12)
// The same sums, rounded.
#define DOT2_FIXED12_ROUNDED(a0, b0, a1, b1) (((s64) (a0) * (b0) + (s64) (a1) * (b1) + 0x800) >> 12)
#define DOT3_FIXED12_ROUNDED(a0, b0, a1, b1, a2, b2)                                                                   \
    (((s64) (a0) * (b0) + (s64) (a1) * (b1) + (s64) (a2) * (b2) + 0x800) >> 12)
// Difference of two fixed-point products (one component of a cross product), shifted down to 12 fractional bits.
#define CROSS2_FIXED12(a0, b0, a1, b1) (((s64) (a0) * (b0) - (s64) (a1) * (b1)) >> 12)
// The same difference, rounded.
#define CROSS2_FIXED12_ROUNDED(a0, b0, a1, b1) (((s64) (a0) * (b0) - (s64) (a1) * (b1) + 0x800) >> 12)

// Degrees (fx32) to a 16-bit angle, rounded.
#define DEG_TO_ANGLE(deg) ((u16) (((s64) (deg) * 0xb60b60b60bLL + 0x80000000000LL) >> 44))
// Degrees (fx32) to a 16-bit angle, truncated (rounds differently from DEG_TO_ANGLE).
#define DEG_TO_ANGLE_TRUNCATED(deg) ((u16) ((s32) (((s64) (deg) * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12))
// Sine and cosine fx32 of a 16-bit angle, read from the sine table.
#define SIN_OF_ANGLE(angle) FX_SinCosTable_[((angle) >> 4) * 2]
#define COS_OF_ANGLE(angle) FX_SinCosTable_[((angle) >> 4) * 2 + 1]
// Sum of the squares of two or three values, as s64.
#define SQUARE_SUM2(a, b) ((s64) (a) * (a) + (s64) (b) * (b))
#define SQUARE_SUM3(a, b, c) ((s64) (a) * (a) + (s64) (b) * (b) + (s64) (c) * (c))
#define LENGTH_SQUARED(v) ((s64) (v).x * (v).x + (s64) (v).y * (v).y + (s64) (v).z * (v).z)
#define HORIZONTAL_LENGTH_SQUARED(v) ((s64) (v).x * (v).x + (s64) (v).z * (v).z)

// Test, set or clear bit n of v.
#define BIT_IS_SET(v, n) (((v) & (1 << (n))) != 0)
#define BIT_SET(v, n) ((v) |= 1 << (n))
#define BIT_CLEAR(v, n) ((v) &= ~(1 << (n)))

// Milliseconds of a lap or race time given in minutes, seconds and milliseconds.
#define TIME_TO_MS(min, sec, ms) ((sec) * 1000 + (min) * 60000 + (ms))

// Absolute value of a plain variable (x is evaluated twice).
#define ABS(x) ((x) < 0 ? -(x) : (x))

// Pointer to the T that starts OFFSET bytes after BASE (offsets read from file data and headers).
#define OFFSET_PTR(T, base, offset) ((T *) ((u8 *) (base) + (offset)))

// Three fixed-point components (12 fractional bits).
typedef struct Vec3 {
    /* 0 */ s32 x;
    /* 4 */ s32 y;
    /* 8 */ s32 z;
} Vec3;

// Four fixed-point components (12 fractional bits).
typedef struct Vec4 {
    /* 0 */ s32 x;
    /* 4 */ s32 y;
    /* 8 */ s32 z;
    /* c */ s32 w;
} Vec4;
