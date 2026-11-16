#pragma once

#include "types.h"

// Values of KeyInfo.mKeyType: how a key's value is laid out in the server list data, as a string, one byte or two
// bytes.
enum {
    SERVER_KEY_STORED_AS_STRING,
    SERVER_KEY_STORED_AS_ONE_BYTE,
    SERVER_KEY_STORED_AS_TWO_BYTES,
};

// Entry of the list at SBServerList.mKeyList.
typedef struct KeyInfo {
    /* 0 */ char *mKeyName;
    /* 4 */ s32 mKeyType;
} KeyInfo;
