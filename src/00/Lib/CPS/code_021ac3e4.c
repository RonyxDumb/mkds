#include "00/Lib/CPS/code_021ac3e4.h"
#include "00/Lib/CPS/code_021acbf8.h"
#include "00/Lib/CPS/code_021acc68.h"
#include "00/Lib/CPS/code_021acc8c.h"
#include "00/Lib/CPS/code_021acec8.h"
#include "00/unk_021b6000.h"
#include "code_021329f8.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0214d018.h"

void CPSi_big_mult_small(u16 *result, const u16 *value, u16 factor, s32 digitCount) {
    s32 valueDigits;
    s32 f;
    u32 carry;
    u32 product;
    valueDigits = count_digits(value, digitCount);
    carry = 0;
    for (f = 0; f < valueDigits; f++) {
        product = carry + factor * value[f];
        result[f] = product;
        carry = product >> 16;
    }
    if (f < digitCount) {
        result[f++] = carry;
    }
    MI_CpuFill8(result + f, 0, (digitCount - f) * 2);
}

void CPSi_big_sqr(u16 *result, const u16 *value, s32 digitCount) {
    s32 valueDigits;
    s32 e;
    s32 f;
    s32 g;
    u32 square;
    u32 product;
    valueDigits = count_digits(value, digitCount);
    e = valueDigits * 2;
    if (e < digitCount) {
        MI_CpuFill8(result + e, 0, (digitCount - e) * 2);
    }
    for (g = 0; g < valueDigits; g++) {
        f = g * 2;
        if (f >= digitCount) {
            break;
        }
        square = value[g] * value[g];
        result[f] = square;
        if (f == digitCount - 1) {
            break;
        }
        result[f + 1] = square >> 16;
    }
    for (e = 0; e < valueDigits; e++) {
        for (f = e + 1; f < valueDigits && (g = e + f) < digitCount; f++) {
            product = value[f] * value[e];
            if (product <= 0x7fff8000) {
                CPSi_big_add_part(result, product * 2, g, digitCount);
            } else {
                CPSi_big_add_part(result, product, g, digitCount);
                CPSi_big_add_part(result, product, g, digitCount);
            }
        }
    }
}

void CPSi_big_div(u16 *quotient, u16 *dividend, u16 *divisor, u16 *remainder, s32 digitCount, u16 *work) {
    u16 *partialRemainder;
    s32 dividendDigits;
    s32 divisorDigits;
    s32 k;
    u64 divisorTop;
    u16 *quotientDigits;
    u32 quotientGuess;
    u64 remainderTop;
    quotientDigits = work + digitCount;
    partialRemainder = quotientDigits + digitCount;
    MI_CpuFill8(quotientDigits, 0, digitCount * 4);
    dividendDigits = count_digits(dividend, digitCount);
    divisorDigits = count_digits(divisor, digitCount);
    if (dividendDigits > 0 && divisorDigits > 0) {
        k = digitCount - dividendDigits + divisorDigits - 1;
        if (k >= digitCount) {
            MI_CpuCopy8(dividend, partialRemainder, digitCount * 2);
        } else {
            MI_CpuCopy8(dividend, quotientDigits + k, dividendDigits * 2);
            if (divisorDigits > 2) {
                divisorTop = ((u64) * (divisor + divisorDigits - 1) << 32) +
                             ((u64) * (divisor + divisorDigits - 2) << 16) + (u64) * (divisor + divisorDigits - 3);
            } else if (divisorDigits > 1) {
                divisorTop =
                    ((u64) * (divisor + divisorDigits - 1) << 32) + ((u64) * (divisor + divisorDigits - 2) << 16);
            } else {
                divisorTop = (u64) * (divisor + divisorDigits - 1) << 32;
            }
            while (k < digitCount) {
                memmove(quotientDigits + 1, quotientDigits, (digitCount * 2 - 1) * 2);
                remainderTop = ((u64) (partialRemainder + divisorDigits)[0] << 48) +
                               ((u64) (partialRemainder + divisorDigits)[-1] << 32) +
                               ((u64) (partialRemainder + divisorDigits)[-2] << 16) +
                               (u64) (partialRemainder + divisorDigits)[-3];
                quotientGuess = remainderTop / divisorTop;
                if (quotientGuess > 0xffff) {
                    quotientGuess = 0xffff;
                }
                for (;;) {
                    CPSi_big_mult_small(work, divisor, quotientGuess, digitCount);
                    if (CPSi_big_compare(partialRemainder, work, digitCount) >= 0) {
                        break;
                    }
                    quotientGuess--;
                }
                CPSi_big_sub(partialRemainder, partialRemainder, work, digitCount);
                *quotientDigits = quotientGuess;
                k++;
            }
        }
    }
    if (quotient != NULL) {
        MI_CpuCopy8(quotientDigits, quotient, digitCount * 2);
    }
    if (remainder != NULL) {
        MI_CpuCopy8(partialRemainder, remainder, digitCount * 2);
    }
}

