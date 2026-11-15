#include "01/Menu/emblem_cursor.h"
#include "01/Menu/emblem_button_entries.h"
#include "01/MapObjects/lld.h"
#include "types.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "01/Menu/emblem_grid.h"
#include "01/Graphics/clear_chars_and_screen_map.h"
#include "01/Menu/menu_screen_work_structs.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "player.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "sound_archive_load_result.h"
#include "01/Menu/emblem_input.h"
#include "Main/Scene/display_settings.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/emblem_choises_shown.h"
#include "Main/System/backup_net_camera_work.h"
#include "03/Net/essid_packet_steps.h"
#include "cpu_copy_fill.h"
#include "01/Menu/emblem_screen_advance.h"
#include "Main/Save/mission_record.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/nibbles_join.h"
#include "Main/Sound/sound_seq.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Kart/kart_model_menu.h"
#include "gx_load2d.h"
#include "Main/Menu/keyboard_keys.h"
#include "os_thread.h"
#include "Main/Sound/race_end_seq.h"
#include "arena_cache_init.h"
#include "gx.h"
#include "g2.h"
#include "registers.h"
#include "01/Menu/emblem_display_advance.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Sound/sound_system.h"
#include "Main/Save/ghost_record_file.h"

Emblem *gEmblem;

const s32 gEmblemLPressButtonCursorIndices[4] = {0, 6, 3, 9};
const s32 gEmblemSubBg3AffineMatrix[4] = {0x400, 0, 0, 0x400};
const s32 gEmblemButtonLldEntries[12] = {0xe, 0xf, 0x10, 0x14, 0x16, 0x17, 0x11, 0x12, 0x13, 0x15, 0x16, 0x17};
const s32 gEmblemTemplateScreenColorEntries[16] = {0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22,
                                                   0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a};
const s32 gEmblemRPressButtonCursorIndices[4] = {0, 6, 3, 9};
const s32 gEmblemColorLldEntries[16] = {0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22,
                                        0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a};
const s32 gEmblemTemplateLldEntries[29] = {3,    4,    5,    6,    7,    8,    9,    0xa,  0xb,  0xc,
                                           0xd,  0xe,  0xf,  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
                                           0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
const s32 gEmblemButtonCursorHorizontalMoves[3][12] = {{6, 7, 8, 9, 4, 5, 0, 1, 2, 3, 0xa, 0xb},
                                                       {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb},
                                                       {6, 7, 8, 9, 4, 5, 0, 1, 2, 3, 0xa, 0xb}};
const s32 gEmblemButtonCursorVerticalMoves[3][12] = {{5, 0, 1, 2, 3, 4, 0xb, 6, 7, 8, 9, 0xa},
                                                     {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb},
                                                     {1, 2, 3, 4, 5, 0, 7, 8, 9, 0xa, 0xb, 6}};
const s32 gEmblemColorCursorVerticalMoves[3][16] = {{7, 0, 1, 2, 3, 4, 5, 6, 0xf, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe},
                                                    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf},
                                                    {1, 2, 3, 4, 5, 6, 7, 0, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 8}};
const s32 gEmblemColorCursorHorizontalMoves[3][16] = {{8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0, 1, 2, 3, 4, 5, 6, 7},
                                                      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf},
                                                      {8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0, 1, 2, 3, 4, 5, 6, 7}};
const s32 gEmblemTemplateCursorHorizontalMoves[3][29] = {
    {5,   0,   1,    2,    3,    4,    0xb,  6,    7,    8,    9,    0xa,  0x11, 0xc, 0xd,
     0xe, 0xf, 0x10, 0x17, 0x12, 0x13, 0x14, 0x15, 0x16, 0x1c, 0x18, 0x19, 0x1a, 0x1b},
    {0,   1,    2,    3,    4,    5,    6,    7,    8,    9,    0xa,  0xb,  0xc,  0xd, 0xe,
     0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c},
    {1,    2,    3,   4,    5,    0,    7,    8,    9,    0xa,  0xb,  6,    0xd,  0xe, 0xf,
     0x10, 0x11, 0xc, 0x13, 0x14, 0x15, 0x16, 0x17, 0x12, 0x19, 0x1a, 0x1b, 0x1c, 0x18}};
const s32 gEmblemTemplateCursorVerticalMoves[3][29] = {
    {0x12, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0,   1,    2,    3,    4,    5,    6,    7,   8,
     9,    0xa,  0xb,  0xc,  0xd,  0xe,  0xf, 0x10, 0x11, 0x13, 0x14, 0x15, 0x16, 0x17},
    {0,   1,    2,    3,    4,    5,    6,    7,    8,    9,    0xa,  0xb,  0xc,  0xd, 0xe,
     0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c},
    {6,    7,    8,    9, 0xa,  0xb,  0xc,  0xd,  0xe,  0xf, 0x10, 0x11, 0x12, 0x13, 0x14,
     0x15, 0x16, 0x17, 0, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 1,   2,    3,    4,    5}};
EmblemCursor *gEmblemCursor;

void ClampEmblemCursorCell(void) {
    s32 lo = 0;
    s32 hi = gEmblemCursor->mSide - 1;

    switch (gEmblemCursor->mSizeIndex) {
        case EMBLEM_BRUSH_2X2:
            hi -= 1;
            break;
        case EMBLEM_BRUSH_3X3:
            lo += 1;
            hi -= 1;
            break;
    }
    gEmblemCursor->mCellX = (gEmblemCursor->mCellX > lo) ? gEmblemCursor->mCellX : lo;
    gEmblemCursor->mCellX = (gEmblemCursor->mCellX < hi) ? gEmblemCursor->mCellX : hi;
    gEmblemCursor->mCellY = (gEmblemCursor->mCellY > lo) ? gEmblemCursor->mCellY : lo;
    gEmblemCursor->mCellY = (gEmblemCursor->mCellY < hi) ? gEmblemCursor->mCellY : hi;
}

void SetEmblemCursorCellShift(s32 shift) {
    gEmblemCursor->mCellShift = shift;
}

void SetEmblemCursorCellValue(u8 cellValue) {
    gEmblemCursor->mCellValue = cellValue;
}

u8 GetEmblemCursorCellValue(void) {
    return gEmblemCursor->mCellValue;
}

void SetEmblemCursorMode(s32 mode) {
    gEmblemCursor->mMode = mode;
}

s32 GetEmblemCursorMode(void) {
    return gEmblemCursor->mMode;
}

void SetEmblemCursorSizeIndex(s32 sizeIndex) {
    gEmblemCursor->mSizeIndex = sizeIndex;
    ClampEmblemCursorCell();
}

s32 GetEmblemCursorSizeIndex(void) {
    return gEmblemCursor->mSizeIndex;
}

void SetEmblemCursorCellFromPoint(s32 pointX, s32 pointY) {
    gEmblemCursor->mCellX = (pointX - gEmblemCursor->mOriginX) >> gEmblemCursor->mCellShift;
    gEmblemCursor->mCellY = (pointY - gEmblemCursor->mOriginY) >> gEmblemCursor->mCellShift;
    ClampEmblemCursorCell();
}

s32 GetEmblemCursorPointX(void) {
    return gEmblemCursor->mOriginX + (gEmblemCursor->mCellX << gEmblemCursor->mCellShift);
}

s32 GetEmblemCursorPointY(void) {
    return gEmblemCursor->mOriginY + (gEmblemCursor->mCellY << gEmblemCursor->mCellShift);
}

s32 GetEmblemCursorPrevPointX(void) {
    return gEmblemCursor->mOriginX + (gEmblemCursor->mPrevCellX << gEmblemCursor->mCellShift);
}

s32 GetEmblemCursorPrevPointY(void) {
    return gEmblemCursor->mOriginY + (gEmblemCursor->mPrevCellY << gEmblemCursor->mCellShift);
}

BOOL IsEmblemPointInGrid(s32 pointX, s32 pointY) {
    s32 px = (pointX - gEmblemCursor->mOriginX) >> gEmblemCursor->mCellShift;
    s32 py = (pointY - gEmblemCursor->mOriginY) >> gEmblemCursor->mCellShift;

    if (px >= 0 && px < gEmblemCursor->mSide && py >= 0 && py < gEmblemCursor->mSide) {
        return TRUE;
    }
    return FALSE;
}

s32 FillEmblemGridAtCursorCell(void) {
    return FillEmblemGridRegion(gEmblemCursor->mCellX, gEmblemCursor->mCellY, gEmblemCursor->mCellValue);
}

