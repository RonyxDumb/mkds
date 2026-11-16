#include "00/Lib/CPS/big_integer_digit_count.h"

s32 count_digits(const u16 *digits, s32 digitCount) {
    while (digitCount != 0 && digits[digitCount - 1] == 0) {
        digitCount--;
    }
    return digitCount;
}
