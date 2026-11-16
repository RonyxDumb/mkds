#include "Main/Graphics/message_index.h"
#include "Main/Kart/karts.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Race/race_setup.h"
#include "Main/Save/buddy_record_time.h"

const s32 gCharacterKartIndexTableBattle[13] = {0,    3,    6,    9,    0xc,  0xf,  0x12,
                                                0x15, 0x18, 0x1b, 0x1e, 0x21, KART_INDEX_HEYHO};
const s32 gCharacterKartIndexTable[13] = {2,    5,    7,    0xb,  0xe,  0x10, 0x13,
                                          0x16, 0x1a, 0x1d, 0x1f, 0x22, KART_INDEX_HEYHO};
const u32 gCharacterSeqPairNoTable[13] = {4, 0, 1, 2, 5, 6, 7, 3, 0xa, 8, 9, 0xb, 0xc};
const u32 gKartMessageIndexTable[36] = {6,    7,    8,    0x15, 0x16, 0x17, 0x12, 0x13, 0x14, 0x1b, 0x1c, 0x1d,
                                        0xc,  0xd,  0xe,  0x18, 0x19, 0x1a, 0xf,  0x10, 0x11, 9,    0xa,  0xb,
                                        0x21, 0x22, 0x23, 0x1e, 0x1f, 0x20, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29};
const u32 gKartIndexTable[36] = {2,    0,    1,    0x16, 0x15, 0x17, 0xe,  0xc,  0xd,  0x13, 0x12, 0x14,
                                 7,    6,    8,    5,    3,    4,    0x10, 0xf,  0x11, 0xb,  9,    0xa,
                                 0x1d, 0x1b, 0x1c, 0x1a, 0x18, 0x19, 0x1f, 0x1e, 0x20, 0x22, 0x21, 0x23};
const s32 gCourseMessageIndexTable[48] = {-1,   0x4c, -1,   -1,   -1,   -1,   -1,   -1,   -1,   0x44, 0x3d, 0x3e,
                                          0x43, 0x3f, 0x40, 0x45, 0x42, 0x36, 0x30, 0x38, 0x2d, -1,   0x2e, 0x4a,
                                          0x34, 0x37, 0x3a, 0x31, 0x32, 0x3c, 0x35, 0x2f, 0x3b, 0x33, 0x39, 0x41,
                                          0x46, 0x47, 0x48, 0x49, 0x4b, -1,   0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52};

#pragma thumb on
u32 GetCharacterSeqPairNo(u32 characterIndex) {
    return gCharacterSeqPairNoTable[characterIndex];
}
#pragma thumb off

#pragma thumb on
s32 GetCharacterKartIndexByMode(s32 characterIndex) {
    s32 kartIndex = -1;
    switch (GetRaceSetupCopy()->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_VS:
        case MODE_WIFI:
            kartIndex = gCharacterKartIndexTable[characterIndex];
            break;
        case MODE_BATTLE:
            kartIndex = gCharacterKartIndexTableBattle[characterIndex];
            break;
    }
    return kartIndex;
}

s32 FindKartTableIndex(u32 kartIndex) {
    s32 tableIndex = 0;
    s32 foundIndex = -1;
    if (kartIndex != KART_INDEX_HEYHO) {
        for (; tableIndex < 0x24; tableIndex++) {
            if (kartIndex == gKartIndexTable[tableIndex]) {
                foundIndex = tableIndex;
                break;
            }
        }
    }
    return foundIndex;
}
#pragma thumb off

#pragma thumb on
u32 GetKartIndexAtTableIndex(u32 tableIndex) {
    return gKartIndexTable[tableIndex];
}
#pragma thumb off

#pragma thumb on

int CountKartsWithinAppearLimit(KartAppear *appear, u32 characterIndex) {
    int count;
    int tableIndex;
    int testResult;
    u32 kartIndex;
    count = 0;
    tableIndex = 0;
    do {
        kartIndex = GetKartIndexAtTableIndex(tableIndex);
        testResult = IsKartAppearWithinLimit(appear, characterIndex, kartIndex);
        if (testResult != 0) {
            count = count + 1;
        }
        tableIndex = tableIndex + 1;
    } while (tableIndex < 0x24);
    return count;
}

#pragma thumb off

#pragma thumb on
s32 GetKartPositionWithinAppearLimit(KartAppear *appear, u32 characterIndex, s32 kartIndex) {
    s32 position = 1;
    s32 tableIndex;
    s32 startIndex;
    u32 tableKartIndex;
    startIndex = FindKartTableIndex(GetCharacterKartIndexByMode(characterIndex));
    tableIndex = startIndex;
    do {
        tableKartIndex = GetKartIndexAtTableIndex(tableIndex);
        if (IsKartAppearWithinLimit(appear, characterIndex, tableKartIndex) != 0) {
            if (tableKartIndex == kartIndex) {
                break;
            }
            position++;
        }
        tableIndex++;
        if (tableIndex >= 0x24) {
            tableIndex = 0;
        }
    } while (tableIndex != startIndex);
    return position;
}
#pragma thumb off

#pragma thumb on
u32 GetKartMessageIndex(u32 kartIndex) {
    return gKartMessageIndexTable[kartIndex];
}
#pragma thumb off

#pragma thumb on
u32 GetCourseMessageIndex(u32 courseId) {
    return gCourseMessageIndexTable[courseId];
}
#pragma thumb off

#pragma thumb on

int GetGhostCourseMessageIndex(int courseId) {
    int messageIndex;
    messageIndex = gCourseMessageIndexTable[courseId];
    if (messageIndex != -1) {
        messageIndex = messageIndex + -0x1a;
    }
    return messageIndex;
}

int GetWiFiCourseMessageIndex(int courseId) {
    int messageIndex;
    messageIndex = gCourseMessageIndexTable[courseId];
    if (messageIndex != -1) {
        messageIndex = messageIndex + 4;
    }
    return messageIndex;
}

#pragma thumb off
