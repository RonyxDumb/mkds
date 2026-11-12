#include "00/Lib/CPS/code_021acc68.h"

void CPSi_big_add_part(u16 *digits, u32 addend, int position, int digitCount) {
    u16 oldDigit;
    u16 *cursor;
    cursor = digits + position;
    for (; (addend != 0 && (position < digitCount)); position = position + 1) {
        oldDigit = *cursor;
        *cursor = addend + oldDigit;
        addend = addend + oldDigit >> 0x10;
        cursor = cursor + 1;
    }
}
