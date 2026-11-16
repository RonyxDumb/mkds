#include "Main/Graphics/disp_cap.h"
#include "Main/Race/results_gp.h"

#include "Main/Scene/display_settings.h"
#include "Main/Net/participant_get_connection.h"
#include "bios_calls.h"
#include "thread_scheduler.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Menu/record_scene.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Scene/scene_run_step.h"
#include "Main/Net/rom_archive.h"
#include "Main/Net/multiboot_parent.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan.h"
#include "Main/Net/connection.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Net/non_multiboot_own_index.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Kart/kart_name_tags.h"
#include "arena_cache_init.h"
#include "vram_bank_display_setup.h"
#include "display_blend_affine_setup.h"
#include "vram_load_2d_graphics.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/Save/buddy_record.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Scene/scene_run_forever.h"
#include "Main/Race/results_gp.h"

SceneCallbacks g_Scene_Record = {
    InitRecordScene, UpdateRecordScene, ReleaseRecordScene, WriteRecordSceneRegistersCallback, NULL, NULL, 0xa, 0xa, 0};
DispCap *g_GlobalAA04;

#pragma thumb on

// Returns 0 unless all 32 Grand Prix records are filled with a value of 5 or more; else the lowest value (5 to 7)
// minus 4.
u8 GetWorstStarRank_from_thumb(void) {
    u8 cupIndex;
    s32 lowestValue;
    u8 engineClass;
    s32 recordValue;

    lowestValue = 7;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            recordValue = GetCupEntryRank(cupIndex, engineClass);
            if (recordValue == 9 || recordValue < lowestValue) {
                lowestValue = recordValue;
            }
            if (lowestValue == 9 || lowestValue < 5) {
                return 0;
            }
        }
    }
    switch (lowestValue) {
        case RESULTS_GP_GRADE_THIRD_BEST:
            return GP_LOWEST_RECORD_THIRD_BEST;
        case RESULTS_GP_GRADE_SECOND_BEST:
            return GP_LOWEST_RECORD_SECOND_BEST;
        case RESULTS_GP_GRADE_BEST:
            return GP_LOWEST_RECORD_BEST;
        default:
            return 0;
    }
}

#pragma thumb off

void InitializeGlobalAA04(void *heap) {
    g_GlobalAA04 = Mem_AllocateHeap(heap, sizeof(*g_GlobalAA04));
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_GP || g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
        g_GlobalAA04->mOamBuffer = Mem_AllocateHeapAligned(heap, 0x400, HEAP_ALIGN_CACHE_LINE);
    } else {
        g_GlobalAA04->mOamBuffer = NULL;
    }
    g_GlobalAA04->mFlags = 0;
    g_GlobalAA04->mBlendMin = 0;
    g_GlobalAA04->mBlendFactor = DISP_CAP_BLEND_FACTOR_FULL;
    g_GlobalAA04->mMode = DISP_CAP_MODE_OFF;
    if (g_SomeVramConfigMode.mState == BANK_SHARE_ACTIVE) {
        g_GlobalAA04->mMode = DISP_CAP_MODE_OFF;
    }
}

void ResetGlobalAA04(void) {
    g_GlobalAA04 = NULL;
}

static inline u32 DispCapGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