BOOL SetEmblemCursorCellValueFromGrid(void) {
    u8 gridCellValue = GetEmblemGridCellValue(gEmblemCursor->mCellX, gEmblemCursor->mCellY);

    if (gridCellValue != 0 && gridCellValue != gEmblemCursor->mCellValue) {
        gEmblemCursor->mCellValue = gridCellValue;
        return TRUE;
    }
    return FALSE;
}

void CreateEmblemCursorAndGrid(s32 originX, s32 originY, s32 side, s32 scrSide, s32 tableCount) {
    gEmblemCursor = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(EmblemCursor));
    gEmblemCursor->mOriginX = originX;
    gEmblemCursor->mOriginY = originY;
    gEmblemCursor->mSide = side;
    CreateEmblemGrid(side, scrSide, tableCount);
}

s32 AdvanceEmblemCursor(s32 down, s32 pointX, s32 pointY, s32 inputBits, s32 dx, s32 dy) {
    s32 result;
    s32 offsetX;
    s32 offsetY;
    u8 writeValue;
    s32 saveX;
    s32 saveY;
    s32 prevPointFixedX;
    s32 prevPointFixedY;
    s32 pointFixedX;
    s32 pointFixedY;
    s32 prevPointCellX;
    s32 prevPointCellY;
    s32 pointCellX;
    s32 pointCellY;
    s32 originX;
    s32 originY;
    s32 cellShift;
    BOOL prevInGrid;
    BOOL pointInGrid;

    saveX = gEmblemCursor->mCellX;
    saveY = gEmblemCursor->mCellY;
    originX = gEmblemCursor->mOriginX;
    cellShift = gEmblemCursor->mCellShift;
    prevPointFixedX = TO_FIXED12(gEmblemCursor->mPrevX - originX);
    prevPointFixedX >>= cellShift;
    originY = gEmblemCursor->mOriginY;
    prevPointFixedY = TO_FIXED12(gEmblemCursor->mPrevY - originY);
    prevPointFixedY >>= cellShift;
    pointFixedX = TO_FIXED12(pointX - originX);
    pointFixedX >>= cellShift;
    pointFixedY = TO_FIXED12(pointY - originY);
    pointFixedY >>= cellShift;
    prevPointCellX = FROM_FIXED12(prevPointFixedX);
    prevPointCellY = FROM_FIXED12(prevPointFixedY);
    pointCellX = FROM_FIXED12(pointFixedX);
    pointCellY = FROM_FIXED12(pointFixedY);
    prevInGrid = FALSE;
    if (prevPointCellX >= 0 && prevPointCellX < gEmblemCursor->mSide && prevPointCellY >= 0 &&
        prevPointCellY < gEmblemCursor->mSide) {
        prevInGrid = TRUE;
    }
    pointInGrid = FALSE;
    if (pointCellX >= 0 && pointCellX < gEmblemCursor->mSide && pointCellY >= 0 && pointCellY < gEmblemCursor->mSide) {
        pointInGrid = TRUE;
    }
    result = 0;
    gEmblemCursor->mCellX += dx;
    gEmblemCursor->mCellY += dy;
    if ((gEmblemCursor->mPrevDown != 0 && prevInGrid != FALSE) || (down != 0 && pointInGrid != FALSE)) {
        if (gEmblemCursor->mMode == EMBLEM_CURSOR_MODE_ERASE) {
            writeValue = 0;
        } else {
            writeValue = gEmblemCursor->mCellValue;
        }
        gEmblemCursor->mCellX = pointCellX;
        gEmblemCursor->mCellY = pointCellY;
        switch (gEmblemCursor->mMode) {
            case EMBLEM_CURSOR_MODE_DRAW:
            case EMBLEM_CURSOR_MODE_ERASE:
                if (gEmblemCursor->mPrevDown != 0) {
                    switch (gEmblemCursor->mSizeIndex) {
                        case EMBLEM_BRUSH_1X1:
                            if (SetEmblemGridLine(prevPointFixedX, prevPointFixedY, pointFixedX, pointFixedY,
                                                  writeValue) != 0) {
                                result = 1;
                            } else {
                                result = 0;
                            }
                            break;
                        case EMBLEM_BRUSH_2X2:
                            for (offsetX = 0; offsetX < 0x2000; offsetX += 0x1000) {
                                for (offsetY = 0; offsetY < 0x2000; offsetY += 0x1000) {
                                    if (SetEmblemGridLine(prevPointFixedX + offsetX, prevPointFixedY + offsetY,
                                                          pointFixedX + offsetX, pointFixedY + offsetY,
                                                          writeValue) != 0) {
                                        result = 1;
                                    }
                                }
                            }
                            break;
                        case EMBLEM_BRUSH_3X3:
                            for (offsetX = -0x1000; offsetX < 0x2000; offsetX += 0x1000) {
                                for (offsetY = -0x1000; offsetY < 0x2000; offsetY += 0x1000) {
                                    if (SetEmblemGridLine(prevPointFixedX + offsetX, prevPointFixedY + offsetY,
                                                          pointFixedX + offsetX, pointFixedY + offsetY,
                                                          writeValue) != 0) {
                                        result = 1;
                                    }
                                }
                            }
                            break;
                    }
                }
                inputBits = result;
                break;
            case EMBLEM_CURSOR_MODE_FILL:
            case EMBLEM_CURSOR_MODE_PICK_VALUE:
                inputBits = 1;
                break;
        }
    }
    ClampEmblemCursorCell();
    if (inputBits != 0) {
        if (gEmblemCursor->mMode == EMBLEM_CURSOR_MODE_ERASE) {
            writeValue = 0;
        } else {
            writeValue = gEmblemCursor->mCellValue;
        }
        switch (gEmblemCursor->mMode) {
            case EMBLEM_CURSOR_MODE_DRAW:
            case EMBLEM_CURSOR_MODE_ERASE:
                switch (gEmblemCursor->mSizeIndex) {
                    case EMBLEM_BRUSH_1X1:
                        if (SetEmblemGridCellValue(gEmblemCursor->mCellX, gEmblemCursor->mCellY, writeValue) != 0) {
                            result = 1;
                        }
                        break;
                    case EMBLEM_BRUSH_2X2:
                        for (offsetX = 0; offsetX < 2; offsetX++) {
                            for (offsetY = 0; offsetY < 2; offsetY++) {
                                if (SetEmblemGridCellValue(gEmblemCursor->mCellX + offsetX,
                                                           gEmblemCursor->mCellY + offsetY, writeValue) != 0) {
                                    result = 1;
                                }
                            }
                        }
                        break;
                    case EMBLEM_BRUSH_3X3:
                        for (offsetX = -1; offsetX < 2; offsetX++) {
                            for (offsetY = -1; offsetY < 2; offsetY++) {
                                if (SetEmblemGridCellValue(gEmblemCursor->mCellX + offsetX,
                                                           gEmblemCursor->mCellY + offsetY, writeValue) != 0) {
                                    result = 1;
                                }
                            }
                        }
                        break;
                }
                break;
            case EMBLEM_CURSOR_MODE_FILL:
                result = FillEmblemGridAtCursorCell();
                break;
            case EMBLEM_CURSOR_MODE_PICK_VALUE:
                result = SetEmblemCursorCellValueFromGrid();
                break;
        }
    }
    gEmblemCursor->mPrevDown = down;
    gEmblemCursor->mPrevX = pointX;
    gEmblemCursor->mPrevY = pointY;
    gEmblemCursor->mPrevCellX = saveX;
    gEmblemCursor->mPrevCellY = saveY;
    if (down == 0 && inputBits == 0) {
        ClearEmblemGridCopied();
    }
    return result;
}

BOOL AdvanceEmblemColorCursorShrink(LldEntry *entry) {
    if (entry->mCallbackCallCount <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mCallbackCallCount++;
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_PHASE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - EMBLEM_BUTTON_SCALE_STEP);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
            return TRUE;
        }
        return FALSE;
    }
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_BOUNCE_CALLS) {
        SetLldEntryScale(entry, 0);
        return FALSE;
    }
    return TRUE;
}

BOOL AdvanceEmblemColorCursorGrow(LldEntry *entry) {
    if (entry->mCallbackCallCount <= 0) {
        SetLldEntryScale(entry, 0);
    }
    entry->mCallbackCallCount++;
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_PHASE_CALLS) {
        return FALSE;
    }
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_BOUNCE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + EMBLEM_BUTTON_SCALE_STEP);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    SetLldEntryScale(entry, 0x1000);
    if (gEmblem->mPendingTransitionFunc != NULL) {
        gEmblem->mPendingTransitionFunc();
        gEmblem->mPendingTransitionFunc = NULL;
    }
    return TRUE;
}

