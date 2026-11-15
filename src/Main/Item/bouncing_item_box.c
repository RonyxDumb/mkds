#include "Main/Item/bouncing_item_box.h"
#include "Main/Item/item_link_following.h"

#include "Main/System/heap.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/entry_kart_sound.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "geometry_engine_setup.h"
#include "Main/Kart/kart_drift.h"
#include "sound_archive_load_result.h"
#include "Main/Race/entry_race_ended.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "geometry_matrix_commands.h"
#include "Main/Item/pooled_item_box_init.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "registers.h"
#include "fixed_vector_math.h"
#include "Main/System/init_after_startup.h"
#include "Main/Item/bouncing_item_box_timers.h"

u16 gOrthoQuadFirstPolygonId;
u16 gOrthoQuadAlpha;
u16 gOrthoQuadKartIndex;
s32 gOrthoQuadCount;
s32 gOrthoQuadFrames;
s32 gOrthoQuadHoldFrameCount;
s32 gOrthoQuadMoveStartFrameCount;
BOOL gOrthoQuadUseCreamEffect;
OrthoQuad *gOrthoQuads;
u8 gOrthoQuadCells[8];
OrthoQuadModel gOrthoQuadGesoSumi;
OrthoQuadModel gOrthoQuadCreamEffect;
MtxFx44 gOrthoQuadMatrix;

const s32 gOrthoQuadTimersByIndex[4] = {5, 0xb, 0x11, 0x19};
const s32 gOrthoQuadTableScales[13] = {0,     0x986, 0x1000, 0x1143, 0x117c, 0x1107, 0x1041,
                                       0xf87, 0xf34, 0xf52,  0xf95,  0xfd8,  0xff7};
char gGesoSumiTextureNsbmdName[16] = "geso_sumi.nsbmd";
char gGesoSumiModelNsbmdName[16] = "geso_sumi.nsbmd";

#pragma thumb on

void InitBouncingItemBoxMapObjects(void) {
    int objectCount;
    int index;
    BouncingItemBox *box;
    ItemObject **objectCursor;
    ItemPool *pool;
    MapObject *mapObject;
    if (gItemInfos[ITEM_INFO_BOUNCING_ITEM_BOX].mEnabled != FALSE) {
        pool = &gItemPools[8];
        objectCursor = pool->mObjects;
        objectCount = pool->mObjectCount;
        index = 0;
        if (0 < objectCount) {
            do {
                box = (BouncingItemBox *) *objectCursor;
                mapObject = AllocPooledMapObject();
                box->mPooledMapObject = (ItemBox *) mapObject;
                box->mPooledMapObject->mPositionSource = &box->mMapObjectPos;
                objectCursor = objectCursor + 1;
                index = index + 1;
            } while (index < objectCount);
        }
        pool->mDrawnByMapObjects = 1;
    }
}

#pragma thumb off

#pragma thumb on

void InitBouncingItemBoxTimers(void) {
    s32 timerIndex;
    u32 *timerCursor;
    u32 *runningFlagCursor;

    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    timerIndex = 0;
    timerCursor = gBouncingItemBoxTimers;
    runningFlagCursor = gBouncingItemBoxTimerRunning;
    do {
        *timerCursor++ = -1;
        *runningFlagCursor++ = 0;
        timerIndex++;
    } while (timerIndex < 8);
}

#pragma thumb off

