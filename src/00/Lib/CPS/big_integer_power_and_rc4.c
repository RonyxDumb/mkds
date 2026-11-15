#include "00/Lib/CPS/big_integer_power_and_rc4.h"
#include "00/Lib/CPS/big_integer_multiply.h"
#include "00/Lib/CPS/big_integer_add_part.h"
#include "00/Lib/CPS/big_integer_add_subtract.h"
#include "00/Lib/CPS/big_integer_digit_count.h"
#include "00/Lib/CPS/cps_globals.h"
#include "float_subtract.h"
#include "string.h"
#include "print_memory_functions.h"
#include "cpu_copy_fill.h"

void CPSi_big_mult_small(u16 *result, const u16 *value, u16 factor, s32 digitCount) {
    s32 valueDigits;
    s32 digitIndex;
    u32 carry;
    u32 product;
    valueDigits = count_digits(value, digitCount);
    carry = 0;
    for (digitIndex = 0; digitIndex < valueDigits; digitIndex++) {
        product = carry + factor * value[digitIndex];
        result[digitIndex] = product;
        carry = product >> 16;
    }
    if (digitIndex < digitCount) {
        result[digitIndex++] = carry;
    }
    MI_CpuFill8(result + digitIndex, 0, (digitCount - digitIndex) * 2);
}

void CPSi_big_sqr(u16 *result, const u16 *value, s32 digitCount) {
    s32 valueDigits;
    s32 outerIndex;
    s32 innerIndex;
    s32 resultIndex;
    u32 square;
    u32 product;
    valueDigits = count_digits(value, digitCount);
    outerIndex = valueDigits * 2;
    if (outerIndex < digitCount) {
        MI_CpuFill8(result + outerIndex, 0, (digitCount - outerIndex) * 2);
    }
    for (resultIndex = 0; resultIndex < valueDigits; resultIndex++) {
        innerIndex = resultIndex * 2;
        if (innerIndex >= digitCount) {
            break;
        }
        square = value[resultIndex] * value[resultIndex];
        result[innerIndex] = square;
        if (innerIndex == digitCount - 1) {
            break;
        }
        result[innerIndex + 1] = square >> 16;
    }
    for (outerIndex = 0; outerIndex < valueDigits; outerIndex++) {
        for (innerIndex = outerIndex + 1;
             innerIndex < valueDigits && (resultIndex = outerIndex + innerIndex) < digitCount; innerIndex++) {
            product = value[innerIndex] * value[outerIndex];
            if (product <= 0x7fff8000) {
                CPSi_big_add_part(result, product * 2, resultIndex, digitCount);
            } else {
                CPSi_big_add_part(result, product, resultIndex, digitCount);
                CPSi_big_add_part(result, product, resultIndex, digitCount);
            }
        }
    }
}

