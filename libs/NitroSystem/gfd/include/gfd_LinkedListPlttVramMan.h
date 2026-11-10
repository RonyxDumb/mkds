#pragma once

#include "types.h"

#include "code_020169a4.h" // NNSiGfdLnkVramBlock

typedef struct NNS_GfdLnkTexVramManager {
    /* 00 */ NNSiGfdLnkVramBlock *mMgrNrm;
    /* 04 */ NNSiGfdLnkVramBlock *mMgr4x4;
    /* 08 */ NNSiGfdLnkVramBlock *mBlockList;
    /* 0c */ u32 mSzByte;
    /* 10 */ u32 mSzByteFor4x4;
    /* 14 */ NNSiGfdLnkVramBlock *mWorkHead;
    /* 18 */ u32 mSzByteManagementWork;
} NNS_GfdLnkTexVramManager;

typedef struct NNS_GfdLnkPlttVramManager {
    /* 00 */ NNSiGfdLnkVramBlock *mMgr;
    /* 04 */ NNSiGfdLnkVramBlock *mBlockList;
    /* 08 */ u32 mSzByte;
    /* 0c */ NNSiGfdLnkVramBlock *mWorkHead;
    /* 10 */ u32 mSzByteManagementWork;
} NNS_GfdLnkPlttVramManager;

typedef struct LnkTexBankData {
    /* 00 */ u32 mSzFree;
    /* 04 */ u32 mSzNrm;
    /* 08 */ u32 mSz4x4;
} LnkTexBankData;

void NNS_GfdResetLnkPlttVramState(void);
s32 NNS_GfdFreeLnkPlttVram(u32 plttKey);
u32 NNS_GfdAllocLnkPlttVram(u32 szByte, s32 b4Pltt, u32 opt);
void NNS_GfdInitLnkPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, int useAsDefault);
