#include "double_square_root.h"
#pragma avoid_byte all

#include "double_digits_math_functions.h"
#include "file_write_flush.h"
#include "text_to_number.h"
#include "decimal_digit_arith_string_compare.h"
#include "float_trap_dispatch.h"

double gPowersOfTen[8] = {10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0, 100000000.0};
const double gPowBreakpoint[2] = {1.0, 1.5};
const double gPowLogAdjustLow[2] = {0.0, 1.350039202129749e-08};
const double gPowLogAdjustHigh[2] = {0.0, 0.5849624872207642};

// 1 when left and right are equal.
int DigitsEqual(const DigitRecord *left, const DigitRecord *right) {
    int digitIndex;
    int commonCount;
    int la;
    int lb;

    if (left->mDigits[0] == 0) {
        return right->mDigits[0] == 0;
    }
    if (right->mDigits[0] == 0) {
        return left->mDigits[0] == 0;
    }
    if (left->mExponent == right->mExponent) {
        la = left->mDigitCount;
        commonCount = la;
        lb = right->mDigitCount;
        digitIndex = 0;
        if (la > lb) {
            commonCount = lb;
        }
        for (; digitIndex < commonCount; digitIndex++) {
            if (left->mDigits[digitIndex] != right->mDigits[digitIndex]) {
                return 0;
            }
        }
        if (commonCount == la) {
            left = right;
        }
        for (; digitIndex < left->mDigitCount; digitIndex++) {
            if (left->mDigits[digitIndex] != 0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// 1 when left is less than right.
int DigitsLess(const DigitRecord *left, const DigitRecord *right) {
    int digitIndex;
    int commonCount;
    int la;
    int lb;
    u32 rightDigit;
    u32 leftDigit;

    if (left->mDigits[0] == 0) {
        return right->mDigits[0] != 0;
    }
    if (right->mDigits[0] == 0) {
        return 0;
    }
    if (left->mExponent == right->mExponent) {
        la = left->mDigitCount;
        commonCount = la;
        lb = right->mDigitCount;
        digitIndex = 0;
        if (la > lb) {
            commonCount = lb;
        }
        for (; digitIndex < commonCount; digitIndex++) {
            rightDigit = right->mDigits[digitIndex];
            leftDigit = left->mDigits[digitIndex];
            if (leftDigit < rightDigit) {
                return 1;
            }
            if (rightDigit < leftDigit) {
                return 0;
            }
        }
        if (commonCount == la) {
            for (; digitIndex < right->mDigitCount; digitIndex++) {
                if (right->mDigits[digitIndex] != 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return left->mExponent < right->mExponent;
}

// Copies minuend to result and subtracts subtrahend from it.
void DigitsSubtract(DigitRecord *result, const DigitRecord *minuend, const DigitRecord *subtrahend) {
    int digitCount;
    int length;
    int shift;
    char *resultDigits;
    char *resultEnd;
    const char *subDigits;
    const char *subCursor;
    const char *subEnd;
    int consumed;
    char *borrowCursor;
    const char *subTail;
    int roundDown;

    *result = *minuend;
    if (subtrahend->mDigits[0] == 0) {
        return;
    }
    digitCount = result->mDigitCount;
    length = digitCount;
    if (digitCount < subtrahend->mDigitCount) {
        length = subtrahend->mDigitCount;
    }
    shift = result->mExponent - subtrahend->mExponent;
    length += shift;
    if (length > 32) {
        length = 32;
    }
    if (digitCount < length) {
        do {
            result->mDigitCount++;
            result->mDigits[digitCount] = 0;
            digitCount = result->mDigitCount;
        } while (digitCount < length);
    }
    resultDigits = result->mDigits;
    resultEnd = resultDigits + length;
    if (subtrahend->mDigitCount + shift < length) {
        resultEnd = resultDigits + (subtrahend->mDigitCount + shift);
    }
    subDigits = subtrahend->mDigits;
    subCursor = subDigits + (resultEnd - resultDigits - shift);
    subEnd = subCursor;
    while (resultEnd > resultDigits && subCursor > subDigits) {
        resultEnd--;
        subCursor--;
        if (*resultEnd < *subCursor) {
            borrowCursor = resultEnd - 1;
            while (*borrowCursor == 0) {
                borrowCursor--;
            }
            while (borrowCursor != resultEnd) {
                (*borrowCursor)--;
                borrowCursor++;
                *borrowCursor += 10;
            }
        }
        *resultEnd -= *subCursor;
    }
    consumed = subEnd - subDigits;
    if (consumed < subtrahend->mDigitCount) {
        roundDown = 0;
        if (*subEnd < 5) {
            roundDown = 1;
        } else if (*subEnd == 5) {
            subTail = subtrahend->mDigits + subtrahend->mDigitCount;
            subEnd++;
            while (subEnd < subTail) {
                if (*subEnd != 0) {
                    goto done;
                }
                subEnd++;
            }
            resultEnd = resultDigits + consumed + shift - 1;
            if (*resultEnd & 1) {
                roundDown = 1;
            }
        }
        if (roundDown != 0) {
            if (*resultEnd < 1) {
                borrowCursor = resultEnd - 1;
                while (*borrowCursor == 0) {
                    borrowCursor--;
                }
                while (borrowCursor != resultEnd) {
                    (*borrowCursor)--;
                    borrowCursor++;
                    *borrowCursor += 10;
                }
            }
            (*resultEnd)--;
        }
    }
done:
    subEnd = resultDigits;
    while (*subEnd == 0) {
        subEnd++;
    }
    if (subEnd > resultDigits) {
        char *digitsEnd;
        u8 cnt;

        cnt = subEnd - resultDigits;
        result->mExponent -= cnt;
        digitsEnd = resultDigits + result->mDigitCount;
        while (subEnd < digitsEnd) {
            *resultDigits = *subEnd;
            subEnd++;
            resultDigits++;
        }
        result->mDigitCount -= cnt;
    }
    resultDigits = result->mDigits;
    subEnd = resultDigits + result->mDigitCount;
    while (subEnd > resultDigits) {
        subEnd--;
        if (*subEnd != 0) {
            break;
        }
    }
    result->mDigitCount = subEnd - resultDigits + 1;
}

// Fills out with the decimal digits of value.
void DoubleToDigits(DigitRecord *out, double value) {
    int binaryExponent;
    double classifyCopy1;
    double classifyCopy2;
    double mantissaCopy;
    double mantissa;
    DigitRecord big_a;
    DigitRecord big_b;
    u32 *mantissaWords;
    u32 hi;
    u8 sign;
    int fpClass;
    int lowZeroBits;
    int shift;

    hi = ((u32 *) &value)[1];
    sign = (hi & 0x80000000) != 0;
    if (value == 0.0) {
        out->mNegative = sign;
        out->mExponent = 0;
        out->mDigitCount = 1;
        out->mDigits[0] = 0;
        return;
    }
    classifyCopy1 = value;
    switch (((u32 *) &classifyCopy1)[1] & DOUBLE_EXPONENT_MASK) {
        case DOUBLE_EXPONENT_MASK:
            if ((((u32 *) &classifyCopy1)[1] & DOUBLE_HIGH_MANTISSA_MASK) || ((u32 *) &classifyCopy1)[0]) {
                fpClass = 1;
            } else {
                fpClass = 2;
            }
            break;
        case 0:
            if ((((u32 *) &classifyCopy1)[1] & DOUBLE_HIGH_MANTISSA_MASK) || ((u32 *) &classifyCopy1)[0]) {
                fpClass = 5;
            } else {
                fpClass = 3;
            }
            break;
        default:
            fpClass = 4;
            break;
    }
    if (fpClass <= 2) {
        out->mNegative = sign;
        out->mExponent = 0;
        out->mDigitCount = 1;
        classifyCopy2 = value;
        switch (((u32 *) &classifyCopy2)[1] & DOUBLE_EXPONENT_MASK) {
            case DOUBLE_EXPONENT_MASK:
                if ((((u32 *) &classifyCopy2)[1] & DOUBLE_HIGH_MANTISSA_MASK) || ((u32 *) &classifyCopy2)[0]) {
                    fpClass = 1;
                } else {
                    fpClass = 2;
                }
                break;
            case 0:
                if ((((u32 *) &classifyCopy2)[1] & DOUBLE_HIGH_MANTISSA_MASK) || ((u32 *) &classifyCopy2)[0]) {
                    fpClass = 5;
                } else {
                    fpClass = 3;
                }
                break;
            default:
                fpClass = 4;
                break;
        }
        out->mDigits[0] = fpClass == 1 ? 0x4e : 0x49;
        return;
    }
    if (sign) {
        value = 0.0 - value;
    }
    mantissa = frexp(value, &binaryExponent);
    mantissaCopy = mantissa;
    mantissaWords = (u32 *) &mantissaCopy;
    if (mantissaWords[0]) {
        lowZeroBits = CountLowZeroBits(mantissaWords[0]);
    } else {
        lowZeroBits = CountLowZeroBits(mantissaWords[1] | 0x100000) + 0x20;
    }
    shift = 0x35 - lowZeroBits;
    DigitsPowerOfTwo(&big_b, binaryExponent - shift);
    DigitsFromU64(&big_a, ldexp(mantissa, shift));
    DigitsMultiply(out, &big_a, &big_b);
    out->mNegative = sign;
}

// Calls DoubleToDigits on record, then pads it to the requested digit count and turns the digits into characters.
void DoubleToDigitChars(DigitOptions *options, double value, DigitRecord *record) {
    int digitCount;
    int digitIndex;

    digitCount = options->mDigitCount;
    DoubleToDigits(record, value);
    if (record->mDigits[0] > 9) {
        return;
    }
    if (digitCount > 32) {
        digitCount = 32;
    }
    DigitsRoundTo(record, digitCount);
    while (record->mDigitCount < digitCount) {
        record->mDigits[record->mDigitCount++] = 0;
    }
    record->mExponent = record->mExponent - (record->mDigitCount - 1);
    for (digitIndex = 0; digitIndex < record->mDigitCount; digitIndex++) {
        record->mDigits[digitIndex] += 0x30;
    }
}

double DigitCharsToDouble(const DigitRecord *record) {
    char *cursor;
    char *end;
    int exponent5;
    u32 chunkValue;
    int chunkIndex;
    u64 *neighborBits;
    int searchUp;
    int fpClass;
    double nanValue;
    u64 *nanBits;
    double result;
    double neighbor;
    double scaled;
    double sum;
    union {
        double value;
        u32 words[2];
    } resultUnion, neighborUnion;
    DigitRecord parsed;
    DigitRecord maxRecord;
    DigitRecord resultRecord;
    DigitRecord neighborRecord;
    DigitRecord diffLow;
    DigitRecord diffHigh;

    if (record->mDigitCount == 0) {
        return copysign(0.0, record->mNegative == 0 ? 1.0 : -1.0);
    }
    switch (record->mDigits[0]) {
        case '0':
            return copysign(0.0, record->mNegative == 0 ? 1.0 : -1.0);
        case 'I':
            return copysign(gFloatInfinity, record->mNegative == 0 ? 1.0 : -1.0);
        case 'N':
            nanBits = (u64 *) &nanValue;
            *nanBits = 0x7ff0000000000000ULL;
            if (record->mNegative) {
                *nanBits |= 0x8000000000000000ULL;
            }
            *nanBits |= 0x0008000000000000ULL;
            return nanValue;
    }
    parsed = *record;
    for (cursor = parsed.mDigits, end = cursor + parsed.mDigitCount; cursor < end; cursor++) {
        *cursor -= '0';
    }
    parsed.mExponent += parsed.mDigitCount - 1;
    exponent5 = parsed.mExponent;
    DigitsFromString(&maxRecord, "179769313486231580793728714053034151", 0x134);
    if (DigitsLess(&maxRecord, &parsed)) {
        return copysign(gFloatInfinity, record->mNegative == 0 ? 1.0 : -1.0);
    }
    cursor = parsed.mDigits;
    result = *cursor++;
    while (cursor < end) {
        int chunkLength;

        chunkValue = 0;
        chunkLength = (end - cursor) % 8;
        if (chunkLength == 0) {
            chunkLength = 8;
        }
        for (chunkIndex = 0; chunkIndex < chunkLength; chunkIndex++) {
            chunkValue = 10 * chunkValue + *cursor;
            cursor++;
        }
        scaled = result * gPowersOfTen[chunkLength - 1];
        sum = scaled + chunkValue;
        if (chunkValue != 0 && scaled == sum) {
            break;
        }
        result = sum;
        exponent5 -= chunkLength;
    }
    if (exponent5 < 0) {
        result = result / pow(5.0, -exponent5);
    } else {
        result = result * pow(5.0, exponent5);
    }
    result = ldexp(result, exponent5);
    resultUnion.value = result;
    switch (resultUnion.words[1] & DOUBLE_EXPONENT_MASK) {
        case DOUBLE_EXPONENT_MASK:
            if ((resultUnion.words[1] & DOUBLE_HIGH_MANTISSA_MASK) || resultUnion.words[0]) {
                fpClass = 1;
            } else {
                fpClass = 2;
            }
            break;
        case 0:
            if ((resultUnion.words[1] & DOUBLE_HIGH_MANTISSA_MASK) || resultUnion.words[0]) {
                fpClass = 5;
            } else {
                fpClass = 3;
            }
            break;
        default:
            fpClass = 4;
            break;
    }
    if (fpClass == 2) {
        result = 1.7976931348623157e+308;
    }
    neighborBits = (u64 *) &neighbor;
    searchUp = 0;
    DoubleToDigits(&resultRecord, result);
    if (!DigitsEqual(&resultRecord, &parsed)) {
        if (DigitsLess(&resultRecord, &parsed)) {
            searchUp = 1;
        }
        neighbor = result;
        for (;;) {
            if (searchUp) {
                (*neighborBits)++;
                neighborUnion.value = neighbor;
                switch (neighborUnion.words[1] & DOUBLE_EXPONENT_MASK) {
                    case DOUBLE_EXPONENT_MASK:
                        if ((neighborUnion.words[1] & DOUBLE_HIGH_MANTISSA_MASK) || neighborUnion.words[0]) {
                            fpClass = 1;
                        } else {
                            fpClass = 2;
                        }
                        break;
                    case 0:
                        if ((neighborUnion.words[1] & DOUBLE_HIGH_MANTISSA_MASK) || neighborUnion.words[0]) {
                            fpClass = 5;
                        } else {
                            fpClass = 3;
                        }
                        break;
                    default:
                        fpClass = 4;
                        break;
                }
                if (fpClass == 2) {
                    goto done;
                }
            } else {
                (*neighborBits)--;
            }
            DoubleToDigits(&neighborRecord, neighbor);
            if (searchUp && !DigitsLess(&neighborRecord, &parsed)) {
                break;
            }
            if (!searchUp && !DigitsLess(&parsed, &neighborRecord)) {
                diffLow = resultRecord;
                resultRecord = neighborRecord;
                neighborRecord = diffLow;
                scaled = result;
                result = neighbor;
                neighbor = scaled;
                break;
            }
            resultRecord = neighborRecord;
            result = neighbor;
        }
        DigitsSubtract(&diffLow, &parsed, &resultRecord);
        DigitsSubtract(&diffHigh, &neighborRecord, &parsed);
        if (DigitsEqual(&diffLow, &diffHigh)) {
            if (*(u64 *) &result & 1) {
                result = neighbor;
            }
        } else if (!DigitsLess(&diffLow, &diffHigh)) {
            result = neighbor;
        }
    }
done:
    if (parsed.mNegative) {
        result = -result;
    }
    return result;
}

double pow(double base, double power) {
    return PowBody(base, power);
}

// Classifies the exponent field of value as 1 to 5.
static inline int __fpclassifyd(double value) {
    int exponentBits = *((int *) &value + 1) & DOUBLE_EXPONENT_MASK;

    switch (exponentBits) {
        case DOUBLE_EXPONENT_MASK:
            if ((*((int *) &value + 1) & DOUBLE_HIGH_MANTISSA_MASK) != 0 || *(int *) &value != 0) {
                return 1;
            }
            return 2;
        case 0:
            if ((*((int *) &value + 1) & DOUBLE_HIGH_MANTISSA_MASK) != 0 || *(int *) &value != 0) {
                return 5;
            }
            return 3;
    }
    return 4;
}

// Adds exponentDelta to the exponent field of value.
double ldexp(double value, int exponentDelta) {
    int highWord;
    int lowWord;
    int exponentField;

    if (__fpclassifyd(value) <= 2 || 0.0 == value) {
        return value;
    }
    highWord = *((int *) &value + 1);
    lowWord = *(int *) &value;
    exponentField = (highWord & DOUBLE_EXPONENT_MASK) >> 20;
    if (exponentField == 0) {
        if ((lowWord | (highWord & 0x7fffffff)) == 0) {
            return value;
        }
        value *= 18014398509481984.0;
        highWord = *((int *) &value + 1);
        exponentField = ((highWord & DOUBLE_EXPONENT_MASK) >> 20) - 54;
        if (exponentDelta < -50000) {
            return 1e-300 * value;
        }
    }
    if (exponentField == 0x7ff) {
        return value + value;
    }
    exponentField += exponentDelta;
    if (exponentField > 0x7fe) {
        return 1e300 * copysign(1e300, value);
    }
    if (exponentField > 0) {
        *((int *) &value + 1) = (highWord & 0x800fffff) | (exponentField << 20);
        return value;
    }
    if (exponentField <= -54) {
        if (exponentDelta > 50000) {
            return 1e300 * copysign(1e300, value);
        }
        return 1e-300 * copysign(1e-300, value);
    }
    exponentField += 54;
    *((int *) &value + 1) = (highWord & 0x800fffff) | (exponentField << 20);
    return value * 5.551115123125783e-17;
}

// Splits value into a fraction and the exponent count stored to *exponentOut.
double frexp(double value, int *exponentOut) {
    int absHigh;
    int highWord;
    int lowWord;

    highWord = *((int *) &value + 1);
    lowWord = *(int *) &value;
    absHigh = highWord & 0x7fffffff;
    *exponentOut = 0;
    if (absHigh >= DOUBLE_EXPONENT_MASK || (absHigh | lowWord) == 0) {
        return value;
    }
    if (absHigh < 0x100000) {
        value *= 18014398509481984.0;
        highWord = *((int *) &value + 1);
        absHigh = highWord & 0x7fffffff;
        *exponentOut = -54;
    }
    *exponentOut += (absHigh >> 20) - 1022;
    *((int *) &value + 1) = (highWord & 0x800fffff) | 0x3fe00000;
    return value;
}

// Clears the sign bit of value.
double fabs(double value) {
    *((u32 *) &value + 1) &= 0x7fffffff;
    return value;
}

// magnitude with the sign bit of sign.
double copysign(double magnitude, double sign) {
    *((u32 *) &magnitude + 1) = (*((u32 *) &magnitude + 1) & 0x7fffffff) | (*((u32 *) &sign + 1) & 0x80000000);
    return magnitude;
}

double PowBody(double base, double power) {
    static const double ln2Low = -1.904654299957768e-09;
    int scaleExp;
    double result, absBase, logHigh, powerHigh, logProdHigh, workTerm, ratioHigh, tHigh;
    double baseCopy, highTerm, lowTerm, correction, poly, sign, ratio, ratioSquared, ratioError, logProdLow, tLow,
        scaledHigh, scaledLow, logLow;
    int lowBits, bits, expBits, intKind, nonNegative, baseExponent;
    int ha, hb, ia, ib;
    u32 la, lb;

    hb = *(1 + (int *) &power);
    lb = *(u32 *) &power;
    ha = *(1 + (int *) &base);
    la = *(u32 *) &base;
    ib = hb & 0x7fffffff;
    ia = ha & 0x7fffffff;

    if ((ib | lb) == 0) {
        return 1.0;
    }
    if (ia > DOUBLE_EXPONENT_MASK || (ia == DOUBLE_EXPONENT_MASK && la != 0) || ib > DOUBLE_EXPONENT_MASK ||
        (ib == DOUBLE_EXPONENT_MASK && lb != 0)) {
        return base + power;
    }

    intKind = 0;
    if (ha < 0) {
        if (ib >= 0x43400000) {
            intKind = 2;
        } else if (ib >= 0x3ff00000) {
            expBits = (ib >> 20) - 0x3ff;
            if (expBits > 20) {
                bits = lb >> (52 - expBits);
                if ((bits << (52 - expBits)) == lb) {
                    intKind = 2 - (bits & 1);
                }
            } else if (lb == 0) {
                bits = ib >> (20 - expBits);
                if ((bits << (20 - expBits)) == ib) {
                    intKind = 2 - (bits & 1);
                }
            }
        }
    }

    if (lb == 0) {
        if (ib == DOUBLE_EXPONENT_MASK) {
            if (((ia - 0x3ff00000) | la) == 0) {
                return power - power;
            } else if (ia >= 0x3ff00000) {
                return hb >= 0 ? power : 0.0;
            } else {
                return hb < 0 ? -power : 0.0;
            }
        }
        if (ib == 0x3ff00000) {
            if (hb < 0) {
                return 1.0 / base;
            } else {
                return base;
            }
        }
        if (hb == 0x40000000) {
            return base * base;
        }
        if (hb == 0x3fe00000) {
            if (ha >= 0) {
                return SqrtDouble(base);
            }
        }
    }

    baseCopy = base;
    absBase = fabs(baseCopy);
    if (la == 0) {
        if (ia == DOUBLE_EXPONENT_MASK || ia == 0 || ia == 0x3ff00000) {
            result = absBase;
            if (hb < 0) {
                result = 1.0 / result;
            }
            if (ha < 0) {
                if (((ia - 0x3ff00000) | intKind) == 0) {
                    result = (result - result) / (result - result);
                } else if (intKind == 1) {
                    result = -result;
                }
            }
            return result;
        }
    }

    nonNegative = (ha >> 31) + 1;
    if ((nonNegative | intKind) == 0) {
        gLibErrorCode = 33;
        return gFloatQuietNan;
    }

    if (ib > 0x41e00000) {
        if (ib > 0x43f00000) {
            if (ia <= 0x3fefffff) {
                return hb < 0 ? 1e300 * 1e300 : 0.0;
            }
            if (ia >= 0x3ff00000) {
                return hb > 0 ? 1e300 * 1e300 : 0.0;
            }
        }
        if (ia < 0x3fefffff) {
            return hb < 0 ? 1e300 * 1e300 : 0.0;
        }
        if (ia > 0x3ff00000) {
            return hb > 0 ? 1e300 * 1e300 : 0.0;
        }
        workTerm = baseCopy - 1.0;
        correction = (workTerm * workTerm) * (0.5 - workTerm * (0.3333333333333333 - workTerm * 0.25));
        highTerm = 1.4426950216293335 * workTerm;
        lowTerm = workTerm * 1.9259629911266175e-08 - correction * 1.4426950408889634;
        logProdHigh = highTerm + lowTerm;
        *(int *) &logProdHigh = 0;
        logProdLow = lowTerm - (logProdHigh - highTerm);
    } else {
        baseExponent = 0;
        if (ia < 0x00100000) {
            absBase *= 9007199254740992.0;
            baseExponent -= 53;
            ia = *(1 + (int *) &absBase);
        }
        baseExponent += (ia >> 20) - 0x3ff;
        bits = ia & 0x000fffff;
        ia = bits | 0x3ff00000;
        if (bits <= 0x3988e) {
            expBits = 0;
        } else if (bits < 0xbb67a) {
            expBits = 1;
        } else {
            expBits = 0;
            baseExponent += 1;
            ia -= 0x00100000;
        }
        *(1 + (int *) &absBase) = ia;

        highTerm = absBase - gPowBreakpoint[expBits];
        lowTerm = 1.0 / (absBase + gPowBreakpoint[expBits]);
        ratio = highTerm * lowTerm;
        ratioHigh = ratio;
        *(int *) &ratioHigh = 0;
        tHigh = 0.0;
        *(1 + (int *) &tHigh) = ((ia >> 1) | 0x20000000) + 0x00080000 + (expBits << 18);
        tLow = absBase - (tHigh - gPowBreakpoint[expBits]);
        ratioError = lowTerm * ((highTerm - ratioHigh * tHigh) - ratioHigh * tLow);
        ratioSquared = ratio * ratio;
        poly = ratioSquared * ratioSquared *
               (0.5999999999999946 +
                ratioSquared * (0.4285714285785502 +
                                ratioSquared * (0.33333332981837743 +
                                                ratioSquared * (0.272728123808534 +
                                                                ratioSquared * (0.23066074577556175 +
                                                                                ratioSquared * 0.20697501780033842)))));
        poly += ratioError * (ratioHigh + ratio);
        ratioSquared = ratioHigh * ratioHigh;
        tHigh = 3.0 + ratioSquared + poly;
        *(int *) &tHigh = 0;
        tLow = poly - ((tHigh - 3.0) - ratioSquared);
        highTerm = ratioHigh * tHigh;
        lowTerm = ratioError * tHigh + tLow * ratio;
        logHigh = highTerm + lowTerm;
        *(int *) &logHigh = 0;
        logLow = lowTerm - (logHigh - highTerm);
        scaledHigh = 0.9617967009544373 * logHigh;
        scaledLow = gPowLogAdjustLow[expBits] + (-7.028461650952758e-09 * logHigh + logLow * 0.9617966939259756);
        workTerm = baseExponent;
        logProdHigh = ((scaledHigh + scaledLow) + gPowLogAdjustHigh[expBits]) + workTerm;
        *(int *) &logProdHigh = 0;
        logProdLow = scaledLow - (((logProdHigh - workTerm) - gPowLogAdjustHigh[expBits]) - scaledHigh);
    }

    sign = 1.0;
    if ((nonNegative | (intKind - 1)) == 0) {
        sign = -1.0;
    }
    powerHigh = power;
    *(int *) &powerHigh = 0;
    logLow = (power - powerHigh) * logProdHigh + power * logProdLow;
    logHigh = powerHigh * logProdHigh;
    result = logLow + logHigh;
    bits = *(1 + (int *) &result);
    lowBits = *(int *) &result;
    if (bits >= 0x40900000) {
        if (((bits - 0x40900000) | lowBits) != 0) {
            return sign * 1e300 * 1e300;
        } else if (logLow + 8.008566259537294e-17 > result - logHigh) {
            return sign * 1e300 * 1e300;
        }
    } else if ((bits & 0x7fffffff) >= 0x4090cc00) {
        if (((bits - 0xc090cc00) | lowBits) != 0) {
            return sign * 1e-300 * 1e-300;
        } else if (logLow <= result - logHigh) {
            return sign * 1e-300 * 1e-300;
        }
    }

    lowBits = bits & 0x7fffffff;
    expBits = (lowBits >> 20) - 0x3ff;
    scaleExp = 0;
    if (lowBits > 0x3fe00000) {
        lowBits = bits + (0x00100000 >> (expBits + 1));
        expBits = ((lowBits & 0x7fffffff) >> 20) - 0x3ff;
        workTerm = 0.0;
        *(1 + (int *) &workTerm) = lowBits & ~(0x000fffff >> expBits);
        scaleExp = ((lowBits & 0x000fffff) | 0x00100000) >> (20 - expBits);
        if (bits < 0) {
            scaleExp = -scaleExp;
        }
        logHigh -= workTerm;
    }
    workTerm = logLow + logHigh;
    *(int *) &workTerm = 0;
    highTerm = workTerm * 0.6931471824645996;
    lowTerm = (logLow - (workTerm - logHigh)) * 0.6931471805599453 + workTerm * ln2Low;
    result = highTerm + lowTerm;
    correction = lowTerm - (result - highTerm);
    workTerm = result * result;
    logProdHigh =
        result -
        workTerm * (0.16666666666666602 +
                    workTerm * (-0.0027777777777015593 +
                                workTerm * (6.613756321437934e-05 +
                                            workTerm * (-1.6533902205465252e-06 + workTerm * 4.1381367970572385e-08))));
    poly = (result * logProdHigh) / (logProdHigh - 2.0) - (correction + result * correction);
    result = 1.0 - (poly - result);
    bits = *(1 + (int *) &result);
    bits += scaleExp << 20;
    if ((bits >> 20) <= 0) {
        result = LdexpViaFrexp(result, scaleExp);
    } else {
        *(1 + (int *) &result) += scaleExp << 20;
    }
    return sign * result;
}
