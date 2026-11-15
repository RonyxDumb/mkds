#include "capture_output_effect.h"
#include "arena_cache_init.h"
#include "reset_interrupt_enable.h"
#include "sound_command_requests.h"
#include "thread_scheduler.h"
#include "cpu_copy_clear_16.h"
#include "sound_capture_effect.h"
#include "cpu_copy_fill.h"
#include "Main/System/stdio_files.h"
#include "print_memory_functions.h"

CallbackInfo sCallbackInfo = {-1};

// Sets the output effect to type, then starts an effect capture of 32000 Hz with two parts, handled by EffectCallback.
void NNS_SndCaptureStartOutputEffect(void *buffer, u32 bufSize, s32 type) {
    NNS_SndCaptureChangeOutputEffect(type);
    NNS_SndCaptureStartEffect(buffer, bufSize, 0, 32000, 2, EffectCallback, &sCallbackInfo);
}

// Does nothing when type is already set. Otherwise clears CallbackInfo.mBuffer, stores type in CallbackInfo.mType and
// the matching function (type 0 to 3: NothingProc, SurroundProc, HeadphoneProc, MonoProc) in CallbackInfo.mEffectFunc;
// the surround decay is reset first when the old type is 1 and set to 0x3000 last when type is 1.
void NNS_SndCaptureChangeOutputEffect(s32 type) {
    u32 enabled;
    volatile u16 zero;

    if (type == sCallbackInfo.mType) {
        return;
    }
    if (sCallbackInfo.mType == SOUND_OUTPUT_EFFECT_SURROUND) {
        SNDi_SetSurroundDecay(0);
    }
    enabled = OS_DisableInterrupts();
    zero = 0;
    MIi_CpuClear16(zero, &sCallbackInfo.mBuffer, 0xc0);
    sCallbackInfo.mType = type;
    switch (type) {
        case SOUND_OUTPUT_EFFECT_SURROUND:
            sCallbackInfo.mEffectFunc = SurroundProc;
            break;
        case SOUND_OUTPUT_EFFECT_HEADPHONE:
            sCallbackInfo.mEffectFunc = HeadphoneProc;
            break;
        case SOUND_OUTPUT_EFFECT_MONO:
            sCallbackInfo.mEffectFunc = MonoProc;
            break;
        case SOUND_OUTPUT_EFFECT_NONE:
            sCallbackInfo.mEffectFunc = NothingProc;
            break;
        default:
            sCallbackInfo.mEffectFunc = NothingProc;
            break;
    }
    OS_RestoreInterrupts(enabled);
    if (type == SOUND_OUTPUT_EFFECT_SURROUND) {
        SNDi_SetSurroundDecay(0x3000);
    }
}

// Capture callback: runs CallbackInfo.mCbFunc, CallbackInfo.mEffectFunc and CallbackInfo.mCbPostFunc on the buffers
// (the callbacks only when not null), then flushes both.
void EffectCallback(void *bufferL, void *bufferR, u32 len, u32 format, void *arg) {
    CallbackInfo *info = arg;

    if (info->mCbFunc != 0) {
        info->mCbFunc(bufferL, bufferR, len, format, info->mCbArg);
    }
    info->mEffectFunc(bufferL, bufferR, len, info);
    if (info->mCbPostFunc != 0) {
        info->mCbPostFunc(bufferL, bufferR, len, format, info->mCbPostArg);
    }
    DC_FlushRange(bufferL, len);
    DC_FlushRange(bufferR, len);
}

// Does nothing.
void NothingProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info) {}

