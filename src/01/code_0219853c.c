#include "01/code_0219853c.h"
#include "01/OptionSelectMenu.h"
#include "00/code_02181f98.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02128244.h"
#include "01/code_02192e78.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0212b000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_0214d018.h"

Unk021a9be4 *data_ov001_021a9be4;

void func_ov001_021987d4(void *heap, s16 a) {
    Unk02125de0Arg arg;

    data_ov001_021a9be4 = heap_alloc(heap, 0x18);
    data_ov001_021a9be4->mUnk_08 = heap;
    data_ov001_021a9be4->mUnk_10 = func_021250b0(heap);
    arg.mUnk_00 = TRUE;
    arg.mUnk_04 = m2d_getFont(1);
    arg.mUnk_08 = 0;
    arg.mUnk_0c = 1;
    arg.mUnk_10 = 0;
    arg.mUnk_14 = FALSE;
    arg.mUnk_18 = NULL;
    arg.mUnk_1c = TRUE;
    arg.mUnk_20 = TRUE;
    arg.mUnk_24 = 0;
    gmenu_unpackData();
    gmenu_init(heap, &arg);
    data_ov001_021a9be4->mUnk_0c = a;
    data_ov001_021a9be4->mUnk_0e = -1;
    data_ov001_021a9be4->mUnk_00 = 0;
    data_ov001_021a9be4->mUnk_04 = data_ov001_021a9be4->mUnk_00;
    data_ov001_021a9be4->mUnk_14 = arc_get2dArcFile("common.bmg");
}

void func_ov001_021987bc(void) {
    gmenu_finish();
    *(u32 *) &data_ov001_021a9be4 = 0;
}

void func_ov001_02198768(void) {
    void *a;
    void *b;
    void *c;
    if (mbright_isFadedIn() != 0) {
        data_ov001_021a9be4->mUnk_04 = 1;
        a = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 0xc);
        b = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 0);
        c = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 1);
        SetupTxtSystemSubTextTwoButtons(a, b, c, 0);
    }
}

void func_ov001_021986e8(void) {
    void *a;
    void *b;
    void *c;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            data_ov001_021a9be4->mUnk_04 = 2;
            a = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 0xd);
            b = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 0);
            c = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 1);
            SetupTxtSystemSubTextTwoButtons(a, b, c, 0);
        } else {
            data_ov001_021a9be4->mUnk_0e = 0xe;
        }
    }
}

void func_ov001_02198624(void) {
    void *a;
    void *b;
    void *c;
    u8 *d;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            d = gSystemData->mOwnerText;
            gSaveData->mFirstBlock->mUnk_31_0 = 1;
            MI_CpuFill8(gSaveData->mFirstBlock->mPlayerName, 0, 0x14);
            MI_CpuCopy8(d, gSaveData->mFirstBlock->mPlayerName, 0x14);
            savd_flushNksy();
            data_ov001_021a9be4->mUnk_04 = 3;
            a = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 0x13);
            b = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 0);
            c = jn_msg_getMessage(data_ov001_021a9be4->mUnk_14, 1);
            SetupTxtSystemSubTextTwoButtons(a, b, c, 1);
        } else {
            data_ov001_021a9be4->mUnk_0e = 0xe;
        }
    }
}

void func_ov001_021985b0(void) {
    s32 v;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (gSaveData->mBusy == 0) {
            if (gSaveCore->mBackupEnabled != 0) {
                v = gSaveCore->mCommandRunning;
            } else {
                v = 0;
            }
        } else {
            v = 1;
        }
        if (v == 0) {
            if (GetTxtSystemSelectedIndex() == 0) {
                data_ov001_021a9be4->mUnk_0e = 3;
            } else {
                data_ov001_021a9be4->mUnk_0e = 0;
            }
        }
    }
}

void func_ov001_02198554(void) {
    gmenu_render();
    data_ov001_021a9be4->mUnk_00 = data_ov001_021a9be4->mUnk_04;
    switch (data_ov001_021a9be4->mUnk_00) {
        case 0:
            func_ov001_02198768();
            break;
        case 1:
            func_ov001_021986e8();
            break;
        case 2:
            func_ov001_02198624();
            break;
        case 3:
            func_ov001_021985b0();
            break;
    }
}

void func_ov001_0219854c(void) {
    gmenu_vblank();
}

int func_ov001_0219853c(void) {
    return data_ov001_021a9be4->mUnk_0e;
}
