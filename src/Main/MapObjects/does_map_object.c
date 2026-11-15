#include "Main/MapObjects/does_map_object.h"

#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/race_m_number_pair.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_02134398.h"
#include "Main/Graphics/font_and_player_character.h"

BOOL DoesMapObjectRespondToItemObject(MapObject *mapObject, ItemObject *itemObject) {
    s32 kindRemainder;
    s32 kindHundreds;
    s32 itemKind;
    kindRemainder = mapObject->mKind;
    itemKind = itemObject->mKind;
    kindHundreds = 0;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    if (GetItemObjectFirstResponseByKind(0, itemKind, kindHundreds, kindRemainder) == 0 ||
        GetItemObjectResponseByKind(0, itemKind, kindHundreds, kindRemainder, 3) != 2) {
        return FALSE;
    }
    return TRUE;
}

#pragma thumb on

void *FindMainRaceOrMainEffectMapObjFile(const char *name) {
    char buf[0x100];
    snprintf(buf, 0x100, "MapObj/%s", name);
    return FindMainRaceOrMainEffectFile(buf);
}

void *FindCourseMapObjFile(const char *name) {
    char buf[0x100];
    snprintf(buf, 0x100, "MapObj/%s", name);
    return FindCourseFile(buf);
}

u32 DecimalNonZeroDigitsToBitMask(s32 number) {
    u32 bitMask;
    s32 digit;
    bitMask = 0;
    if (number >= 1000) {
        digit = number / 1000;
        BIT_SET(bitMask, digit);
        number = (s16) (number - digit * 1000);
    }
    if (number >= 100) {
        digit = number / 100;
        BIT_SET(bitMask, digit);
        number = (s16) (number - digit * 100);
    }
    if (number >= 10) {
        digit = number / 10;
        BIT_SET(bitMask, digit);
        number = (s16) (number - digit * 10);
    }
    if (number >= 1) {
        BIT_SET(bitMask, number);
    }
    return bitMask;
}

#pragma thumb off

void InitRaceMNumberPair(void) {
    RaceMNumberPair *pair;
    pair = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gRaceMNumberPair = pair;
    pair->mCourseNumber = gRaceSetup->mCourseNumber;
    if (gRaceSetup->mMode == MODE_WIFI) {
        gRaceMNumberPair->mCourseCount = 4;
    } else if (gRaceSetup->mMode == MODE_VS && gRaceSetup->mRuleKind == RULE_KIND_RACE_COUNT) {
        gRaceMNumberPair->mCourseCount = gRaceSetup->mCourseCount;
    } else {
        gRaceMNumberPair->mCourseCount = 0;
    }
    Matrix2x2ReciprocalScale(&gRaceMNumberPair->mScaleMatrix, 0x1000);
    gRaceMNumberPair->mCellMatrix = NULL;
    gRaceMNumberPair->mScale = 0;
    gRaceMNumberPair->mMatrixIndex = 0;
    gRaceMNumberPair->mOffsetX = 0;
}

void ClearRaceMNumberPairPointer(void) {
    gRaceMNumberPair = NULL;
}

void UpdateRaceMNumberPairNop(void) {}
