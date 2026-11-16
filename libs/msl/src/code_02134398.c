#include "code_02134398.h"
#include "string.h"

#pragma avoid_byte all

#include "code_02134890.h"
#include "code_021352e0.h"
#include "code_0213c94c.h"
#include "code_0200e77c.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"

void *FormatPutFwrite(void *a, const char *b, u32 n) {
    if (n != fwrite(b, 1, n, a)) {
        a = 0;
    }
    return a;
}

void *FormatPutBuffer(void *p, const char *b, u32 n) {
    FormatPutTarget *a = p;

    if (a->mWrittenCount + n > a->mSize) {
        n = a->mSize - a->mWrittenCount;
    }
    memcpy(a->mBuffer + a->mWrittenCount, b, n);
    a->mWrittenCount += n;
    return (void *) 1;
}

int printf(const char *fmt, ...) {
    int r;

    if (fwide(&data_0216eb7c[1], -1) >= 0) {
        return -1;
    }
    if (OS_TryLockMutex((OSMutex *) g_AnotherMutex[3]) == 0) {
        g_SomeThreadId[3] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[3] = 1;
    } else if (g_SomeThreadId[3] == g_Os_ThreadInfo.mListHead->mId) {
        g_SomeCounter[3]++;
    } else {
        OS_LockMutex((OSMutex *) g_AnotherMutex[3]);
        g_SomeThreadId[3] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[3] = 1;
    }
    r = FormatWithPutFunc(FormatPutFwrite, &data_0216eb7c[1], fmt, (char *) (((int) &fmt & ~3) + 4));
    g_SomeCounter[3]--;
    if (g_SomeCounter[3] == 0) {
        OS_UnlockMutex((OSMutex *) g_AnotherMutex[3]);
    }
    return r;
}

int vsnprintf(char *buf, u32 n, const char *fmt, char *va) {
    FormatPutTarget st;
    int r;

    st.mBuffer = buf;
    st.mSize = n;
    st.mWrittenCount = 0;
    r = FormatWithPutFunc(FormatPutBuffer, &st, fmt, va);
    if (buf == 0) {
        return r;
    }
    if (r < n) {
        buf[r] = 0;
    } else if (n != 0) {
        *(buf + n - 1) = 0;
    }
    return r;
}

int snprintf(char *buf, u32 n, const char *fmt, ...) {
    return vsnprintf(buf, n, fmt, (char *) (((int) &fmt & ~3) + 4));
}

int sprintf(char *buf, const char *fmt, ...) {
    return vsnprintf(buf, -1, fmt, (char *) (((int) &fmt & ~3) + 4));
}

#pragma avoid_byte all

void nullsub_18(void) {}

void MemsetBody(u8 *p, int c, u32 n) {
    u32 *w;
    u32 m;
    u32 k;

    c = (u8) c;
    if (n >= 0x20) {
        m = -(u32) p & 3;
        if (m != 0) {
            n -= m;
            do {
                *p++ = c;
                m--;
            } while (m != 0);
        }
        w = (u32 *) p;
        if (c != 0) {
            c = (c << 24) | (c << 16) | (c << 8) | c;
        }
        for (k = n >> 5; k != 0; k--) {
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
        }
        for (k = (n & 0x1f) >> 2; k != 0; k--) {
            *w++ = c;
        }
        n &= 3;
        p = (u8 *) w;
    }
    for (; n != 0; n--) {
        *p++ = c;
    }
}

void *memcpy(void *dst, const void *src, u32 n) {
    u8 *p = dst;
    const u8 *s = src;

    for (; n != 0; n--) {
        *p++ = *s++;
    }
    return dst;
}

void *memmove(void *a, const void *b, u32 n) {
    if (b >= a) {
        u8 *d;
        const u8 *s;

        for (d = a, s = b; n != 0; n--) {
            *d++ = *s++;
        }
    } else {
        const u8 *s;
        u8 *d;

        for (s = (const u8 *) b + n, d = (u8 *) a + n; n != 0; n--) {
            *--d = *--s;
        }
    }
    return a;
}

void *memset(void *p, int c, size_t n) {
    MemsetBody(p, c, n);
    return p;
}

void *memchr(const void *x, int c, u32 n) {
    const u8 *p = x;
    u8 ch = c;

    for (; n != 0; n--) {
        if (*p++ == ch) {
            return (p - 1);
        }
    }
    return 0;
}

