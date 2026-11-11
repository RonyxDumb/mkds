#include "00/code_021857b8.h"

#include "Main/Unknown/code_02036c5c.h"
#include "00/code_02180608.h"
#include "00/code_021832d8.h"
#include "code_02148950.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "registers.h"
#include "code_0200e77c.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036820.h"

void InitWiFiConnectionLost(void *heap) {
    gWiFiConnectionLost = HeapAlloc(heap, 8);
    gWiFiConnectionLost->mState = 0;
    gWiFiConnectionLost->mNextState = 0;
    StartFadeToFadedNegative(0x1e);
}

void ClearWiFiConnectionLostPointer(void) {
    gWiFiConnectionLost = NULL;
}

void AdvanceWiFiConnectionLostState0(void) {
    u32 total;
    BackupFirstBlock *firstBlock;
    s8 otherKartCount;

    if (AreBrightnessFadesFaded() != 0) {
        gWiFiConnectionLost->mNextState = 1;
        StartFadeToClear(0x1e);
        reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x1208;
        reg_G2_BG1CNT = reg_G2_BG1CNT & ~3;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1f00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1700;
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
        GX_SetGraphicsMode(1, 0, 1);
        if (gMenuShared->mUnk_6c != FALSE) {
            firstBlock = gBackupBuffers->mFirstBlock;
            total = firstBlock->mTotals[5];
            otherKartCount = gWiFiSession->mKartCountCopy - 1;
            if (otherKartCount > 0) {
                if (total < otherKartCount) {
                    total = 0;
                } else {
                    total -= otherKartCount;
                }
            }
            firstBlock->mTotals[5] = total;
            WriteBackupFirstBlockWrapper();
            WaitThreadFunctionsDone();
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
}

void AdvanceWiFiConnectionLostState1(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestWiFiState(2);
        gMenuShared->mUnk_1c = 1;
    }
}

void AdvanceWiFiConnectionLost(void) {
    gWiFiConnectionLost->mState = gWiFiConnectionLost->mNextState;
    switch (gWiFiConnectionLost->mState) {
        case 0:
            AdvanceWiFiConnectionLostState0();
            break;
        case 1:
            AdvanceWiFiConnectionLostState1();
            break;
    }
}

void WriteWiFiConnectionLostRegistersNop(void) {}

void RegisterWiFiConnectionLostCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiConnectionLostCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
