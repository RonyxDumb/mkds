#include "00/Menu/wi_fi_connection_lost.h"

#include "Main/Scene/display_settings.h"
#include "00/code_02180608.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "code_02148950.h"
#include "code_021458c4.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/System/thread_function_queue.h"
#include "Main/MapObjects/data_0217a000.h"
#include "registers.h"
#include "code_0200e77c.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/System/heap.h"
#include "Main/Menu/menu_shared_clear.h"

WiFiStateCallbacks gWiFiConnectionLostCallbacks = {InitWiFiConnectionLost, ClearWiFiConnectionLostPointer, AdvanceWiFiConnectionLost, WriteWiFiConnectionLostRegistersNop};
WiFiConnectionLost *gWiFiConnectionLost;

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
        if (gMenuShared->mOtherKartCountAdded != FALSE) {
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
        gMenuShared->mWiFiMenuStartKind = 1;
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
