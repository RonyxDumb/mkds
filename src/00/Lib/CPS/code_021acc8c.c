#include "00/Lib/CPS/code_021acc8c.h"
#include "00/Lib/CPS/code_021acec8.h"
#include "code_0214d018.h"

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
    s32 i;
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
    for (i = 0; i < firstDigits; i++) {
        digitSum = first[i] + second[i] + carry;
        sum[i] = digitSum;
        carry = digitSum >> 16;
    }
    if (sum != first && sum != second) {
        MI_CpuFill8(sum + i, 0, (digitCount - i) * 2);
    }
}

void CPSi_big_add_small(u16 *result, const u16 *value, u32 carry, s32 digitCount) {
    s32 i;

    for (i = 0; i < digitCount; i++) {
        carry += value[i];
        result[i] = carry;
        carry >>= 16;
        if (carry == 0) {
            break;
        }
    }
    if (result != value) {
        for (i++; i < digitCount; i++) {
            result[i] = value[i];
        }
    }
}

void CPSi_big_negate(u16 *digits, s32 digitCount) {
    s32 i;

    for (i = 0; i < digitCount; i++) {
        digits[i] = ~digits[i];
    }
    CPSi_big_add_small(digits, digits, 1, digitCount);
}

void CPSi_big_sub(u16 *difference, const u16 *minuend, const u16 *subtrahend, s32 digitCount) {
    s32 minuendDigits;
    s32 subtrahendDigits;
    s32 i;
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
    for (i = 0; i < minuendDigits || (i < digitCount && borrow != 0); i++) {
        digitDifference = minuend[i] - subtrahend[i] + borrow;
        difference[i] = digitDifference;
        borrow = digitDifference >> 16;
    }
    if (difference != minuend && difference != subtrahend) {
        MI_CpuFill8(difference + i, 0, (digitCount - i) * 2);
    }
}

void CPSi_big_sub_small(u16 *result, const u16 *value, u32 borrow, s32 digitCount) {
    s32 i;

    for (i = 0; i < digitCount; i++) {
        borrow = value[i] - borrow;
        result[i] = borrow;
        borrow = (borrow >> 16) & 1;
        if (borrow == 0) {
            break;
        }
    }
    if (result != value) {
        for (i++; i < digitCount; i++) {
            result[i] = value[i];
        }
    }
}

s32 CPSi_big_compare(const u16 *first, const u16 *second, s32 digitCount) {
    s32 i;

    for (i = digitCount - 1; i >= 0; i--) {
        if (first[i] > second[i]) {
            return 1;
        }
        if (first[i] < second[i]) {
            return -1;
        }
    }
    return 0;
}
