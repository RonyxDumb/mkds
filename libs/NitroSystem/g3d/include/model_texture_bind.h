#pragma once

#include "types.h"
#include "texture_resource_type.h"
#include "model_material_set.h"

u32 OsCountZeroBits(u32 bitmap);

// Filled by OS_GetLowEntropyData.
typedef struct LowEntropyData {
    /* 00 */ u32 mTickAndVcount;
    /* 04 */ u32 mMacAddressAndTickOverflow;
    /* 08 */ u32 mTickOverflowMacAddressVblankAndGxStat;
    /* 0c */ u32 mRealTimeClockFirstWord;
    /* 10 */ u32 mClockSecond;
    /* 14 */ u32 mMicrophone;
    /* 18 */ u32 mTouchPanel;
    /* 1c */ u32 mWmRssiPoolAndButtons;
} LowEntropyData;

typedef struct NNSG3dResMdlSet {
    /* 00 */ NNSG3dResDataBlockHeader mHeader;
    /* 08 */ NNSG3dResDict mDict;
} NNSG3dResMdlSet;

typedef struct NNSG3dResDictTexToMatIdxData {
    /* 00 */ u16 mOffset;
    /* 02 */ u8 mNumIdx;
    /* 03 */ u8 mFlag;
} NNSG3dResDictTexToMatIdxData;

// Bit k set: VRAM bank k (0 to 8) is locked.
extern u32 gVramBankLockedMask;
// Id that locked bank k; 0 when the bank is not locked.
extern u16 gVramBankLockIds[9];

// Under OS_DisableInterrupts: for each locked bank of bank & 0x1ff whose lock id equals lockId, clears the lock bit
// and the id. Other banks are left alone.
void OSi_UnlockVram(u32 bank, u16 lockId);
// Under OS_DisableInterrupts: returns 0 and changes nothing when a bank of bank is already locked with an id other
// than lockId. Otherwise locks every bank of bank & 0x1ff with lockId and returns 1.
u32 OSi_TryLockVram(u32 bank, u16 lockId);
// Sets the locked-bank mask and the nine bank lock ids to 0. Called once by the start-up function.
void OSi_InitVramExclusive(void);
void OS_GetLowEntropyData(LowEntropyData *buffer);
void NNS_G3dReleaseMdlSet(NNSG3dResMdlSet *mdlSet);
u32 NNS_G3dBindMdlSet(NNSG3dResMdlSet *mdlSet, NNSG3dResTex *tex);
u32 NNS_G3dReleaseMdlPlttEx(NNSG3dResMdl *mdl, const u32 *name);
void NNS_G3dReleaseMdlPltt(NNSG3dResMdl *mdl);
u32 NNS_G3dBindMdlPlttEx(NNSG3dResMdl *mdl, NNSG3dResTex *tex, const u32 *name);
u32 NNS_G3dBindMdlPltt(NNSG3dResMdl *mdl, NNSG3dResTex *tex);
void bindMdlPltt_Internal_(NNSG3dResMat *mat, NNSG3dResDictTexToMatIdxData *data, NNSG3dResTex *tex,
                           NNSG3dResDictPlttData *plttData);
u32 NNS_G3dReleaseMdlTexEx(NNSG3dResMdl *mdl, const u32 *name);
void NNS_G3dReleaseMdlTex(NNSG3dResMdl *mdl);
int NNS_G3dBindMdlTexEx(NNSG3dResMdl *mdl, NNSG3dResTex *tex, const u32 *name);
int NNS_G3dBindMdlTex(NNSG3dResMdl *mdl, NNSG3dResTex *tex);
void releaseMdlTex_Internal_(NNSG3dResMat *mat, NNSG3dResDictTexToMatIdxData *data);
void bindMdlTex_Internal_(NNSG3dResMat *mat, NNSG3dResDictTexToMatIdxData *data, NNSG3dResTex *tex,
                          NNSG3dResDictTexData *texData);
