#include "Main/Unknown/code_02046c10.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0210f0d8.h"
#include "Main/Unknown/code_0210f068.h"
#include "Main/Unknown/code_0210f090.h"
#include "Main/Unknown/code_0210f130.h"
#include "tp.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"

void spi_startTouchAutoSampling(void) {
    if (gSpiData->mTouchAutoSampling != 0) {
        return;
    }
    TP_RequestAutoSamplingStartAsync(0xa, 4, gSpiData->mAutoSamples, 5);
    TP_WaitBusy(2);
    TP_CheckError(2);
    gSpiData->mTouchAutoSampling = 1;
}

void spi_startMicAutoSampling(void *heap) {
    if (gSpiData->mMicAutoSampling != 0) {
        return;
    }
    gSpiData->mMicBuffer = heap_allocEx(heap, 0x420, 0x20);
    mic_initAutoSampling(gSpiData->mMicBuffer);
    mic_startAutoSampling(gSpiData->mMicBuffer);
    gSpiData->mMicAutoSampling = 1;
    gSpiData->field30_2 = 0;
    gSpiData->mMicOverThreshold = 0;
}

void spi_stopTouchAutoSampling(void) {
    if (gSpiData->mTouchAutoSampling == 0) {
        return;
    }
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    TP_CheckError(4);
    gSpiData->mTouchAutoSampling = 0;
}

void spi_stopMicAutoSampling(void) {
    if (gSpiData->mMicAutoSampling == 0) {
        return;
    }
    mic_stopAutoSampling(gSpiData->mMicBuffer);
    gSpiData->mMicBuffer = NULL;
    gSpiData->mMicAutoSampling = 0;
    gSpiData->field30_2 = 0;
}

void spi_handlePreSleep(void) {
    TouchMicInput *touchMicInput;

    touchMicInput = gSpiData;
    if (touchMicInput->mMicAutoSampling == 0) {
        return;
    }
    if (touchMicInput->field30_2 == 0) {
        mic_handlePreSleep(touchMicInput->mMicBuffer);
    }
    gSpiData->field30_2 = 1;
}

void spi_handlePostSleep(void) {
    TouchMicInput *touchMicInput;

    touchMicInput = gSpiData;
    if (touchMicInput->mMicAutoSampling == 0) {
        return;
    }
    if (touchMicInput->field30_2) {
        mic_handlePostSleep(touchMicInput->mMicBuffer);
    }
    gSpiData->field30_2 = 0;
}

void spi_update(void) {
    TouchMicInput *touchMicInput;
    u32 latestIndex;

    latestIndex = TP_GetLatestIndexInAuto();
    touchMicInput = gSpiData;
    touchMicInput->mCalibratedPoint = *(TPData *) &touchMicInput->mAutoSamples[latestIndex];
    TP_GetCalibratedPoint(&touchMicInput->mCalibratedPoint, &touchMicInput->mCalibratedPoint);
    if (gSpiData->mMicAutoSampling) {
        gSpiData->mMicOverThreshold = mic_update(gSpiData->mMicBuffer) > 0x14;
    }
}

void spi_updateTpMic(InputSlotPair *pair, s32 b, s32 c) {
    TPData point;
    u32 pointY;
    s32 pointX;

    if (gSpiData->mTouchAutoSampling) {
        pointX = (b >> 8) & 0xff;
        pointY = b & 0xff;
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
    if (gSpiData->mMicAutoSampling) {
        pair->field12[0] = c;
    }
}

void spi_finalize(void) {
    mic_finalize(gSpiData->mMicBuffer);
    gSpiData = NULL;
}

u16 spi_getTouchPos(void) {
    TouchMicInput *touchMicInput;
    TPData *calibratedPoint;
    u32 pointX;
    u32 pointY;

    touchMicInput = gSpiData;
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
