#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Argument block of the search of gpiCheckProfileForUser.
typedef struct GPIFindProfileByUserData {
    /* 00 */ const char *mNick;
    /* 04 */ const char *mEmail;
    /* 08 */ void **mProfile;
    /* 0c */ BOOL mFound;
} GPIFindProfileByUserData;

s32 gpiFindProfileByUser(GpConnection *connection, const char *nick, const char *email, void **profile);