void AdvanceOrthoQuadCornersByVelocity(OrthoQuad *quad) {
    s16(*velocities)[2];
    s32 framesFromMoveStart;
    s32 cornerIndex;
    s32 fallSpeed;
    NNSSndSeqPlayer **sndHandle;
    s16 coordX;
    s16 coordY;
    s32 fallDistance;

    velocities = quad->mCornerVelocities;
    framesFromMoveStart = gOrthoQuadFrames - gOrthoQuadMoveStartFrameCount;
    if (framesFromMoveStart < 0) {
        for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
            quad->mCorners[cornerIndex].mHalf.mY -= 2;
        }
        return;
    }
    if (framesFromMoveStart == 0 && gOrthoQuadUseCreamEffect == 0 && quad == gOrthoQuads) {
        sndHandle = GetSndHandleSlot(6);
        NNS_SndPlayerStopSeq(sndHandle, 1);
        if ((gRaceSoundKind & 1) != 0 && gSoundModeHolder.mSeqStartEnabled != 0) {
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
        for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
            quad->mCorners[cornerIndex].mHalf.mX += velocities[cornerIndex][0];
            quad->mCorners[cornerIndex].mHalf.mY += velocities[cornerIndex][1];
            velocities[cornerIndex][0] = MUL_FIXED12_NO_ROUND(velocities[cornerIndex][0], 0x10cd);
            velocities[cornerIndex][1] = MUL_FIXED12_NO_ROUND(velocities[cornerIndex][1], 0x10cd);
            coordX = quad->mCorners[cornerIndex].mHalf.mX;
            if (coordX > ORTHO_QUAD_COORD_LIMIT) {
                quad->mCorners[cornerIndex].mHalf.mX = ORTHO_QUAD_COORD_LIMIT;
            } else if (coordX < -ORTHO_QUAD_COORD_LIMIT) {
                quad->mCorners[cornerIndex].mHalf.mX = -ORTHO_QUAD_COORD_LIMIT;
            }
            coordY = quad->mCorners[cornerIndex].mHalf.mY;
            if (coordY > ORTHO_QUAD_COORD_LIMIT) {
                quad->mCorners[cornerIndex].mHalf.mY = ORTHO_QUAD_COORD_LIMIT;
            } else if (coordY < -ORTHO_QUAD_COORD_LIMIT) {
                quad->mCorners[cornerIndex].mHalf.mY = -ORTHO_QUAD_COORD_LIMIT;
            }
        }
    } else {
        cornerIndex = 0;
        if (cornerIndex < 4) {
            do {
                coordX = velocities[cornerIndex][0];
                coordY = velocities[cornerIndex][1];
                if (coordY < 0) {
                    fallSpeed = coordY * coordY > coordX * coordX ? 7 : 5;
                    if (cornerIndex == quad->mPickedCornerIndex) {
                        fallSpeed += (fallSpeed << 1) + ((fallSpeed * framesFromMoveStart) >> 9);
                    }
                } else {
                    fallSpeed = coordY * coordY > coordX * coordX ? 2 : 3;
                }
                fallDistance = fallSpeed;
                fallDistance += (fallSpeed * framesFromMoveStart) >> 8;
                quad->mCorners[cornerIndex].mHalf.mY = quad->mCorners[cornerIndex].mHalf.mY - fallDistance;
                if (quad->mCorners[cornerIndex].mHalf.mY < -ORTHO_QUAD_COORD_LIMIT) {
                    quad->mCorners[cornerIndex].mHalf.mY = -ORTHO_QUAD_COORD_LIMIT;
                }
                cornerIndex++;
            } while (cornerIndex < 4);
        }
    }
    quad->mTimer = quad->mTimer - 1;
    if ((quad->mTimer & ORTHO_QUAD_CORNER_PICK_MASK) == 0) {
        RandomState64 *random = &gRaceProgress->mLocalRandom;

        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        quad->mPickedCornerIndex = (u16) (((u64) (u32) (random->mValue >> 32) * 6) >> 32);
    }
}

void AdvanceOrthoQuadCornersByTable(OrthoQuad *quad) {
    s16(*velocities)[2] = quad->mCornerVelocities;
    s32 cornerIndex;
    s32 tableScale;
    s16 startX;
    s16 startY;
    s32 velocity;

    tableScale = gOrthoQuadTableScales[-quad->mTimer];
    startX = quad->mStartPair.mHalf.mX;
    startY = quad->mStartPair.mHalf.mY;
    for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
        velocity = velocities[cornerIndex][0];
        quad->mCorners[cornerIndex].mHalf.mX = startX + MUL_FIXED12_NO_ROUND(velocity, tableScale);
        velocity = velocities[cornerIndex][1];
        quad->mCorners[cornerIndex].mHalf.mY = startY + MUL_FIXED12_NO_ROUND(velocity, tableScale);
    }
    quad->mTimer = quad->mTimer - 1;
    if (quad->mTimer == -13) {
        quad->mUpdateFunction = AdvanceOrthoQuadCornersByVelocity;
    }
}

