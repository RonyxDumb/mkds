#pragma once

#include "types.h"

// Most digits a DigitRecord holds.
#define DIGIT_RECORD_MAX_DIGITS 32

// High word of a double: the exponent bits (all set for infinity and NaN) and the top mantissa bits.
#define DOUBLE_EXPONENT_MASK 0x7ff00000
#define DOUBLE_HIGH_MANTISSA_MASK 0xfffff

// 0x26 bytes. Filled by DoubleToDigitChars (which caps mDigitCount at 32) and DigitsFromString (at most 32 bytes);
// mDigitCount counts the bytes used in mDigits. Read by FormatRoundDigitChars, FormatWideRoundDigitChars and
// DigitCharsToDouble (DigitCharsToDouble copies it as a whole).
typedef struct DigitRecord {
    /* 00 */ u8 mNegative;
    /* 01 */ u8 mUnk_01;
    /* 02 */ s16 mExponent;
    /* 04 */ u8 mDigitCount;
    /* 05 */ char mDigits[DIGIT_RECORD_MAX_DIGITS];
} DigitRecord;

// First argument of DoubleToDigitChars (reads mDigitCount).
typedef struct DigitOptions {
    /* 00 */ u8 mUnk_00;
    /* 02 */ s16 mDigitCount;
} DigitOptions;

// Read as a float by DigitCharsToDouble.
extern float gFloatInfinity;
// Read as a float by PowBody and nan.
extern float gFloatQuietNan;

// Two doubles each, indexed 0/1 by PowBody.
extern const double gPowLogAdjustHigh[2];
extern const double gPowBreakpoint[2];
extern const double gPowLogAdjustLow[2];
// Indexed 0-7 by DigitCharsToDouble.
extern double gPowersOfTen[];

double PowBody(double base, double power);
double copysign(double magnitude, double sign);
double fabs(double value);
double frexp(double value, int *exponentOut);
double ldexp(double value, int exponentDelta);
double pow(double base, double power);
double DigitCharsToDouble(const DigitRecord *record);
void DoubleToDigitChars(DigitOptions *options, double value, DigitRecord *record);
void DoubleToDigits(DigitRecord *out, double value);
void DigitsSubtract(DigitRecord *result, const DigitRecord *minuend, const DigitRecord *subtrahend);
int DigitsLess(const DigitRecord *left, const DigitRecord *right);
int DigitsEqual(const DigitRecord *left, const DigitRecord *right);