void StartEmblemColorCursorShrinkAndGrow(void *lld, s32 index) {
    void *pickedEntry = GetLldEntry(lld, index);
    void *shrinkEntry = GetLldEntry(lld, 9);
    void *growEntry = GetLldEntry(lld, 10);

    SetLldEntryPos(shrinkEntry, GetLldEntryX(pickedEntry), GetLldEntryY(pickedEntry));
    SetLldEntryPos(growEntry, GetLldEntryX(pickedEntry), GetLldEntryY(pickedEntry));
    SetLldEntryCallback(shrinkEntry, (s32(*)(LldEntry *)) AdvanceEmblemColorCursorShrink);
    SetLldEntryCallback(growEntry, (s32(*)(LldEntry *)) AdvanceEmblemColorCursorGrow);
}

BOOL AdvanceEmblemButtonBounceThenWait(LldEntry *entry) {
    if (entry->mCallbackCallCount <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mCallbackCallCount++;
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_PHASE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - EMBLEM_BUTTON_SCALE_STEP);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_BOUNCE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + EMBLEM_BUTTON_SCALE_STEP);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (entry->mCallbackCallCount == EMBLEM_BUTTON_TRANSITION_CALL) {
        if (gEmblem->mPendingTransitionFunc != NULL) {
            gEmblem->mPendingTransitionFunc();
            gEmblem->mPendingTransitionFunc = NULL;
        }
        return FALSE;
    }
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_FINISH_CALLS) {
        return FALSE;
    }
    ApplyLldEntryFrameCommand(entry, 0);
    return TRUE;
}

void StartEmblemButtonBounceThenWait(void *lld, s32 index) {
    SetLldEntryCallback(GetLldEntry(lld, index), (s32(*)(LldEntry *)) AdvanceEmblemButtonBounceThenWait);
}

BOOL AdvanceEmblemButtonBounce(LldEntry *entry) {
    if (entry->mCallbackCallCount <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mCallbackCallCount++;
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_PHASE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - EMBLEM_BUTTON_SCALE_STEP);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_BOUNCE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + EMBLEM_BUTTON_SCALE_STEP);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (gEmblem->mPendingTransitionFunc != NULL) {
        gEmblem->mPendingTransitionFunc();
        gEmblem->mPendingTransitionFunc = NULL;
    }
    ApplyLldEntryFrameCommand(entry, 0);
    return TRUE;
}

void StartEmblemButtonBounce(void *lld, s32 index) {
    SetLldEntryCallback(GetLldEntry(lld, index), (s32(*)(LldEntry *)) AdvanceEmblemButtonBounce);
}

BOOL AdvanceEmblemModeButtonPress(LldEntry *entry) {
    if (entry->mCallbackCallCount <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mCallbackCallCount++;
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_PHASE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - EMBLEM_BUTTON_SCALE_STEP);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_BOUNCE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + EMBLEM_BUTTON_SCALE_STEP);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (gEmblem->mPendingTransitionFunc != NULL) {
        gEmblem->mPendingTransitionFunc();
        gEmblem->mPendingTransitionFunc = NULL;
    }
    return TRUE;
}

void ResetEmblemButton(void *lld, s32 index) {
    LldEntry *entry = GetLldEntry(lld, index);

    SetLldEntryCallback(entry, NULL);
    ApplyLldEntryFrameCommand(entry, 0);
    entry->mScale = TO_FIXED12(1);
}

void StartEmblemModeButtonPress(void *lld, s32 index) {
    ResetEmblemButton(gEmblem->mEmblemSLld, 14);
    ResetEmblemButton(gEmblem->mEmblemSLld, 15);
    ResetEmblemButton(gEmblem->mEmblemSLld, 16);
    ResetEmblemButton(gEmblem->mEmblemSLld, 17);
    ResetEmblemButton(gEmblem->mEmblemSLld, 18);
    ResetEmblemButton(gEmblem->mEmblemSLld, 19);
    ResetEmblemButton(gEmblem->mEmblemSLld, 20);
    ResetEmblemButton(gEmblem->mEmblemSLld, 21);
    SetLldEntryCallback(GetLldEntry(lld, index), (s32(*)(LldEntry *)) AdvanceEmblemModeButtonPress);
}

BOOL AdvanceEmblemButtonHold(LldEntry *entry) {
    if (entry->mCallbackCallCount <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mCallbackCallCount++;
    if (entry->mCallbackCallCount <= EMBLEM_BUTTON_BOUNCE_CALLS) {
        ApplyLldEntryFrameCommand(entry, 1);
        return FALSE;
    }
    if (gEmblem->mPendingTransitionFunc != NULL) {
        gEmblem->mPendingTransitionFunc();
        gEmblem->mPendingTransitionFunc = NULL;
    }
    return TRUE;
}

void StartEmblemButtonHold(void *lld, s32 index) {
    SetLldEntryCallback(GetLldEntry(lld, index), (s32(*)(LldEntry *)) AdvanceEmblemButtonHold);
}

void StartEmblemButtonBounceAndToggle(void *lld, s32 index) {
    void *pressedEntry = GetLldEntry(lld, index);
    void *toggleEntry = GetLldEntry(lld, EMBLEM_ENTRY_TOGGLED_BY_BUTTON);

    if (GetLldEntryFrameIndex(toggleEntry) >= 0) {
        SetLldEntryCallback(pressedEntry, (s32(*)(LldEntry *)) AdvanceEmblemButtonBounceThenWait);
        ApplyLldEntryFrameCommand(toggleEntry, -5);
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 505);
    } else {
        SetLldEntryCallback(pressedEntry, (s32(*)(LldEntry *)) AdvanceEmblemButtonBounceThenWait);
        ApplyLldEntryFrameCommand(toggleEntry, 0);
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 506);
    }
}