void AdvanceOrthoQuadDelayAndStartSound(OrthoQuad *quad) {
    NNSSndSeqPlayer **sndHandle;
    u32 seqNo;

    quad->mTimer = quad->mTimer - 1;
    if (quad->mTimer != 0) {
        return;
    }
    quad->mUpdateFunction = AdvanceOrthoQuadCornersByTable;
    if (GetEntryRaceEnded() != 0) {
        return;
    }
    seqNo = gOrthoQuadUseCreamEffect != 0 ? 0x157 : 0xee;
    if (seqNo == 1) {
        return;
    }
    if ((gRaceSoundKind & 1) == 0) {
        return;
    }
    sndHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
    if (gSoundModeHolder.mSeqStartEnabled == 0) {
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

void UpdateOrthoQuads(void) {
    s32 quadIndex;
    OrthoQuadModel *model;
    s32 frames;
    u16 alpha;

    if (gOrthoQuadCount == 0) {
        return;
    }
    for (quadIndex = 0; quadIndex < gOrthoQuadCount; quadIndex++) {
        OrthoQuad *quad = &gOrthoQuads[quadIndex];

        quad->mUpdateFunction(quad);
    }
    frames = gOrthoQuadFrames + 1;
    gOrthoQuadFrames = frames;
    if (frames <= gOrthoQuadHoldFrameCount) {
        return;
    }
    if (frames & 1) {
        return;
    }
    alpha = gOrthoQuadAlpha;
    gOrthoQuadAlpha = alpha - 1;
    alpha = gOrthoQuadAlpha;
    if (alpha == 0) {
        gOrthoQuadCount = 0;
        gOrthoQuadUseCreamEffect = FALSE;
        NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
        return;
    }
    model = gOrthoQuadUseCreamEffect != 0 ? &gOrthoQuadCreamEffect : &gOrthoQuadGesoSumi;
    model->mPolygonAttr = model->mPolygonAttr & ~POLYGON_ATTR_ALPHA_MASK;
    model->mPolygonAttr = model->mPolygonAttr | (alpha << POLYGON_ATTR_ALPHA_SHIFT);
}

void DrawOrthoQuadsWithModel(OrthoQuadModel *model) {
    s32 quadIndex;

    if (gOrthoQuadCount == 0) {
        return;
    }
    if (GetEntryRaceEnded() != 0) {
        return;
    }
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 8;
    reg_G3_TEXIMAGE_PARAM = model->mTeximageParam;
    reg_G3_PLTT_BASE = model->mPlttBase;
    reg_G3_DIF_AMB = model->mDifAmb;
    reg_G3_SPE_EMI = model->mSpeEmi;
    reg_G3_MTX_MODE = 0;
    G3_LoadMtx44(&gOrthoQuadMatrix);
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_SCALE = 0x64000;
    reg_G3_MTX_SCALE = 0x64000;
    reg_G3_MTX_SCALE = 0x64000;
    quadIndex = 0;
    if (gOrthoQuadCount <= 0) {
        return;
    }
    do {
        OrthoQuad *quad = &gOrthoQuads[quadIndex];

        reg_G3_POLYGON_ATTR = model->mPolygonAttr | (gOrthoQuadFirstPolygonId + quadIndex) << POLYGON_ATTR_ID_SHIFT;
        reg_G3_BEGIN_VTXS = 1;
        reg_G3_TEXCOORD = 0;
        reg_G3_VTX_16 = quad->mCorners[0].mWord;
        reg_G3_VTX_16 = 0;
        reg_G3_TEXCOORD = (u16) ((s32) (model->mTexSizeS << 8) >> 16) << 16;
        reg_G3_VTX_DIFF = quad->mCorners[1].mWord;
        reg_G3_TEXCOORD =
            (u16) ((s32) (model->mTexSizeT << 8) >> 16) | ((u16) ((s32) (model->mTexSizeS << 8) >> 16) << 16);
        reg_G3_VTX_DIFF = quad->mCorners[2].mWord;
        reg_G3_TEXCOORD = (u16) ((s32) (model->mTexSizeT << 8) >> 16);
        reg_G3_VTX_DIFF = quad->mCorners[3].mWord;
        reg_G3_END_VTXS = 0;
        quadIndex++;
    } while (quadIndex < gOrthoQuadCount);
}

void DrawOrthoQuads(void) {
    DrawOrthoQuadsWithModel(gOrthoQuadUseCreamEffect != 0 ? &gOrthoQuadCreamEffect : &gOrthoQuadGesoSumi);
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
        overlapAbove |= gOrthoQuadCells[row - 2] & (u8) (threeCellMask >> 3);
        gOrthoQuadCells[row - 2] |= (u8) (threeCellMask >> 3);
    }
    if (row > 0) {
        overlapAbove |= gOrthoQuadCells[row - 1] & (u8) (fiveCellMask >> 3);
        gOrthoQuadCells[row - 1] |= (u8) (fiveCellMask >> 3);
    }
    overlap = overlapAbove | (gOrthoQuadCells[row] & (u8) (fiveCellMask >> 3));
    gOrthoQuadCells[row] |= (u8) (fiveCellMask >> 3);
    if (row < 7) {
        overlap |= gOrthoQuadCells[row + 1] & (u8) (fiveCellMask >> 3);
        gOrthoQuadCells[row + 1] |= (u8) (fiveCellMask >> 3);
    }
    if (row < 6) {
        overlap |= gOrthoQuadCells[row + 2] & (u8) (threeCellMask >> 3);
        gOrthoQuadCells[row + 2] |= (u8) (threeCellMask >> 3);
    }
    return overlap;
}

void SetupOrthoQuad(s32 index, HalfwordPair startPair, s32 overlap) {
    RaceProgress *raceProgress;
    RandomState64 *random;
    OrthoQuad *quad;
    s16(*velocities)[2];
    s32 cornerIndex;
    s16 cosResult;
    s16 sinResult;
    s32 value;
    s16 velocityX;
    s16 velocityY;

    raceProgress = gRaceProgress;
    quad = &gOrthoQuads[index];
    random = &raceProgress->mLocalRandom;
    velocities = quad->mCornerVelocities;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    value = (s32) (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32);
    cosResult = SIN_OF_ANGLE(value);
    sinResult = COS_OF_ANGLE(value);
    if (overlap != 0) {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        value = (s16) (((u64) (u32) (random->mValue >> 32) * 0xcd) >> 32) + 0x800;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        value = 0xa66 + (s16) (((u64) (u32) (random->mValue >> 32) * 0x52) >> 32);
    }
    value = (s16) value;
    if (gOrthoQuadUseCreamEffect != 0) {
        value = (s16) MUL_FIXED12_NO_ROUND(value, 0x800);
    }
    quad->mTimer = gOrthoQuadTimersByIndex[index];
    velocities[0][0] = -value;
    velocities[0][1] = -value;
    velocities[1][0] = -value;
    velocities[1][1] = value;
    velocities[2][0] = value;
    velocities[2][1] = value;
    velocities[3][0] = value;
    velocities[3][1] = -value;
    for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
        velocityY = velocities[cornerIndex][1];
        velocityX = velocities[cornerIndex][0];
        velocities[cornerIndex][0] = (sinResult * velocityX - cosResult * velocityY) >> 12;
        velocities[cornerIndex][1] = (cosResult * velocityX + sinResult * velocityY) >> 12;
        *GetOrthoQuadCorner(quad, cornerIndex) = startPair;
    }
    quad->mStartPair = startPair;
    quad->mUpdateFunction = AdvanceOrthoQuadDelayAndStartSound;
    quad->mPickedCornerIndex = -1;
    quad->mVelocityMode = 0;
}

