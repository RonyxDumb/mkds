#pragma avoid_byte all

#include "code_02134b18.h"
#include "code_02139f70.h"

int func_02134d08(u16 *dst, const u8 *src, u32 n) {
    return data_0216eccc.mUnk_08->mUnk_00(dst, src, n);
}

int func_02134ccc(u16 *dst, const u8 *src, u32 n) {
    if (src == 0) {
        return 0;
    }
    if (n == 0) {
        return -1;
    }
    if (dst != 0) {
        *dst = *src;
    }
    if (*src == 0) {
        return 0;
    }
    return 1;
}

int func_02134c94(u8 *dst, u16 c) {
    if (dst == 0) {
        return 0;
    }
    *dst = c;
    return 1;
}

int func_02134c6c(u8 *dst, u16 c) {
    return data_0216eccc.mUnk_08->mUnk_04(dst, c);
}

int func_02134bd4(u16 *dst, const u8 *src, u32 n) {
    u32 i;
    int len;
    int r;

    len = func_0213a434(src);
    if (dst != 0) {
        for (i = 0; i < n; i++) {
            if (*src != 0) {
                r = func_02134d08(dst, src, len);
                dst++;
                if (r > 0) {
                    src += r;
                    len -= r;
                } else {
                    return -1;
                }
            } else {
                *dst = 0;
                break;
            }
        }
    } else {
        i = 0;
    }
    return i;
}

int func_02134b18(u8 *dst, const u16 *src, u32 n) {
    u32 len;
    u32 i = 0;
    u8 buf[4];
    u8 *p;

    if (dst == 0 || src == 0) {
        return 0;
    }
    p = buf;
    while (1) {
        if (*src == 0) {
            dst[i] = 0;
            break;
        }
        len = func_02134c6c(p, *src++);
        if (i + len > n) {
            break;
        }
        func_0213a228(dst + i, p, len);
        i += len;
        if (i > n) {
            break;
        }
    }
    return i;
}