void InitEmblem(void) {
    DisplaySettingsDesc displaySettingsDesc;
    EmblemRecord *emblemRecord;

    gEmblem = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(Emblem));
    InitDisplaySettingsDesc(&displaySettingsDesc);
    displaySettingsDesc.mDispMode = 1;
    displaySettingsDesc.mMainBgMode = GX_BGMODE_0;
    displaySettingsDesc.mBg0As = 1;
    displaySettingsDesc.mMainDisplayMask = GX_PLANEMASK_BG0 | GX_PLANEMASK_OBJ;
    displaySettingsDesc.mBankForTex = 3;
    displaySettingsDesc.mBankForTexPltt = 0x10;
    displaySettingsDesc.mBankForBG = 0x20;
    displaySettingsDesc.mBankForOBJ = 0x40;
    displaySettingsDesc.mSubBgMode = GX_BGMODE_1;
    displaySettingsDesc.mSubDisplayMask = GX_PLANEMASK_OBJ;
    displaySettingsDesc.mBankForSubBG = 4;
    displaySettingsDesc.mBankForSubOBJ = 8;
    InitDisplayFromSettings(CreateDisplaySettings(GetHeap(GetCurrentHeapCall()), &displaySettingsDesc));
    LoadNclrData(&gEmblem->mEmblemMONclr, (FindSceneFile("emblem_m_o.NCLR")));
    LoadNcgrData2(&gEmblem->mEmblemMONcgr, (FindSceneFile("emblem_m_o.NCGR")));
    LoadNcerData(&gEmblem->mEmblemMNcer, FindSceneFile("emblem_m.NCER"));
    LoadNanrData(&gEmblem->mEmblemMNanr, FindSceneFile("emblem_m.NANR"));
    gEmblem->mEmblemMLld = CreateLld("emblem_m.lld", gEmblem->mEmblemMNcer, gEmblem->mEmblemMNanr);
    LoadNclrData(&gEmblem->mEmblemMBNclr, (FindSceneFile("emblem_m_b.NCLR")));
    LoadNcgrData(&gEmblem->mEmblemMBNcgr, (FindSceneFile("emblem_m_b.NCGR")));
    LoadNscrData(&gEmblem->mEmblemMNscr, (FindSceneFile("emblem_m.NSCR")));
    LoadNscrData(&gEmblem->mEmblemMBgNscr, (FindSceneFile("emblem_m_bg.NSCR")));
    LoadNclrData(&gEmblem->mEmblemSONclr, (FindSceneFile("emblem_s_o.NCLR")));
    LoadNcgrData2(&gEmblem->mEmblemSONcgr, (FindSceneFile("emblem_s_o.NCGR")));
    LoadNcerData(&gEmblem->mEmblemSNcer, FindSceneFile("emblem_s.NCER"));
    LoadNanrData(&gEmblem->mEmblemSNanr, FindSceneFile("emblem_s.NANR"));
    gEmblem->mEmblemSLld = CreateLld("emblem_s.lld", gEmblem->mEmblemSNcer, gEmblem->mEmblemSNanr);
    gEmblem->mEmblemTemplateSLld = CreateLld("emblem_template_s.lld", gEmblem->mEmblemSNcer, gEmblem->mEmblemSNanr);
    LoadNclrData(&gEmblem->mEmblemSBNclr, (FindSceneFile("emblem_s_b.NCLR")));
    LoadNcgrData(&gEmblem->mEmblemSBNcgr, (FindSceneFile("emblem_s_b.NCGR")));
    LoadNcgrData(&gEmblem->mEmblemTemplateBNcgr, (FindSceneFile("emblem_template_b.NCGR")));
    LoadNscrData(&gEmblem->mEmblemSTemplateFrameNscr, (FindSceneFile("emblem_s_template_frame.NSCR")));
    LoadNscrData(&gEmblem->mEmblemSToolNscr, (FindSceneFile("emblem_s_tool.NSCR")));
    LoadNscrData(&gEmblem->mEmblemSBgNscr, (FindSceneFile("emblem_s_bg.NSCR")));
    LoadNscrData(&gEmblem->mEmblemSTemplateDarkNscr, (FindSceneFile("emblem_s_template_dark.NSCR")));
    LoadNcgrData2(&gEmblem->mEmblemCameraSONcgr, (FindSceneFile("emblem_camera_s_o.NCGR")));
    LoadNcerData(&gEmblem->mEmblemCameraSNcer, FindSceneFile("emblem_camera_s.NCER"));
    LoadNanrData(&gEmblem->mEmblemCameraSNanr, FindSceneFile("emblem_camera_s.NANR"));
    gEmblem->mEmblemCameraSLld =
        CreateLld("emblem_camera_s.lld", gEmblem->mEmblemCameraSNcer, gEmblem->mEmblemCameraSNanr);
    LoadNcgrData(&gEmblem->mEmblemCameraSBNcgr, (FindSceneFile("emblem_camera_s_b.NCGR")));
    LoadNscrData(&gEmblem->mEmblemCameraSDSNscr, (FindSceneFile("emblem_camera_s_DS.NSCR")));
    LoadNscrData(&gEmblem->mEmblemCameraSBgNscr, (FindSceneFile("emblem_camera_s_bg.NSCR")));
    CreateEmblemInput();
    InitKartModelMenuWithKartList(GetHeap(GetCurrentHeapCall()));
    InitEmblemChoises();
    ResetOamLists(&gEmblem->mMainOam, &gEmblem->mSubOam);
    CreateEmblemCursorAndGrid(0x40, 0x10, 0x20, 0x80, 0x10);
    emblemRecord = gBackupBuffers->mEmblemRecord;
    if (emblemRecord->mFilled) {
        MI_CpuCopy8(emblemRecord->mEmblemData, gEmblem->mRecordBytes, sizeof(gEmblem->mRecordBytes));
        SplitBytesIntoNibbleTiles(gEmblem->mRecordBytes, gEmblem->mCellNibbles, GetEmblemGridSide());
        SetEmblemGridCells(gEmblem->mCellNibbles);
        SwapEmblemGridCells();
        SetEmblemGridCells(gEmblem->mCellNibbles);
        ResetEmblemGridChanges();
    }
    SetEmblemCursorCellShift(2);
    SetEmblemCursorCellValue(1);
    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_DRAW);
    SetEmblemCursorSizeIndex(EMBLEM_BRUSH_1X1);
    SetEmblemCursorCellFromPoint(GetLldEntryX(GetLldEntry(gEmblem->mEmblemSLld, 0)),
                                 GetLldEntryY(GetLldEntry(gEmblem->mEmblemSLld, 0)));
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 14), 1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 12), 0);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 10), 0);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 23), 2);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 14), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 15), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 16), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 17), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 18), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 19), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 20), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 21), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 22), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 23), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 27), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 28), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 29), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 30), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 31), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 32), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 33), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 34), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 35), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 36), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 37), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 38), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 39), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 40), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 41), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 42), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 25), -32, -20, 32, 20);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 26), -32, -20, 32, 20);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemTemplateSLld, 1), -52, -15, 52, 15);
    gEmblem->mKartListSkipped = TRUE;
    gEmblem->mTransitionRunning = FALSE;
    gEmblem->mUnk_10bc = 6;
}

void UploadEmblemMainScreen(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1700;
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0x400;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0x600;
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
    GXS_SetGraphicsMode(GX_BGMODE_1);
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
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x1010;
    DC_FlushRange(gEmblem->mEmblemSTemplateDarkNscr->mData, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    GXS_LoadBG3Scr(gEmblem->mEmblemSTemplateDarkNscr->mData, 0, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x1218;
    DC_FlushRange(GetEmblemGridScr(), GetEmblemGridScrSize());
    GXS_LoadBG3Scr(GetEmblemGridScr(), GetEmblemGridScrOffset(), GetEmblemGridScrSize());
}

void UploadEmblemCameraSubScreen(void) {
    GXS_SetGraphicsMode(GX_BGMODE_1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1600;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 0xe10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG2CNT =
        (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0x1010;
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

void ActivateEmblemEntry(s32 entryIndex, s32 isTouch) {
    s32 templateByteSize;
    u8 *templateBytes;
    u16 templateCellValues[16];

    switch (gEmblem->mState) {
        case EMBLEM_STATE_GRID:
            switch (entryIndex) {
                case EMBLEM_ENTRY_COLOR_FIRST:
                case EMBLEM_ENTRY_COLOR_FIRST + 1:
                case EMBLEM_ENTRY_COLOR_FIRST + 2:
                case EMBLEM_ENTRY_COLOR_FIRST + 3:
                case EMBLEM_ENTRY_COLOR_FIRST + 4:
                case EMBLEM_ENTRY_COLOR_FIRST + 5:
                case EMBLEM_ENTRY_COLOR_FIRST + 6:
                case EMBLEM_ENTRY_COLOR_FIRST + 7:
                case EMBLEM_ENTRY_COLOR_FIRST + 8:
                case EMBLEM_ENTRY_COLOR_FIRST + 9:
                case EMBLEM_ENTRY_COLOR_FIRST + 10:
                case EMBLEM_ENTRY_COLOR_FIRST + 11:
                case EMBLEM_ENTRY_COLOR_FIRST + 12:
                case EMBLEM_ENTRY_COLOR_FIRST + 13:
                case EMBLEM_ENTRY_COLOR_FIRST + 14:
                    if (isTouch) {
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                        gEmblem->mColorCursorIndex = entryIndex - EMBLEM_ENTRY_COLOR_FIRST;
                        SetEmblemCursorCellValue(gEmblem->mColorCursorIndex + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f1);
                    } else {
                        gEmblem->mColorCursorIndex = entryIndex - EMBLEM_ENTRY_COLOR_FIRST;
                        StartEmblemColorCursorShrinkAndGrow((gEmblem->mEmblemSLld), entryIndex);
                        SetEmblemCursorCellValue(gEmblem->mColorCursorIndex + 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f0);
                    }
                    if (GetEmblemCursorMode() == EMBLEM_CURSOR_MODE_ERASE) {
                        StartEmblemModeButtonPress(gEmblem->mEmblemSLld,
                                                   GetEmblemCursorSizeIndex() + EMBLEM_ENTRY_DRAW_BRUSH_FIRST);
                        SetEmblemCursorMode(EMBLEM_CURSOR_MODE_DRAW);
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_TOGGLE_BUTTON:
                    if (isTouch) {
                        SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    }
                    StartEmblemButtonBounceAndToggle((gEmblem->mEmblemSLld), entryIndex);
                    if (isTouch) {
                        gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                        return;
                    }
                    break;
                case EMBLEM_ENTRY_DRAW_BRUSH_FIRST:
                case EMBLEM_ENTRY_DRAW_BRUSH_FIRST + 1:
                case EMBLEM_ENTRY_DRAW_BRUSH_FIRST + 2:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_DRAW);
                    SetEmblemCursorSizeIndex(entryIndex - EMBLEM_ENTRY_DRAW_BRUSH_FIRST);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_ERASE_BRUSH_FIRST:
                case EMBLEM_ENTRY_ERASE_BRUSH_FIRST + 1:
                case EMBLEM_ENTRY_ERASE_BRUSH_FIRST + 2:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_ERASE);
                    SetEmblemCursorSizeIndex(entryIndex - EMBLEM_ENTRY_ERASE_BRUSH_FIRST);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_FILL:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_FILL);
                    SetEmblemCursorSizeIndex(EMBLEM_BRUSH_1X1);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_PICK_VALUE:
                    StartEmblemModeButtonPress((gEmblem->mEmblemSLld), entryIndex);
                    SetEmblemCursorMode(EMBLEM_CURSOR_MODE_PICK_VALUE);
                    SetEmblemCursorSizeIndex(EMBLEM_BRUSH_1X1);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f2);
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_TEMPLATE_BUTTON:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemTemplateSlideIn;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f3);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_SWAP_CELLS:
                    if (IsEmblemGridChanged()) {
                        if (IsEmblemGridSwapped()) {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1fb);
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1fc);
                        }
                        SwapEmblemGridCells();
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                    }
                    if (isTouch) {
                        gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                        return;
                    }
                    break;
                case EMBLEM_ENTRY_CAMERA:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemFadeOutToCamera;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                        gEmblem->mTransitionRunning = TRUE;
                        gEmblem->mKartListSkipped = FALSE;
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_ENTRY_CHOISES:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemChoises;
                        StartEmblemButtonBounce((gEmblem->mEmblemSLld), entryIndex);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
            }
            break;
        case EMBLEM_STATE_TEMPLATE:
            switch (entryIndex) {
                case 0:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        gEmblem->mPendingTransitionFunc = StartEmblemTemplateSlideOut;
                        StartEmblemButtonHold((gEmblem->mEmblemTemplateSLld), 1);
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xe);
                        gEmblem->mTransitionRunning = TRUE;
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
                case EMBLEM_TEMPLATE_ENTRY_FIRST:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 1:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 2:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 3:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 4:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 5:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 6:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 7:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 8:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 9:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 10:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 11:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 12:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 13:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 14:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 15:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 16:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 17:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 18:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 19:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 20:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 21:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 22:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 23:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 24:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 25:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 26:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 27:
                case EMBLEM_TEMPLATE_ENTRY_FIRST + 28:
                    if (gEmblem->mPendingTransitionFunc == NULL) {
                        templateByteSize = (s32) (GetEmblemGridSide() * GetEmblemGridSide()) / 2;
                        templateBytes = (u8 *) gEmblem->mEmblemTemplateBNcgr->mData +
                                        (entryIndex - EMBLEM_TEMPLATE_ENTRY_FIRST) * templateByteSize;
                        templateCellValues[0] = 0;
                        templateCellValues[1] = (GetEmblemCursorCellValue() == 1) ? 2 : 1;
                        templateCellValues[2] = GetEmblemCursorCellValue();
                        SplitBytesIntoNibbles(templateBytes, gEmblem->mCellNibbles, GetEmblemGridSide());
                        SetEmblemGridCellsFromTable((gEmblem->mCellNibbles), (templateCellValues));
                        ClearEmblemGridCopied();
                        gEmblem->mPendingTransitionFunc = StartEmblemTemplateSlideOut;
                        StartEmblemButtonBounceThenWait((gEmblem->mEmblemTemplateSLld), entryIndex);
                        gEmblem->mTemplateCursorIndex = entryIndex - 3;
                        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f6);
                    }
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    return;
            }
            break;
        case EMBLEM_STATE_CAMERA:
            if (entryIndex == 1) {
                if (gEmblem->mPendingTransitionFunc == NULL) {
                    gEmblem->mPendingTransitionFunc = StartEmblemFadeOutToGrid;
                    StartEmblemButtonBounceThenWait((gEmblem->mEmblemCameraSLld), entryIndex);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xc);
                    gEmblem->mKartListSkipped = TRUE;
                }
                gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
            }
            break;
    }
}