void CPSi_big_power(u16 *result, u16 *base, u16 *exponent, s32 digitCount, u16 *modulus) {
    u16 *scratch;
    u16 *divisionWork;
    s32 zeroDigitCount;
    s32 bitIndex;
    scratch = (u16 *) CPSiAlloc(digitCount * 8);
    if (scratch != NULL) {
        divisionWork = scratch + digitCount;
        MI_CpuFill8(result + 1, 0, (digitCount - 1) * 2);
        result[0] = 1;
        zeroDigitCount = digitCount - count_digits(exponent, digitCount);
        bitIndex = zeroDigitCount * 16;
        for (; bitIndex < (u32) (digitCount << 4); bitIndex++) {
            if (((0x8000u >> (bitIndex & 0xf)) & exponent[digitCount - (bitIndex >> 4) - 1]) != 0) {
                MI_CpuCopy8(base, result, digitCount * 2);
                bitIndex++;
                break;
            }
        }
        for (; bitIndex < (u32) (digitCount << 4); bitIndex++) {
            CPSi_big_sqr(scratch, result, digitCount);
            MI_CpuCopy8(scratch, result, digitCount * 2);
            if (modulus != NULL) {
                CPSi_big_div(NULL, result, modulus, result, digitCount, divisionWork);
            }
            if (((0x8000u >> (bitIndex & 0xf)) & exponent[digitCount - (bitIndex >> 4) - 1]) != 0) {
                CPSi_big_mult(scratch, result, base, digitCount);
                MI_CpuCopy8(scratch, result, digitCount * 2);
                if (modulus != NULL) {
                    CPSi_big_div(NULL, result, modulus, result, digitCount, divisionWork);
                }
            }
        }
        CPSiFree(scratch);
    }
}

void CPSi_big_modinv(u16 *inverse, u16 *value, u16 *modulus, s32 digitCount, u16 *work) {
    u16 *f;
    u16 *g;
    u16 *h;
    u16 *i;
    u16 *j;
    u16 *k;
    s32 byteCount;
    byteCount = digitCount * 2;
    f = work + digitCount;
    g = f + digitCount;
    h = g + digitCount;
    i = h + digitCount;
    j = i + digitCount;
    k = j + digitCount;
    MI_CpuCopy8(value, work, byteCount);
    MI_CpuCopy8(modulus, g, byteCount);
    g[digitCount] = 1;
    while (CPSi_big_sign(work, digitCount) > 0) {
        CPSi_big_div(f, g, work, j, digitCount, k);
        MI_CpuCopy8(work, g, byteCount);
        MI_CpuCopy8(j, work, byteCount);
        CPSi_big_mult(j, f, h, digitCount);
        CPSi_big_sub(j, i, j, digitCount);
        MI_CpuCopy8(h, i, byteCount);
        MI_CpuCopy8(j, h, byteCount);
    }
    CPSi_big_add(i, i, modulus, digitCount);
    CPSi_big_div(NULL, i, modulus, inverse, digitCount, k);
}

void CPSi_big_montmult(u16 *accumulator, u16 *savedCopy, u16 *multiplier, s32 digitCount, s32 modulusDigits,
                       u16 *modulus, u16 *modulusPrime, u16 *reduceFactor, u16 *reduceProduct) {
    s32 byteCount;
    s32 k;
    s32 l;
    s32 compareResult;
    byteCount = digitCount * 2;
    MI_CpuCopy8(accumulator, savedCopy, byteCount);
    if (multiplier == (u16 *) 1) {
        CPSi_big_sqr(accumulator, savedCopy, digitCount);
    } else if (multiplier != NULL) {
        CPSi_big_mult(accumulator, savedCopy, multiplier, digitCount);
    }
    CPSi_big_mult(reduceFactor, accumulator, modulusPrime, modulusDigits);
    k = (digitCount - modulusDigits) * 2;
    l = modulusDigits * 2;
    MI_CpuFill8(reduceFactor + modulusDigits, 0, k);
    CPSi_big_mult(reduceProduct, reduceFactor, modulus, digitCount);
    CPSi_big_add(accumulator, accumulator, reduceProduct, digitCount);
    memmove(accumulator, accumulator + modulusDigits, k);
    MI_CpuFill8(accumulator + digitCount - modulusDigits, 0, l);
    compareResult = CPSi_big_compare(accumulator, modulus, digitCount);
    switch (compareResult) {
        case 0:
            MI_CpuFill8(accumulator, 0, byteCount);
            break;
        case 1:
            CPSi_big_sub(accumulator, accumulator, modulus, digitCount);
            break;
    }
}