// Cross-feeds the channels with a delay of two samples: works on the last two entries of the buffers first, then on
// the rest from the end, with 16-bit clamping, and keeps the two delayed values in CallbackInfo.mBuffer.
void SurroundProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info) {
    s16 saved[2];
    u32 sampleCount;
    s32 savedIndex;
    s32 tailIndex;
    s32 delayIndex;
    s32 newLeft;
    s32 newRight;
    s32 diff;
    s16 *leftPtr;
    s16 *rightPtr;

    sampleCount = len >> 1;
    for (savedIndex = 0; savedIndex < 2; savedIndex++) {
        diff = *(bufferL + sampleCount + savedIndex - 2) - *(bufferR + sampleCount + savedIndex - 2);
        if (diff < -32768) {
            diff = -32768;
        } else if (diff > 32767) {
            diff = 32767;
        }
        saved[savedIndex] = diff;
    }
    leftPtr = bufferL + (sampleCount - 1);
    rightPtr = bufferR + (sampleCount - 1);
    for (; leftPtr >= bufferL + 2; leftPtr--, rightPtr--) {
        diff = leftPtr[-2] - rightPtr[-2];
        newLeft = leftPtr[0] + diff;
        newRight = rightPtr[0] - diff;
        if (diff >= 0) {
            if (newLeft < 32767) {
                leftPtr[0] = newLeft;
            } else {
                leftPtr[0] = 32767;
            }
            if (newRight > -32768) {
                rightPtr[0] = newRight;
            } else {
                rightPtr[0] = -32768;
            }
        } else {
            if (newLeft > -32768) {
                leftPtr[0] = newLeft;
            } else {
                leftPtr[0] = -32768;
            }
            if (newRight < 32767) {
                rightPtr[0] = newRight;
            } else {
                rightPtr[0] = 32767;
            }
        }
    }
    for (tailIndex = 1; tailIndex >= 0; tailIndex--) {
        newLeft = bufferL[tailIndex] + info->mBuffer.surround[tailIndex];
        if (newLeft < -32768) {
            newLeft = -32768;
        } else if (newLeft > 32767) {
            newLeft = 32767;
        }
        bufferL[tailIndex] = newLeft;
        newRight = bufferR[tailIndex] - info->mBuffer.surround[tailIndex];
        if (newRight < -32768) {
            newRight = -32768;
        } else if (newRight > 32767) {
            newRight = 32767;
        }
        bufferR[tailIndex] = newRight;
    }
    for (delayIndex = 0; delayIndex < 2; delayIndex++) {
        info->mBuffer.surround[delayIndex] = saved[delayIndex];
    }
}

// Adds the pairs in CallbackInfo.mBuffer to the buffers in blocks of 24 entries with 16-bit clamping and stores new
// pairs.
void HeadphoneProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info) {
    u32 sampleCount;
    u32 rest;
    s32 sampleIndex;
    s32 restLeft;
    s32 left;
    s32 right;
    u32 offset;
    s32 clampedLeft;
    s32 clampedRight;

    sampleCount = len >> 1;
    offset = 0;
    while (sampleCount > offset + 24) {
        for (sampleIndex = 0; sampleIndex < 24; sampleIndex++) {
            left = bufferL[sampleIndex + offset];
            left += info->mBuffer.headphone[sampleIndex][0];
            right = bufferR[sampleIndex + offset];
            right += info->mBuffer.headphone[sampleIndex][1];
            clampedLeft = left;
            if (left < -32768) {
                clampedLeft = -32768;
            } else if (left > 32767) {
                clampedLeft = 32767;
            }
            bufferL[sampleIndex + offset] = clampedLeft;
            clampedRight = right;
            if (right < -32768) {
                clampedRight = -32768;
            } else if (right > 32767) {
                clampedRight = 32767;
            }
            bufferR[sampleIndex + offset] = clampedRight;
            info->mBuffer.headphone[sampleIndex][0] = (right + 1) >> 2;
            info->mBuffer.headphone[sampleIndex][1] = (left + 1) >> 2;
        }
        offset += 24;
    }
    rest = sampleCount - offset;
    for (sampleIndex = 0; sampleIndex < rest; sampleIndex++) {
        restLeft = bufferL[sampleIndex + offset];
        restLeft += info->mBuffer.headphone[sampleIndex][0];
        right = bufferR[sampleIndex + offset];
        right += info->mBuffer.headphone[sampleIndex][1];
        if (restLeft < -32768) {
            restLeft = -32768;
        } else if (restLeft > 32767) {
            restLeft = 32767;
        }
        bufferL[sampleIndex + offset] = restLeft;
        if (right < -32768) {
            right = -32768;
        } else if (right > 32767) {
            right = 32767;
        }
        bufferR[sampleIndex + offset] = right;
    }
    for (sampleIndex = 0; sampleIndex < 24 - rest; sampleIndex++) {
        info->mBuffer.headphone[sampleIndex][0] = (info->mBuffer.headphone + rest)[sampleIndex][0];
        info->mBuffer.headphone[sampleIndex][1] = (info->mBuffer.headphone + rest)[sampleIndex][1];
    }
    for (sampleIndex = 0; sampleIndex < rest; sampleIndex++) {
        info->mBuffer.headphone[24 + sampleIndex - rest][0] = (bufferR[sampleIndex + offset] + 1) >> 2;
        info->mBuffer.headphone[24 + sampleIndex - rest][1] = (bufferL[sampleIndex + offset] + 1) >> 2;
    }
}

// Replaces the left buffer with the rounded average of both channels, then copies it over the right buffer.
void MonoProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info) {
    u32 sampleCount;
    u32 sampleIndex;

    sampleCount = len >> 1;
    for (sampleIndex = 0; sampleIndex < sampleCount; sampleIndex++) {
        bufferL[sampleIndex] = (bufferL[sampleIndex] + bufferR[sampleIndex] + 1) >> 1;
    }
    MIi_CpuCopyFast(bufferL, bufferR, len);
}