static inline s32 DispCapIsConnectionActive(void) {
    BOOL result = FALSE;
    if (DispCapGetConnectionMode() != CONNECTION_MODE_NONE && g_GlobalZE->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 DispCapIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (DispCapIsConnectionActive() && !(g_GlobalZE->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 DispCapIsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (DispCapIsConnectionActiveNotEnding() && g_GlobalZE->mErrorCode != CONNECTION_ERROR_NONE) {
        result = TRUE;
    }
    return result;
}

void SetDispCapMode(s32 mode) {
    g_GlobalAA04->mMode = mode;
    if (g_SomeVramConfigMode.mState == BANK_SHARE_ACTIVE) {
        g_GlobalAA04->mMode = DISP_CAP_MODE_OFF;
    }
}

void SetupDispCapMode1(void) {
    DispCapOamEntry *oamBuffer;
    s32 affineMatrix[4];
    s32 clearIndex;
    s32 column;
    s32 row;
    s32 entryIndex;
    DispCapOamEntry *oamEntry;

    oamBuffer = g_GlobalAA04->mOamBuffer;
    if (oamBuffer == NULL) {
        return;
    }
    affineMatrix[0] = 0x1000;
    affineMatrix[3] = 0x1000;
    affineMatrix[1] = 0;
    affineMatrix[2] = 0;
    G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, affineMatrix, 0, 0, 0, 0);
    for (clearIndex = 0; clearIndex < 0x80; clearIndex++) {
        oamBuffer[clearIndex].mAttr0And1 = 0;
        oamBuffer[clearIndex].mUnk_04 = 0;
    }
    entryIndex = 0;
    for (row = 0; row < 3; row++) {
        for (column = 0; column < 4; column++) {
            oamEntry = &oamBuffer[entryIndex++];
            oamEntry->mAttr0And1 = (u8) (0x40 * row) | 0xc0000c00 | ((column * 0x40 & 0x1ff) << 16);
            oamEntry->mAttr2 = (0x100 * row + column * 8) | 0xf000;
        }
    }
    Arm_FlushRange(oamBuffer, 0x400);
    CopyToOamB(oamBuffer, 0, 0x400);
    Svc_VblankIntrWait_from_thumb();
    g_GlobalAA04->mFlags &= ~DISP_CAP_FLAG_BANK_SWAPPED;
    reg_GX_POWCNT = reg_GX_POWCNT | 0x8000;
    ToggleDispCapBanks();
}

void SetupDispCap(void) {
    switch (g_GlobalAA04->mMode) {
        case DISP_CAP_MODE_BANK_TOGGLE:
            SetupDispCapMode1();
            break;
        case DISP_CAP_MODE_BLEND:
            ConfigureDispcntDisplay(0xe, 0, 1);
            break;
    }
}

// Alternates the VRAM banks used for the display capture each time it runs.
void ToggleDispCapBanks(void) {
    u32 captureBits;
    u32 powerBit;

    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    if (g_GlobalAA04->mFlags & DISP_CAP_FLAG_BANK_SWAPPED) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1000;
        GX_SetBankForLCDC(4);
        GX_SetBankForSubOBJ(8);
        g_GlobalAA04->mFlags &= ~DISP_CAP_FLAG_BANK_SWAPPED;
        captureBits = 2;
        powerBit = 1;
    } else {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x400;
        GX_SetBankForSubBG(4);
        GX_SetBankForLCDC(8);
        g_GlobalAA04->mFlags |= DISP_CAP_FLAG_BANK_SWAPPED;
        captureBits = 3;
        powerBit = 0;
    }
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x8000) | (powerBit << 15);
    reg_GX_DISPCAPCNT = 0x80300010 | (captureBits << 16);
}

// Writes the capture blend weights; with a 0 it also moves the blend factor toward 0 (DISP_CAP_FLAG_BLEND_FALLING set)
// or 0x1000.
void AdvanceDispCapBlend(s32 prevMenuOpen) {
    u8 weight;

    weight = g_GlobalAA04->mBlendMin + (((16 - g_GlobalAA04->mBlendMin) * g_GlobalAA04->mBlendFactor) >> 12);
    reg_GX_DISPCAPCNT = weight | (0xc0330000 | (u8) (16 - weight) << 8);
    if (prevMenuOpen != 0) {
        return;
    }
    if (g_GlobalAA04->mFlags & DISP_CAP_FLAG_BLEND_FALLING) {
        if (g_GlobalAA04->mBlendFactor <= 0) {
            return;
        }
        g_GlobalAA04->mBlendFactor -= DISP_CAP_BLEND_FACTOR_FALL_STEP;
        if (g_GlobalAA04->mBlendFactor < 0) {
            g_GlobalAA04->mBlendFactor = 0;
        }
    } else {
        if (g_GlobalAA04->mBlendFactor >= DISP_CAP_BLEND_FACTOR_FULL) {
            return;
        }
        g_GlobalAA04->mBlendFactor = g_GlobalAA04->mBlendFactor + DISP_CAP_BLEND_FACTOR_RISE_STEP;
        if (g_GlobalAA04->mBlendFactor > DISP_CAP_BLEND_FACTOR_FULL) {
            g_GlobalAA04->mBlendFactor = DISP_CAP_BLEND_FACTOR_FULL;
        }
    }
}

