#pragma once

#include "types.h"
#include "00/code_0218f960.h"

// 0xac-byte array element GpiUpdateSearch fills.
typedef struct ProfileMatch {
    /* 00 */ s32 mProfile;
    /* 04 */ char mUnk_04[0x1f];
    /* 23 */ char mUnk_23[0x15];
    /* 38 */ char mUnk_38[0x1f];
    /* 57 */ char mUnk_57[0x1f];
    /* 76 */ char mUnk_76[0x36];
} ProfileMatch;

// 0x128-byte array element GpiUpdateSearch fills.
typedef struct PlayerMatch {
    /* 000 */ s32 mUnk_000;
    /* 004 */ char mUnk_004[0x20];
    /* 024 */ s32 mUnk_024;
    /* 028 */ char mUnk_028[0x100];
} PlayerMatch;

// 0x10-byte local of GpiUpdateSearch passed to GpiCallback.mCallback.
typedef struct Unk02194cac_10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ ProfileMatch *mUnk_0c;
} Unk02194cac_10;

// Objects GpiUpdateSearch allocates and passes to GpiQueueCallback.
typedef struct GpCheckNewUserResponseArg {
    /* 00 */ s32 mResult;
    /* 04 */ s32 mProfile;
} GpCheckNewUserResponseArg;

typedef struct ReverseBuddiesReply {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ ProfileMatch *mUnk_08;
} ReverseBuddiesReply;

typedef struct SuggestNickReply {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ char **mUnk_08;
} SuggestNickReply;

typedef struct FindPlayersReply {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ PlayerMatch *mUnk_0c;
} FindPlayersReply;

typedef struct EmailCheckReply {
    /* 00 */ s32 mUnk_00;
    /* 04 */ char mUnk_04[0x34];
    /* 38 */ BOOL mUnk_38;
} EmailCheckReply;

typedef struct UserNicksReply {
    /* 00 */ s32 mUnk_00;
    /* 04 */ char mUnk_04[0x34];
    /* 38 */ s32 mUnk_38;
    /* 3c */ char **mUnk_3c;
    /* 40 */ char **mUnk_40;
} UserNicksReply;

extern char data_ov000_021b35b8[];
extern u8 data_ov000_021b35f8[];
extern char data_ov000_021b3608[];
extern char data_ov000_021b3628[];
extern s8 data_ov000_021b3634[];
extern char data_ov000_021b3638[];
extern u8 data_ov000_021b3664[];
extern u8 data_ov000_021b3670[];
extern u8 data_ov000_021b367c[];
extern u8 data_ov000_021b3688[];
extern u8 data_ov000_021b3698[];
extern u8 data_ov000_021b36a0[];
extern u8 data_ov000_021b36b0[];
extern u8 data_ov000_021b36b8[];
extern u8 data_ov000_021b36c4[];
extern u8 data_ov000_021b36d0[];
extern u8 data_ov000_021b36dc[];
extern u8 data_ov000_021b36e4[];
extern u8 data_ov000_021b36ec[];
extern u8 data_ov000_021b36f4[];
extern u8 data_ov000_021b36fc[];
extern u8 data_ov000_021b3708[];
extern u8 data_ov000_021b3714[];
extern u8 data_ov000_021b371c[];
extern u8 data_ov000_021b3728[];
extern u8 data_ov000_021b3734[];
extern u8 data_ov000_021b373c[];
extern u8 data_ov000_021b3748[];
extern u8 data_ov000_021b3758[];
extern char data_ov000_021b3768[];
extern u8 data_ov000_021b376c[];
extern char data_ov000_021b3778[];
extern char data_ov000_021b3780[];
extern char data_ov000_021b37ac[];
extern char data_ov000_021b37b4[];
extern char data_ov000_021b37bc[];
extern char data_ov000_021b37c0[];
extern char data_ov000_021b37c8[];
extern char data_ov000_021b37d4[];
extern char data_ov000_021b37e0[];
extern char data_ov000_021b37ec[];
extern char data_ov000_021b37f4[];
extern char data_ov000_021b381c[];
extern char data_ov000_021b3820[];
extern char data_ov000_021b3824[];
extern char data_ov000_021b382c[];
extern char data_ov000_021b3834[];
extern char data_ov000_021b3838[];
extern char data_ov000_021b3840[];
extern char data_ov000_021b384c[];
extern char data_ov000_021b3850[];
extern char data_ov000_021b3858[];
extern char data_ov000_021b385c[];
extern char data_ov000_021b3864[];
extern char data_ov000_021b386c[];
extern char data_ov000_021b3870[];
extern char data_ov000_021b3878[];
extern char data_ov000_021b3880[];
extern char data_ov000_021b3884[];
extern char data_ov000_021b388c[];
extern char data_ov000_021b38c0[];
extern char data_ov000_021b38e8[];
extern char data_ov000_021b391c[];
extern char data_ov000_021b394c[];
extern char data_ov000_021b396c[];
extern char data_ov000_021b3994[];
extern char data_ov000_021b399c[];

BOOL GpiUpdateSearches(GpConnection *connection);
s32 GpiUpdateSearch(GpConnection *connection, GpiOperation *operation);
int gpiProfileSearch(GpConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                         int icquin, int skip, u32 blocking, u32 callback, u32 param);
int GpiStartSearchOperation(GpConnection *connection, u32 data, u32 blocking, u32 callback, u32 param);
BOOL GpiCreateSearch(GpConnection *connection, GPISearchData **searchData, u32 kind);
s32 GpiOpenSearchSocket(GpConnection *connection, GpiOperation *operation);
void gpiHandleTransferMessage(GpConnection *connection, GpiPeer *peer, s32 type, const char *headers, s32 buffer,
                              s32 len);
