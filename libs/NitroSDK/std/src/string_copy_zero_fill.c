#include "string_copy_zero_fill.h"

// Copies up to size - 1 characters of srcp to destp, padding with zeros after the end of srcp, and terminates destp.
void STD_CopyLStringZeroFill(char *destp, const char *srcp, s32 size) {
    s32 index;
    size = size - 1;
    for (index = 0; index < size; index++) {
        destp[index] = *srcp;
        if (*srcp != 0) {
            srcp++;
        }
    }
    destp[index] = 0;
}
