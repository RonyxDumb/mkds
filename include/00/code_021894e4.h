#pragma once

#include "types.h"

typedef struct Unk02188ee0 Unk02188ee0;
typedef struct ACSL ACSL;
typedef struct ACFL ACFL;
typedef struct ACWORK ACWORK;

typedef struct Unk02188ee0 Unk02188ee0;

u8 MakeDifferChannelList(s32 findListNum, ACFL *findList, ACSL *searchList, Unk02188ee0 *bssDescs);
u8 MakeUserList(ACWORK *object);
u8 MakeStealthList(ACWORK *object);
u8 MakeAroundList(ACWORK *object);
u32 DWCi_AC_CheckFreespot(Unk02188ee0 *bssDesc);
