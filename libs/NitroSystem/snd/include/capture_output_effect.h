#pragma once

#include "types.h"
#include "sound_capture_effect.h" // NNSSndCaptureCallback

struct CallbackInfo;

typedef void (*EffectFunc)(s16 *bufferL, s16 *bufferR, u32 len, struct CallbackInfo *info);

// Values of CallbackInfo.mType (-1 until the first change): which effect runs on the captured sound.
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
