#pragma once

#include "types.h"

// Values of the sex members; the profile text carries the sex as the characters 0 and 1 (male and female);
// anything else reads as PROFILE_SEX_CODE_DEFAULT.
enum {
    PROFILE_SEX_CODE_MALE = 0x500,
    PROFILE_SEX_CODE_FEMALE = 0x501,
    PROFILE_SEX_CODE_DEFAULT = 0x502,
};

// Values read from the text, as built by GpiProcessInfoOperation on its stack. The pointers at 0x00 to 0x14 point to
// buffers of its own; 0x1c, 0x27 and 0x34 are arrays inside.
typedef struct GPIInfoCache {
    /* 00 */ char *mNick;
    /* 04 */ char *mUniquenick;
    /* 08 */ char *mEmail;
    /* 0c */ char *mFirstname;
    /* 10 */ char *mLastname;
    /* 14 */ char *mHomepage;
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
    /* cc */ s32 mPic;
    /* d0 */ s32 mOccupationid;
    /* d4 */ s32 mIndustryid;
    /* d8 */ s32 mIncomeid;
    /* dc */ s32 mMarriedid;
    /* e0 */ s32 mChildcount;
    /* e4 */ s32 mInterests1;
    /* e8 */ s32 mOwnership1;
    /* ec */ s32 mConntypeid;
} GPIInfoCache;

// Copy of GPIInfoCache made by gpiInfoCacheToArg, 0x204 bytes.
typedef struct GetInfoReply {
    /* 000 */ u32 mResult;
    /* 004 */ s32 mProfile;
    /* 008 */ char mNick[0x1f];
    /* 027 */ char mUniquenick[0x15];
    /* 03c */ char mEmail[0x33];
    /* 06f */ char mFirstname[0x1f];
    /* 08e */ char mLastname[0x1f];
    /* 0ad */ char mHomepage[0x4c];
    /* 0f9 */ u8 mUnk_0f9[3];
    /* 0fc */ s32 mIcquin;
    /* 100 */ char mZipcode[0xb];
    /* 10b */ char mCountrycode[3];
    /* 10e */ u8 mUnk_10e[2];
    /* 110 */ float mLongitude;
    /* 114 */ float mLatitude;
    /* 118 */ char mPlace[0x80];
    /* 198 */ u32 mBirthday;
    /* 19c */ u32 mBirthmonth;
    /* 1a0 */ u32 mBirthyear;
    /* 1a4 */ s32 mSex;
    /* 1a8 */ s32 mPmask;
    /* 1ac */ char mAimName[0x33];
    /* 1df */ u8 mUnk_1df;
    /* 1e0 */ s32 mPic;
    /* 1e4 */ s32 mOccupationid;
    /* 1e8 */ s32 mIndustryid;
    /* 1ec */ s32 mIncomeid;
    /* 1f0 */ s32 mMarriedid;
    /* 1f4 */ s32 mChildcount;
    /* 1f8 */ s32 mInterests1;
    /* 1fc */ s32 mOwnership1;
    /* 200 */ s32 mConntypeid;
} GetInfoReply;

#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/buddy_messages.h"

u32 GpiWriteUpdateBuffers(GpConnection *connection, GpiBuffer *buffer);
s32 GpiProcessInfoOperation(GpConnection *connection, GpiOperation *operation, const char *input);
void gpiInfoCacheToArg(GPIInfoCache *cache, GetInfoReply *arg);
u32 GpiUnpackDate(GpConnection *connection, s32 date, u32 *day, u32 *month, u32 *year);
