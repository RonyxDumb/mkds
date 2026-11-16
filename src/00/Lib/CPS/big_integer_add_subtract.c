#include "00/Lib/CPS/big_integer_add_subtract.h"
#include "00/Lib/CPS/big_integer_digit_count.h"
#include "cpu_copy_fill.h"

s32 CPSi_big_sign(const u16 *digits, s32 digitCount) {
    if (digits[digitCount - 1] & 0x8000) {
        return -1;
    }
    if (count_digits(digits, digitCount) != 0) {
        return 1;
    }
    return 0;
}

void CPSi_big_add(u16 *sum, const u16 *first, const u16 *second, s32 digitCount) {
    s32 firstDigits;
    s32 secondDigits;
    s32 digitIndex;
    u32 digitSum;
    u32 carry;

    firstDigits = count_digits(first, digitCount);
    secondDigits = count_digits(second, digitCount);
    if (firstDigits < secondDigits) {
        firstDigits = secondDigits;
    }
    if (firstDigits != digitCount) {
        firstDigits++;
    }
    carry = 0;
    for (digitIndex = 0; digitIndex < firstDigits; digitIndex++) {
        digitSum = first[digitIndex] + second[digitIndex] + carry;
        sum[digitIndex] = digitSum;
        carry = digitSum >> 16;
    }
    if (sum != first && sum != second) {
        Mem_CpuFill8(sum + digitIndex, 0, (digitCount - digitIndex) * 2);
    }
}

void CPSi_big_add_small(u16 *result, const u16 *value, u32 carry, s32 digitCount) {
    s32 digitIndex;

    for (digitIndex = 0; digitIndex < digitCount; digitIndex++) {
        carry += value[digitIndex];
        result[digitIndex] = carry;
        carry >>= 16;
        if (carry == 0) {
            break;
        }
    }
    if (result != value) {
        for (digitIndex++; digitIndex < digitCount; digitIndex++) {
            result[digitIndex] = value[digitIndex];
        }
    }
}

void CPSi_big_negate(u16 *digits, s32 digitCount) {
    s32 digitIndex;

    for (digitIndex = 0; digitIndex < digitCount; digitIndex++) {
        digits[digitIndex] = ~digits[digitIndex];
    }
    CPSi_big_add_small(digits, digits, 1, digitCount);
}

void CPSi_big_sub(u16 *difference, const u16 *minuend, const u16 *subtrahend, s32 digitCount) {
    s32 minuendDigits;
    s32 subtrahendDigits;
    s32 digitIndex;
    s32 digitDifference;
    s32 borrow;

    minuendDigits = count_digits(minuend, digitCount);
    subtrahendDigits = count_digits(subtrahend, digitCount);
    if (minuendDigits < subtrahendDigits) {
        minuendDigits = subtrahendDigits;
    }
    if (minuendDigits != digitCount) {
        minuendDigits++;
    }
    borrow = 0;
    for (digitIndex = 0; digitIndex < minuendDigits || (digitIndex < digitCount && borrow != 0); digitIndex++) {
        digitDifference = minuend[digitIndex] - subtrahend[digitIndex] + borrow;
        difference[digitIndex] = digitDifference;
        borrow = digitDifference >> 16;
    }
    if (difference != minuend && difference != subtrahend) {
        Mem_CpuFill8(difference + digitIndex, 0, (digitCount - digitIndex) * 2);
    }
}

void CPSi_big_sub_small(u16 *result, const u16 *value, u32 borrow, s32 digitCount) {
    s32 digitIndex;

    for (digitIndex = 0; digitIndex < digitCount; digitIndex++) {
        borrow = value[digitIndex] - borrow;
        result[digitIndex] = borrow;
        borrow = (borrow >> 16) & 1;
        if (borrow == 0) {
            break;
        }
    }
    if (result != value) {
        for (digitIndex++; digitIndex < digitCount; digitIndex++) {
            result[digitIndex] = value[digitIndex];
        }
    }
}

s32 CPSi_big_compare(const u16 *first, const u16 *second, s32 digitCount) {
    s32 digitIndex;

    for (digitIndex = digitCount - 1; digitIndex >= 0; digitIndex--) {
        if (first[digitIndex] > second[digitIndex]) {
            return 1;
        }
        if (first[digitIndex] < second[digitIndex]) {
            return -1;
        }
    }
    return 0;
}
