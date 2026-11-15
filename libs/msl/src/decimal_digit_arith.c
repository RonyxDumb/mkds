#pragma avoid_byte all
#pragma dont_reuse_strings off

#include "decimal_digit_arith.h"
#include "text_to_number.h"

// Compares the byte strings a and b, mapping each byte below 0x80 through gLowerCaseMap first: -1 or 1 at the first
// difference, 0 when both end together.
int StrcmpMapped(const char *firstString, const char *secondString) {
    int charCode;
    u8 firstChar;
    u8 secondChar;

    for (;;) {
        charCode = *firstString++;
        firstChar = (charCode < 0 || charCode >= 0x80) ? charCode : gLowerCaseMap[charCode];
        charCode = *secondString++;
        secondChar = (charCode < 0 || charCode >= 0x80) ? charCode : gLowerCaseMap[charCode];
        if (firstChar < secondChar) {
            return -1;
        }
        if (firstChar > secondChar) {
            return 1;
        }
        if (firstChar == 0) {
            return 0;
        }
    }
}

int CompareStringsMapped(const char *firstString, const char *secondString) {
    return StrcmpMapped(firstString, secondString);
}

// Number of 0 bits below the lowest 1 bit of a, its bytes read from the lowest address up; 32 when a is 0.
int CountLowZeroBits(u32 value) {
    u8 *bytePointer;
    int count;

    if (value != 0) {
        bytePointer = (u8 *) &value;
        count = 0;
        while (*bytePointer == 0) {
            bytePointer++;
            count += 8;
        }
        *bytePointer = ~*bytePointer;
        while (*bytePointer & 1) {
            *bytePointer >>= 1;
            count++;
        }
        return count;
    }
    return 32;
}

// Compares the digits from index n on with 5 followed by 0s: 1 when above, -1 when below; when equal, 1 if the digit
// before index n is odd, else -1.
int DigitsRoundCompare(const DigitRecord *digitRecord, int digitIndex) {
    const char *digitPointer;
    const char *end;
    u8 digit;

    digitPointer = digitRecord->mDigits + digitIndex;
    digit = digitRecord->mDigits[digitIndex];
    if (digit > 5) {
        return 1;
    }
    if (digit < 5) {
        return -1;
    }
    end = digitRecord->mDigits + digitRecord->mDigitCount;
    for (digitPointer++; digitPointer < end; digitPointer++) {
        if (*digitPointer != 0) {
            return 1;
        }
    }
    if (digitRecord->mDigits[digitIndex - 1] & 1) {
        return 1;
    }
    return -1;
}

// Adds 1 to the digit at index n - 1, carrying into the digits before it; a carry out of the first digit sets it to 1
// and adds 1 to mUnk_02.
void DigitsIncrement(DigitRecord *digitRecord, int digitCount) {
    char *base;
    char *digitPointer;

    base = digitRecord->mDigits;
    digitPointer = base + digitCount - 1;
    for (;;) {
        if (*digitPointer < 9) {
            (*digitPointer)++;
            return;
        }
        if (digitPointer == base) {
            *digitPointer = 1;
            digitRecord->mExponent++;
            return;
        }
        *digitPointer-- = 0;
    }
}

// For 0 < n < mUnk_04: keeps the first n digits and adds 1 to the last one (DigitsIncrement) when DigitsRoundCompare is
// not negative.
void DigitsRoundTo(DigitRecord *digitRecord, int digitCount) {
    int comparison;

    if (digitCount <= 0) {
        return;
    }
    if (digitCount >= digitRecord->mDigitCount) {
        return;
    }
    comparison = DigitsRoundCompare(digitRecord, digitCount);
    digitRecord->mDigitCount = digitCount;
    if (comparison < 0) {
        return;
    }
    DigitsIncrement(digitRecord, digitCount);
}

// Writes the decimal digits of v, most significant first, with mUnk_02 = digit count - 1.
void DigitsFromU64(DigitRecord *out, u64 value) {
    char *leftDigit;
    char *rightDigit;
    u8 swapDigit;

    out->mNegative = 0;
    out->mDigitCount = 0;
    while (value != 0) {
        out->mDigits[out->mDigitCount++] = value % 10;
        value /= 10;
    }
    for (leftDigit = out->mDigits, rightDigit = leftDigit + out->mDigitCount - 1; leftDigit < rightDigit;
         leftDigit++, rightDigit--) {
        swapDigit = *leftDigit;
        *leftDigit = *rightDigit;
        *rightDigit = swapDigit;
    }
    out->mExponent = out->mDigitCount - 1;
}

