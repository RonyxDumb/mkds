#include "03/System/application.h"
#include "registers.h"

#include "03/System/dwc_archive.h"
#include "03/code_021d197c.h"
#include "03/code_021d3000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/System/task_input.h"
#include "03/code_021d2d50.h"
#include "03/System/task_vblank_irq.h"
#include "03/code_021d2ecc.h"
#include "03/Graphics/text_canvas.h"
#include "03/System/exp_heap.h"
#include "03/Net/led_pattern_send.h"
#include "03/Graphics/vram_bank_settings.h"
#include "03/unk_021da000.h"
#include "03/System/tasks.h"
#include "03/code_021d1f70.h"
#include "03/code_021c2b28.h"
#include "03/code_021d3278.h"
#include "code_0200007e.h"
#include "os_tick.h"
#include "code_0200f790.h"
#include "code_0200fc8c.h"
#include "code_02004dc0.h"
#include "gx.h"
#include "code_02148950.h"
#include "g2.h"
#include "code_0214d93c.h"
#include "tp.h"
#include "code_021519d4.h"
#include "03/System/lcd_power.h"

u8 gQuitFlag[4];
u8 gLanguageIndex[4];
void (*gUpdateFunction)(void);
void *gHeapMemoryBlock;
ModeAndFlags gModeAndFlags;
s32 gMenuPairs[4];

s32 RunMainLoop(void *memoryBlock, s32 languageIndex, u32 modeAndFlags) {
    gHeapMemoryBlock = memoryBlock;
    if (InitLanguageAndMode(languageIndex, modeAndFlags) == 0) {
        return -1;
    }
    gQuitFlag[0] = 0;
    InitApplication();
    InitGraphics();
    CreateSoundData();
    SetUpdateFunction(LoadMainFilesAndSetBgCnt);
    do {
        UpdateKeyTouchInput();
        gUpdateFunction();
        RunTasksAndRemoveRequested(0);
        UpdateLcdPower();
        SendLedPatternWirelessIfDifferent();
        VBlankIntrWait();
    } while (gQuitFlag[0] == 0);
    ReleaseApplication();
    return 0;
}

BOOL InitLanguageAndMode(s32 languageIndex, u32 modeAndFlags) {
    gLanguageIndex[0] = languageIndex;
    *(u32 *) &gModeAndFlags = modeAndFlags;
    if (languageIndex < 0 || languageIndex > 5) {
        return 0;
    }
    if ((u32) (modeAndFlags << 28) >> 28 > 1) {
        return 0;
    }
    if (languageIndex != 0 && ((modeAndFlags >> 4) & 1) != 0) {
        return 0;
    }
    if (languageIndex == 0 && (gModeAndFlags.mFlags & 1) == 0) {
        return 0;
    }
    return 1;
}

void InitApplication(void) {
    u8 *work;
    u16 imeValue = reg_OS_IME;
    reg_OS_IME = 0;
    GX_DispOff();
    reg_GXS_DB_DISPCNT &= 0xfffeffff;
    if (OS_IsTickAvailable() == 0) {
        OS_Terminate();
    }
    if (OS_IsAlarmAvailable() == 0) {
        OS_Terminate();
    }
    GX_VBlankIntr(0);
    FX_Init();
    FS_Init(-1);
    TP_Init();
    RTC_Init();
    GX_DispOff();
    reg_GXS_DB_DISPCNT &= 0xfffeffff;
    SaveBankSettingsAndClearVram();
    CreateExpHeapOverBuffer(gHeapMemoryBlock);
    EnableTaskVBlankIrq();
    InitTasks();
    InitDwcArchive();
    InitKeyTouchInput();
    InitBlendBrightnessFadeSlotsFaded();
    work = AllocExpHeapBlock(0x700, 0x20);
    DWC_BM_Init(work);
    FreeExpHeapBlockAndClearPointer(&work);
}