void CPSi_big_div(u16 *quotient, u16 *dividend, u16 *divisor, u16 *remainder, s32 digitCount, u16 *work) {
    u16 *partialRemainder;
    s32 dividendDigits;
    s32 divisorDigits;
    s32 quotientPos;
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
        quotientPos = digitCount - dividendDigits + divisorDigits - 1;
        if (quotientPos >= digitCount) {
            MI_CpuCopy8(dividend, partialRemainder, digitCount * 2);
        } else {
            MI_CpuCopy8(dividend, quotientDigits + quotientPos, dividendDigits * 2);
            if (divisorDigits > 2) {
                divisorTop = ((u64) * (divisor + divisorDigits - 1) << 32) +
                             ((u64) * (divisor + divisorDigits - 2) << 16) + (u64) * (divisor + divisorDigits - 3);
            } else if (divisorDigits > 1) {
                divisorTop =
                    ((u64) * (divisor + divisorDigits - 1) << 32) + ((u64) * (divisor + divisorDigits - 2) << 16);
            } else {
                divisorTop = (u64) * (divisor + divisorDigits - 1) << 32;
            }
            while (quotientPos < digitCount) {
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
                quotientPos++;
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
    u16 *quotientBlock;
    u16 *remainderBlock;
    u16 *coefficientBlock;
    u16 *previousCoefficientBlock;
    u16 *tempBlock;
    u16 *divisionWork;
    s32 byteCount;
    byteCount = digitCount * 2;
    quotientBlock = work + digitCount;
    remainderBlock = quotientBlock + digitCount;
    coefficientBlock = remainderBlock + digitCount;
    previousCoefficientBlock = coefficientBlock + digitCount;
    tempBlock = previousCoefficientBlock + digitCount;
    divisionWork = tempBlock + digitCount;
    MI_CpuCopy8(value, work, byteCount);
    MI_CpuCopy8(modulus, remainderBlock, byteCount);
    remainderBlock[digitCount] = 1;
    while (CPSi_big_sign(work, digitCount) > 0) {
        CPSi_big_div(quotientBlock, remainderBlock, work, tempBlock, digitCount, divisionWork);
        MI_CpuCopy8(work, remainderBlock, byteCount);
        MI_CpuCopy8(tempBlock, work, byteCount);
        CPSi_big_mult(tempBlock, quotientBlock, coefficientBlock, digitCount);
        CPSi_big_sub(tempBlock, previousCoefficientBlock, tempBlock, digitCount);
        MI_CpuCopy8(coefficientBlock, previousCoefficientBlock, byteCount);
        MI_CpuCopy8(tempBlock, coefficientBlock, byteCount);
    }
    CPSi_big_add(previousCoefficientBlock, previousCoefficientBlock, modulus, digitCount);
    CPSi_big_div(NULL, previousCoefficientBlock, modulus, inverse, digitCount, divisionWork);
}

void CPSi_big_montmult(u16 *accumulator, u16 *savedCopy, u16 *multiplier, s32 digitCount, s32 modulusDigits,
                       u16 *modulus, u16 *modulusPrime, u16 *reduceFactor, u16 *reduceProduct) {
    s32 byteCount;
    s32 upperBytes;
    s32 modulusBytes;
    s32 compareResult;
    byteCount = digitCount * 2;
    MI_CpuCopy8(accumulator, savedCopy, byteCount);
    if (multiplier == (u16 *) 1) {
        CPSi_big_sqr(accumulator, savedCopy, digitCount);
    } else if (multiplier != NULL) {
        CPSi_big_mult(accumulator, savedCopy, multiplier, digitCount);
    }
    CPSi_big_mult(reduceFactor, accumulator, modulusPrime, modulusDigits);
    upperBytes = (digitCount - modulusDigits) * 2;
    modulusBytes = modulusDigits * 2;
    MI_CpuFill8(reduceFactor + modulusDigits, 0, upperBytes);
    CPSi_big_mult(reduceProduct, reduceFactor, modulus, digitCount);
    CPSi_big_add(accumulator, accumulator, reduceProduct, digitCount);
    memmove(accumulator, accumulator + modulusDigits, upperBytes);
    MI_CpuFill8(accumulator + digitCount - modulusDigits, 0, modulusBytes);
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
    u16 *primeBlock;
    u16 *baseMontBlock;
    u16 *reduceFactorBlock;
    u16 *reduceProductBlock;
    u16 *accumulatorCopy;
    u16 *divisionWork;
    s32 modulusDigits;
    s32 count;
    u32 exponentBitCount;
    count = digitCount * 0x16;
    workBlock = (u16 *) CPSiAlloc(count);
    if (workBlock != NULL) {
        MI_CpuFill8(workBlock, 0, count);
        primeBlock = workBlock + digitCount;
        baseMontBlock = primeBlock + digitCount;
        reduceFactorBlock = baseMontBlock + digitCount;
        reduceProductBlock = reduceFactorBlock + digitCount;
        accumulatorCopy = reduceProductBlock + digitCount;
        divisionWork = accumulatorCopy + digitCount;
        modulusDigits = count_digits(modulus, digitCount);
        workBlock[modulusDigits] = 1;
        CPSi_big_modinv(primeBlock, workBlock, modulus, digitCount, baseMontBlock);
        CPSi_big_mult(reduceFactorBlock, workBlock, primeBlock, digitCount);
        CPSi_big_sub_small(primeBlock, reduceFactorBlock, 1, digitCount);
        CPSi_big_div(primeBlock, primeBlock, modulus, NULL, digitCount, divisionWork);
        CPSi_big_mult(baseMontBlock, base, workBlock, digitCount);
        CPSi_big_div(NULL, baseMontBlock, modulus, baseMontBlock, digitCount, divisionWork);
        CPSi_big_div(NULL, workBlock, modulus, result, digitCount, divisionWork);
        count = 0;
        exponentBitCount = modulusDigits << 4;
        for (; count < exponentBitCount; count++) {
            CPSi_big_montmult(result, accumulatorCopy, (u16 *) 1, digitCount, modulusDigits, modulus, primeBlock,
                              reduceFactorBlock, reduceProductBlock);
            if (((0x8000u >> (count & 0xf)) & exponent[modulusDigits - (count >> 4) - 1]) != 0) {
                CPSi_big_montmult(result, accumulatorCopy, baseMontBlock, digitCount, modulusDigits, modulus,
                                  primeBlock, reduceFactorBlock, reduceProductBlock);
            }
        }
        CPSi_big_montmult(result, accumulatorCopy, NULL, digitCount, modulusDigits, modulus, primeBlock,
                          reduceFactorBlock, reduceProductBlock);
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
    s32 index;
    u8 swapIndex;
    u8 keyIndex;
    u8 entry;
    context[0] = 0;
    context[1] = 0;
    table = context + 2;
    for (index = 0; index < 0x100; index++) {
        table[index] = index;
    }
    keyIndex = 0;
    swapIndex = 0;
    for (index = 0; index < 0x100; index++) {
        entry = table[index];
        swapIndex = swapIndex + (entry + key[keyIndex]);
        table[index] = table[swapIndex];
        table[swapIndex] = entry;
        keyIndex = keyIndex + 1;
        if (keyIndex >= keyLength) {
            keyIndex = 0;
        }
    }
}

void CPSi_rc4_crypt(u8 *context, u8 *data, s32 length) {
    s32 byteIndex;
    u8 firstIndex;
    u8 secondIndex;
    u8 *table;
    u8 firstValue;
    u8 secondValue;
    firstIndex = context[0];
    secondIndex = context[1];
    table = context + 2;
    for (byteIndex = 0; byteIndex < length; byteIndex++) {
        firstIndex = firstIndex + 1;
        firstValue = table[firstIndex];
        secondIndex = secondIndex + firstValue;
        secondValue = table[secondIndex];
        table[firstIndex] = secondValue;
        table[secondIndex] = firstValue;
        data[byteIndex] ^= table[(u8) (firstValue + secondValue)];
    }
    context[0] = firstIndex;
    context[1] = secondIndex;
}
