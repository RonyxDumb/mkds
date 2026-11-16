#include "Main/System/touch_mic_input.h"
#include "Main/System/heap.h"
#include "Main/Sound/mic_auto_sampling.h"
#include "Main/Sound/mic_buffer_sleep.h"
#include "Main/Sound/mic_init.h"
#include "touch_panel_sampling.h"
#include "Main/System/input_slots.h"
#include "Main/Race/race_setup_block.h"
#include "Main/Graphics/oam.h"

void StartTouchAutoSampling(void) {
    if (g_Global59C4->mTouchAutoSampling != 0) {
        return;
    }
    TP_RequestAutoSamplingStartAsync(0xa, 4, g_Global59C4->mAutoSamples, 5);
    WaitForTPFlags(2);
    TP_CheckError(2);
    g_Global59C4->mTouchAutoSampling = 1;
}

void CreateGlobal59C4Sub(void *heap) {
    if (g_Global59C4->mMicAutoSampling != 0) {
        return;
    }
    g_Global59C4->mMicBuffer = Mem_AllocateHeapAligned(heap, sizeof(MicBuffer), HEAP_ALIGN_CACHE_LINE);
    Struct59C4Sub_Initialize(g_Global59C4->mMicBuffer);
    Struct59C4Sub_SomeFn(g_Global59C4->mMicBuffer);
    g_Global59C4->mMicAutoSampling = 1;
    g_Global59C4->mMicPreSleepDone = 0;
    g_Global59C4->mMicOverThreshold = 0;
}

void StopTouchAutoSampling(void) {
    if (g_Global59C4->mTouchAutoSampling == 0) {
        return;
    }
    TP_RequestAutoSamplingStopAsync();
    WaitForTPFlags(4);
    TP_CheckError(4);
    g_Global59C4->mTouchAutoSampling = 0;
}

void ResetGlobal59C4Sub(void) {
    if (g_Global59C4->mMicAutoSampling == 0) {
        return;
    }
    StopMicAutoSampling(g_Global59C4->mMicBuffer);
    g_Global59C4->mMicBuffer = NULL;
    g_Global59C4->mMicAutoSampling = 0;
    g_Global59C4->mMicPreSleepDone = 0;
}

void PreSleepMicInput(void) {
    TouchMicInput *touchMicInput;

    touchMicInput = g_Global59C4;
    if (touchMicInput->mMicAutoSampling == 0) {
        return;
    }
    if (touchMicInput->mMicPreSleepDone == 0) {
        Struct59C4Sub_SomeFn_2(touchMicInput->mMicBuffer);
    }
    g_Global59C4->mMicPreSleepDone = 1;
}

void Scene_Race_PostSleepImpl(void) {
    TouchMicInput *touchMicInput;

    touchMicInput = g_Global59C4;
    if (touchMicInput->mMicAutoSampling == 0) {
        return;
    }
    if (touchMicInput->mMicPreSleepDone) {
        Struct59C4Sub_SomeFn_3(touchMicInput->mMicBuffer);
    }
    g_Global59C4->mMicPreSleepDone = 0;
}

void UpdateTouchMicInput(void) {
    TouchMicInput *touchMicInput;
    u32 latestIndex;

    latestIndex = TP_GetLatestIndexInAuto();
    touchMicInput = g_Global59C4;
    touchMicInput->mCalibratedPoint = touchMicInput->mAutoSamples[latestIndex];
    TP_GetCalibratedPoint(&touchMicInput->mCalibratedPoint, &touchMicInput->mCalibratedPoint);
    if (g_Global59C4->mMicAutoSampling) {
        g_Global59C4->mMicOverThreshold = Struct59C4Sub_SomeFn_1(g_Global59C4->mMicBuffer) > 0x14;
    }
}

void UpdateInputSlotPair(InputSlotPair *pair, s32 packedTouchPoint, s32 micOverThreshold) {
    TPData point;
    u32 pointY;
    s32 pointX;

    if (g_Global59C4->mTouchAutoSampling) {
        pointX = (packedTouchPoint >> 8) & 0xff;
        pointY = packedTouchPoint & 0xff;
        if (pointY > 0xbf) {
            point.mY = 0;
            point.mX = 0;
            point.mTouch = 0;
        } else {
            point.mX = pointX;
            point.mY = pointY;
            point.mTouch = 1;
        }
        pair->mPrevPoint = pair->mPoint;
        pair->mPoint = point;
        if (pair->mHasPair != 0) {
            pair->mNoPairCount = 0;
        } else if (pair->mNoPairCount <= INPUT_PAIR_NO_PAIR_COUNT_LIMIT) {
            pair->mNoPairCount++;
        }
    }
    if (g_Global59C4->mMicAutoSampling) {
        pair->mMicOverThreshold[0] = micOverThreshold;
    }
}

void ResetGlobal59C4(void) {
    TouchMicInputStopMicAutoSampling(g_Global59C4->mMicBuffer);
    g_Global59C4 = NULL;
}

u16 GetPackedTouchPoint(void) {
    TouchMicInput *touchMicInput;
    TPData *calibratedPoint;
    u32 pointX;
    u32 pointY;

    touchMicInput = g_Global59C4;
    calibratedPoint = &touchMicInput->mCalibratedPoint;
    if (!touchMicInput->mTouchAutoSampling || calibratedPoint->mTouch == 0 || calibratedPoint->mValidity != 0) {
        pointX = 0xff;
        pointY = pointX;
    } else {
        pointX = calibratedPoint->mX & 0xff;
        pointY = calibratedPoint->mY & 0xff;
    }
    return pointY + (pointX << 8);
}
