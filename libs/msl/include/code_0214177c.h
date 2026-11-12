#pragma once

#include "types.h"
#include "code_0213ee6c.h" // DigitRecord


void DigitsPowerOfTwo(DigitRecord *out, int power);
void DigitsFromString(DigitRecord *out, const char *text, int exponent);
void DigitsMultiply(DigitRecord *out, const DigitRecord *firstRecord, const DigitRecord *secondRecord);
void DigitsFromU64(DigitRecord *out, u64 value);
void DigitsRoundTo(DigitRecord *digitRecord, int digitCount);
void DigitsIncrement(DigitRecord *digitRecord, int digitCount);
int DigitsRoundCompare(const DigitRecord *digitRecord, int digitIndex);
int CountLowZeroBits(u32 value);
int CompareStringsMapped(const char *firstString, const char *secondString);
int StrcmpMapped(const char *firstString, const char *secondString);
