#include "01/Menu/emblem_screen_upload.h"
#include "01/MapObjects/lld.h"
#include "01/code_021a5140.h"
#include "01/code_02185000.h"
#include "01/Menu/emblem_grid.h"
#include "os_thread.h"
#include "Main/Menu/emblem_choises_shown.h"
#include "Main/Sound/race_end_seq.h"
#include "code_0200eddc.h"
#include "gx.h"
#include "g2.h"
#include "gx_load2d.h"
#include "01/unk_021a6000.h"
#include "01/Menu/emblem_cursor.h"
#include "registers.h"

void UploadEmblemMainScreen(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1700;
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffcfffef;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x400;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x600;
    DC_FlushRange(gEmblem->mEmblemMONclr->mData, gEmblem->mEmblemMONclr->mDataSize);
    GX_LoadOBJPltt(gEmblem->mEmblemMONclr->mData, 0, gEmblem->mEmblemMONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMONcgr->mData, gEmblem->mEmblemMONcgr->mDataSize);
    GX_LoadOBJ(gEmblem->mEmblemMONcgr->mData, 0, gEmblem->mEmblemMONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBNclr->mData, gEmblem->mEmblemMBNclr->mDataSize);
    GX_LoadBGPltt(gEmblem->mEmblemMBNclr->mData, 0, gEmblem->mEmblemMBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBNcgr->mData, gEmblem->mEmblemMBNcgr->mDataSize);
    GX_LoadBG1Char((gEmblem->mEmblemMBNcgr->mData), 0, gEmblem->mEmblemMBNcgr->mDataSize);
    DC_FlushRange(gEmblem->mGridCharBytes, 0x200);
    GX_LoadBG2Char(gEmblem->mGridCharBytes, 0, 0x200);
    DC_FlushRange(gEmblem->mEmblemMNscr->mData, gEmblem->mEmblemMNscr->mDataSize);
    GX_LoadBG1Scr(gEmblem->mEmblemMNscr->mData, 0, gEmblem->mEmblemMNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBgNscr->mData, gEmblem->mEmblemMBgNscr->mDataSize);
    GX_LoadBG2Scr(gEmblem->mEmblemMBgNscr->mData, 0, gEmblem->mEmblemMBgNscr->mDataSize);
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
}

void UploadEmblemSubScreen(void) {
    GXS_SetGraphicsMode(1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1e00;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x8a10;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 2;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xc10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0xe10;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, gEmblemSubBg3AffineMatrix, 16, 16, -0x70, -0x40);
    DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSONcgr->mData, gEmblem->mEmblemSONcgr->mDataSize);
    GXS_LoadOBJ(gEmblem->mEmblemSONcgr->mData, 0, gEmblem->mEmblemSONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    GXS_LoadBGPltt(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNcgr->mData, gEmblem->mEmblemSBNcgr->mDataSize);
    GXS_LoadBG1Char((gEmblem->mEmblemSBNcgr->mData), 0, gEmblem->mEmblemSBNcgr->mDataSize);
    DC_FlushRange(GetEmblemGridCells(), GetEmblemGridCharSize());
    GXS_LoadBG3Char(GetEmblemGridCells(), GetEmblemGridCharOffset(), GetEmblemGridCharSize());
    DC_FlushRange(gEmblem->mEmblemSTemplateFrameNscr->mData, gEmblem->mEmblemSTemplateFrameNscr->mDataSize);
    GXS_LoadBG0Scr(gEmblem->mEmblemSTemplateFrameNscr->mData, 0, gEmblem->mEmblemSTemplateFrameNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSToolNscr->mData, gEmblem->mEmblemSToolNscr->mDataSize);
    GXS_LoadBG1Scr(gEmblem->mEmblemSToolNscr->mData, 0, gEmblem->mEmblemSToolNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBgNscr->mData, gEmblem->mEmblemSBgNscr->mDataSize);
    GXS_LoadBG2Scr(gEmblem->mEmblemSBgNscr->mData, 0, gEmblem->mEmblemSBgNscr->mDataSize);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1010;
    DC_FlushRange(gEmblem->mEmblemSTemplateDarkNscr->mData, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    GXS_LoadBG3Scr(gEmblem->mEmblemSTemplateDarkNscr->mData, 0, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1218;
    DC_FlushRange((const void *) GetEmblemGridScr(), GetEmblemGridScrSize());
    GXS_LoadBG3Scr((const void *) (GetEmblemGridScr()), GetEmblemGridScrOffset(), GetEmblemGridScrSize());
}

void UploadEmblemCameraSubScreen(void) {
    GXS_SetGraphicsMode(1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xe10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x1010;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSONcgr->mData, gEmblem->mEmblemCameraSONcgr->mDataSize);
    GXS_LoadOBJ(gEmblem->mEmblemCameraSONcgr->mData, 0, gEmblem->mEmblemCameraSONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    GXS_LoadBGPltt(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSBNcgr->mData, gEmblem->mEmblemCameraSBNcgr->mDataSize);
    GXS_LoadBG1Char((gEmblem->mEmblemCameraSBNcgr->mData), 0, gEmblem->mEmblemCameraSBNcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSDSNscr->mData, gEmblem->mEmblemCameraSDSNscr->mDataSize);
    GXS_LoadBG1Scr(gEmblem->mEmblemCameraSDSNscr->mData, 0, gEmblem->mEmblemCameraSDSNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSBgNscr->mData, gEmblem->mEmblemCameraSBgNscr->mDataSize);
    GXS_LoadBG2Scr(gEmblem->mEmblemCameraSBgNscr->mData, 0, gEmblem->mEmblemCameraSBgNscr->mDataSize);
}

void StartEmblemChoises(void) {
    RequestEmblemChoisesGraphicsUpload();
    SetEmblemChoisesShownAndReset(1);
    gEmblem->mState = 10;
    gEmblem->mDisplayState = 14;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -3);
}

void StopEmblemChoises(void) {
    SetEmblemChoisesShownAndReset(0);
    gEmblem->mState = 0;
    gEmblem->mDisplayState = 15;
    gEmblem->mTransitionRunning = FALSE;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
}

void StartEmblemTemplateSlideIn(void) {
    gEmblem->mState = 2;
    gEmblem->mDisplayState = 2;
    gEmblem->mTemplateSlideOffset = 0;
    gEmblem->mTemplateSlideSpeed = 32;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemTemplateSLld, 1), 0);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -3);
}

