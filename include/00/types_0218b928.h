#pragma once

#include "types.h"

// Values of KeyInfo.mKeyType: how the key's value is stored in a server record, as a string index, one byte or two
// bytes.
enum {
    SERVER_KEY_STORED_AS_STRING_INDEX,
    SERVER_KEY_STORED_AS_ONE_BYTE,
    SERVER_KEY_STORED_AS_TWO_BYTES,
};

// Entry of the list at SbServerList.mUnk_008.
typedef struct KeyInfo {
    /* 0 */ char *mKeyName;
    /* 4 */ s32 mKeyType;
} KeyInfo;
