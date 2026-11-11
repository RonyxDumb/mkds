#pragma once

#include "types.h"

extern void *gQr2RegisteredKeyList[255];

void qr2_register_keyA(s32 keyid, void *key);
