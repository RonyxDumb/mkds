#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Argument block of the search of gpiCheckProfileForUser.
typedef struct GPIFindProfileByUserData {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ void **mUnk_08;
    /* 0c */ BOOL mUnk_0c;
} GPIFindProfileByUserData;

s32 gpiFindProfileByUser(GpConnection *connection, const char *nick, const char *email, void **profile);