void InitGraphics(void) {
    volatile u32 *displayControl;
    volatile u16 *powerControl;
    GX_VBlankIntr(0);
    GX_SetBankForBG(1);
    GX_SetBankForOBJ(2);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    displayControl = &reg_GX_DISPCNT;
    *displayControl = *displayControl & 0xffffe0ff;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) | 0x200010;
    reg_G2_BG0CNT &= ~REG_G2_BG0CNT_MOSAIC_MASK;
    reg_G2_BG1CNT &= ~REG_G2_BG1CNT_MOSAIC_MASK;
    reg_G2_BG2CNT &= ~REG_G2_BG2CNT_MOSAIC_MASK;
    reg_G2_BG3CNT &= ~REG_G2_BG3CNT_MOSAIC_MASK;
    reg_G2_BG0OFS = 0;
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
    reg_G2_BG3OFS = 0;
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 0x3f, 0x10);
    GX_SetBankForSubBG(0x80);
    GX_SetBankForSubOBJ(0x100);
    GXS_SetGraphicsMode(GX_BGMODE_0);
    displayControl = &reg_GXS_DB_DISPCNT;
    *displayControl = *displayControl & 0xffffe0ff;
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) |
        REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK;
    reg_G2S_DB_BG0CNT &= ~REG_G2S_DB_BG0CNT_MOSAIC_MASK;
    reg_G2S_DB_BG1CNT &= ~REG_G2S_DB_BG1CNT_MOSAIC_MASK;
    reg_G2S_DB_BG2CNT &= ~REG_G2S_DB_BG2CNT_MOSAIC_MASK;
    reg_G2S_DB_BG3CNT &= ~REG_G2S_DB_BG3CNT_MOSAIC_MASK;
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3f, 0x10);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0xc00;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0xd08;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0xe10;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & (REG_G2_BG3CNT_PRIORITY_MASK | REG_G2_BG3CNT_MOSAIC_MASK)) | 0xf10;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0xc00;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 0xd00;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0xe00;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0xf00;
    powerControl = &reg_GX_POWCNT;
    *powerControl = *powerControl & ~0x8000;
    InitTextCanvases();
    InitOamBuffers();
    InitObjCharRanges();
    InitOamRanges();
    GX_DispOn();
    *(u32 *) 0x4001000 = *(u32 *) 0x4001000 | 0x10000;
    GX_VBlankIntr(1);
}

void ReleaseApplication(void) {
    GX_DispOff();
    reg_GXS_DB_DISPCNT &= 0xfffeffff;
    SendLedPatternOn();
    ReleaseKeyTouchInput();
    RestoreTaskVBlankIrq();
    ReleaseSoundData();
    ReleaseOamRanges();
    ReleaseOamBuffers();
    ReleaseTextCanvases();
    FreeBlendBrightnessFadeSlots();
    ReleaseDwcArchive();
    ReleaseTasks();
    ReleaseExpHeap();
    RestoreBankSettingsAndResetDisplay();
}

void SetUpdateFunction(void (*callback)(void)) {
    gUpdateFunction = callback;
}

void SetPrimaryMenuPair(u32 first, u32 second) {
    gMenuPairs[0] = first;
    gMenuPairs[1] = second;
}

void GetPrimaryMenuPair(s32 *first, s32 *second) {
    if (first != NULL) {
        *first = gMenuPairs[0];
    }
    if (second != NULL) {
        *second = gMenuPairs[1];
    }
}

void SetSecondaryMenuPair(u32 third, u32 fourth) {
    gMenuPairs[2] = third;
    gMenuPairs[3] = fourth;
}

void GetSecondaryMenuPair(s32 *first, s32 *second) {
    if (first != NULL) {
        *first = gMenuPairs[2];
    }
    if (second != NULL) {
        *second = gMenuPairs[3];
    }
}

u8 GetLanguageIndex(void) {
    return gLanguageIndex[0];
}

u32 GetMode(void) {
    return gModeAndFlags.mMode;
}

BOOL HasModeFlag(u32 mask) {
    if ((gModeAndFlags.mFlags & mask) != 0) {
        return 1;
    }
    return 0;
}

void SetQuitFlag(void) {
    gQuitFlag[0] = 1;
}
