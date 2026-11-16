#pragma once

#include "types.h"
#include "00/Lib/GameSpy/query_reporting.h"

extern void *gQr2RegisteredKeyList[REPORT_KEY_MAX];

void qr2_register_keyA(s32 keyid, void *key);
