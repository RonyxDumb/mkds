#include "01/code_021a2408.h"
#include "registers.h"
#include "01/code_02180ce8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Unknown/code_020ca9e4.h"
#include "Main/Unknown/code_021108ac.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_0214a000.h"
#include "code_0200eddc.h"
#include "gx.h"
#include "g2.h"
#include "code_0214b824.h"
#include "01/code_021a2a40.h"
#include "01/code_021a5140.h"
#include "01/code_021a4000.h"
#include "01/code_021a59cc.h"
#include "01/code_021a6000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/unk_0217a000.h"

void AdvanceEmblemDisplay(void) {
    u16 *sbColors;
    u16 *soColors;
    u32 dispcntBits;

    if ((gBackupBuffers->mBusy == 0 ? (gBackupAccess->mBackupEnabled ? gBackupAccess->mCommandRunning : 0) : 1) == 0) {
        AdvanceKartModelMenuLoad();
    }

    switch (gEmblem->mDisplayState) {
        case 0:
            UploadEmblemMainScreen();
            UploadEmblemSubScreen();
            gEmblem->mUploadFrames++;
            if (gEmblem->mUploadFrames >= 2) {
                gEmblem->mDisplayState = 8;
            }
            break;
        case 2:
            dispcntBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((dispcntBits | 1) << 8);
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x8a10;
            reg_G2S_DB_BG0OFS = (-(gEmblem->mTemplateSlideOffset - 0xc0) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS = ((gEmblem->mBgScrollPosition >> 12) & 0x1ff) |
                                (((-gEmblem->mBgScrollPosition >> 12) << 16) & 0x1ff0000);
            gEmblem->mDisplayState = 4;
            break;
        case 6:
            reg_G2S_DB_BG0OFS = (-(gEmblem->mTemplateSlideOffset - 0xc0) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS = ((gEmblem->mBgScrollPosition >> 12) & 0x1ff) |
                                (((-gEmblem->mBgScrollPosition >> 12) << 16) & 0x1ff0000);
            GXS_SetGraphicsMode(1);
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1218;
            DC_FlushRange(gEmblem->mGridCharBytes, 0x200);
            GX_LoadBG2Char((gEmblem->mGridCharBytes), 0, 0x200);
            G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0, 0x10, 0x10);
            gEmblem->mDisplayState = 4;
            break;
        case 4:
            reg_G2S_DB_BG0OFS = (-(gEmblem->mTemplateSlideOffset - 0xc0) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS = ((gEmblem->mBgScrollPosition >> 12) & 0x1ff) |
                                (((-gEmblem->mBgScrollPosition >> 12) << 16) & 0x1ff0000);
            DC_FlushRange(GetEmblemGridCells(), GetEmblemGridCharSize());
            GXS_LoadBG3Char(GetEmblemGridCells(), GetEmblemGridCharOffset(), GetEmblemGridCharSize());
            DC_FlushRange(gEmblem->mGridCharBytes, 0x200);
            GX_LoadBG2Char((gEmblem->mGridCharBytes), 0, 0x200);
            sbColors = gEmblem->mEmblemSBNclr->mData;
            soColors = gEmblem->mEmblemSONclr->mData;
            soColors[0x91] = sbColors[GetEmblemCursorCellValue() == 1 ? 2 : 1];
            soColors[0x92] = sbColors[GetEmblemCursorCellValue()];
            DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 3:
            reg_G2S_DB_BG0OFS = (-(gEmblem->mTemplateSlideOffset - 0xc0) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS = ((gEmblem->mBgScrollPosition >> 12) & 0x1ff) |
                                (((-gEmblem->mBgScrollPosition >> 12) << 16) & 0x1ff0000);
            GXS_SetGraphicsMode(0);
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1010;
            reg_G2S_DB_BG3OFS = 0;
            G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 8, 0x36, 8, 8);
            gEmblem->mDisplayState = 5;
            break;
        case 7:
            dispcntBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((dispcntBits & ~1) << 8);
            reg_G2S_DB_BG2OFS = ((gEmblem->mBgScrollPosition >> 12) & 0x1ff) |
                                (((-gEmblem->mBgScrollPosition >> 12) << 16) & 0x1ff0000);
            gEmblem->mDisplayState = 8;
            break;
        case 5:
            DC_FlushRange(gEmblem->mGridCharBytes, 0x200);
            GX_LoadBG2Char((gEmblem->mGridCharBytes), 0, 0x200);
            sbColors = gEmblem->mEmblemSBNclr->mData;
            soColors = gEmblem->mEmblemSONclr->mData;
            soColors[0x91] = sbColors[GetEmblemCursorCellValue() == 1 ? 2 : 1];
            soColors[0x92] = sbColors[GetEmblemCursorCellValue()];
            DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 8:
            reg_G2S_DB_BG2OFS = ((gEmblem->mBgScrollPosition >> 12) & 0x1ff) |
                                (((-gEmblem->mBgScrollPosition >> 12) << 16) & 0x1ff0000);
            DC_FlushRange(GetEmblemGridCells(), GetEmblemGridCharSize());
            GXS_LoadBG3Char(GetEmblemGridCells(), GetEmblemGridCharOffset(), GetEmblemGridCharSize());
            DC_FlushRange(gEmblem->mGridCharBytes, 0x200);
            GX_LoadBG2Char((gEmblem->mGridCharBytes), 0, 0x200);
            sbColors = gEmblem->mEmblemSBNclr->mData;
            soColors = gEmblem->mEmblemSONclr->mData;
            soColors[0x91] = sbColors[GetEmblemCursorCellValue() == 1 ? 2 : 1];
            soColors[0x92] = sbColors[GetEmblemCursorCellValue()];
            DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 12:
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -16);
            UploadEmblemSubScreen();
            gEmblem->mDisplayState = 13;
            break;
        case 9:
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -16);
            UploadEmblemCameraSubScreen();
            gEmblem->mDisplayState = 10;
            break;
        case 10:
            reg_G2S_DB_BG2OFS = 0;
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -gEmblem->mFadeLevel);
            break;
        case 13:
            reg_G2S_DB_BG2OFS = ((gEmblem->mBgScrollPosition >> 12) & 0x1ff) |
                                (((-gEmblem->mBgScrollPosition >> 12) << 16) & 0x1ff0000);
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -gEmblem->mFadeLevel);
            break;
        case 14:
            UploadEmblemSubScreen();
            reg_G2S_DB_BG0OFS = 0;
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0xa00;
            gEmblem->mDisplayState = 1;
            break;
        case 15:
            UploadEmblemSubScreen();
            gEmblem->mDisplayState = 8;
            break;
    }

    if (gEmblem->mSoundPending != FALSE) {
        if (GetEmblemCursorMode() == 0) {
            if (GetEmblemCursorSizeIndex() == 0) {
                SetEmblemSoundValue(0);
            } else if (GetEmblemCursorSizeIndex() == 1) {
                SetEmblemSoundValue(1);
                gEmblem->mUnk_10bc = 1;
            } else if (GetEmblemCursorSizeIndex() == 2) {
                SetEmblemSoundValue(2);
                gEmblem->mUnk_10bc = 2;
            }
        } else if (GetEmblemCursorMode() == 1) {
            if (GetEmblemCursorSizeIndex() == 0) {
                SetEmblemSoundValue(3);
            } else if (GetEmblemCursorSizeIndex() == 1) {
                SetEmblemSoundValue(4);
            } else if (GetEmblemCursorSizeIndex() == 2) {
                SetEmblemSoundValue(5);
            }
        }
        gEmblem->mSoundPending = FALSE;
    }
    DrawEmblemChoises();
    UploadOamLists(&gEmblem->mMainOam, &gEmblem->mSubOam);
}