void AdvanceEmblemKartList(void) {
    int kartListNumber;
    int kartListCount;

    kartListNumber = GetKartListNumber();
    kartListCount = GetKartListCount();
    AdvanceKartModelMenuInput();
    if (kartListCount >= 10) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 4), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 5), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 6), kartListCount / 10);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 7), kartListCount % 10);
        if (kartListNumber >= 10) {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), kartListNumber / 10);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), kartListNumber % 10);
        } else {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), kartListNumber);
        }
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 3), -5);
    } else {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 4), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 5), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 6), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 7), kartListCount);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 1), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 2), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemMLld, 3), kartListNumber);
    }
}

void AdvanceEmblemGridScreen(void) {
    s32 touchedEntry;
    s32 inputX;
    s32 inputY;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 previousCursor;
    BOOL flag;
    void *buttonCursorEntry;
    void *colorCursorEntry;
    void *targetEntry;

    flag = FALSE;
    if (GetEmblemInputPressed()) {
        inputY = GetEmblemInputY();
        inputX = GetEmblemInputX();
        touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemSLld, 0, inputX, inputY);
        while (touchedEntry >= 0) {
            ActivateEmblemEntry(touchedEntry, 1);
            inputY = GetEmblemInputY();
            inputX = GetEmblemInputX();
            touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemSLld, touchedEntry + 1, inputX, inputY);
        }
    }

    if (GetEmblemInputNewBits(8)) {
        ActivateEmblemEntry(EMBLEM_ENTRY_CHOISES, 0);
    } else if (GetEmblemInputNewBits(4)) {
        ActivateEmblemEntry(EMBLEM_ENTRY_CAMERA, 0);
    } else if (GetEmblemInputNewBits(2)) {
        ActivateEmblemEntry(EMBLEM_ENTRY_SWAP_CELLS, 0);
    } else if (GetEmblemInputNewBits(0x800)) {
        ActivateEmblemEntry(EMBLEM_ENTRY_TOGGLE_BUTTON, 0);
    } else {
        buttonCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 8);
        GetLldEntry(gEmblem->mEmblemSLld, gEmblemButtonLldEntries[gEmblem->mButtonCursorIndex]);
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 9);
        GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mColorCursorIndex]);
        dx = 0;
        dy = 0;
        dz = 0;
        dx += GetNewOrRepeatBits(8, PAD_KEY_LEFT) ? -1 : 0;
        dx += GetNewOrRepeatBits(8, PAD_KEY_RIGHT) ? 1 : 0;
        dy += GetNewOrRepeatBits(8, PAD_KEY_UP) ? -1 : 0;
        dy += GetNewOrRepeatBits(8, PAD_KEY_DOWN) ? 1 : 0;
        dz += GetNewOrRepeatBits(8, PAD_KEY_L) ? -1 : 0;
        dz += GetNewOrRepeatBits(8, PAD_KEY_R) ? 1 : 0;

        switch (gEmblem->mCursorTargetState) {
            case EMBLEM_CURSOR_TARGET_GRID:
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
                if (dz > 0) {
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_COLORS;
                    gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0x1000);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 9), NULL);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 10), NULL);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz < 0) {
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_BUTTONS;
                    switch (GetEmblemCursorMode()) {
                        case EMBLEM_CURSOR_MODE_DRAW:
                            gEmblem->mButtonCursorIndex =
                                GetEmblemCursorSizeIndex() + gEmblemLPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case EMBLEM_CURSOR_MODE_ERASE:
                            gEmblem->mButtonCursorIndex =
                                GetEmblemCursorSizeIndex() + gEmblemLPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case EMBLEM_CURSOR_MODE_FILL:
                            gEmblem->mButtonCursorIndex = gEmblemLPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case EMBLEM_CURSOR_MODE_PICK_VALUE:
                            gEmblem->mButtonCursorIndex = gEmblemLPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                    }
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0x1000);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 8), NULL);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                }
                break;
            case EMBLEM_CURSOR_TARGET_BUTTONS:
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), 0);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
                if (dz < 0) {
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_COLORS;
                    gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0x1000);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 9), NULL);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 10), NULL);
                    ApplyLldEntryFrameCommand(buttonCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz > 0) {
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    ApplyLldEntryFrameCommand(buttonCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (GetEmblemInputNewBits(1)) {
                    if (gEmblemButtonLldEntries[gEmblem->mButtonCursorIndex] != 0x17 || IsEmblemGridChanged()) {
                        ActivateEmblemEntry(gEmblemButtonLldEntries[gEmblem->mButtonCursorIndex], 0);
                    }
                } else {
                    previousCursor = gEmblem->mButtonCursorIndex;
                    gEmblem->mButtonCursorIndex = gEmblemButtonCursorVerticalMoves[dy + 1][previousCursor];
                    gEmblem->mButtonCursorIndex =
                        gEmblemButtonCursorHorizontalMoves[dx + 1][gEmblem->mButtonCursorIndex];
                    targetEntry =
                        GetLldEntry(gEmblem->mEmblemSLld, gEmblemButtonLldEntries[gEmblem->mButtonCursorIndex]);
                    ApplyLldEntryFrameCommand(buttonCursorEntry, 0);
                    SetLldEntryPos(buttonCursorEntry, GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));
                    if (gEmblem->mButtonCursorIndex != previousCursor) {
                        StartSoundOncePerFrame(0x1ef);
                    }
                }
                AdvanceEmblemCursor(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
                break;
            case EMBLEM_CURSOR_TARGET_COLORS:
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), -5);
                ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), 0);
                if (dz > 0) {
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_BUTTONS;
                    switch (GetEmblemCursorMode()) {
                        case EMBLEM_CURSOR_MODE_DRAW:
                            gEmblem->mButtonCursorIndex =
                                GetEmblemCursorSizeIndex() + gEmblemRPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case EMBLEM_CURSOR_MODE_ERASE:
                            gEmblem->mButtonCursorIndex =
                                GetEmblemCursorSizeIndex() + gEmblemRPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case EMBLEM_CURSOR_MODE_FILL:
                            gEmblem->mButtonCursorIndex = gEmblemRPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                        case EMBLEM_CURSOR_MODE_PICK_VALUE:
                            gEmblem->mButtonCursorIndex = gEmblemRPressButtonCursorIndices[GetEmblemCursorMode()];
                            break;
                    }
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0x1000);
                    SetLldEntryCallback(GetLldEntry(gEmblem->mEmblemSLld, 8), NULL);
                    SetLldEntryScale(colorCursorEntry, 0);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                    ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (dz < 0) {
                    gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_HELD;
                    SetLldEntryScale(colorCursorEntry, 0);
                    SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
                    gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                    ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ee);
                } else if (GetEmblemInputNewBits(1)) {
                    ActivateEmblemEntry(gEmblemColorLldEntries[gEmblem->mColorCursorIndex], 0);
                } else {
                    previousCursor = gEmblem->mColorCursorIndex;
                    gEmblem->mColorCursorIndex = gEmblemColorCursorVerticalMoves[dy + 1][previousCursor];
                    gEmblem->mColorCursorIndex = gEmblemColorCursorHorizontalMoves[dx + 1][gEmblem->mColorCursorIndex];
                    GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mColorCursorIndex]);
                    if (gEmblem->mColorCursorIndex < EMBLEM_COLOR_COUNT) {
                        ApplyLldEntryFrameCommand(colorCursorEntry, 0);
                    } else {
                        ApplyLldEntryFrameCommand(colorCursorEntry, -5);
                    }
                    if (gEmblem->mColorCursorIndex != previousCursor) {
                        StartSoundOncePerFrame(0x1ef);
                    }
                }
                AdvanceEmblemCursor(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
                break;
        }
    }

    if (GetEmblemInputPressed() && IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
        gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
        }
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0);
        }
        gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_GRID;
    } else if (gEmblem->mCursorTargetState == EMBLEM_CURSOR_TARGET_HELD) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xb), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xc), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0xd), -5);
        gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 9), 0);
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 10), 0x1000);
        }
        if (GetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8)) == 0x1000) {
            SetLldEntryScale(GetLldEntry(gEmblem->mEmblemSLld, 8), 0);
        }
        if (!GetEmblemInputDown() && !GetEmblemInputBits(1) && !GetEmblemInputBits(2)) {
            gEmblem->mCursorTargetState = EMBLEM_CURSOR_TARGET_GRID;
        }
    }

    if (gEmblem->mCursorTargetState == EMBLEM_CURSOR_TARGET_GRID) {
        dx = 0;
        dy = 0;
        dx += IsEmblemInputRepeat(0x20) ? -1 : 0;
        dx += IsEmblemInputRepeat(0x10) ? 1 : 0;
        dy += IsEmblemInputRepeat(0x40) ? -1 : 0;
        dy += IsEmblemInputRepeat(0x80) ? 1 : 0;
        if (AdvanceEmblemCursor(GetEmblemInputDown(), GetEmblemInputX(), GetEmblemInputY(), GetEmblemInputBits(1), dx,
                                dy)) {
            if (GetEmblemCursorMode() == EMBLEM_CURSOR_MODE_PICK_VALUE) {
                gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f4);
            } else if (GetEmblemCursorMode() == EMBLEM_CURSOR_MODE_FILL) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f5);
            }
        } else if (GetEmblemInputBits(0x400)) {
            flag = TRUE;
            if (SetEmblemCursorCellValueFromGrid()) {
                gEmblem->mColorCursorIndex = GetEmblemCursorCellValue() - 1;
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f4);
            }
        }
        if (GetEmblemInputDown() && !GetEmblemInputPrevDown() &&
            IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
            gEmblem->mSoundPending = TRUE;
        } else if (GetEmblemInputDown() &&
                   (IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY()) ||
                    IsEmblemPointInGrid(GetEmblemInputPrevX(), GetEmblemInputPrevY())) &&
                   (GetEmblemCursorPointX() != GetEmblemCursorPrevPointX() ||
                    GetEmblemCursorPointY() != GetEmblemCursorPrevPointY())) {
            gEmblem->mSoundPending = TRUE;
        } else if (GetEmblemInputNewBits(1)) {
            gEmblem->mSoundPending = TRUE;
        } else if (GetEmblemInputBits(1) && (GetEmblemCursorPointX() != GetEmblemCursorPrevPointX() ||
                                             GetEmblemCursorPointY() != GetEmblemCursorPrevPointY())) {
            gEmblem->mSoundPending = TRUE;
        }
    } else {
        AdvanceEmblemCursor(0, GetEmblemInputX(), GetEmblemInputY(), 0, 0, 0);
    }

    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 0), GetEmblemCursorPointX(), GetEmblemCursorPointY());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 1), GetEmblemCursorPointX(), GetEmblemCursorPointY());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 2), GetEmblemCursorPointX(), GetEmblemCursorPointY());
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 3), GetEmblemCursorPointX(), GetEmblemCursorPointY());

    if (gEmblem->mCursorTargetState == EMBLEM_CURSOR_TARGET_GRID && GetEmblemInputDown() &&
        IsEmblemPointInGrid(GetEmblemInputX(), GetEmblemInputY())) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mCursorSizeIndex = EMBLEM_BRUSH_NONE;
    } else if (gEmblem->mCursorTargetState == EMBLEM_CURSOR_TARGET_GRID && GetEmblemInputDown() &&
               GetLldEntryFrameIndex(GetLldEntry(gEmblem->mEmblemSLld, 0)) == -5) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mCursorSizeIndex = EMBLEM_BRUSH_NONE;
    } else {
        gEmblem->mCursorSizeIndex = GetEmblemCursorSizeIndex();
        if (flag) {
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 3);
        } else {
            switch (GetEmblemCursorMode()) {
                case EMBLEM_CURSOR_MODE_DRAW:
                    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 0);
                    break;
                case EMBLEM_CURSOR_MODE_FILL:
                    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 1);
                    break;
                case EMBLEM_CURSOR_MODE_ERASE:
                    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 2);
                    break;
                case EMBLEM_CURSOR_MODE_PICK_VALUE:
                    ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), 3);
                    break;
            }
        }
    }

    switch (gEmblem->mCursorSizeIndex) {
        case EMBLEM_BRUSH_1X1:
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -4);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -5);
            break;
        case EMBLEM_BRUSH_2X2:
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -4);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -5);
            break;
        case EMBLEM_BRUSH_3X3:
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 1), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 2), -5);
            ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 3), -4);
            break;
    }

    targetEntry = GetLldEntry(gEmblem->mEmblemSLld, gEmblemColorLldEntries[gEmblem->mColorCursorIndex]);
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 9), GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));
    SetLldEntryPos(GetLldEntry(gEmblem->mEmblemSLld, 10), GetLldEntryX(targetEntry), GetLldEntryY(targetEntry));

    if (gEmblem->mColorCursorIndex < EMBLEM_COLOR_COUNT) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 4), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 5), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 6), -5);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 7), -5);
    } else {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 4), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 5), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 6), 0);
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 7), 0);
    }

    if (IsEmblemGridChanged() && GetLldEntryFrameIndex(GetLldEntry(gEmblem->mEmblemSLld, 0x17)) == 2) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0x17), 0);
    }
}