// Local entry only: places up to count quads at random cells; the cream effect does not restart while quads show.
void StartOrthoQuads(s32 kartIndex, s32 count, s32 useCreamEffect) {
    HalfwordPair startPair;
    s32 cellIndex;
    s32 placedCount;
    s32 cellBit;
    s32 column;
    s32 row;
    RandomState64 *random;

    random = &gRaceProgress->mLocalRandom;
    GetKart(kartIndex);
    if (kartIndex != gRaceSetup->mEntryIndex) {
        return;
    }
    gOrthoQuadKartIndex = kartIndex;
    if (gOrthoQuadCount != 0) {
        if (useCreamEffect != 0) {
            return;
        }
    }
    gOrthoQuadCount = 0;
    gOrthoQuadUseCreamEffect = FALSE;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
    gOrthoQuadUseCreamEffect = useCreamEffect;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gOrthoQuadCells[cellIndex] = 0;
    }
    cellBit = 1;
    for (cellIndex = 0, placedCount = 0; cellIndex < 0x10 && placedCount < count; cellIndex++) {
        if (gOrthoQuadUseCreamEffect != 0) {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mX = (s16) (((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32) * 2;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mY = (s16) (((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32) * 2;
        } else if (gOrthoQuadCount == 0) {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mX = ((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mX =
                startPair.mHalf.mX + (s16) (((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32);
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mY = ((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mY =
                startPair.mHalf.mY + (s16) (((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32);
        } else {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mX = ((u64) (u32) (random->mValue >> 32) * 0x2000) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mY = ((u64) (u32) (random->mValue >> 32) * 0x1800) >> 32;
        }
        column = startPair.mHalf.mX >> 10;
        row = startPair.mHalf.mY >> 10;
        if (row >= 3 || column < 3 || column > 4) {
            if ((gOrthoQuadCells[row] & (cellBit << column)) == 0) {
                s32 overlap = MarkOrthoQuadCellsAndGetOverlap(column, row);

                startPair.mHalf.mX -= 0x1000;
                startPair.mHalf.mY -= 0x600;
                SetupOrthoQuad(placedCount, startPair, overlap);
                placedCount++;
            }
        }
    }
    gOrthoQuadCount = placedCount;
    gOrthoQuadFrames = 0;
    gOrthoQuadAlpha = 0x1f;
    if (gOrthoQuadUseCreamEffect != 0) {
        gOrthoQuadHoldFrameCount = 0x96;
        gOrthoQuadMoveStartFrameCount = 0x1e;
        gOrthoQuadCreamEffect.mPolygonAttr &= ~POLYGON_ATTR_ALPHA_MASK;
        gOrthoQuadCreamEffect.mPolygonAttr |= POLYGON_ATTR_ALPHA_MASK;
    } else {
        gOrthoQuadHoldFrameCount = 0x184;
        gOrthoQuadMoveStartFrameCount = 0x2d;
        gOrthoQuadGesoSumi.mPolygonAttr &= ~POLYGON_ATTR_ALPHA_MASK;
        gOrthoQuadGesoSumi.mPolygonAttr |= POLYGON_ATTR_ALPHA_MASK;
    }
}

void StartOrthoQuadsGesoSumi(u32 kartIndex, u32 count) {
    StartOrthoQuads(kartIndex, count, 0);
}

void StopOrthoQuads(int kartIndex) {
    if (kartIndex != gRaceSetup->mEntryIndex) {
        return;
    }
    gOrthoQuadCount = 0;
    gOrthoQuadUseCreamEffect = FALSE;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
}

// Local entry only: moves the frame counter up to the hold count so the alpha starts to fall.
u32 SkipOrthoQuadsHold(u32 kartIndex) {
    s32 hold;
    s32 *frames;
    if (kartIndex != gRaceSetup->mEntryIndex) {
        return kartIndex;
    }
    if (gOrthoQuadCount == 0) {
        return gOrthoQuadCount;
    }
    hold = gOrthoQuadHoldFrameCount;
    frames = &gOrthoQuadFrames;
    if (*frames < hold) {
        *frames = hold;
    }
    return (u32) frames;
}

// Derives the corner velocities from the corner positions and switches the quad to velocity mode.
void SetOrthoQuadVelocitiesFromCorners(OrthoQuad *quad) {
    s32 cornerIndex;
    s32 cornerX;
    s32 cornerY;
    s32 pushY;
    s32 pushX;
    s32 otherCornerIndex;
    s16(*velocities)[2] = quad->mCornerVelocities;

    for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
        velocities[cornerIndex][0] = 0;
        velocities[cornerIndex][1] = 0;
    }
    for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
        cornerX = quad->mCorners[cornerIndex].mHalf.mX;
        cornerY = quad->mCorners[cornerIndex].mHalf.mY;
        if (cornerX > 0) {
            if (cornerX > 0x4cd) {
                pushX = MUL_FIXED12_NO_ROUND(cornerX, cornerX);
            } else {
                pushX = 0x171;
            }
        } else {
            if (cornerX < 0x4cd) {
                pushX = -MUL_FIXED12_NO_ROUND(cornerX, cornerX);
            } else {
                pushX = -0x171;
            }
        }
        if (cornerY > 0) {
            if (cornerY > 0x4cd) {
                pushY = MUL_FIXED12_NO_ROUND(cornerY, cornerY);
            } else {
                pushY = 0x171;
            }
        } else {
            if (cornerY < 0x4cd) {
                pushY = -MUL_FIXED12_NO_ROUND(cornerY, cornerY);
            } else {
                pushY = -0x171;
            }
        }
        for (otherCornerIndex = 0; otherCornerIndex < 4; otherCornerIndex++) {
            if (cornerIndex == otherCornerIndex) {
                velocities[otherCornerIndex][0] += MUL_FIXED12_NO_ROUND(pushX, 12);
                velocities[otherCornerIndex][1] += MUL_FIXED12_NO_ROUND(pushY, 12);
            } else {
                velocities[otherCornerIndex][0] += MUL_FIXED12_NO_ROUND(pushX, 8);
                velocities[otherCornerIndex][1] += MUL_FIXED12_NO_ROUND(pushY, 8);
            }
        }
    }
    for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
        if (velocities[cornerIndex][1] < 0) {
            velocities[cornerIndex][1] = 0;
        }
    }
    quad->mVelocityMode = 1;
}

void SkipOrthoQuadsHoldAndSetVelocities(int kartIndex) {
    OrthoQuad *quad;
    s32 quadIndex;
    s32 quadCount;
    s32 holdFrameCount;
    s32 frames;

    if (kartIndex != gRaceSetup->mEntryIndex) {
        return;
    }
    quadCount = gOrthoQuadCount;
    if (quadCount == 0) {
        return;
    }
    holdFrameCount = gOrthoQuadHoldFrameCount;
    frames = gOrthoQuadFrames;
    if (frames < holdFrameCount) {
        gOrthoQuadFrames = holdFrameCount;
    }
    quadIndex = 0;
    if (quadCount <= 0) {
        return;
    }
    do {
        quad = &gOrthoQuads[quadIndex];
        if (quad->mVelocityMode == 0 && quad->mUpdateFunction == AdvanceOrthoQuadCornersByVelocity) {
            SetOrthoQuadVelocitiesFromCorners(quad);
        }
        quadIndex++;
    } while (quadIndex < gOrthoQuadCount);
}

OrthoQuadModel *ClearOrthoQuadCreamEffectPointer(void) {
    gOrthoQuadCreamEffect.mModel = NULL;
    return &gOrthoQuadCreamEffect;
}

void CreateOrthoQuadCreamEffect(const char *fileName) {
    NsbmdModel *model;

    CreateNsbmdModel(&model, FindCourseMapObjFile(fileName), 0, 0);
    SetNsbmdModelFixedAttributes(model);
    SetupOrthoQuadModel(&gOrthoQuadCreamEffect, model);
}

void StartOrthoQuadsCreamEffect(u32 kartIndex, u32 count) {
    StartOrthoQuads(kartIndex, count, 1);
}

#pragma thumb on
void InitOrthoQuads(void) {
    NsbmdModel *model;
    s32 index;

    gOrthoQuads = HeapAlloc(GetHeap(GetCurrentHeapCall()), 4 * sizeof(OrthoQuad));
    gOrthoQuadKartIndex = 0xffff;
    gOrthoQuadCount = 0;
    gOrthoQuadUseCreamEffect = FALSE;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
    model = CreateItemModel(gGesoSumiModelNsbmdName, NULL, gGesoSumiTextureNsbmdName);
    SetupOrthoQuadModel(&gOrthoQuadGesoSumi, model);
    gOrthoQuadFirstPolygonId = AllocPolygonId();
    for (index = 0; index < 3; index++) {
        AllocPolygonId();
    }
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_PUSH = 0;
    G3i_OrthoW_(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x1fb, 1, &gOrthoQuadMatrix);
    reg_G3_MTX_POP = 1;
}

void SetupOrthoQuadModel(OrthoQuadModel *quadModel, NsbmdModel *model) {
    u32 teximageParam;

    quadModel->mModel = model;
    quadModel->mPolygonAttr = 0x51f80c0;
    quadModel->mPolygonAttr = quadModel->mPolygonAttr & ~POLYGON_ATTR_ID_MASK;
    quadModel->mTeximageParam = *model->mTexImageParams;
    quadModel->mPlttBase = *model->mTexPlttBases;
    quadModel->mDifAmb = model->mDiffAmb;
    quadModel->mSpeEmi = model->mSpecEmi;
    teximageParam = quadModel->mTeximageParam;
    quadModel->mTexSizeT = 1 << (((teximageParam & 0x3800000) >> 0x17) + 0xf);
    quadModel->mTexSizeS = 1 << (((teximageParam & 0x700000) >> 0x14) + 0xf);
}
#pragma thumb off

void SetupItemGessoKarts(ItemGesso *gesso) {
    s32 kartCount;
    s32 entryIndex;
    s32 ownerIndex;
    s32 candidateIndex;
    RaceProgress *raceProgress;
    RandomState64 *random;
    Kart *kart;
    u16 rank;
    u32 ownerRank;
    u16 kartIndex;

    ownerIndex = (u16) ((gesso->mItemObject.mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER) == 0
                            ? (u16) (gesso->mItemObject.mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)
                            : ITEM_NO_KART_INDEX);
    entryIndex = gRaceSetup->mEntryIndex;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        kartCount = gRaceSetup->mKartCount;
        for (candidateIndex = 0; candidateIndex < kartCount; candidateIndex++) {
            if (candidateIndex == ownerIndex) {
                continue;
            }
            kart = GetKart(candidateIndex);
            if (kart->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) {
                continue;
            }
            if (kart->mEffectFlags & (KART_EFFECT_STAR | KART_EFFECT_RESPAWN_DROP | KART_EFFECT_KILLER)) {
                continue;
            }
            if (kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) {
                continue;
            }
            raceProgress = gRaceProgress;
            random = &raceProgress->mLocalRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            gesso->mOrthoQuadCounts[candidateIndex] =
                (u16) (((random->mValue >> 32) * ITEM_GESSO_MAX_QUADS_PER_KART) >> 32) + 1;
        }
    } else {
        rank = 1;
        ownerRank = GetKartRank(ownerIndex);
        do {
            kartIndex = GetKartAtRank(rank);
            kart = GetKart(kartIndex);
            if ((kart->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) == 0 &&
                (kart->mEffectFlags & (KART_EFFECT_STAR | KART_EFFECT_RESPAWN_DROP | KART_EFFECT_KILLER)) == 0 &&
                (kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) == 0) {
                gesso->mOrthoQuadCounts[kartIndex] = ITEM_GESSO_MAX_QUADS_PER_KART - ((rank - 1) >> 1);
            }
            rank++;
        } while (rank < ownerRank);
    }
    if (entryIndex < 0 || gesso->mOrthoQuadCounts[entryIndex] == 0) {
        gesso->mVisible = FALSE;
        return;
    }
    gesso->mVisible = TRUE;
    gesso->mKart = GetKart(entryIndex);
    StartEntryKartSound(gesso->mKart, 0xf3);
}
