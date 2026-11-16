#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_020ec8bc.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_0212bcac.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02103598.h"
#include "Main/Unknown/code_021035ac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02103840.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "g3imm.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

#pragma thumb on

void InitBouncingItemBoxMapObjects(void) {
    int objectCount;
    int index;
    BouncingItemBox *box;
    ItemObject **objectCursor;
    ItemPool *pool;
    MapObject *mapObject;
    if (it_sItemConfigs[17].mEnabled != FALSE) {
        pool = &it_sItemsets[8];
        objectCursor = pool->mObjects;
        objectCount = pool->mObjectCount;
        index = 0;
        if (0 < objectCount) {
            do {
                box = (BouncingItemBox *) *objectCursor;
                mapObject = AllocPooledMapObject();
                box->mPooledMapObject = (PooledMapObject *) mapObject;
                box->mPooledMapObject->mUnk_fc = &box->mMapObjectPos;
                objectCursor = objectCursor + 1;
                index = index + 1;
            } while (index < objectCount);
        }
        pool->mUnk_40 = 1;
    }
}

#pragma thumb off

#pragma thumb on

void InitBouncingItemBoxTimers(void) {
    s32 i;
    u32 *timerCursor;
    u32 *runningFlagCursor;

    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        return;
    }
    i = 0;
    timerCursor = gBouncingItemBoxTimers;
    runningFlagCursor = gBouncingItemBoxTimerRunning;
    do {
        *timerCursor++ = -1;
        *runningFlagCursor++ = 0;
        i++;
    } while (i < 8);
}

#pragma thumb off

void cspl_dripUpdate(OrthoQuad *quad) {
    s16(*velocities)[2];
    s32 framesFromMoveStart;
    s32 i;
    s32 k;
    NNSSndSeqPlayer **sndHandle;
    s16 x;
    s16 y;
    s32 b;

    velocities = quad->mCornerVelocities;
    framesFromMoveStart = cspl_sSplashTimer - gOrthoQuadMoveStartFrameCount;
    if (framesFromMoveStart < 0) {
        for (i = 0; i < 4; i++) {
            quad->mCorners[i][1] -= 2;
        }
        return;
    }
    if (framesFromMoveStart == 0 && cspl_sUseCustomSplash == 0 && quad == cspl_sSplashes) {
        sndHandle = GetSndHandleSlot(6);
        NNS_SndPlayerStopSeq(sndHandle, 1);
        if ((data_0217c780 & 1) != 0 && SoundHandle_217D084.mUnk_0c != 0) {
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0xef);
        }
    }
    if (quad->mVelocityMode != 0) {
        for (i = 0; i < 4; i++) {
            quad->mCorners[i][0] += velocities[i][0];
            quad->mCorners[i][1] += velocities[i][1];
            velocities[i][0] = ((s64) velocities[i][0] * 0x10cd) >> 12;
            velocities[i][1] = ((s64) velocities[i][1] * 0x10cd) >> 12;
            x = quad->mCorners[i][0];
            if (x > 0x3ccd) {
                quad->mCorners[i][0] = 0x3ccd;
            } else if (x < -0x3ccd) {
                quad->mCorners[i][0] = -0x3ccd;
            }
            y = quad->mCorners[i][1];
            if (y > 0x3ccd) {
                quad->mCorners[i][1] = 0x3ccd;
            } else if (y < -0x3ccd) {
                quad->mCorners[i][1] = -0x3ccd;
            }
        }
    } else {
        i = 0;
        if (i < 4) {
            do {
                x = velocities[i][0];
                y = velocities[i][1];
                if (y < 0) {
                    k = y * y > x * x ? 7 : 5;
                    if (i == quad->mPickedCornerIndex) {
                        k += (k << 1) + ((k * framesFromMoveStart) >> 9);
                    }
                } else {
                    k = y * y > x * x ? 2 : 3;
                }
                b = k;
                b += (k * framesFromMoveStart) >> 8;
                quad->mCorners[i][1] = quad->mCorners[i][1] - b;
                if (quad->mCorners[i][1] < -0x3ccd) {
                    quad->mCorners[i][1] = -0x3ccd;
                }
                i++;
            } while (i < 4);
        }
    }
    quad->mTimer = quad->mTimer - 1;
    if ((quad->mTimer & 0xf) == 0) {
        RandomState64 *a = &gRaceStatus->mLocalRandom;

        a->mValue = a->mMultiplier * a->mValue + a->mIncrement;
        quad->mPickedCornerIndex = (u16) (((u64) (u32) (a->mValue >> 32) * 6) >> 32);
    }
}

