#include "Main/Race/race_m_number_pair.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/race_m_ncer_entry.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "cell_animation.h"
#include "Main/Graphics/font_and_player_character.h"

RaceMNumberPair *gRaceMNumberPair;

void DrawRaceMNumberPair(RaceHudOamBuffer *oamBuffer) {
    s32 startFrames;

    startFrames = GetRaceStartCountdown();
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE || g_GlobalCO->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (startFrames >= 0xb4) {
        return;
    }
    if (g_GlobalCO->mMode != MODE_WIFI &&
        (g_GlobalCO->mMode != MODE_VS || g_GlobalCO->mRuleKind != RULE_KIND_RACE_COUNT)) {
        return;
    }
    SetRaceMNumberPairAnimation(oamBuffer, startFrames);
    if (gRaceMNumberPair->mScale == 0) {
        return;
    }
    if (gRaceMNumberPair->mCourseCount >= 10) {
        DrawRaceMNumberPairTwoDigit(oamBuffer);
        return;
    }
    DrawRaceMNumberPairOneDigit(oamBuffer);
}

void SetRaceMNumberPairAnimation(RaceHudOamBuffer *oamBuffer, s32 startFrames) {
    s32 scaleTable[20] = {0,    205,  410,  614,  819,  1638, 2253, 2867, 3891, 4506,
                          4710, 4915, 5120, 5325, 5325, 5120, 4915, 4710, 4506, 4096};
    s32 scale;
    GXOamAttr *matrixOams;

    if (startFrames < 0) {
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mCellMatrix = NULL;
        gRaceMNumberPair->mScale = 0;
        gRaceMNumberPair->mMatrixIndex = 0;
        return;
    }
    if (startFrames < 0x14) {
        MtxFx22 *matrix;

        scale = scaleTable[startFrames];
        Matrix2x2ReciprocalScale(&gRaceMNumberPair->mScaleMatrix, scale);
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mCellMatrix = &gRaceMNumberPair->mScaleMatrix;
        gRaceMNumberPair->mScale = scale;
        gRaceMNumberPair->mMatrixIndex = AllocOamMatrixIndex(oamBuffer);
        matrix = gRaceMNumberPair->mCellMatrix;
        matrixOams = &oamBuffer->mOams[gRaceMNumberPair->mMatrixIndex * 4];
        matrixOams[0].mAttrs[3] = matrix->mElements[0] >> 4;
        matrixOams[1].mAttrs[3] = matrix->mElements[1] >> 4;
        matrixOams[2].mAttrs[3] = matrix->mElements[2] >> 4;
        matrixOams[3].mAttrs[3] = matrix->mElements[3] >> 4;
        gRaceMNumberPair->mCellMatrix->mElements[3] = gRaceMNumberPair->mScale;
        gRaceMNumberPair->mCellMatrix->mElements[0] = gRaceMNumberPair->mCellMatrix->mElements[3];
        gRaceMNumberPair->mCellMatrix->mElements[2] = 0;
        gRaceMNumberPair->mCellMatrix->mElements[1] = gRaceMNumberPair->mCellMatrix->mElements[2];
        return;
    }
    if (startFrames < 0x78) {
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mCellMatrix = NULL;
        gRaceMNumberPair->mScale = TO_FIXED12(1);
        gRaceMNumberPair->mMatrixIndex = 0;
        return;
    }
    gRaceMNumberPair->mOffsetX = ComputeValueInterpolation_from_thumb(1, 0, 0x80, startFrames - 0x78, 0x14);
    gRaceMNumberPair->mCellMatrix = NULL;
    gRaceMNumberPair->mScale = TO_FIXED12(1);
    gRaceMNumberPair->mMatrixIndex = 0;
}

void DrawRaceMNumberPairTwoDigit(RaceHudOamBuffer *oamBuffer) {
    s32 spriteX[5] = {175, 190, 203, 216, 231};
    NNSG2dCellDataWithBR *cell;
    MtxFx22 *matrix = NULL;
    u16 matrixIndex;
    s32 position0[2];
    s32 position1[2];
    s32 position2[2];
    s32 position3[2];
    s32 position4[2];

    if (gRaceMNumberPair->mCourseNumber / 10 != 0) {
        matrixIndex = gRaceMNumberPair->mMatrixIndex;
        matrix = gRaceMNumberPair->mCellMatrix;
        cell = GetB3C4_Cell_RaceM(gRaceMNumberPair->mCourseNumber / 10 + 0x2d);
        position0[0] = TO_FIXED12(spriteX[0] + gRaceMNumberPair->mOffsetX);
        position0[1] = 0xb1000;
        oamBuffer->mOamCount +=
            MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  position0, matrixIndex, 1);
    }
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetB3C4_Cell_RaceM(gRaceMNumberPair->mCourseNumber % 10 + 0x2d);
    position1[0] = TO_FIXED12(spriteX[1] + gRaceMNumberPair->mOffsetX);
    position1[1] = 0xb1000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position1, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetB3C4_Cell_RaceM(0x37);
    position2[0] = TO_FIXED12(spriteX[2] + gRaceMNumberPair->mOffsetX);
    position2[1] = 0xb1000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position2, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetB3C4_Cell_RaceM(gRaceMNumberPair->mCourseCount / 10 + 0x2d);
    position3[0] = TO_FIXED12(spriteX[3] + gRaceMNumberPair->mOffsetX);
    position3[1] = 0xb1000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position3, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetB3C4_Cell_RaceM(gRaceMNumberPair->mCourseCount % 10 + 0x2d);
    position4[0] = TO_FIXED12(spriteX[4] + gRaceMNumberPair->mOffsetX);
    position4[1] = 0xb1000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position4, matrixIndex, 1);
}

void DrawRaceMNumberPairOneDigit(RaceHudOamBuffer *oamBuffer) {
    s32 spriteX[3] = {205, 218, 231};
    NNSG2dCellDataWithBR *cell;
    MtxFx22 *matrix;
    u16 matrixIndex;
    s32 position0[2];
    s32 position1[2];
    s32 position2[2];

    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetB3C4_Cell_RaceM(gRaceMNumberPair->mCourseNumber + 0x2d);
    position0[0] = TO_FIXED12(spriteX[0] + gRaceMNumberPair->mOffsetX);
    position0[1] = 0xb1000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position0, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetB3C4_Cell_RaceM(0x37);
    position1[0] = TO_FIXED12(spriteX[1] + gRaceMNumberPair->mOffsetX);
    position1[1] = 0xb1000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position1, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetB3C4_Cell_RaceM(gRaceMNumberPair->mCourseCount + 0x2d);
    position2[0] = TO_FIXED12(spriteX[2] + gRaceMNumberPair->mOffsetX);
    position2[1] = 0xb1000;
    oamBuffer->mOamCount += MaybeMakeOamSlot(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position2, matrixIndex, 1);
}
