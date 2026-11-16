#include "Main/Unknown/code_020d2090.h"

#include "Main/Unknown/code_020d2094.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02134398.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020b4000.h"

BOOL mobj_destroysItemOnHit(MapObject *mapObject, ItemObject *itemObject) {
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
    if (mobj_getItemHitObjResponse(0, itemKind, kindHundreds, kindRemainder) == 0 ||
        mobj_getItemHitResponse(0, itemKind, kindHundreds, kindRemainder, 3) != 2) {
        return FALSE;
    }
    return TRUE;
}

#pragma thumb on

void *mobj_getSharedMapObjFile(const char *name) {
    char buf[0x100];
    snprintf(buf, 0x100, "MapObj/%s", name);
    return arc_getMainRaceMainEffectArcFile(buf);
}

void *mobj_getMapObjFile(const char *name) {
    char buf[0x100];
    snprintf(buf, 0x100, "MapObj/%s", name);
    return arc_getCourseArcFile(buf);
}

u32 mobj_parseDecimalBits(s32 number) {
    u32 bitMask;
    s32 digit;
    bitMask = 0;
    if (number >= 1000) {
        digit = number / 1000;
        bitMask |= 1 << digit;
        number = (s16) (number - digit * 1000);
    }
    if (number >= 100) {
        digit = number / 100;
        bitMask |= 1 << digit;
        number = (s16) (number - digit * 100);
    }
    if (number >= 10) {
        digit = number / 10;
        bitMask |= 1 << digit;
        number = (s16) (number - digit * 10);
    }
    if (number >= 1) {
        bitMask |= 1 << number;
    }
    return bitMask;
}

#pragma thumb off

void r2d_initRaceNumber(void) {
    RaceMNumberPair *pair;
    pair = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    gRaceMNumberPair = pair;
    pair->mCourseNumber = gRaceMultiConfig->mCourseNumber;
    if (gRaceMultiConfig->mMode == 5) {
        gRaceMNumberPair->mCourseCount = 4;
    } else if (gRaceMultiConfig->mMode == MODE_VS && gRaceMultiConfig->mRuleKind == 2) {
        gRaceMNumberPair->mCourseCount = gRaceMultiConfig->mCourseCount;
    } else {
        gRaceMNumberPair->mCourseCount = 0;
    }
    lmap_scaleMtx22(gRaceMNumberPair->mScaleMatrix, 0x1000);
    gRaceMNumberPair->mCellMatrix = NULL;
    gRaceMNumberPair->mScale = 0;
    gRaceMNumberPair->mMatrixIndex = 0;
    gRaceMNumberPair->mOffsetX = 0;
}

u32 r2d_finalizeRaceNumber(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceMNumberPair;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void r2d_updateRaceNumber(void) {}
