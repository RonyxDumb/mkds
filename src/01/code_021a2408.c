#include "01/code_021a2408.h"
#include "registers.h"
#include "01/code_02180ce8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ca9e4.h"
#include "Main/Unknown/code_021108ac.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_0214a000.h"
#include "code_0200eddc.h"
#include "gx.h"
#include "code_0214a390.h"
#include "code_0214b824.h"
#include "01/code_021a2a40.h"
#include "01/code_021a5140.h"
#include "01/code_021a4000.h"
#include "01/code_021a59cc.h"
#include "01/code_021a6000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/unk_0217a000.h"

void func_ov001_021a2408(void) {
    u16 *src;
    u16 *dst;
    u32 bits;

    if ((gSaveData->mBusy == 0 ? (gSaveCore->mBackupEnabled ? gSaveCore->mCommandRunning : 0) : 1) == 0) {
        AdvanceKartModelMenuLoad();
    }

    switch (gEmblem->field1098) {
        case 0:
            func_ov001_021a4fa0();
            func_ov001_021a4d10();
            gEmblem->field10B4++;
            if (gEmblem->field10B4 >= 2) {
                gEmblem->field1098 = 8;
            }
            break;
        case 2:
            bits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((bits | 1) << 8);
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x8a10;
            reg_G2S_DB_BG0OFS = (-(gEmblem->field10A0 - 0xc0) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS =
                ((gEmblem->field10A8 >> 12) & 0x1ff) | (((-gEmblem->field10A8 >> 12) << 16) & 0x1ff0000);
            gEmblem->field1098 = 4;
            break;
        case 6:
            reg_G2S_DB_BG0OFS = (-(gEmblem->field10A0 - 0xc0) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS =
                ((gEmblem->field10A8 >> 12) & 0x1ff) | (((-gEmblem->field10A8 >> 12) << 16) & 0x1ff0000);
            GXS_SetGraphicsMode(1);
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1218;
            DC_FlushRange(gEmblem->fieldA7C, 0x200);
            GX_LoadBG2Char((gEmblem->fieldA7C), 0, 0x200);
            G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0, 0x10, 0x10);
            gEmblem->field1098 = 4;
            break;
        case 4:
            reg_G2S_DB_BG0OFS = (-(gEmblem->field10A0 - 0xc0) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS =
                ((gEmblem->field10A8 >> 12) & 0x1ff) | (((-gEmblem->field10A8 >> 12) << 16) & 0x1ff0000);
            DC_FlushRange(GetEmblemGridCells(), GetEmblemGridCharSize());
            GXS_LoadBG3Char(GetEmblemGridCells(), func_ov001_02181194(), GetEmblemGridCharSize());
            DC_FlushRange(gEmblem->fieldA7C, 0x200);
            GX_LoadBG2Char((gEmblem->fieldA7C), 0, 0x200);
            src = gEmblem->mEmblemSBNclr->mData;
            dst = gEmblem->mEmblemSONclr->mData;
            dst[0x91] = src[func_ov001_021a63b4() == 1 ? 2 : 1];
            dst[0x92] = src[func_ov001_021a63b4()];
            DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 3:
            reg_G2S_DB_BG0OFS = (-(gEmblem->field10A0 - 0xc0) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS =
                ((gEmblem->field10A8 >> 12) & 0x1ff) | (((-gEmblem->field10A8 >> 12) << 16) & 0x1ff0000);
            GXS_SetGraphicsMode(0);
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1010;
            reg_G2S_DB_BG3OFS = 0;
            G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 8, 0x36, 8, 8);
            gEmblem->field1098 = 5;
            break;
        case 7:
            bits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((bits & ~1) << 8);
            reg_G2S_DB_BG2OFS =
                ((gEmblem->field10A8 >> 12) & 0x1ff) | (((-gEmblem->field10A8 >> 12) << 16) & 0x1ff0000);
            gEmblem->field1098 = 8;
            break;
        case 5:
            DC_FlushRange(gEmblem->fieldA7C, 0x200);
            GX_LoadBG2Char((gEmblem->fieldA7C), 0, 0x200);
            src = gEmblem->mEmblemSBNclr->mData;
            dst = gEmblem->mEmblemSONclr->mData;
            dst[0x91] = src[func_ov001_021a63b4() == 1 ? 2 : 1];
            dst[0x92] = src[func_ov001_021a63b4()];
            DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 8:
            reg_G2S_DB_BG2OFS =
                ((gEmblem->field10A8 >> 12) & 0x1ff) | (((-gEmblem->field10A8 >> 12) << 16) & 0x1ff0000);
            DC_FlushRange(GetEmblemGridCells(), GetEmblemGridCharSize());
            GXS_LoadBG3Char(GetEmblemGridCells(), func_ov001_02181194(), GetEmblemGridCharSize());
            DC_FlushRange(gEmblem->fieldA7C, 0x200);
            GX_LoadBG2Char((gEmblem->fieldA7C), 0, 0x200);
            src = gEmblem->mEmblemSBNclr->mData;
            dst = gEmblem->mEmblemSONclr->mData;
            dst[0x91] = src[func_ov001_021a63b4() == 1 ? 2 : 1];
            dst[0x92] = src[func_ov001_021a63b4()];
            DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 12:
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -16);
            func_ov001_021a4d10();
            gEmblem->field1098 = 13;
            break;
        case 9:
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -16);
            func_ov001_021a4ba0();
            gEmblem->field1098 = 10;
            break;
        case 10:
            reg_G2S_DB_BG2OFS = 0;
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -gEmblem->field109C);
            break;
        case 13:
            reg_G2S_DB_BG2OFS =
                ((gEmblem->field10A8 >> 12) & 0x1ff) | (((-gEmblem->field10A8 >> 12) << 16) & 0x1ff0000);
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -gEmblem->field109C);
            break;
        case 14:
            func_ov001_021a4d10();
            reg_G2S_DB_BG0OFS = 0;
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0xa00;
            gEmblem->field1098 = 1;
            break;
        case 15:
            func_ov001_021a4d10();
            gEmblem->field1098 = 8;
            break;
    }

    if (gEmblem->field10B8 != FALSE) {
        if (func_ov001_021a639c() == 0) {
            if (func_ov001_021a637c() == 0) {
                func_021108ac(0);
            } else if (func_ov001_021a637c() == 1) {
                func_021108ac(1);
                gEmblem->field10BC = 1;
            } else if (func_ov001_021a637c() == 2) {
                func_021108ac(2);
                gEmblem->field10BC = 2;
            }
        } else if (func_ov001_021a639c() == 1) {
            if (func_ov001_021a637c() == 0) {
                func_021108ac(3);
            } else if (func_ov001_021a637c() == 1) {
                func_021108ac(4);
            } else if (func_ov001_021a637c() == 2) {
                func_021108ac(5);
            }
        }
        gEmblem->field10B8 = FALSE;
    }
    echoi_vblank();
    oam_applyBuffers(&gEmblem->field0, &gEmblem->field404);
}
