#include "Main/Unknown/code_020365ac.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_02152ac8.h"

#include "Main/Unknown/code_02036c5c.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_02036c4c.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02039000.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200f5ac.h"
#include "code_0200f790.h"
#include "gx.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_02004dc0.h"
#include "registers.h"

void vblankIrq(void) {
    if (gCurDisplayConfig != NULL) {
        dc_clearFlagsBit0();
        if (gCurDisplayConfig->mIrqCallback != NULL) {
            gCurDisplayConfig->mIrqCallback();
        }
    }
    *OFFSET_PTR(u32, &data_027e0000, 0x3ff8) |= 1;
}

void mkds_restoreIrqs(void) {
    OS_SetIrqFunction(1, vblankIrq);
    OS_EnableIrqMask(1);
    reg_OS_IME;
    reg_OS_IME = 1;
    OS_EnableInterrupts();
    GX_VBlankIntr(1);
}

void initSdk(void) {
    OS_DisableMainExArena();
    OS_Init();
    gMainHeap.field0 = 0;
    OS_InitTick();
    OS_InitAlarm();
    FX_Init();
    GX_Init();
    vram_initializeWvrStatus();
    vram_clearDisableAll();
    GX_DispOff();
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0x10000;
    OS_SetIrqFunction(1, vblankIrq);
    OS_EnableIrqMask(1);
    reg_OS_IME;
    reg_OS_IME = 1;
    OS_EnableInterrupts();
    GX_VBlankIntr(1);
    FS_Init(-1);
    func_02039774();
    gDWCInitResult = DWC_Init(sDwcWork);
    vram_startUpWifiVram();
}

void checkArenas(void) {
    OS_GetArenaLo(0);
    OS_GetArenaHi(0);
    OS_GetArenaLo(3);
    OS_GetArenaHi(3);
    OS_GetArenaLo(4);
    OS_GetArenaHi(4);
}

void mkds_init(void) {
    u8 *arenaLo;
    initSdk();
    dc_initMasterBright();
    gMainHeap.mArm9TextStart = (u32) ARM9_TEXT_START;
    gMainHeap.mArenaLo = OS_GetArenaLo(0);
    checkArenas();
    arenaLo = OS_GetArenaLo(0);
    gMainHeap.mHeap = heap_create(arenaLo, (u8 *) OS_GetArenaHi(0) - arenaLo);
    proc_init(&sMainProcess, 0);
    gMainHeap.field10 = aMainproc;
    func_020394cc();
}

void mkds_runMainProc(u32 func) {
    proc_setMainFunc(&sMainProcess, func);
    proc_run(&sMainProcess, 0xbeef);
}

void *getMainHeapHandle(void) {
    return gMainHeap.mHeap;
}
