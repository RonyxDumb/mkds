#include "00/Menu/wi_fi_connection_lost.h"

#include "Main/Scene/display_settings.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "vram_bank_display_setup.h"
#include "card_rom_backup_access.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/backup_net_camera_work.h"
#include "registers.h"
#include "thread_mutex_types.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/System/heap.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_record_file.h"

WiFiStateCallbacks gWiFiConnectionLostCallbacks = {InitWiFiConnectionLost, ClearWiFiConnectionLostPointer,
                                                   AdvanceWiFiConnectionLost, WriteWiFiConnectionLostRegistersNop};
WiFiConnectionLost *gWiFiConnectionLost;

void InitWiFiConnectionLost(void *heap) {
    gWiFiConnectionLost = HeapAlloc(heap, 8);
    gWiFiConnectionLost->mState = WIFI_CONNECTION_LOST_STATE_WAIT_FADE_OUT;
    gWiFiConnectionLost->mNextState = WIFI_CONNECTION_LOST_STATE_WAIT_FADE_OUT;
    StartFadeToFadedNegative(0x1e);
}

void ClearWiFiConnectionLostPointer(void) {
    gWiFiConnectionLost = NULL;
}

void AdvanceWiFiConnectionLostWaitFadeOut(void) {
    u32 total;
    BackupFirstBlock *firstBlock;
    s8 otherKartCount;

    if (AreBrightnessFadesFaded() != 0) {
        gWiFiConnectionLost->mNextState = WIFI_CONNECTION_LOST_STATE_WAIT_FADE_IN;
        StartFadeToClear(0x1e);
        reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0x1208;
        reg_G2_BG1CNT = reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1f00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1700;
        reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT &
                             ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
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

void AdvanceWiFiConnectionLostWaitFadeIn(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestWiFiState(WIFI_STATE_VS_SETTING);
        gMenuShared->mWiFiMenuStartKind = WIFI_MENU_START_VS_SETTING;
    }
}

void AdvanceWiFiConnectionLost(void) {
    gWiFiConnectionLost->mState = gWiFiConnectionLost->mNextState;
    switch (gWiFiConnectionLost->mState) {
        case WIFI_CONNECTION_LOST_STATE_WAIT_FADE_OUT:
            AdvanceWiFiConnectionLostWaitFadeOut();
            break;
        case WIFI_CONNECTION_LOST_STATE_WAIT_FADE_IN:
            AdvanceWiFiConnectionLostWaitFadeIn();
            break;
    }
}

void WriteWiFiConnectionLostRegistersNop(void) {}

void RegisterWiFiConnectionLostCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiConnectionLostCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
