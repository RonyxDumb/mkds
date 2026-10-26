#include "code_0214cfe4.h"

// Copies size bytes from src to dst, a halfword at a time.
void func_0214cffc(const void *src, void *dst, s32 size) {
    s32 i;

    i = 0;
    do {
        if (i >= size) {
            break;
        }
        *(u16 *) ((u32) dst + i) = *(const u16 *) ((u32) src + i);
        i += 2;
    } while (1);
}

// Stores value at dst, a halfword at a time, for size bytes.
void func_0214cfe4(u16 value, void *dst, s32 size) {
    s32 i;

    i = 0;
    do {
        if (i >= size) {
            break;
        }
        *(u16 *) ((u32) dst + i) = value;
        i += 2;
    } while (1);
}