void AdvanceEmblemTemplateScreen(void) {
    void *templateCursorEntry;
    void *templateEntry;
    s32 touchedEntry;
    s32 horizontalStep;
    s32 verticalStep;
    s32 colorStep;
    s32 sel;
    s32 colorIndexHigh;
    s32 colorIndexLow;
    u32 inputY;
    s32 inputX;
    void *colorEntry;
    void *colorCursorEntry;

    if (GetEmblemInputPressed() != 0) {
        inputY = GetEmblemInputY();
        inputX = GetEmblemInputX();
        touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemTemplateSLld, 0, inputX, inputY);
        while (touchedEntry >= 0) {
            ActivateEmblemEntry(touchedEntry, 1);
            inputY = GetEmblemInputY();
            inputX = GetEmblemInputX();
            touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemTemplateSLld, touchedEntry + 1, inputX, inputY);
        }
    }
    if (GetEmblemInputNewBits(1) != 0) {
        ActivateEmblemEntry(gEmblemTemplateLldEntries[gEmblem->mTemplateCursorIndex], 0);
        return;
    }
    if (GetEmblemInputNewBits(2) != 0) {
        ActivateEmblemEntry(0, 0);
        return;
    }
    horizontalStep = 0;
    verticalStep = 0;
    colorStep = 0;
    horizontalStep += (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) ? -1 : 0;
    horizontalStep += (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) ? 1 : 0;
    verticalStep += (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) ? -1 : 0;
    verticalStep += (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) ? 1 : 0;
    colorStep += (GetNewOrRepeatBits(8, PAD_KEY_L) != 0) ? -1 : 0;
    colorStep += (GetNewOrRepeatBits(8, PAD_KEY_R) != 0) ? 1 : 0;
    gEmblem->mColorCursorIndex = colorStep + (GetEmblemCursorCellValue() - 1);
    colorIndexLow = gEmblem->mColorCursorIndex;
    if (colorIndexLow < 0) {
        colorIndexLow = 0xe;
    }
    gEmblem->mColorCursorIndex = colorIndexLow;
    colorIndexHigh = gEmblem->mColorCursorIndex;
    if (colorIndexHigh > 0xe) {
        colorIndexHigh = 0;
    }
    gEmblem->mColorCursorIndex = colorIndexHigh;
    sel = gEmblem->mColorCursorIndex;
    if (sel != GetEmblemCursorCellValue() - 1) {
        colorEntry = GetLldEntry(gEmblem->mEmblemSLld, gEmblemTemplateScreenColorEntries[sel]);
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 9);
        SetLldEntryPos(colorCursorEntry, GetLldEntryX(colorEntry), GetLldEntryY(colorEntry));
        colorCursorEntry = GetLldEntry(gEmblem->mEmblemSLld, 10);
        SetLldEntryPos(colorCursorEntry, GetLldEntryX(colorEntry), GetLldEntryY(colorEntry));
        SetEmblemCursorCellValue(gEmblem->mColorCursorIndex + 1);
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1f1);
    }
    sel = gEmblem->mTemplateCursorIndex;
    gEmblem->mTemplateCursorIndex = gEmblemTemplateCursorVerticalMoves[verticalStep + 1][sel];
    gEmblem->mTemplateCursorIndex =
        gEmblemTemplateCursorHorizontalMoves[horizontalStep + 1][gEmblem->mTemplateCursorIndex];
    templateCursorEntry = GetLldEntry(gEmblem->mEmblemTemplateSLld, 2);
    templateEntry = GetLldEntry(gEmblem->mEmblemTemplateSLld, gEmblemTemplateLldEntries[gEmblem->mTemplateCursorIndex]);
    ApplyLldEntryFrameCommand(templateCursorEntry, 0);
    SetLldEntryPos(templateCursorEntry, GetLldEntryX(templateEntry), GetLldEntryY(templateEntry));
    if (gEmblem->mTemplateCursorIndex != sel) {
        StartSoundOncePerFrame(0x1ef);
    }
    {
        s32 templateIndex;
        void *entryAtIndex;

        for (templateIndex = 0; templateIndex < 0x1d; templateIndex++) {
            entryAtIndex = GetLldEntry(gEmblem->mEmblemTemplateSLld, gEmblemTemplateLldEntries[templateIndex]);
            ApplyLldEntryFrameCommand(entryAtIndex, templateIndex == gEmblem->mTemplateCursorIndex ? 1 : 0);
        }
    }
}

