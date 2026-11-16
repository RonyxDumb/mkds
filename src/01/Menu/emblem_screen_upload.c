#include "01/Menu/emblem_screen_upload.h"
#include "01/MapObjects/lld.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "01/Menu/emblem_grid.h"
#include "thread_scheduler.h"
#include "Main/Menu/emblem_choises_shown.h"
#include "Main/Sound/race_end_seq.h"
#include "arena_cache_init.h"
#include "fixed_point_graphics_setup.h"
#include "display_blend_affine_setup.h"
#include "vram_load_2d_graphics.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "01/Menu/emblem_cursor.h"
#include "registers.h"

void UploadEmblemMainScreen(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1700;
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0x400;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0x600;
    Arm_FlushRange(gEmblem->mEmblemMONclr->mData, gEmblem->mEmblemMONclr->mDataSize);
    CopySomePaletteData(gEmblem->mEmblemMONclr->mData, 0, gEmblem->mEmblemMONclr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemMONcgr->mData, gEmblem->mEmblemMONcgr->mDataSize);
    CopyTileDataTop_0(gEmblem->mEmblemMONcgr->mData, 0, gEmblem->mEmblemMONcgr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemMBNclr->mData, gEmblem->mEmblemMBNclr->mDataSize);
    CopyPaletteTop(gEmblem->mEmblemMBNclr->mData, 0, gEmblem->mEmblemMBNclr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemMBNcgr->mData, gEmblem->mEmblemMBNcgr->mDataSize);
    CopyBgData_Bg1_Top((gEmblem->mEmblemMBNcgr->mData), 0, gEmblem->mEmblemMBNcgr->mDataSize);
    Arm_FlushRange(gEmblem->mGridCharBytes, 0x200);
    CopyBgData_Bg2_Top(gEmblem->mGridCharBytes, 0, 0x200);
    Arm_FlushRange(gEmblem->mEmblemMNscr->mData, gEmblem->mEmblemMNscr->mDataSize);
    TEQSub_Fn9Impl(gEmblem->mEmblemMNscr->mData, 0, gEmblem->mEmblemMNscr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemMBgNscr->mData, gEmblem->mEmblemMBgNscr->mDataSize);
    TEQSub_Fn10Impl_Fn12Impl(gEmblem->mEmblemMBgNscr->mData, 0, gEmblem->mEmblemMBgNscr->mDataSize);
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
}