void AdvanceEmblemTemplateSlideIn(void) {
    gEmblem->mTemplateSlideOffset += gEmblem->mTemplateSlideSpeed;
    gEmblem->mTemplateSlideSpeed -= 2;
    if (gEmblem->mTemplateSlideOffset >= 0xc0) {
        gEmblem->mTemplateSlideOffset = 0xc0;
        gEmblem->mState = 1;
        gEmblem->mDisplayState = 3;
        gEmblem->mTransitionRunning = FALSE;
    }
    gEmblem->mEmblemTemplateSLld->mOffsetY = gEmblem->mTemplateSlideOffset - 0xc0;
}

void StartEmblemTemplateSlideOut(void) {
    gEmblem->mState = 3;
    gEmblem->mDisplayState = 6;
    gEmblem->mTemplateSlideOffset = 0xc0;
    gEmblem->mTemplateSlideSpeed = -0x20;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
}

void AdvanceEmblemTemplateSlideOut(void) {
    gEmblem->mTemplateSlideOffset += gEmblem->mTemplateSlideSpeed;
    gEmblem->mTemplateSlideSpeed += 2;
    if (gEmblem->mTemplateSlideOffset <= 0) {
        gEmblem->mTemplateSlideOffset = 0;
        gEmblem->mState = 0;
        gEmblem->mDisplayState = 7;
        gEmblem->mTransitionRunning = FALSE;
    }
    gEmblem->mEmblemTemplateSLld->mOffsetY = gEmblem->mTemplateSlideOffset - 0xc0;
}

void StartEmblemFadeOutToCamera(void) {
    gEmblem->mState = 5;
    gEmblem->mDisplayState = 13;
    gEmblem->mFadeLevel = 0;
}

void StartEmblemFadeOutToGrid(void) {
    gEmblem->mState = 7;
    gEmblem->mDisplayState = 10;
    gEmblem->mFadeLevel = 0;
    SetKartModelMenuInputSeqs(2, 0);
}

void AdvanceEmblemFadeOutToCamera(void) {
    gEmblem->mFadeLevel += 2;
    if (gEmblem->mFadeLevel > 16) {
        gEmblem->mFadeLevel = 16;
        gEmblem->mState = 6;
        gEmblem->mDisplayState = 9;
    }
}

void AdvanceEmblemFadeInAtCamera(void) {
    gEmblem->mFadeLevel -= 2;
    if (gEmblem->mFadeLevel < 0) {
        gEmblem->mFadeLevel = 0;
        gEmblem->mState = 4;
        gEmblem->mDisplayState = 11;
        gEmblem->mTransitionRunning = FALSE;
    }
}

void AdvanceEmblemFadeOutToGrid(void) {
    gEmblem->mFadeLevel += 2;
    if (gEmblem->mFadeLevel > 16) {
        gEmblem->mFadeLevel = 16;
        gEmblem->mState = 8;
        gEmblem->mDisplayState = 12;
    }
}

void AdvanceEmblemFadeInAtGrid(void) {
    gEmblem->mFadeLevel -= 2;
    if (gEmblem->mFadeLevel < 0) {
        gEmblem->mFadeLevel = 0;
        gEmblem->mState = 0;
        gEmblem->mDisplayState = 8;
        gEmblem->mTransitionRunning = FALSE;
    }
}
