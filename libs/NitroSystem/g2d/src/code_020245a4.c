#include "code_020245a4.h"
#include "code_0200fc8c.h"

u16 NNSi_G2dSplitCharUTF16(u16 **a) {
    u16 *p;
    u16 c;

    p = *a;
    c = *p++;
    *a = p;
    return c;
}

static inline s32 NNSi_G2dIsBinFileSignatureValid(Unk02021f9c *a) {
    if (a != 0 && a->mUnk_00 == 0x4e465452) {
        return 1;
    }
    return 0;
}

static inline s32 NNSi_G2dIsBinFileVersionValid(Unk02021f9c *a, u16 v) {
    if (a != 0 && a->mUnk_06 == v) {
        return 1;
    }
    return 0;
}

static inline s32 NNS_G2dIsBinFileValid(Unk02021f9c *a, u16 v) {
    if (a != 0) {
        return NNSi_G2dIsBinFileSignatureValid(a) && NNSi_G2dIsBinFileVersionValid(a, v);
    }
    return 0;
}

u16 NNSi_G2dSplitCharUTF8(u8 **a) {
    u8 *p;
    u16 c;

    p = *a;
    c = *p;
    if ((c & 0x80) == 0) {
        *a = p + 1;
    } else if ((c & 0xe0) == 0xc0) {
        c = ((c & 0x1f) << 6) | (p[1] & 0x3f);
        *a = p + 2;
    } else {
        c = ((c & 0x1f) << 12) | ((p[1] & 0x3f) << 6) | (p[2] & 0x3f);
        *a = p + 3;
    }
    return c;
}

u16 NNSi_G2dSplitCharShiftJIS(u8 **a) {
    u16 c;
    u8 *p;

    p = *a;
    c = *p;
    if ((c >= 0x81 && c < 0xa0) || c >= 0xe0) {
        c = p[1] | (c << 8);
        *a = *a + 2;
    } else {
        *a = *a + 1;
    }
    return c;
}

u16 NNSi_G2dSplitChar1Byte(u8 **a) {
    u8 *p;
    u8 c;

    p = *a;
    c = *p++;
    *a = p;
    return c;
}

u32 NNSi_G2dBitReaderRead(NNSiG2dBitReader *a, s32 b) {
    s32 n;
    u32 c;
    u32 r;
    u8 *p;

    n = a->mAvailableBits;
    c = a->mBits;
    if (n < b) {
        p = a->mSrc;
        a->mSrc = p + 1;
        r = c << (b - n);
        a->mBits = *p;
        a->mAvailableBits = 8;
        r = NNSi_G2dBitReaderRead(a, b - n) | r;
    } else {
        a->mAvailableBits = n - b;
        r = c >> (n - b);
    }
    return r & (0xff >> (8 - b));
}

u32 NNSi_G2dGetUnpackedFont(Unk02021f9c *a, Unk02022ce4 **b) {
    u32 r;
    Unk02021fd0 *p;

    if (NNS_G2dIsBinFileValid(a, 0x100)) {
        r = 0;
    } else if (NNS_G2dIsBinFileValid(a, 1)) {
        r = 1;
    } else {
        OS_Terminate();
    }
    NNSi_G2dUnpackNFT(a);
    p = FindPartByTag(a, 0x46494e46);
    if (p == 0) {
        *b = 0;
        return 0;
    }
    *b = (Unk02022ce4 *) (p + 1);
    if (r != 0) {
        (*b)->mUnk_07 = (*b)->mUnk_04.mCharWidth;
        (*b)->mUnk_04.mCharWidth = 0;
    }
    return r + 1;
}

void NNSi_G2dUnpackNFT(Unk02021f9c *a) {
    Unk02021fd0 *p;
    s32 i;
    Unk020245a4_08 *q;

    p = OFFSET_PTR(Unk02021fd0, a, a->mUnk_0c);
    for (i = 0; i < a->mUnk_0e; i++) {
        switch (p->mUnk_00) {
            case 0x46494e46:
                q = (Unk020245a4_08 *) (p + 1);
                q->mUnk_04[1] += (u32) a;
                if (q->mUnk_04[2] != 0) {
                    q->mUnk_04[2] += (u32) a;
                }
                if (q->mUnk_04[3] != 0) {
                    q->mUnk_04[3] += (u32) a;
                }
                break;
            case 0x43574448:
                q = (Unk020245a4_08 *) (p + 1);
                if (q->mUnk_04[0] != 0) {
                    q->mUnk_04[0] += (u32) a;
                }
                break;
            case 0x434d4150:
                q = (Unk020245a4_08 *) (p + 1);
                if (q->mUnk_04[1] != 0) {
                    q->mUnk_04[1] += (u32) a;
                }
                break;
            case 0x43474c50:
                break;
        }
        p = OFFSET_PTR(Unk02021fd0, p, p->mUnk_04);
    }
}
