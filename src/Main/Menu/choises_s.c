#include "Main/Menu/choises_s.h"
#include "Main/System/heap.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Race/grand_prix_last_course.h"
#include "Main/Menu/choises_s_screen_map.h"
#include "Main/Menu/choises_s_course.h"
#include "Main/Menu/choises_s_select.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/System/file_in_loaded.h"
#include "g2d_CharCanvas.h"

void ChoisesSInitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing) {
    textCanvas->mCharCanvas = charCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = lineSpacing;
}

u32 ChoisesSDrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, textX, textY, color, flags, text);
}

#pragma thumb on
#pragma optimize_for_size on

void InitChoisesS(void) {
    ChoisesS *choisesS;
    u32 charCount;
    s32 index;

    gChoisesS = HeapAlloc(ChoisesSGetCurrentHeap(), 0x1a4);
    gChoisesS->mOpenDuringRace = 0;
    gChoisesS->mPrevOpenDuringRace = 0;
    gChoisesS->mOpenAfterRace = 0;
    gChoisesS->mPickLocked = 0;
    gChoisesS->mPickFrames = 0;
    gChoisesS->mPickStartedOnSelected = FALSE;
    gChoisesS->mAutoPickFrames = 0;
    if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN) {
        gChoisesS->mOtherMissionRecordsFilled5To7 = AreOtherMissionRecordsFilled5To7();
    } else {
        gChoisesS->mOtherMissionRecordsFilled5To7 = FALSE;
    }
    gChoisesS->mUnk_02c = 0;
    gChoisesS->mUnk_030 = 0;
    ResetChoisesSSelection();
    ClearChoisesSListValueCounts();
    switch (ChoisesSGetCurrentMode()) {
        case MODE_GRAND_PRIX:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            if (IsGrandPrixLastCourse() != FALSE) {
                AppendChoisesSListValue(1, 7);
                AppendChoisesSListValue(1, 8);
            } else {
                AppendChoisesSListValue(1, 2);
                AppendChoisesSListValue(1, 8);
                AppendChoisesSListValue(1, 9);
            }
            if (IsGrandPrixLastCourse() != FALSE) {
                AppendChoisesSListValue(3, 0);
                AppendChoisesSListValue(3, 7);
                AppendChoisesSListValue(3, 8);
            } else {
                AppendChoisesSListValue(3, 0);
                AppendChoisesSListValue(3, 2);
                AppendChoisesSListValue(3, 8);
                AppendChoisesSListValue(3, 9);
            }
            break;
        case MODE_TIME_ATTACK:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 3);
            AppendChoisesSListValue(0, 4);
            AppendChoisesSListValue(0, 5);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 1);
            AppendChoisesSListValue(1, 4);
            AppendChoisesSListValue(1, 5);
            AppendChoisesSListValue(1, 8);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(3, 0);
            AppendChoisesSListValue(3, 1);
            AppendChoisesSListValue(3, 4);
            AppendChoisesSListValue(3, 5);
            AppendChoisesSListValue(3, 8);
            AppendChoisesSListValue(3, 9);
            break;
        case MODE_BATTLE:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 2);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(2, 7);
            break;
        case MODE_VS:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 2);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(2, 7);
            break;
        case MODE_MISSION_RUN:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 3);
            AppendChoisesSListValue(0, 6);
            AppendChoisesSListValue(0, 9);
            if (IsMissionRunTableRow6Or7Column9() != 0) {
                if (IsMissionRunRecordFilled() != 0) {
                    AppendChoisesSListValue(1, 1);
                    AppendChoisesSListValue(1, 6);
                    AppendChoisesSListValue(1, 9);
                    AppendChoisesSListValue(2, 6);
                    AppendChoisesSListValue(2, 1);
                    AppendChoisesSListValue(2, 10);
                    AppendChoisesSListValue(2, 9);
                } else {
                    AppendChoisesSListValue(1, 1);
                    AppendChoisesSListValue(1, 6);
                    AppendChoisesSListValue(1, 9);
                    AppendChoisesSListValue(2, 6);
                    AppendChoisesSListValue(2, 1);
                    AppendChoisesSListValue(2, 9);
                }
            } else {
                AppendChoisesSListValue(1, 1);
                AppendChoisesSListValue(1, 6);
                AppendChoisesSListValue(1, 9);
                AppendChoisesSListValue(2, 6);
                AppendChoisesSListValue(2, 1);
                AppendChoisesSListValue(2, 9);
            }
            break;
        case 5:
            AppendChoisesSListValue(0, 0);
            if (GetCourseNumber() != 4) {
                AppendChoisesSListValue(1, 2);
            } else {
                AppendChoisesSListValue(1, 7);
            }
            break;
    }
    if (ChoisesSGetCurrentRaceKind() != RACE_KIND_START_GP && ChoisesSGetCurrentRaceKind() != RACE_KIND_STAFF_ROLL) {
        const char *nscrNames[6] = {
            "choises_s_1.NSCR", "choises_s_2.NSCR", "choises_s_3.NSCR",
            "choises_s_4.NSCR", "choises_s_5.NSCR", "choises_s_6.NSCR",
        };

        LoadNclrData(&gChoisesS->mChoisesSBNclr, FindSceneFileWrapper("choises_s_b.NCLR"));
        LoadNcgrData(&gChoisesS->mChoisesSBNcgr, FindSceneFileWrapper("choises_s_b.NCGR"));
        for (index = 0; index < 6; index++) {
            LoadNscrData(&gChoisesS->mChoisesSNscrs[index], FindSceneFileWrapper(nscrNames[index]));
        }
        gChoisesS->mList0Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[0].mValueCount - 1];
        gChoisesS->mList1Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[1].mValueCount - 1];
        gChoisesS->mList2Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[2].mValueCount - 1];
        gChoisesS->mList3Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[3].mValueCount - 1];
        gChoisesS->mList1Chars =
            HeapAlloc(ChoisesSGetCurrentHeap(), GetChoisesSListCharsSize(gChoisesS->mLists[1].mValueCount));
        switch (ChoisesSGetCurrentMode()) {
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_MISSION_RUN:
                gChoisesS->mList2Chars =
                    HeapAlloc(ChoisesSGetCurrentHeap(), GetChoisesSListCharsSize(gChoisesS->mLists[2].mValueCount));
                break;
        }
        gChoisesS->mFont = GetFontByIndex(2);
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[0], GetChoisesSBNcgrWithListChars()->mData, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        ChoisesSInitTextCanvas(&choisesS->mTextCanvases[0], choisesS->mCharCanvases[0], choisesS->mFont, IsLanguageJa(),
                               0);
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[1], gChoisesS->mList1Chars, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        ChoisesSInitTextCanvas(&choisesS->mTextCanvases[1], choisesS->mCharCanvases[1], choisesS->mFont, IsLanguageJa(),
                               0);
        charCount = GetChoisesSListCharsSize(gChoisesS->mLists[1].mValueCount) >> 1;
        for (index = 0; index < charCount; index++) {
            gChoisesS->mList1Chars[index] = GetChoisesSBNcgrWithListChars()->mData[index];
        }
        if (gChoisesS->mList2Chars != NULL) {
            NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[2], gChoisesS->mList2Chars, 0x20, 0xc, 4);
            choisesS = gChoisesS;
            ChoisesSInitTextCanvas(&choisesS->mTextCanvases[2], choisesS->mCharCanvases[2], choisesS->mFont,
                                   IsLanguageJa(), 0);
            charCount = GetChoisesSListCharsSize(gChoisesS->mLists[2].mValueCount) >> 1;
            for (index = 0; index < charCount; index++) {
                gChoisesS->mList2Chars[index] = GetChoisesSBNcgrWithListChars()->mData[index];
            }
        }
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[3], GetChoisesSBNcgrWithListChars()->mData, 0x20, 0xc, 4);
        choisesS = gChoisesS;
        ChoisesSInitTextCanvas(&choisesS->mTextCanvases[3], choisesS->mCharCanvases[3], choisesS->mFont, IsLanguageJa(),
                               0);
        if (ChoisesSGetCurrentRaceKind() != RACE_KIND_REPLAY) {
            for (index = 0; index < gChoisesS->mLists[0].mValueCount; index++) {
                ChoisesSDrawTextOnCanvas(&gChoisesS->mTextCanvases[0], 0x90, index * 16 + 9, 0xc, 0x412,
                                         GetChoisesSValueMessage(0, gChoisesS->mLists[0].mValues[index]));
            }
        } else {
            for (index = 0; index < gChoisesS->mLists[3].mValueCount; index++) {
                ChoisesSDrawTextOnCanvas(&gChoisesS->mTextCanvases[3], 0x90, index * 16 + 9, 0xc, 0x412,
                                         GetChoisesSValueMessage(3, gChoisesS->mLists[3].mValues[index]));
            }
        }
        for (index = 0; index < gChoisesS->mLists[1].mValueCount; index++) {
            ChoisesSDrawTextOnCanvas(&gChoisesS->mTextCanvases[1], 0x90, index * 16 + 9, 0xc, 0x412,
                                     GetChoisesSValueMessage(1, gChoisesS->mLists[1].mValues[index]));
        }
        for (index = 0; index < gChoisesS->mLists[2].mValueCount; index++) {
            ChoisesSDrawTextOnCanvas(&gChoisesS->mTextCanvases[2], 0x90, index * 16 + 9, 0xc, 0x412,
                                     GetChoisesSValueMessage(2, gChoisesS->mLists[2].mValues[index]));
        }
    } else {
        gChoisesS->mChoisesSBNclr = NULL;
        gChoisesS->mChoisesSBNcgr = NULL;
        gChoisesS->mList1Chars = NULL;
        gChoisesS->mList2Chars = NULL;
        gChoisesS->mList0Nscr = NULL;
        gChoisesS->mList1Nscr = NULL;
        gChoisesS->mList2Nscr = NULL;
        gChoisesS->mList3Nscr = NULL;
    }
}

void ClearChoisesSPointer(void) {
    gChoisesS = NULL;
}

#pragma thumb off
