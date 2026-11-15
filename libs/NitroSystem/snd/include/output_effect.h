#pragma once

#include "types.h"
#include "code_0212c9d4.h" // NNSSndCaptureCallback

struct CallbackInfo;

typedef void (*EffectFunc)(s16 *bufferL, s16 *bufferR, u32 len, struct CallbackInfo *info);

// 0xd8-byte object (sCallbackInfo): EffectCallback calls mCbFunc, then mEffectFunc, then mCbPostFunc (the callbacks
// only when not null) and flushes both buffers. NNS_SndCaptureChangeOutputEffect stores the effect type in mType, the
// matching function in mEffectFunc and clears mBuffer. mBuffer holds two words for SurroundProc and 24 pairs of words
// for HeadphoneProc.
// Values of CallbackInfo.mType: which effect runs on the captured sound.
#define SOUND_OUTPUT_EFFECT_NONE 0
#define SOUND_OUTPUT_EFFECT_SURROUND 1
#define SOUND_OUTPUT_EFFECT_HEADPHONE 2
#define SOUND_OUTPUT_EFFECT_MONO 3

typedef struct CallbackInfo {
    /* 00 */ s32 mType;
    /* 04 */ EffectFunc mEffectFunc;
    /* 08 */ NNSSndCaptureCallback mCbFunc;
    /* 0c */ void *mCbArg;
    /* 10 */ NNSSndCaptureCallback mCbPostFunc;
    /* 14 */ void *mCbPostArg;
    union {
        /* 00 */ s32 surround[2];
        /* 00 */ s32 headphone[24][2];
    } /* 18 */ mBuffer;
} CallbackInfo;

void MonoProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info);
void HeadphoneProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info);
void SurroundProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info);
void NothingProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info);
void EffectCallback(void *bufferL, void *bufferR, u32 len, u32 format, void *arg);
void NNS_SndCaptureChangeOutputEffect(s32 type);
void NNS_SndCaptureStartOutputEffect(void *buffer, u32 bufSize, s32 type);