void *MemChrBackward(const void *a, int v, u32 n) {
    u8 c = v;
    const u8 *p = (const u8 *) a + n;

    for (; n != 0; n--) {
        if (*--p == c) {
            return p;
        }
    }
    return 0;
}

int memcmp(const void *x, const void *y, u32 n) {
    const u8 *a = x;
    const u8 *b = y;

    for (; n != 0; n--) {
        if (*a++ != *b++) {
            return a[-1] < b[-1] ? -1 : 1;
        }
    }
    return 0;
}

#pragma avoid_byte all

#include "code_02134b18.h"
#include "code_02139f70.h"

int mbtowc(u16 *dst, const char *src, u32 n) {
    return data_0216eccc.field8->field0(dst, src, n);
}

int MbtowcSingleByte(u16 *dst, const char *src, u32 n) {
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

int WctombSingleByte(char *dst, u16 c) {
    if (dst == 0) {
        return 0;
    }
    *dst = c;
    return 1;
}

int wctomb(char *dst, u16 c) {
    return data_0216eccc.field8->field4(dst, c);
}

int mbstowcs(u16 *dst, const char *src, u32 n) {
    u32 i;
    int len;
    int r;

    len = strlen(src);
    if (dst != 0) {
        for (i = 0; i < n; i++) {
            if (*src != 0) {
                r = mbtowc(dst, src, len);
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

int wcstombs(char *dst, const u16 *src, u32 n) {
    u32 len;
    u32 i = 0;
    char buf[4];
    char *p;

    if (dst == 0 || src == 0) {
        return 0;
    }
    p = buf;
    while (1) {
        if (*src == 0) {
            dst[i] = 0;
            break;
        }
        len = wctomb(p, *src++);
        if (i + len > n) {
            break;
        }
        strncpy(dst + i, p, len);
        i += len;
        if (i > n) {
            break;
        }
    }
    return i;
}

#pragma avoid_byte all

#include "code_0213ee6c.h"

double LdexpViaFrexp(double a, int n) {
    int e;

    a = frexp(a, &e);
    e += n;
    return ldexp(a, e);
}

int fflush(FILE *a) {
    if (a == 0) {
        return FflushAll();
    }
    if (a->mFailed != 0 || a->field4_7 == 0) {
        return -1;
    }
    if (a->field4_2 == 1) {
        return 0;
    }
    if (a->field8_0 >= 3) {
        a->field8_0 = 2;
    }
    if (a->field8_0 == 2) {
        a->mBufferRemaining = 0;
    }
    if (a->field8_0 != 1) {
        a->field8_0 = 0;
        return 0;
    }
    if (FileFlushBuffer(a, 0) != 0) {
        a->mFailed = 1;
        a->mBufferRemaining = 0;
        return -1;
    }
    a->field8_0 = 0;
    a->field18 = 0;
    a->mBufferRemaining = 0;
    return 0;
}

u32 fwrite(const char *a, u32 b, u32 c, FILE *d) {
    int i;
    OSMutex *p;
    u32 r;

    if (d == &data_0216eb7c[1]) {
        i = 3;
    } else if (d == &data_0216eb7c[2]) {
        i = 4;
    } else {
        i = 5;
    }
    p = (OSMutex *) g_AnotherMutex[i];
    if (OS_TryLockMutex(p) == 0) {
        g_SomeThreadId[i] = g_Os_ThreadInfo.mListHead->mId;
        g_SomeCounter[i] = 1;
    } else {
        u32 v;

        v = g_SomeThreadId[i];
        if (v == g_Os_ThreadInfo.mListHead->mId) {
            g_SomeCounter[i]++;
        } else {
            OS_LockMutex(p);
            g_SomeThreadId[i] = g_Os_ThreadInfo.mListHead->mId;
            g_SomeCounter[i] = 1;
        }
    }
    r = FwriteBody(a, b, c, d);
    if (--g_SomeCounter[i] == 0) {
        OS_UnlockMutex(p);
    }
    return r;
}

#pragma avoid_byte all

#include "code_02133e50.h"

u32 FwriteBody(const char *a, u32 b, u32 c, FILE *d) {
    u32 n;
    u32 t;
    u32 v;
    u32 l;
    int m;
    char *q;
    u8 *s1;
    u32 s2;

    if (fwide(d, 0) == 0) {
        fwide(d, -1);
    }
    n = b * c;
    if (n == 0 || d->mFailed != 0 || d->field4_7 == 0) {
        return 0;
    }
    if (d->field4_7 == 2) {
        nullsub_18();
    }
    m = 1;
    if (d->field4_12 != 0) {
        if (d->field4_5 != 2 && d->field4_5 != 1) {
            m = 0;
        }
    }
    if (d->field8_0 == 0 && (d->field4_2 & 2) != 0) {
        d->field8_0 = 1;
        FileResetBuffer(d);
    }
    if (d->field8_0 != 1) {
        d->mFailed = 1;
        d->mBufferRemaining = 0;
        return 0;
    }
    t = 0;
    if (n != 0 && (d->mBufferNext != d->mBuffer || m != 0)) {
        d->mBufferRemaining = d->mBufferSize - (d->mBufferNext - d->mBuffer);
        v = 10;
        do {
            q = 0;
            l = d->mBufferRemaining;
            if (l > n) {
                l = n;
            }
            if (d->field4_5 == 1 && l != 0) {
                q = MemChrBackward(a, v, l);
                if (q != 0) {
                    l = q + 1 - a;
                }
            }
            if (l != 0) {
                memcpy(d->mBufferNext, a, l);
                a += l;
                n -= l;
                d->mBufferNext += l;
                d->mBufferRemaining -= l;
            }
            if (d->mBufferRemaining == 0 || q != 0 || d->field4_5 == 0) {
                if (FileFlushBuffer(d, 0) != 0) {
                    d->mFailed = 1;
                    n = 0;
                    d->mBufferRemaining = n;
                    break;
                }
            }
            t += l;
        } while (n != 0 && m != 0);
    }
    if (n != 0 && m == 0) {
        s1 = d->mBuffer;
        s2 = d->mBufferSize;
        d->mBuffer = (u8 *) a;
        d->mBufferSize = n;
        d->mBufferNext = (u8 *) a + n;
        if (FileFlushBuffer(d, &l) == 0) {
            t += l;
        } else {
            d->mFailed = 1;
            d->mBufferRemaining = 0;
        }
        d->mBuffer = s1;
        d->mBufferSize = s2;
        FileResetBuffer(d);
        d->mBufferRemaining = 0;
    }
    if (d->field4_5 != 2) {
        d->mBufferRemaining = 0;
    }
    return t / b;
}

void nullsub_17(u8 *a, u32 *b) {}

void FileResetBuffer(FILE *a) {
    a->mBufferNext = a->mBuffer;
    a->mBufferRemaining = a->mBufferSize;
    a->mBufferRemaining = a->mBufferRemaining - (a->field18 & a->field2C);
    a->field34 = a->field18;
}

int FileFlushBuffer(FILE *a, u32 *b) {
    int n;
    int r;

    n = a->mBufferNext - a->mBuffer;
    if (n != 0) {
        a->mBufferRemaining = n;
        if (a->field4_12 == 0) {
            nullsub_17(a->mBuffer, &a->mBufferRemaining);
        }
        r = a->mWriteFunc(a->field0, a->mBuffer, &a->mBufferRemaining, a->field48);
        if (b != 0) {
            *b = a->mBufferRemaining;
        }
        if (r != 0) {
            return r;
        }
        a->field18 = a->field18 + a->mBufferRemaining;
    }
    FileResetBuffer(a);
    return 0;
}

void AssertionFailed(const char *a, const char *b, const char *c, int d) {
    printf("Assertion (%s) failed in \"%s\", function \"%s\", line %d\n", a, b, c, d);
    abort();
}

u32 Abs(u32 arg0) {
    u32 value0 = arg0;
    s32 compareLeft0;
    s32 compareRight0;
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 < compareRight0) {
        value0 = (0u) - (value0);
    }
    return value0;
}

#pragma avoid_byte all

int FflushAll(void) {
    int r;
    int i;
    FILE *p;

    r = 0;
    i = 1;
    p = data_0216eb7c;
    do {
        if (p->field4_7 != 0) {
            if (fflush(p) != 0) {
                r = -1;
            }
        }
        p = (i < 3) ? &data_0216eb7c[i++] : 0;
    } while (p != 0);
    return r;
}

double nan(const char *a) {
    return data_0216ec9c;
}
