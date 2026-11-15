#include "01/Menu/emblem_grid_screen.h"
#include "01/MapObjects/lld.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_system.h"
#include "player.h"
#include "Main/Graphics/oam.h"
#include "01/Menu/emblem_grid.h"
#include "01/Menu/emblem_entry_activate.h"
#include "01/code_021a5140.h"
#include "01/unk_021ca000.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02192000.h"
#include "01/Menu/emblem_input.h"
#include "01/code_021a4000.h"
#include "01/code_021a5000.h"
#include "01/code_021a6000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/Menu/emblem_cursor.h"
#include "code_0212df7c.h"

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
        ActivateEmblemEntry(0x1a, 0);
    } else if (GetEmblemInputNewBits(4)) {
        ActivateEmblemEntry(0x19, 0);
    } else if (GetEmblemInputNewBits(2)) {
        ActivateEmblemEntry(0x17, 0);
    } else if (GetEmblemInputNewBits(0x800)) {
        ActivateEmblemEntry(0x2a, 0);
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
                    if (gEmblem->mColorCursorIndex < 0xf) {
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
        gEmblem->mCursorSizeIndex = -1;
    } else if (gEmblem->mCursorTargetState == EMBLEM_CURSOR_TARGET_GRID && GetEmblemInputDown() &&
               GetLldEntryFrameIndex(GetLldEntry(gEmblem->mEmblemSLld, 0)) == -5) {
        ApplyLldEntryFrameCommand(GetLldEntry(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mCursorSizeIndex = -1;
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

    if (gEmblem->mColorCursorIndex < 0xf) {
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
