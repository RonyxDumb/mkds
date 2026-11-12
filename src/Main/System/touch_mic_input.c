#include "Main/System/touch_mic_input.h"
#include "Main/System/heap.h"
#include "Main/Sound/mic_auto_sampling.h"
#include "Main/Sound/mic_buffer_sleep.h"
#include "Main/Sound/mic_init.h"
#include "tp.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Race/data_021759c0.h"

void StartTouchAutoSampling(void) {
    if (gTouchMicInput->mTouchAutoSampling != 0) {
        return;
    }
    TP_RequestAutoSamplingStartAsync(0xa, 4, gTouchMicInput->mAutoSamples, 5);
    TP_WaitBusy(2);
    TP_CheckError(2);
    gTouchMicInput->mTouchAutoSampling = 1;
}

void StartMicInput(void *heap) {
    if (gTouchMicInput->mMicAutoSampling != 0) {
        return;
    }
    gTouchMicInput->mMicBuffer = HeapAllocAligned(heap, 0x420, 0x20);
    SetupMicAutoSampling(gTouchMicInput->mMicBuffer);
    StartMicAutoSampling(gTouchMicInput->mMicBuffer);
    gTouchMicInput->mMicAutoSampling = 1;
    gTouchMicInput->mMicPreSleepDone = 0;
    gTouchMicInput->mMicOverThreshold = 0;
}

void StopTouchAutoSampling(void) {
    if (gTouchMicInput->mTouchAutoSampling == 0) {
        return;
    }
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    TP_CheckError(4);
    gTouchMicInput->mTouchAutoSampling = 0;
}

void StopMicInput(void) {
    if (gTouchMicInput->mMicAutoSampling == 0) {
        return;
    }
    StopMicAutoSampling(gTouchMicInput->mMicBuffer);
    gTouchMicInput->mMicBuffer = NULL;
    gTouchMicInput->mMicAutoSampling = 0;
    gTouchMicInput->mMicPreSleepDone = 0;
}

void PreSleepMicInput(void) {
    TouchMicInput *touchMicInput;

    touchMicInput = gTouchMicInput;
    if (touchMicInput->mMicAutoSampling == 0) {
        return;
    }
    if (touchMicInput->mMicPreSleepDone == 0) {
        PreSleepMicBuffer(touchMicInput->mMicBuffer);
    }
    gTouchMicInput->mMicPreSleepDone = 1;
}

void PostSleepMicInput(void) {
    TouchMicInput *touchMicInput;

    touchMicInput = gTouchMicInput;
    if (touchMicInput->mMicAutoSampling == 0) {
        return;
    }
    if (touchMicInput->mMicPreSleepDone) {
        PostSleepMicBuffer(touchMicInput->mMicBuffer);
    }
    gTouchMicInput->mMicPreSleepDone = 0;
}

void UpdateTouchMicInput(void) {
    TouchMicInput *touchMicInput;
    u32 latestIndex;

    latestIndex = TP_GetLatestIndexInAuto();
    touchMicInput = gTouchMicInput;
    touchMicInput->mCalibratedPoint = touchMicInput->mAutoSamples[latestIndex];
    TP_GetCalibratedPoint(&touchMicInput->mCalibratedPoint, &touchMicInput->mCalibratedPoint);
    if (gTouchMicInput->mMicAutoSampling) {
        gTouchMicInput->mMicOverThreshold = UpdateMicBufferInput(gTouchMicInput->mMicBuffer) > 0x14;
    }
}

void UpdateInputSlotPair(InputSlotPair *pair, s32 packedTouchPoint, s32 micOverThreshold) {
    TPData point;
    u32 pointY;
    s32 pointX;

    if (gTouchMicInput->mTouchAutoSampling) {
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
        *(TPData *) &pair->mPrevPairX = *(TPData *) pair;
        *(TPData *) pair = point;
        if (pair->mHasPair != 0) {
            pair->mNoPairCount = 0;
        } else if (pair->mNoPairCount <= 5) {
            pair->mNoPairCount++;
        }
    }
    if (gTouchMicInput->mMicAutoSampling) {
        pair->mMicOverThreshold[0] = micOverThreshold;
    }
}

void ReleaseTouchMicInput(void) {
    TouchMicInputStopMicAutoSampling(gTouchMicInput->mMicBuffer);
    gTouchMicInput = NULL;
}

u16 GetPackedTouchPoint(void) {
    TouchMicInput *touchMicInput;
    TPData *calibratedPoint;
    u32 pointX;
    u32 pointY;

    touchMicInput = gTouchMicInput;
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