void AdvanceEmblemCameraScreen(void) {
    s32 touchedEntry;
    u32 inputY;
    s32 inputX;

    if (GetEmblemInputPressed() != 0) {
        inputY = GetEmblemInputY();
        inputX = GetEmblemInputX();
        touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemCameraSLld, 0, inputX, inputY);
        while (touchedEntry >= 0) {
            ActivateEmblemEntry(touchedEntry, 1);
            inputY = GetEmblemInputY();
            inputX = GetEmblemInputX();
            touchedEntry = FindLldEntryAtPoint(gEmblem->mEmblemCameraSLld, touchedEntry + 1, inputX, inputY);
        }
    }
    if (GetEmblemInputNewBits(4) != 0) {
        ActivateEmblemEntry(1, 0);
    }
}

void AdvanceEmblemChoisesScreen(void) {
    s32 choisesResult;

    choisesResult = GetEmblemChoisesResult();
    switch (choisesResult) {
        case -2:
        case EMBLEM_CHOISE_BACK:
            StopEmblemChoises();
            break;
        case EMBLEM_CHOISE_SAVE:
            SetEmblemChoisesShownAndReset(0);
            JoinNibbleTilesIntoBytes(GetEmblemGridCells(), gEmblem->mRecordBytes, GetEmblemGridSide());
            SetEmblemRecordAndWriteBackup(gEmblem->mRecordBytes);
            gEmblem->mState = EMBLEM_STATE_SAVING;
            gEmblem->mDisplayState = EMBLEM_DISPLAY_IDLE;
            break;
        case EMBLEM_CHOISE_DISCARD:
            SetEmblemChoisesShownAndReset(0);
            gEmblem->mState = EMBLEM_STATE_SAVING;
            gEmblem->mDisplayState = EMBLEM_DISPLAY_IDLE;
            break;
    }
    UpdateEmblemChoises();
    WriteEmblemChoisesScreenMapWrapper();
}

void AdvanceEmblem(void) {
    s32 scrollPosition;

    AdvanceEmblemInput();
    gEmblem->mBgScrollPosition += 0x4cd;
    scrollPosition = gEmblem->mBgScrollPosition;
    if (scrollPosition >= 0x100000) {
        scrollPosition -= 0x100000;
    }
    gEmblem->mBgScrollPosition = scrollPosition;
    ClearOamListCounts(gEmblem, &gEmblem->mSubOam);
    AdvanceLld(gEmblem->mEmblemMLld, &gEmblem->mMainOam);
    switch (gEmblem->mState) {
        case EMBLEM_STATE_GRID:
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_TEMPLATE:
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemTemplateScreen();
            }
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mSubOam);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_TEMPLATE_SLIDE_IN:
            AdvanceEmblemTemplateSlideIn();
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mSubOam);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_TEMPLATE_SLIDE_OUT:
            AdvanceEmblemTemplateSlideOut();
            AdvanceLld(gEmblem->mEmblemTemplateSLld, &gEmblem->mSubOam);
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_CAMERA:
            if (gEmblem->mKartListSkipped == FALSE) {
                AdvanceEmblemKartList();
            }
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemCameraScreen();
            }
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_FADE_OUT_TO_CAMERA:
            if (gEmblem->mKartListSkipped == FALSE) {
                AdvanceEmblemKartList();
            }
            AdvanceEmblemFadeOutToCamera();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_FADE_IN_AT_CAMERA:
            if (gEmblem->mKartListSkipped == FALSE) {
                AdvanceEmblemKartList();
            }
            AdvanceEmblemFadeInAtCamera();
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_FADE_OUT_TO_GRID:
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceEmblemFadeOutToGrid();
            AdvanceLld(gEmblem->mEmblemCameraSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_FADE_IN_AT_GRID:
            if (gEmblem->mTransitionRunning == FALSE) {
                AdvanceEmblemGridScreen();
            }
            AdvanceEmblemFadeInAtGrid();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_CHOISES:
            AdvanceEmblemChoisesScreen();
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
        case EMBLEM_STATE_SAVING:
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            if (gBackupBuffers->mBusy == 0) {
                if (gBackupAccess->mBackupEnabled != 0) {
                    scrollPosition = gBackupAccess->mCommandRunning;
                } else {
                    scrollPosition = 0;
                }
            } else {
                scrollPosition = 1;
            }
            if (scrollPosition == 0) {
                gEmblem->mState = EMBLEM_STATE_DONE;
            }
            break;
        case EMBLEM_STATE_DONE:
            AdvanceLld(gEmblem->mEmblemSLld, &gEmblem->mSubOam);
            break;
    }
    HideUnusedOams(gEmblem, &gEmblem->mSubOam);
    AdvanceShownSlotAndQueueEmblem();
    DrawKartModelMenuUnmirrored();
    JoinNibbleTilesIntoBytes(GetEmblemGridCells(), gEmblem->mRecordBytes, GetEmblemGridSide());
    JoinNibblesIntoBytes(GetEmblemGridCells(), gEmblem->mGridCharBytes, GetEmblemGridSide());
}

