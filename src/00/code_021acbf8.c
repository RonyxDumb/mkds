#include "00/code_021acbf8.h"
#include "00/code_021acc68.h"
#include "00/code_021acec8.h"
#include "code_0214d018.h"

void CPSi_big_mult(u16 *result, const u16 *first, const u16 *second, s32 digitCount) {
    s32 firstDigits;
    s32 secondDigits;
    s32 i;
    s32 j;
    const u16 *firstCursor;
    const u16 *secondCursor;

    MI_CpuFill8(result, 0, digitCount * 2);
    firstDigits = count_digits(first, digitCount);
    secondDigits = count_digits(second, digitCount);
    secondCursor = second;
    for (i = 0; i < secondDigits; i++) {
        j = 0;
        firstCursor = first;
        for (; j < firstDigits && j < digitCount - i; j++) {
            CPSi_big_add_part(result, *firstCursor * *secondCursor, i + j, digitCount);
            firstCursor++;
        }
        secondCursor++;
    }
}