void AdvanceDispCap(s32 prevMenuOpen) {
    switch (g_GlobalAA04->mMode) {
        case DISP_CAP_MODE_BANK_TOGGLE:
            if (prevMenuOpen == 0) {
                ToggleDispCapBanks();
            }
            break;
        case DISP_CAP_MODE_BLEND:
            AdvanceDispCapBlend(prevMenuOpen);
            break;
    }
    if (!(g_GlobalAA04->mFlags & DISP_CAP_FLAG_FADE_RUNNING)) {
        return;
    }
    if (Bright_IsBothScreensFadedIn() == 0) {
        return;
    }
    g_GlobalAA04->mFlags &= ~DISP_CAP_FLAG_FADE_RUNNING;
    g_GlobalAA04->mFlags &= ~DISP_CAP_FLAG_FADE_FLAG;
}

void StartDispCapBlend(u8 blendMin) {
    if (g_GlobalAA04->mMode != DISP_CAP_MODE_BLEND) {
        return;
    }
    g_GlobalAA04->mFlags |= DISP_CAP_FLAG_BLEND_FALLING;
    g_GlobalAA04->mBlendFactor = DISP_CAP_BLEND_FACTOR_FULL;
    g_GlobalAA04->mBlendMin = blendMin;
}

static inline s32 DispCapIsConnectionActiveViaLocal(void) {
    BOOL result = FALSE;
    u32 connectionMode;
    if (g_GlobalZE == NULL) {
        connectionMode = CONNECTION_MODE_NONE;
        result = FALSE;
    } else {
        connectionMode = g_GlobalZE->mConnectionMode;
    }
    if (connectionMode != CONNECTION_MODE_NONE && g_GlobalZE->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

void StopDispCapBlend(void) {
    if (g_GlobalAA04->mMode == DISP_CAP_MODE_BLEND) {
        g_GlobalAA04->mFlags &= ~DISP_CAP_FLAG_BLEND_FALLING;
    }
}

void StartDispCapFadeToFaded(u32 frameCount) {
    if (GetSceneRunStep() != SCENE_RUN_STEP_RUNNING) {
        return;
    }
    g_GlobalAA04->mFlags |= DISP_CAP_FLAG_FADE_RUNNING;
    BrightCtx_SomeFn_0(frameCount, 1);
}

void StartDispCapFadeToClear(u32 frameCount) {
    if (GetSceneRunStep() != SCENE_RUN_STEP_RUNNING) {
        return;
    }
    g_GlobalAA04->mFlags |= DISP_CAP_FLAG_FADE_RUNNING;
    BrightCtx_SomeFn_1(frameCount, 1);
}

BOOL IsSharedDispCapFadeFlagSet(void) {
    if (DispCapIsConnectionActiveViaLocal()) {
        if (IsDataSharingSyncDone() != 0) {
            return (g_GlobalZE->mDataSharing.mReceivedRecords->mFlags & SHARING_RECORD_FLAG_DISP_CAP_FADE) != 0;
        }
        return FALSE;
    }
    return (g_GlobalAA04->mFlags & DISP_CAP_FLAG_FADE_FLAG) != 0;
}

BOOL HasAAFlag8(void) {
    return (g_GlobalAA04->mFlags & DISP_CAP_FLAG_FADE_FLAG) != 0;
}

// Sets the fade flag; it stays set until the brightness fades are clear. A child console in a link leaves it alone.
void SetDispCapFadeFlag(void) {
    if (DispCapIsConnectionActive() != 0 && DispCapGetConnectionMode() != CONNECTION_MODE_PARENT) {
        return;
    }
    g_GlobalAA04->mFlags |= DISP_CAP_FLAG_FADE_FLAG;
}

s32 SceneFn_Record(SceneNumbers *sceneNumbers) {
    SceneCallbacks recordSceneCallbacks = g_Scene_Record;

    OnSceneLoop(sceneNumbers, &recordSceneCallbacks);
    return 0;
}

void StoreReceivedPlayerName(const void *entryName, s32 entryIndex, s32 keepMask) {
    u8 keptBits;

    keptBits = g_GlobalZE->mReceivedNameMask & keepMask;
    Mem_CpuCopy8(entryName, &g_GlobalZE->mPlayerRecords[entryIndex], PLAYER_NAME_BYTES);
    g_GlobalZE->mReceivedNameMask = keptBits | (1 << entryIndex);
}

s32 AdvanceNonMultiBootSetup(s32 isParent) {
    BOOL result;

    result = FALSE;
    if (g_GlobalZE->mRequestPending != 0) {
        return result;
    }
    if (DispCapIsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    switch (g_GlobalZE->mStep) {
        case CONNECTION_STEP_NOTHING:
        case CONNECTION_STEP_SHUTTING_DOWN:
            g_GlobalZE->mFlags &= ~CONNECTION_FLAG_MULTIBOOT_SETUP;
            g_GlobalZE->mState = CONNECTION_STATE_STARTING;
            Initialize();
            break;
        case CONNECTION_STEP_STARTING_UP:
            StartRomArchiveTransfer();
            break;
        case CONNECTION_STEP_RESTARTING:
        case CONNECTION_STEP_ROM_ARCHIVE_TRANSFER:
            if (isParent != 0) {
                SetLifeTime(0x14);
            } else {
                result = TRUE;
                g_GlobalZE->mState = CONNECTION_STATE_MULTIBOOT_SCAN_READY;
                StartScan(1, NULL, NULL);
            }
            break;
        case CONNECTION_STEP_SETTING_TIMEOUT:
            MeasureChannel(0);
            break;
        case CONNECTION_STEP_CHECKING_CHANNELS:
            SetParentChannelLowestSum();
            FillParentParameter(1);
            SetParentParameter();
            break;
        case CONNECTION_STEP_CONFIGURING_HOST:
            StartParent(NULL);
            break;
        case CONNECTION_STEP_OPENING_HOST:
            StartMP();
            break;
        case CONNECTION_STEP_STARTING_EXCHANGE:
            g_GlobalZE->mState = CONNECTION_STATE_MULTIBOOT_PARENT_READY;
            g_GlobalZE->mChildren.mNameSendIndex = 0;
            result = TRUE;
            g_GlobalZE->mStatusFlags &= ~CONNECTION_STATUS_CHILDREN_CHANGED;
            break;
        default:
            StopConnection();
            break;
    }
    return result;
}

s32 AdvanceSetupByMultiBoot(s32 isParent, s32 isMultiBoot) {
    if (isParent != 0) {
        if (isMultiBoot != 0) {
            return AdvanceMultiBootSetup(isParent);
        }
        return AdvanceNonMultiBootSetup(isParent);
    }
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return AdvanceMultiBootSetup(isParent);
    }
    return AdvanceNonMultiBootSetup(isParent);
}

s32 AdvanceConnectByMultiBoot(u16 entryIndex) {
    if (g_GlobalZE->mOperationFlags & CONNECTION_OPERATION_SCANNING) {
        g_GlobalZE->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
    }
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT || IsScanSlotMultiBoot(entryIndex) != 0) {
        return AdvanceScanConnect(entryIndex);
    }
    return AdvanceNonMultiBootConnect(entryIndex);
}