// Multiplies the digits of a and b (mUnk_02 = the sum of theirs), keeps the first 32 and adds 1 to the last kept one
// (DigitsIncrement) when the digits after them are above 5 followed by 0s, or equal to it and the last kept digit is
// odd.
void DigitsMultiply(DigitRecord *out, const DigitRecord *firstRecord, const DigitRecord *secondRecord) {
    char buf[64];
    int firstIndex;
    u32 carry;
    int columnIndex;
    char *resultPointer;
    char *end;
    int secondIndex;
    int termCount;
    const char *pa;
    const char *pb;

    carry = 0;
    columnIndex = firstRecord->mDigitCount + secondRecord->mDigitCount - 1;
    resultPointer = buf + columnIndex + 1;
    end = resultPointer;
    out->mNegative = 0;
    while (columnIndex > 0) {
        secondIndex = secondRecord->mDigitCount - 1;
        firstIndex = columnIndex - secondIndex - 1;
        if (firstIndex < 0) {
            firstIndex = 0;
            secondIndex = columnIndex - 1;
        }
        pa = firstRecord->mDigits + firstIndex;
        pb = secondRecord->mDigits + secondIndex;
        termCount = secondIndex + 1;
        if (termCount > firstRecord->mDigitCount - firstIndex) {
            termCount = firstRecord->mDigitCount - firstIndex;
        }
        for (; termCount > 0; termCount--, pa++, pb--) {
            carry += *pa * *pb;
        }
        *--resultPointer = carry % 10;
        carry /= 10;
        columnIndex--;
    }
    out->mExponent = firstRecord->mExponent + secondRecord->mExponent;
    if (carry != 0) {
        *--resultPointer = carry;
        out->mExponent++;
    }
    for (columnIndex = 0; columnIndex < 32 && resultPointer < end; columnIndex++, resultPointer++) {
        out->mDigits[columnIndex] = *resultPointer;
    }
    out->mDigitCount = columnIndex;
    if (resultPointer >= end) {
        return;
    }
    if (*resultPointer < 5) {
        return;
    }
    if (*resultPointer == 5) {
        for (pa = resultPointer + 1; pa < end; pa++) {
            if (*pa != 0) {
                goto round;
            }
        }
        if (!(resultPointer[-1] & 1)) {
            return;
        }
    }
round:
    DigitsIncrement(out, out->mDigitCount);
}

// Reads up to 32 digit characters of s into out with mUnk_02 = n. Then adds 1 to the last digit (DigitsIncrement) when
// the next byte is above 5, or is 5 with only '0' bytes after it and the last digit odd.
void DigitsFromString(DigitRecord *out, const char *text, int exponent) {
    int digitIndex;
    const char *scanPointer;

    out->mExponent = exponent;
    out->mNegative = 0;
    for (digitIndex = 0; digitIndex < 32 && *text != 0; digitIndex++) {
        out->mDigits[digitIndex] = *text++ - '0';
    }
    out->mDigitCount = digitIndex;
    if (*text == 0) {
        return;
    }
    if (*text < 5) {
        return;
    }
    if (*text <= 5) {
        for (scanPointer = text + 1; *scanPointer != 0; scanPointer++) {
            if (*scanPointer != '0') {
                goto round;
            }
        }
        if (!(out->mDigits[digitIndex - 1] & 1)) {
            return;
        }
    }
round:
    DigitsIncrement(out, out->mDigitCount);
}

// For n of -64, -53, -32, -16 and -8 to 8, passes a digit string and a count to DigitsFromString. Otherwise calls
// itself for n / 2 (the sign bit added by hand) and combines the result with itself through DigitsMultiply, then with a
// one-digit string when n is odd.
void DigitsPowerOfTwo(DigitRecord *out, int power) {
    DigitRecord halfPower;
    DigitRecord savedResult;

    switch (power) {
        case -64:
            DigitsFromString(out, "542101086242752217003726400434970855712890625", -20);
            return;
        case -53:
            DigitsFromString(out, "11102230246251565404236316680908203125", -16);
            return;
        case -32:
            DigitsFromString(out, "23283064365386962890625", -10);
            return;
        case -16:
            DigitsFromString(out, "152587890625", -5);
            return;
        case -8:
            DigitsFromString(out, "390625", -3);
            return;
        case -7:
            DigitsFromString(out, "78125", -3);
            return;
        case -6:
            DigitsFromString(out, "15625", -2);
            return;
        case -5:
            DigitsFromString(out, "3125", -2);
            return;
        case -4:
            DigitsFromString(out, "625", -2);
            return;
        case -3:
            DigitsFromString(out, "125", -1);
            return;
        case -2:
            DigitsFromString(out, "25", -1);
            return;
        case -1:
            DigitsFromString(out, "5", -1);
            return;
        case 0:
            DigitsFromString(out, "1", 0);
            return;
        case 1:
            DigitsFromString(out, "2", 0);
            return;
        case 2:
            DigitsFromString(out, "4", 0);
            return;
        case 3:
            DigitsFromString(out, "8", 0);
            return;
        case 4:
            DigitsFromString(out, "16", 1);
            return;
        case 5:
            DigitsFromString(out, "32", 1);
            return;
        case 6:
            DigitsFromString(out, "64", 1);
            return;
        case 7:
            DigitsFromString(out, "128", 2);
            return;
        case 8:
            DigitsFromString(out, "256", 2);
            return;
    }
    DigitsPowerOfTwo(&halfPower, (power + (int) ((u32) (power & 0x80000000) >> 31)) >> 1);
    DigitsMultiply(out, &halfPower, &halfPower);
    if (power & 1) {
        savedResult = *out;
        if (power > 0) {
            DigitsFromString(&halfPower, "2", 0);
        } else {
            DigitsFromString(&halfPower, "5", -1);
        }
        DigitsMultiply(out, &savedResult, &halfPower);
    }
}