void UploadEmblemSubScreen(void) {
    SetDispcntSubBgMode(GX_BGMODE_1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1e00;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2S_DB_BG0CNT =
        (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0x8a10;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 2;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 0xc10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0xe10;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 2;
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, gEmblemSubBg3AffineMatrix, 16, 16, -0x70, -0x40);
    Arm_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    TEQSub_Fn30Impl(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemSONcgr->mData, gEmblem->mEmblemSONcgr->mDataSize);
    TEQSub_Fn35Impl(gEmblem->mEmblemSONcgr->mData, 0, gEmblem->mEmblemSONcgr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    CopyPaletteBottom(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemSBNcgr->mData, gEmblem->mEmblemSBNcgr->mDataSize);
    CopyBgData_Bg1_Bottom((gEmblem->mEmblemSBNcgr->mData), 0, gEmblem->mEmblemSBNcgr->mDataSize);
    Arm_FlushRange(GetEmblemGridCells(), GetEmblemGridCharSize());
    CopyBgData_Bg3_Bottom(GetEmblemGridCells(), GetEmblemGridCharOffset(), GetEmblemGridCharSize());
    Arm_FlushRange(gEmblem->mEmblemSTemplateFrameNscr->mData, gEmblem->mEmblemSTemplateFrameNscr->mDataSize);
    TEQSub_Fn24Impl(gEmblem->mEmblemSTemplateFrameNscr->mData, 0, gEmblem->mEmblemSTemplateFrameNscr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemSToolNscr->mData, gEmblem->mEmblemSToolNscr->mDataSize);
    TEQSub_Fn25Impl(gEmblem->mEmblemSToolNscr->mData, 0, gEmblem->mEmblemSToolNscr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemSBgNscr->mData, gEmblem->mEmblemSBgNscr->mDataSize);
    TEQSub_Fn26Impl_Fn28Impl(gEmblem->mEmblemSBgNscr->mData, 0, gEmblem->mEmblemSBgNscr->mDataSize);
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x1010;
    Arm_FlushRange(gEmblem->mEmblemSTemplateDarkNscr->mData, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    TEQSub_Fn27Impl_Fn29Impl(gEmblem->mEmblemSTemplateDarkNscr->mData, 0, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x1218;
    Arm_FlushRange(GetEmblemGridScr(), GetEmblemGridScrSize());
    TEQSub_Fn27Impl_Fn29Impl(GetEmblemGridScr(), GetEmblemGridScrOffset(), GetEmblemGridScrSize());
}

void UploadEmblemCameraSubScreen(void) {
    SetDispcntSubBgMode(GX_BGMODE_1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1600;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 0xe10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG2CNT =
        (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0x1010;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    Arm_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    TEQSub_Fn30Impl(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemCameraSONcgr->mData, gEmblem->mEmblemCameraSONcgr->mDataSize);
    TEQSub_Fn35Impl(gEmblem->mEmblemCameraSONcgr->mData, 0, gEmblem->mEmblemCameraSONcgr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    CopyPaletteBottom(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemCameraSBNcgr->mData, gEmblem->mEmblemCameraSBNcgr->mDataSize);
    CopyBgData_Bg1_Bottom((gEmblem->mEmblemCameraSBNcgr->mData), 0, gEmblem->mEmblemCameraSBNcgr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemCameraSDSNscr->mData, gEmblem->mEmblemCameraSDSNscr->mDataSize);
    TEQSub_Fn25Impl(gEmblem->mEmblemCameraSDSNscr->mData, 0, gEmblem->mEmblemCameraSDSNscr->mDataSize);
    Arm_FlushRange(gEmblem->mEmblemCameraSBgNscr->mData, gEmblem->mEmblemCameraSBgNscr->mDataSize);
    TEQSub_Fn26Impl_Fn28Impl(gEmblem->mEmblemCameraSBgNscr->mData, 0, gEmblem->mEmblemCameraSBgNscr->mDataSize);
}

void StartEmblemChoises(void) {
    RequestEmblemChoisesGraphicsUpload();
    SetEmblemChoisesShownAndReset(1);
    gEmblem->mState = EMBLEM_STATE_CHOISES;
    gEmblem->mDisplayState = EMBLEM_DISPLAY_CHOISES_SETUP;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -3);
}

void StopEmblemChoises(void) {
    SetEmblemChoisesShownAndReset(0);
    gEmblem->mState = EMBLEM_STATE_GRID;
    gEmblem->mDisplayState = EMBLEM_DISPLAY_CHOISES_CLOSE;
    gEmblem->mTransitionRunning = FALSE;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
}

void StartEmblemTemplateSlideIn(void) {
    gEmblem->mState = EMBLEM_STATE_TEMPLATE_SLIDE_IN;
    gEmblem->mDisplayState = EMBLEM_DISPLAY_TEMPLATE_SLIDE_IN_SETUP;
    gEmblem->mTemplateSlideOffset = 0;
    gEmblem->mTemplateSlideSpeed = EMBLEM_TEMPLATE_SLIDE_SPEED;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemTemplateSLld, 1), 0);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -3);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -3);
}

void AdvanceEmblemTemplateSlideIn(void) {
    gEmblem->mTemplateSlideOffset += gEmblem->mTemplateSlideSpeed;
    gEmblem->mTemplateSlideSpeed -= 2;
    if (gEmblem->mTemplateSlideOffset >= EMBLEM_TEMPLATE_SLIDE_DISTANCE) {
        gEmblem->mTemplateSlideOffset = EMBLEM_TEMPLATE_SLIDE_DISTANCE;
        gEmblem->mState = EMBLEM_STATE_TEMPLATE;
        gEmblem->mDisplayState = EMBLEM_DISPLAY_TEMPLATE_SETUP;
        gEmblem->mTransitionRunning = FALSE;
    }
    gEmblem->mEmblemTemplateSLld->mOffsetY = gEmblem->mTemplateSlideOffset - EMBLEM_TEMPLATE_SLIDE_DISTANCE;
}

void StartEmblemTemplateSlideOut(void) {
    gEmblem->mState = EMBLEM_STATE_TEMPLATE_SLIDE_OUT;
    gEmblem->mDisplayState = EMBLEM_DISPLAY_TEMPLATE_SLIDE_OUT_SETUP;
    gEmblem->mTemplateSlideOffset = EMBLEM_TEMPLATE_SLIDE_DISTANCE;
    gEmblem->mTemplateSlideSpeed = -EMBLEM_TEMPLATE_SLIDE_SPEED;
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
}

void AdvanceEmblemTemplateSlideOut(void) {
    gEmblem->mTemplateSlideOffset += gEmblem->mTemplateSlideSpeed;
    gEmblem->mTemplateSlideSpeed += 2;
    if (gEmblem->mTemplateSlideOffset <= 0) {
        gEmblem->mTemplateSlideOffset = 0;
        gEmblem->mState = EMBLEM_STATE_GRID;
        gEmblem->mDisplayState = EMBLEM_DISPLAY_GRID_RESTORE;
        gEmblem->mTransitionRunning = FALSE;
    }
    gEmblem->mEmblemTemplateSLld->mOffsetY = gEmblem->mTemplateSlideOffset - EMBLEM_TEMPLATE_SLIDE_DISTANCE;
}

void StartEmblemFadeOutToCamera(void) {
    gEmblem->mState = EMBLEM_STATE_FADE_OUT_TO_CAMERA;
    gEmblem->mDisplayState = EMBLEM_DISPLAY_GRID_FADE;
    gEmblem->mFadeLevel = 0;
}

void StartEmblemFadeOutToGrid(void) {
    gEmblem->mState = EMBLEM_STATE_FADE_OUT_TO_GRID;
    gEmblem->mDisplayState = EMBLEM_DISPLAY_CAMERA_FADE;
    gEmblem->mFadeLevel = 0;
    SetKartModelMenuInputSeqs(2, 0);
}

void AdvanceEmblemFadeOutToCamera(void) {
    gEmblem->mFadeLevel += 2;
    if (gEmblem->mFadeLevel > EMBLEM_FADE_LEVEL_MAX) {
        gEmblem->mFadeLevel = EMBLEM_FADE_LEVEL_MAX;
        gEmblem->mState = EMBLEM_STATE_FADE_IN_AT_CAMERA;
        gEmblem->mDisplayState = EMBLEM_DISPLAY_CAMERA_UPLOAD;
    }
}

void AdvanceEmblemFadeInAtCamera(void) {
    gEmblem->mFadeLevel -= 2;
    if (gEmblem->mFadeLevel < 0) {
        gEmblem->mFadeLevel = 0;
        gEmblem->mState = EMBLEM_STATE_CAMERA;
        gEmblem->mDisplayState = EMBLEM_DISPLAY_CAMERA;
        gEmblem->mTransitionRunning = FALSE;
    }
}

void AdvanceEmblemFadeOutToGrid(void) {
    gEmblem->mFadeLevel += 2;
    if (gEmblem->mFadeLevel > EMBLEM_FADE_LEVEL_MAX) {
        gEmblem->mFadeLevel = EMBLEM_FADE_LEVEL_MAX;
        gEmblem->mState = EMBLEM_STATE_FADE_IN_AT_GRID;
        gEmblem->mDisplayState = EMBLEM_DISPLAY_GRID_UPLOAD;
    }
}

void AdvanceEmblemFadeInAtGrid(void) {
    gEmblem->mFadeLevel -= 2;
    if (gEmblem->mFadeLevel < 0) {
        gEmblem->mFadeLevel = 0;
        gEmblem->mState = EMBLEM_STATE_GRID;
        gEmblem->mDisplayState = EMBLEM_DISPLAY_GRID;
        gEmblem->mTransitionRunning = FALSE;
    }
}
