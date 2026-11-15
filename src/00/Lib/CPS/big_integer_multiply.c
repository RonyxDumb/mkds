#include "00/Lib/CPS/big_integer_multiply.h"
#include "00/Lib/CPS/big_integer_add_part.h"
#include "00/Lib/CPS/big_integer_digit_count.h"
#include "cpu_copy_fill.h"

void CPSi_big_mult(u16 *result, const u16 *first, const u16 *second, s32 digitCount) {
    s32 firstDigits;
    s32 secondDigits;
    s32 secondIndex;
    s32 firstIndex;
    const u16 *firstCursor;
    const u16 *secondCursor;

    MI_CpuFill8(result, 0, digitCount * 2);
    firstDigits = count_digits(first, digitCount);
    secondDigits = count_digits(second, digitCount);
    secondCursor = second;
    for (secondIndex = 0; secondIndex < secondDigits; secondIndex++) {
        firstIndex = 0;
        firstCursor = first;
        for (; firstIndex < firstDigits && firstIndex < digitCount - secondIndex; firstIndex++) {
            CPSi_big_add_part(result, *firstCursor * *secondCursor, secondIndex + firstIndex, digitCount);
            firstCursor++;
        }
        secondCursor++;
    }
}
