#pragma once

#include "types.h"

// Values read from the text, as built by GpiProcessInfoOperation on its stack. The pointers at 0x00 to 0x14 point to
// buffers of its own; 0x1c, 0x27 and 0x34 are arrays inside.
typedef struct GPIInfoCache {
    /* 00 */ char *mUnk_00[6];
    /* 18 */ s32 mIcquin;
    /* 1c */ char mZipcode[0xb];
    /* 27 */ char mCountrycode[3];
    /* 2a */ u8 mUnk_2a[2];
    /* 2c */ float mLongitude;
    /* 30 */ float mLatitude;
    /* 34 */ char mPlace[0x80];
    /* b4 */ u32 mBirthday;
    /* b8 */ u32 mBirthmonth;
    /* bc */ u32 mBirthyear;
    /* c0 */ s32 mSex;
    /* c4 */ s32 mPmask;
    /* c8 */ char *mAimName;
    /* cc */ s32 mUnk_cc[9];
} GPIInfoCache;

// Copy of GPIInfoCache made by gpiInfoCacheToArg, 0x204 bytes.
typedef struct GetInfoReply {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ char mUnk_008[0x1f];
    /* 027 */ char mUnk_027[0x15];
    /* 03c */ char mUnk_03c[0x33];
    /* 06f */ char mUnk_06f[0x1f];
    /* 08e */ char mUnk_08e[0x1f];
    /* 0ad */ char mUnk_0ad[0x4c];
    /* 0f9 */ u8 mUnk_0f9[3];
    /* 0fc */ s32 mUnk_0fc;
    /* 100 */ char mUnk_100[0xb];
    /* 10b */ char mUnk_10b[3];
    /* 10e */ u8 mUnk_10e[2];
    /* 110 */ float mUnk_110;
    /* 114 */ float mUnk_114;
    /* 118 */ char mUnk_118[0x80];
    /* 198 */ u32 mUnk_198;
    /* 19c */ u32 mUnk_19c;
    /* 1a0 */ u32 mUnk_1a0;
    /* 1a4 */ s32 mUnk_1a4;
    /* 1a8 */ s32 mUnk_1a8;
    /* 1ac */ char mUnk_1ac[0x33];
    /* 1df */ u8 mUnk_1df;
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ s32 mUnk_1e4;
    /* 1e8 */ s32 mUnk_1e8;
    /* 1ec */ s32 mUnk_1ec;
    /* 1f0 */ s32 mUnk_1f0;
    /* 1f4 */ s32 mUnk_1f4;
    /* 1f8 */ s32 mUnk_1f8;
    /* 1fc */ s32 mUnk_1fc;
    /* 200 */ s32 mUnk_200;
} GetInfoReply;

#include "00/code_021906e4.h"
#include "00/code_0218f960.h"

u32 GpiWriteUpdateBuffers(GpConnection *connection, GpiBuffer *buffer);
s32 GpiProcessInfoOperation(GpConnection *connection, GpiOperation *operation, const char *input);
void gpiInfoCacheToArg(GPIInfoCache *cache, GetInfoReply *arg);
u32 GpiUnpackDate(u32 *connection, s32 date, u32 *day, u32 *month, u32 *year);
