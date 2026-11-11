#pragma once

#include "types.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"

u32 DWCi_QR2AddErrorCallback(u32 error);
s32 DWCi_QR2CountCallback(void);
void AddMatchingKeyIds(s32 keytype, MatchingKeyIds *keyIds, void *userdata);
void DWCi_QR2TeamKeyCallback(void);
void DWCi_QR2PlayerKeyCallback(void);