void CPSi_big_montpower(u16 *result, u16 *base, u16 *exponent, s32 digitCount, u16 *modulus) {
    u16 *workBlock;
    u16 *g;
    u16 *h;
    u16 *i;
    u16 *j;
    u16 *accumulatorCopy;
    u16 *divisionWork;
    s32 modulusDigits;
    s32 n;
    u32 exponentBitCount;
    n = digitCount * 0x16;
    workBlock = (u16 *) CPSiAlloc(n);
    if (workBlock != NULL) {
        MI_CpuFill8(workBlock, 0, n);
        g = workBlock + digitCount;
        h = g + digitCount;
        i = h + digitCount;
        j = i + digitCount;
        accumulatorCopy = j + digitCount;
        divisionWork = accumulatorCopy + digitCount;
        modulusDigits = count_digits(modulus, digitCount);
        workBlock[modulusDigits] = 1;
        CPSi_big_modinv(g, workBlock, modulus, digitCount, h);
        CPSi_big_mult(i, workBlock, g, digitCount);
        CPSi_big_sub_small(g, i, 1, digitCount);
        CPSi_big_div(g, g, modulus, NULL, digitCount, divisionWork);
        CPSi_big_mult(h, base, workBlock, digitCount);
        CPSi_big_div(NULL, h, modulus, h, digitCount, divisionWork);
        CPSi_big_div(NULL, workBlock, modulus, result, digitCount, divisionWork);
        n = 0;
        exponentBitCount = modulusDigits << 4;
        for (; n < exponentBitCount; n++) {
            CPSi_big_montmult(result, accumulatorCopy, (u16 *) 1, digitCount, modulusDigits, modulus, g, i, j);
            if (((0x8000u >> (n & 0xf)) & exponent[modulusDigits - (n >> 4) - 1]) != 0) {
                CPSi_big_montmult(result, accumulatorCopy, h, digitCount, modulusDigits, modulus, g, i, j);
            }
        }
        CPSi_big_montmult(result, accumulatorCopy, NULL, digitCount, modulusDigits, modulus, g, i, j);
        CPSiFree(workBlock);
    }
}

void CPSi_big_from_char(u16 *digits, const u8 *bytes, s32 byteCount, s32 digitCount) {
    MI_CpuFill8(digits, 0, digitCount * 2);
    bytes += byteCount - 1;
    while (byteCount > 1) {
        *digits = bytes[0] + (bytes[-1] << 8);
        digits++;
        bytes -= 2;
        byteCount -= 2;
    }
    if (byteCount > 0) {
        *digits = *bytes;
    }
}

void CPSi_char_from_big(u8 *bytes, const u16 *digits, s32 byteCount, s32 digitCount) {
    bytes += byteCount - 1;
    while (byteCount > 1) {
        *bytes-- = *digits;
        *bytes-- = *digits++ >> 8;
        byteCount -= 2;
    }
    if (byteCount > 0) {
        *bytes = *digits;
    }
}

void CPSi_rc4_init(u8 *context, const u8 *key, s32 keyLength) {
    u8 *table;
    s32 i;
    u8 swapIndex;
    u8 keyIndex;
    u8 entry;
    context[0] = 0;
    context[1] = 0;
    table = context + 2;
    for (i = 0; i < 0x100; i++) {
        table[i] = i;
    }
    keyIndex = 0;
    swapIndex = 0;
    for (i = 0; i < 0x100; i++) {
        entry = table[i];
        swapIndex = swapIndex + (entry + key[keyIndex]);
        table[i] = table[swapIndex];
        table[swapIndex] = entry;
        keyIndex = keyIndex + 1;
        if (keyIndex >= keyLength) {
            keyIndex = 0;
        }
    }
}

void CPSi_rc4_crypt(u8 *context, u8 *data, s32 length) {
    s32 i;
    u8 firstIndex;
    u8 secondIndex;
    u8 *table;
    u8 firstValue;
    u8 secondValue;
    firstIndex = context[0];
    secondIndex = context[1];
    table = context + 2;
    for (i = 0; i < length; i++) {
        firstIndex = firstIndex + 1;
        firstValue = table[firstIndex];
        secondIndex = secondIndex + firstValue;
        secondValue = table[secondIndex];
        table[firstIndex] = secondValue;
        table[secondIndex] = firstValue;
        data[i] ^= table[(u8) (firstValue + secondValue)];
    }
    context[0] = firstIndex;
    context[1] = secondIndex;
}
