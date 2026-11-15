#pragma avoid_byte all

#include "wide_string_functions.h"

// Number of u16 elements before the 0 terminator.
int wcslen(const u16 *string) {
    int length = -1;
    u16 character;

    do {
        character = *string++;
        length++;
    } while (character != 0);
    return length;
}

// Copies src up to and including its 0 terminator; returns dst.
u16 *wcscpy(u16 *dst, const u16 *src) {
    u16 *out = dst;

    while ((*out++ = *src++) != 0) {
    }
    return dst;
}

// Copies at most n elements of src to dst, then fills the rest of the n elements with 0; returns dst.
u16 *wcsncpy(u16 *dst, const u16 *src, u32 count) {
    u16 *out = dst;

    if (count != 0) {
        do {
            if ((*out++ = *src++) == 0) {
                if (--count != 0) {
                    do {
                        *out++ = 0;
                    } while (--count != 0);
                }
                return dst;
            }
        } while (--count != 0);
    }
    return dst;
}

// Appends at most n elements of src after the 0 terminator of dst, then writes a 0 terminator; returns dst.
u16 *wcsncat(u16 *dst, const u16 *src, u32 count) {
    u16 *out = dst;

    while (*out++ != 0) {
    }
    out--;
    if (count != 0) {
        do {
            if ((*out++ = *src++) == 0) {
                out--;
                break;
            }
        } while (--count != 0);
    }
    *out = 0;
    return dst;
}

// Compares at most n elements of a and b, stopping after a 0; returns the first difference a - b, or 0.
int wcsncmp(const u16 *first, const u16 *second, u32 count) {
    u16 secondChar;
    u16 firstChar;

    if (count != 0) {
        do {
            secondChar = *second++;
            firstChar = *first++;
            if (firstChar != secondChar) {
                return firstChar - secondChar;
            }
            if (firstChar == 0) {
                break;
            }
        } while (--count != 0);
    }
    return 0;
}

// Pointer to the first element equal to c, or to the 0 terminator when c is 0; 0 when there is none.
u16 *wcschr(const u16 *string, int target) {
    u16 ch;

    while ((ch = *string++) != 0) {
        if (ch == target) {
            return (u16 *) (string - 1);
        }
    }
    return target != 0 ? 0 : (u16 *) (string - 1);
}