void AdvanceEmblemDisplay(void) {
    u16 *sbColors;
    u16 *soColors;
    u32 dispcntBits;

    if ((gBackupBuffers->mBusy == 0 ? (gBackupAccess->mBackupEnabled ? gBackupAccess->mCommandRunning : 0) : 1) == 0) {
        AdvanceKartModelMenuLoad();
    }

    switch (gEmblem->mDisplayState) {
        case EMBLEM_DISPLAY_UPLOAD_SCREENS:
            UploadEmblemMainScreen();
            UploadEmblemSubScreen();
            gEmblem->mUploadFrames++;
            if (gEmblem->mUploadFrames >= EMBLEM_UPLOAD_FRAMES) {
                gEmblem->mDisplayState = EMBLEM_DISPLAY_GRID;
            }
            break;
        case EMBLEM_DISPLAY_TEMPLATE_SLIDE_IN_SETUP:
            dispcntBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((dispcntBits | 1) << 8);
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 1;
            reg_G2S_DB_BG0CNT =
                (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0x8a10;
            reg_G2S_DB_BG0OFS = (-(gEmblem->mTemplateSlideOffset - EMBLEM_TEMPLATE_SLIDE_DISTANCE) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS = (FROM_FIXED12(gEmblem->mBgScrollPosition) & 0x1ff) |
                                ((FROM_FIXED12(-gEmblem->mBgScrollPosition) << 16) & 0x1ff0000);
            gEmblem->mDisplayState = EMBLEM_DISPLAY_TEMPLATE_SLIDING;
            break;
        case EMBLEM_DISPLAY_TEMPLATE_SLIDE_OUT_SETUP:
            reg_G2S_DB_BG0OFS = (-(gEmblem->mTemplateSlideOffset - EMBLEM_TEMPLATE_SLIDE_DISTANCE) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS = (FROM_FIXED12(gEmblem->mBgScrollPosition) & 0x1ff) |
                                ((FROM_FIXED12(-gEmblem->mBgScrollPosition) << 16) & 0x1ff0000);
            GXS_SetGraphicsMode(GX_BGMODE_1);
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 2;
            reg_G2S_DB_BG3CNT =
                (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x1218;
            DC_FlushRange(gEmblem->mGridCharBytes, 0x200);
            GX_LoadBG2Char((gEmblem->mGridCharBytes), 0, 0x200);
            G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0, 0x10, 0x10);
            gEmblem->mDisplayState = EMBLEM_DISPLAY_TEMPLATE_SLIDING;
            break;
        case EMBLEM_DISPLAY_TEMPLATE_SLIDING:
            reg_G2S_DB_BG0OFS = (-(gEmblem->mTemplateSlideOffset - EMBLEM_TEMPLATE_SLIDE_DISTANCE) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS = (FROM_FIXED12(gEmblem->mBgScrollPosition) & 0x1ff) |
                                ((FROM_FIXED12(-gEmblem->mBgScrollPosition) << 16) & 0x1ff0000);
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
        case EMBLEM_DISPLAY_TEMPLATE_SETUP:
            reg_G2S_DB_BG0OFS = (-(gEmblem->mTemplateSlideOffset - EMBLEM_TEMPLATE_SLIDE_DISTANCE) << 16) & 0x1ff0000;
            reg_G2S_DB_BG2OFS = (FROM_FIXED12(gEmblem->mBgScrollPosition) & 0x1ff) |
                                ((FROM_FIXED12(-gEmblem->mBgScrollPosition) << 16) & 0x1ff0000);
            GXS_SetGraphicsMode(GX_BGMODE_0);
            reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 1;
            reg_G2S_DB_BG3CNT =
                (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x1010;
            reg_G2S_DB_BG3OFS = 0;
            G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 8, 0x36, 8, 8);
            gEmblem->mDisplayState = EMBLEM_DISPLAY_TEMPLATE_SHOWN;
            break;
        case EMBLEM_DISPLAY_GRID_RESTORE:
            dispcntBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((dispcntBits & ~1) << 8);
            reg_G2S_DB_BG2OFS = (FROM_FIXED12(gEmblem->mBgScrollPosition) & 0x1ff) |
                                ((FROM_FIXED12(-gEmblem->mBgScrollPosition) << 16) & 0x1ff0000);
            gEmblem->mDisplayState = EMBLEM_DISPLAY_GRID;
            break;
        case EMBLEM_DISPLAY_TEMPLATE_SHOWN:
            DC_FlushRange(gEmblem->mGridCharBytes, 0x200);
            GX_LoadBG2Char((gEmblem->mGridCharBytes), 0, 0x200);
            sbColors = gEmblem->mEmblemSBNclr->mData;
            soColors = gEmblem->mEmblemSONclr->mData;
            soColors[0x91] = sbColors[GetEmblemCursorCellValue() == 1 ? 2 : 1];
            soColors[0x92] = sbColors[GetEmblemCursorCellValue()];
            DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case EMBLEM_DISPLAY_GRID:
            reg_G2S_DB_BG2OFS = (FROM_FIXED12(gEmblem->mBgScrollPosition) & 0x1ff) |
                                ((FROM_FIXED12(-gEmblem->mBgScrollPosition) << 16) & 0x1ff0000);
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
        case EMBLEM_DISPLAY_GRID_UPLOAD:
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -16);
            UploadEmblemSubScreen();
            gEmblem->mDisplayState = EMBLEM_DISPLAY_GRID_FADE;
            break;
        case EMBLEM_DISPLAY_CAMERA_UPLOAD:
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -16);
            UploadEmblemCameraSubScreen();
            gEmblem->mDisplayState = EMBLEM_DISPLAY_CAMERA_FADE;
            break;
        case EMBLEM_DISPLAY_CAMERA_FADE:
            reg_G2S_DB_BG2OFS = 0;
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -gEmblem->mFadeLevel);
            break;
        case EMBLEM_DISPLAY_GRID_FADE:
            reg_G2S_DB_BG2OFS = (FROM_FIXED12(gEmblem->mBgScrollPosition) & 0x1ff) |
                                ((FROM_FIXED12(-gEmblem->mBgScrollPosition) << 16) & 0x1ff0000);
            G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3e, -gEmblem->mFadeLevel);
            break;
        case EMBLEM_DISPLAY_CHOISES_SETUP:
            UploadEmblemSubScreen();
            reg_G2S_DB_BG0OFS = 0;
            reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 1;
            reg_G2S_DB_BG0CNT =
                (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0xa00;
            gEmblem->mDisplayState = EMBLEM_DISPLAY_IDLE;
            break;
        case EMBLEM_DISPLAY_CHOISES_CLOSE:
            UploadEmblemSubScreen();
            gEmblem->mDisplayState = EMBLEM_DISPLAY_GRID;
            break;
    }

    if (gEmblem->mSoundPending != FALSE) {
        if (GetEmblemCursorMode() == EMBLEM_CURSOR_MODE_DRAW) {
            if (GetEmblemCursorSizeIndex() == EMBLEM_BRUSH_1X1) {
                SetEmblemSoundValue(0);
            } else if (GetEmblemCursorSizeIndex() == EMBLEM_BRUSH_2X2) {
                SetEmblemSoundValue(1);
                gEmblem->mUnk_10bc = 1;
            } else if (GetEmblemCursorSizeIndex() == EMBLEM_BRUSH_3X3) {
                SetEmblemSoundValue(2);
                gEmblem->mUnk_10bc = 2;
            }
        } else if (GetEmblemCursorMode() == EMBLEM_CURSOR_MODE_ERASE) {
            if (GetEmblemCursorSizeIndex() == EMBLEM_BRUSH_1X1) {
                SetEmblemSoundValue(3);
            } else if (GetEmblemCursorSizeIndex() == EMBLEM_BRUSH_2X2) {
                SetEmblemSoundValue(4);
            } else if (GetEmblemCursorSizeIndex() == EMBLEM_BRUSH_3X3) {
                SetEmblemSoundValue(5);
            }
        }
        gEmblem->mSoundPending = FALSE;
    }
    DrawEmblemChoises();
    UploadOamLists(&gEmblem->mMainOam, &gEmblem->mSubOam);
}

void InitEmblemAndAdvanceKartList(void) {
    InitEmblem();
    AdvanceEmblemKartList();
}

BOOL AdvanceEmblemAndCheckDone(void) {
    AdvanceEmblem();
    if (gEmblem->mState == EMBLEM_STATE_DONE) {
        return TRUE;
    }
    return FALSE;
}

void AdvanceEmblemDisplayWrapper(void) {
    AdvanceEmblemDisplay();
}

u16 *GetEmblemSBPalette(void) {
    return gEmblem->mEmblemSBNclr->mData;
}

u8 *GetEmblemRecordBytes(void) {
    return gEmblem->mRecordBytes;
}
