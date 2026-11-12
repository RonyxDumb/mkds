#pragma once

#include "types.h"

extern void *gQr2RegisteredKeyList[254];

void qr2_register_keyA(s32 keyid, void *key);