void cspl_appearUpdate(OrthoQuad *quad) {
    s16(*velocities)[2] = quad->mCornerVelocities;
    s32 i;
    s32 tableScale;
    s16 startX;
    s16 startY;
    s32 v;

    tableScale = cspl_appearScaleAnim[-quad->mTimer];
    startX = quad->mStartPair[0];
    startY = quad->mStartPair[1];
    for (i = 0; i < 4; i++) {
        v = velocities[i][0];
        quad->mCorners[i][0] = startX + (s32) (((s64) v * tableScale) >> 12);
        v = velocities[i][1];
        quad->mCorners[i][1] = startY + (s32) (((s64) v * tableScale) >> 12);
    }
    quad->mTimer = quad->mTimer - 1;
    if (quad->mTimer == -13) {
        quad->mUpdateFunction = cspl_dripUpdate;
    }
}

void cspl_initialWaitUpdate(OrthoQuad *quad) {
    NNSSndSeqPlayer **sndHandle;
    u32 seqNo;

    quad->mTimer = quad->mTimer - 1;
    if (quad->mTimer != 0) {
        return;
    }
    quad->mUpdateFunction = cspl_appearUpdate;
    if (rstat_getUncontrollable() != 0) {
        return;
    }
    seqNo = cspl_sUseCustomSplash != 0 ? 0x157 : 0xee;
    if (seqNo == 1) {
        return;
    }
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    sndHandle = sp_acquireElement(sound_getPoolById(0));
    if (SoundHandle_217D084.mUnk_0c == 0) {
        return;
    }
    if (*sndHandle != NULL) {
        NNS_SndPlayerStopSeq(sndHandle, 0);
    }
    if (*sndHandle != NULL) {
        NNS_SndPlayerStopSeq(sndHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(sndHandle, 0, (u16) seqNo);
}

void cspl_update(void) {
    s32 i;
    OrthoQuadModel *model;
    s32 frames;
    u16 alpha;

    if (cspl_sSplashCount == 0) {
        return;
    }
    for (i = 0; i < cspl_sSplashCount; i++) {
        OrthoQuad *e = &cspl_sSplashes[i];

        e->mUpdateFunction(e);
    }
    frames = cspl_sSplashTimer + 1;
    cspl_sSplashTimer = frames;
    if (frames <= cspl_sSplashDuration) {
        return;
    }
    if (frames & 1) {
        return;
    }
    alpha = cspl_sSplashAlpha;
    cspl_sSplashAlpha = alpha - 1;
    alpha = cspl_sSplashAlpha;
    if (alpha == 0) {
        cspl_sSplashCount = 0;
        cspl_sUseCustomSplash = FALSE;
        NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
        return;
    }
    model = cspl_sUseCustomSplash != 0 ? &cspl_sCustomSplashTex : &cspl_sGessoSplashTex;
    model->mPolygonAttr = model->mPolygonAttr & ~0x1f0000;
    model->mPolygonAttr = model->mPolygonAttr | (alpha << 16);
}

void cspl_renderSplash(OrthoQuadModel *model) {
    s32 i;

    if (cspl_sSplashCount == 0) {
        return;
    }
    if (rstat_getUncontrollable() != 0) {
        return;
    }
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    reg_G3_TEXIMAGE_PARAM = model->mTeximageParam;
    reg_G3_PLTT_BASE = model->mPlttBase;
    reg_G3_DIF_AMB = model->mDifAmb;
    reg_G3_SPE_EMI = model->mSpeEmi;
    reg_G3_MTX_MODE = 0;
    G3_LoadMtx44(cspl_sProjMtx);
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_SCALE = 0x64000;
    reg_G3_MTX_SCALE = 0x64000;
    reg_G3_MTX_SCALE = 0x64000;
    i = 0;
    if (cspl_sSplashCount <= 0) {
        return;
    }
    do {
        OrthoQuad *e = &cspl_sSplashes[i];

        reg_G3_POLYGON_ATTR = model->mPolygonAttr | (cspl_sPolygonId + i) << 24;
        reg_G3_BEGIN_VTXS = 1;
        reg_G3_TEXCOORD = 0;
        reg_G3_VTX_16 = *(u32 *) &e->mCorners[0];
        reg_G3_VTX_16 = 0;
        reg_G3_TEXCOORD = (u16) ((s32) (model->mUnk_1c << 8) >> 16) << 16;
        *(u32 *) 0x4000494 = *(u32 *) &e->mCorners[1];
        reg_G3_TEXCOORD = (u16) ((s32) (model->mUnk_18 << 8) >> 16) | ((u16) ((s32) (model->mUnk_1c << 8) >> 16) << 16);
        *(u32 *) 0x4000494 = *(u32 *) &e->mCorners[2];
        reg_G3_TEXCOORD = (u16) ((s32) (model->mUnk_18 << 8) >> 16);
        *(u32 *) 0x4000494 = *(u32 *) &e->mCorners[3];
        reg_G3_END_VTXS = 0;
        i++;
    } while (i < cspl_sSplashCount);
}

void cspl_render(void) {
    cspl_renderSplash(cspl_sUseCustomSplash != 0 ? &cspl_sCustomSplashTex : &cspl_sGessoSplashTex);
}

// Marks the cells in rows row - 2 to row + 2 next to column; returns the bits that were already marked.
u8 MarkOrthoQuadCellsAndGetOverlap(s32 column, s32 row) {
    u8 overlapAbove;
    s32 fiveCellMask;
    s32 threeCellMask;
    u8 overlap;

    threeCellMask = (1 << (column + 1)) | (1 << (column + 2)) | (1 << (column + 3));
    fiveCellMask = threeCellMask | (1 << column) | (1 << (column + 4));
    overlapAbove = 0;
    if (row > 1) {
        overlapAbove |= cspl_sScreenCoverageFlags[row - 2] & (u8) (threeCellMask >> 3);
        cspl_sScreenCoverageFlags[row - 2] |= (u8) (threeCellMask >> 3);
    }
    if (row > 0) {
        overlapAbove |= cspl_sScreenCoverageFlags[row - 1] & (u8) (fiveCellMask >> 3);
        cspl_sScreenCoverageFlags[row - 1] |= (u8) (fiveCellMask >> 3);
    }
    overlap = overlapAbove | (cspl_sScreenCoverageFlags[row] & (u8) (fiveCellMask >> 3));
    cspl_sScreenCoverageFlags[row] |= (u8) (fiveCellMask >> 3);
    if (row < 7) {
        overlap |= cspl_sScreenCoverageFlags[row + 1] & (u8) (fiveCellMask >> 3);
        cspl_sScreenCoverageFlags[row + 1] |= (u8) (fiveCellMask >> 3);
    }
    if (row < 6) {
        overlap |= cspl_sScreenCoverageFlags[row + 2] & (u8) (threeCellMask >> 3);
        cspl_sScreenCoverageFlags[row + 2] |= (u8) (threeCellMask >> 3);
    }
    return overlap;
}

void cspl_emitSplash(s32 index, HalfwordPair startPair, s32 overlap) {
    RaceProgress *raceProgress;
    RandomState64 *random;
    OrthoQuad *quad;
    s16(*velocities)[2];
    s32 i;
    s16 c;
    s16 s;
    s32 t;
    s16 velocityX;
    s16 velocityY;

    raceProgress = gRaceStatus;
    quad = &cspl_sSplashes[index];
    random = &raceProgress->mLocalRandom;
    velocities = quad->mCornerVelocities;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    t = (s32) (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32) >> 4;
    c = FX_SinCosTable_[2 * t];
    s = FX_SinCosTable_[2 * t + 1];
    if (overlap != 0) {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        t = (s16) (((u64) (u32) (random->mValue >> 32) * 0xcd) >> 32) + 0x800;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        t = 0xa66 + (s16) (((u64) (u32) (random->mValue >> 32) * 0x52) >> 32);
    }
    t = (s16) t;
    if (cspl_sUseCustomSplash != 0) {
        t = (s16) (((s64) t * 0x800) >> 12);
    }
    quad->mTimer = cspl_sInitialDelayTable[index];
    velocities[0][0] = -t;
    velocities[0][1] = -t;
    velocities[1][0] = -t;
    velocities[1][1] = t;
    velocities[2][0] = t;
    velocities[2][1] = t;
    velocities[3][0] = t;
    velocities[3][1] = -t;
    for (i = 0; i < 4; i++) {
        velocityY = velocities[i][1];
        velocityX = velocities[i][0];
        velocities[i][0] = (s * velocityX - c * velocityY) >> 12;
        velocities[i][1] = (c * velocityX + s * velocityY) >> 12;
        *(HalfwordPair *) quad->mCorners[(u32) i] = startPair;
    }
    *(HalfwordPair *) quad->mStartPair = startPair;
    quad->mUpdateFunction = cspl_initialWaitUpdate;
    quad->mPickedCornerIndex = -1;
    quad->mVelocityMode = 0;
}

// Local entry only: places up to count quads at random cells; the cream effect does not restart while quads show.
void cspl_emitSplashes(s32 kartIndex, s32 count, s32 useCreamEffect) {
    HalfwordPair startPair;
    s32 i;
    s32 placedCount;
    s32 m;
    s32 column;
    s32 row;
    RandomState64 *random;

    random = &gRaceStatus->mLocalRandom;
    driver_getById(kartIndex);
    if (kartIndex != gRaceMultiConfig->mEntryIndex) {
        return;
    }
    cspl_sDriverId = kartIndex;
    if (cspl_sSplashCount != 0) {
        if (useCreamEffect != 0) {
            return;
        }
    }
    cspl_sSplashCount = 0;
    cspl_sUseCustomSplash = FALSE;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
    cspl_sUseCustomSplash = useCreamEffect;
    for (i = 0; i < 8; i++) {
        cspl_sScreenCoverageFlags[i] = 0;
    }
    m = 1;
    for (i = 0, placedCount = 0; i < 0x10 && placedCount < count; i++) {
        if (cspl_sUseCustomSplash != 0) {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_00 = (s16) (((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32) * 2;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_02 = (s16) (((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32) * 2;
        } else if (cspl_sSplashCount == 0) {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_00 = ((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_00 =
                startPair.mHalf.mUnk_00 + (s16) (((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32);
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_02 = ((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_02 =
                startPair.mHalf.mUnk_02 + (s16) (((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32);
        } else {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_00 = ((u64) (u32) (random->mValue >> 32) * 0x2000) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_02 = ((u64) (u32) (random->mValue >> 32) * 0x1800) >> 32;
        }
        column = startPair.mHalf.mUnk_00 >> 10;
        row = startPair.mHalf.mUnk_02 >> 10;
        if (row >= 3 || column < 3 || column > 4) {
            if ((cspl_sScreenCoverageFlags[row] & (m << column)) == 0) {
                s32 r = MarkOrthoQuadCellsAndGetOverlap(column, row);

                startPair.mHalf.mUnk_00 -= 0x1000;
                startPair.mHalf.mUnk_02 -= 0x600;
                cspl_emitSplash(placedCount, startPair, r);
                placedCount++;
            }
        }
    }
    cspl_sSplashCount = placedCount;
    cspl_sSplashTimer = 0;
    cspl_sSplashAlpha = 0x1f;
    if (cspl_sUseCustomSplash != 0) {
        cspl_sSplashDuration = 0x96;
        gOrthoQuadMoveStartFrameCount = 0x1e;
        cspl_sCustomSplashTex.mPolygonAttr &= ~0x1f0000;
        cspl_sCustomSplashTex.mPolygonAttr |= 0x1f0000;
    } else {
        cspl_sSplashDuration = 0x184;
        gOrthoQuadMoveStartFrameCount = 0x2d;
        cspl_sGessoSplashTex.mPolygonAttr &= ~0x1f0000;
        cspl_sGessoSplashTex.mPolygonAttr |= 0x1f0000;
    }
}

void cspl_emitGessoSplash(u32 kartIndex, u32 count) {
    cspl_emitSplashes(kartIndex, count, 0);
}

void cspl_killSplashes(int kartIndex) {
    if (kartIndex != gRaceMultiConfig->mEntryIndex) {
        return;
    }
    cspl_sSplashCount = 0;
    cspl_sUseCustomSplash = FALSE;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
}

// Local entry only: moves the frame counter up to the hold count so the alpha starts to fall.
u32 cspl_clearSplashes(u32 kartIndex) {
    u32 value0 = kartIndex;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    s32 compareLeft2;
    s32 compareRight2;
    value1 = gRaceMultiConfig->mEntryIndex;
    compareLeft0 = value0;
    compareRight0 = value1;
    if (compareLeft0 != compareRight0) {
        return value0;
    }
    value0 = (u32) &cspl_sSplashCount;
    value0 = *(const u32 *) ((value0) + (0));
    compareLeft1 = value0;
    compareRight1 = 0u;
    if (compareLeft1 == compareRight1) {
        return value0;
    }
    value1 = (u32) &cspl_sSplashDuration;
    value0 = (u32) &cspl_sSplashTimer;
    value2 = *(const u32 *) ((value1) + (0));
    value1 = *(const u32 *) ((value0) + (0));
    compareLeft2 = value1;
    compareRight2 = value2;
    if (compareLeft2 < compareRight2) {
        *(u32 *) ((value0) + (0)) = value2;
    }
    return value0;
}

// Derives the corner velocities from the corner positions and switches the quad to velocity mode.
void cspl_speedClearSplash(OrthoQuad *quad) {
    s32 i;
    s32 cornerX;
    s32 cornerY;
    s32 pushY;
    s32 pushX;
    s32 j;
    s16(*velocities)[2] = quad->mCornerVelocities;

    for (i = 0; i < 4; i++) {
        velocities[i][0] = 0;
        velocities[i][1] = 0;
    }
    for (i = 0; i < 4; i++) {
        cornerX = quad->mCorners[i][0];
        cornerY = quad->mCorners[i][1];
        if (cornerX > 0) {
            if (cornerX > 0x4cd) {
                pushX = ((s64) cornerX * cornerX) >> 12;
            } else {
                pushX = 0x171;
            }
        } else {
            if (cornerX < 0x4cd) {
                pushX = -(s32) (((s64) cornerX * cornerX) >> 12);
            } else {
                pushX = -0x171;
            }
        }
        if (cornerY > 0) {
            if (cornerY > 0x4cd) {
                pushY = ((s64) cornerY * cornerY) >> 12;
            } else {
                pushY = 0x171;
            }
        } else {
            if (cornerY < 0x4cd) {
                pushY = -(s32) (((s64) cornerY * cornerY) >> 12);
            } else {
                pushY = -0x171;
            }
        }
        for (j = 0; j < 4; j++) {
            if (i == j) {
                velocities[j][0] += (s32) (((s64) pushX * 12) >> 12);
                velocities[j][1] += (s32) (((s64) pushY * 12) >> 12);
            } else {
                velocities[j][0] += (s32) (((s64) pushX * 8) >> 12);
                velocities[j][1] += (s32) (((s64) pushY * 8) >> 12);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (velocities[i][1] < 0) {
            velocities[i][1] = 0;
        }
    }
    quad->mVelocityMode = 1;
}

void cspl_speedClearSplashes(int kartIndex) {
    OrthoQuad *quad;
    s32 i;
    s32 quadCount;
    s32 holdFrameCount;
    s32 frames;

    if (kartIndex != gRaceMultiConfig->mEntryIndex) {
        return;
    }
    quadCount = cspl_sSplashCount;
    if (quadCount == 0) {
        return;
    }
    holdFrameCount = cspl_sSplashDuration;
    frames = cspl_sSplashTimer;
    if (frames < holdFrameCount) {
        cspl_sSplashTimer = holdFrameCount;
    }
    i = 0;
    if (quadCount <= 0) {
        return;
    }
    do {
        quad = &cspl_sSplashes[i];
        if (quad->mVelocityMode == 0 && quad->mUpdateFunction == cspl_dripUpdate) {
            cspl_speedClearSplash(quad);
        }
        i++;
    } while (i < cspl_sSplashCount);
}

u32 cspl_unloadCustomSplashModel(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &cspl_sCustomSplashTex;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void cspl_loadCustomSplashModel(const char *fileName) {
    u32 model;

    bbm_createFromNsbmd((NsbmdModel **) &model, mobj_getMapObjFile(fileName), 0, 0);
    bbm_setDefaultMatParams((NsbmdModel *) model);
    cspl_initSplashTex(&cspl_sCustomSplashTex, (NsbmdModel *) model);
}

void cspl_emitCustomSplash(u32 kartIndex, u32 count) {
    cspl_emitSplashes(kartIndex, count, 1);
}

#pragma thumb on
void cspl_init(void) {
    NsbmdModel *model;
    s32 i;

    cspl_sSplashes = heap_alloc(proc_getHeap(proc_getCurrent()), 0xd0);
    cspl_sDriverId = 0xffff;
    cspl_sSplashCount = 0;
    cspl_sUseCustomSplash = FALSE;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
    model = it_loadItemBillboardModel(aGeso_sumi_nsbm, NULL, aGeso_sumi_ns_0);
    cspl_initSplashTex(&cspl_sGessoSplashTex, model);
    cspl_sPolygonId = mobj_getStaticPolygonId();
    for (i = 0; i < 3; i++) {
        mobj_getStaticPolygonId();
    }
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_PUSH = 0;
    G3i_OrthoW_(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x1fb, 1, (Unk0214ad4c *) cspl_sProjMtx);
    reg_G3_MTX_POP = 1;
}

void cspl_initSplashTex(OrthoQuadModel *quadModel, NsbmdModel *model) {
    u32 teximageParam;

    quadModel->mModel = model;
    quadModel->mPolygonAttr = 0x51f80c0;
    quadModel->mPolygonAttr = quadModel->mPolygonAttr & 0xc0ffffff;
    quadModel->mTeximageParam = *model->mUnk_1c;
    quadModel->mPlttBase = *model->mUnk_20;
    quadModel->mDifAmb = model->mUnk_0c;
    quadModel->mSpeEmi = model->mUnk_10;
    teximageParam = quadModel->mTeximageParam;
    quadModel->mUnk_18 = 1 << (((teximageParam & 0x3800000) >> 0x17) + 0xf);
    quadModel->mUnk_1c = 1 << (((teximageParam & 0x700000) >> 0x14) + 0xf);
}
#pragma thumb off

void itgsso_21031F4(ItemGesso *gesso) {
    s32 kartCount;
    s32 entryIndex;
    s32 ownerIndex;
    s32 i;
    RaceProgress *raceProgress;
    RandomState64 *random;
    Kart *kart;
    u16 rank;
    u32 ownerRank;
    u16 kartIndex;

    ownerIndex = (u16) ((gesso->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (gesso->mUnk_000.mUnk_78 & ~0xff00) : 8);
    entryIndex = gRaceMultiConfig->mEntryIndex;
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        kartCount = gRaceMultiConfig->mKartCount;
        for (i = 0; i < kartCount; i++) {
            if (i == ownerIndex) {
                continue;
            }
            kart = driver_getById(i);
            if (kart->mUnk_7c & 0x402020) {
                continue;
            }
            if (kart->mUnk_4c & 0x10000840) {
                continue;
            }
            if (kart->mUnk_48 & 0x10000) {
                continue;
            }
            raceProgress = gRaceStatus;
            random = &raceProgress->mLocalRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            gesso->mOrthoQuadCounts[i] = (u16) (((random->mValue >> 32) * 4) >> 32) + 1;
        }
    } else {
        rank = 1;
        ownerRank = rstat_getPlace(ownerIndex);
        do {
            kartIndex = gRaceStatus->mKartAtRank[(u8) rank - 1];
            kart = driver_getById(kartIndex);
            if ((kart->mUnk_7c & 0x402020) == 0 && (kart->mUnk_4c & 0x10000840) == 0 &&
                (kart->mUnk_48 & 0x10000) == 0) {
                gesso->mOrthoQuadCounts[kartIndex] = 4 - ((rank - 1) >> 1);
            }
            rank++;
        } while (rank < ownerRank);
    }
    if (entryIndex < 0 || gesso->mOrthoQuadCounts[entryIndex] == 0) {
        gesso->mVisible = FALSE;
        return;
    }
    gesso->mVisible = TRUE;
    gesso->mKart = driver_getById(entryIndex);
    func_020f8e3c((u32) gesso->mKart, 0xf3);
}
