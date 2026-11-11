#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_02062ed8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_020b6000.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_020e3b08.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200eddc.h"
#include "code_0214b338.h"

// Object not known yet; it only sets the order of the tables below
u8 data_020cfca4_pad[24];

void CopyRaceHudSubScreenBgColors(void) {
    s32 rowIndex;
    s32 columnIndex;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_NOKO_SFC:
            for (rowIndex = 0; rowIndex < 9; rowIndex++) {
                for (columnIndex = 0; columnIndex < 3; columnIndex++) {
                    gRaceHudSubScreenBgColors->mColors.mFrameColors[rowIndex][columnIndex] =
                        ((u16 *) 0x05000400)[rowIndex * 16 + columnIndex + 0x40];
                }
            }
            break;
        case COURSE_ID_CLOCK: {
            s32 rowOffsets[5] = {0, 5, 10, 16, 21};

            for (rowIndex = 0; rowIndex < 5; rowIndex++) {
                for (columnIndex = 0; columnIndex < 4; columnIndex++) {
                    gRaceHudSubScreenBgColors->mColors.mGearColors[rowIndex][columnIndex] =
                        ((u16 *) 0x05000400)[rowOffsets[rowIndex] + columnIndex + 0x80];
                }
            }
            break;
        }
        case COURSE_ID_TOWN:
            for (rowIndex = 0; rowIndex < 20; rowIndex++) {
                gRaceHudSubScreenBgColors->mColors.mUnk_00[rowIndex] = ((u16 *) 0x05000400)[0x78 + rowIndex];
            }
            gRaceHudSubScreenBgColors->mColors.mUnk_00[20] = ((u16 *) 0x05000400)[0];
            break;
        case COURSE_ID_BEACH:
            for (rowIndex = 0; rowIndex < 3; rowIndex++) {
                gRaceHudSubScreenBgColors->mColors.mUnk_00[rowIndex] = ((u16 *) 0x05000400)[0x46 + rowIndex];
            }
            break;
        case COURSE_ID_KOOPA:
            for (rowIndex = 0; rowIndex < 6; rowIndex++) {
                gRaceHudSubScreenBgColors->mColors.mKoopaColors.mSecondObjectColors[rowIndex] =
                    ((u16 *) 0x05000400)[0x54 + rowIndex];
            }
            for (rowIndex = 0; rowIndex < 2; rowIndex++) {
                for (columnIndex = 0; columnIndex < 3; columnIndex++) {
                    gRaceHudSubScreenBgColors->mColors.mKoopaColors.mFirstObjectColors[rowIndex][columnIndex] =
                        ((u16 *) 0x05000400)[rowIndex * 3 + columnIndex + 0x5a];
                }
            }
            for (rowIndex = 0; rowIndex < 2; rowIndex++) {
                gRaceHudSubScreenBgColors->mColors.mKoopaColors.mKoopaBlockColors[rowIndex] =
                    ((u16 *) 0x05000400)[rowIndex];
            }
            break;
        case COURSE_ID_MINI_STAGE3:
            for (rowIndex = 0; rowIndex < 5; rowIndex++) {
                gRaceHudSubScreenBgColors->mColors.mUnk_00[rowIndex] = ((u16 *) 0x05000400)[0xfb + rowIndex];
            }
            break;
    }
    gRaceHudSubScreenBgColors->mUnk_00 = 0;
}

void UpdateRaceHudSubScreenBgPalette(u16 *palette) {
    s32 rowIndex;
    s32 colorIndex;
    s32 shift;
    s32 limit;
    s32 offset;
    s32 value;
    u32 waterAngle;
    float threshold;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_NOKO_SFC:
            value = GetCourseModelNsbtpFrame();
            for (rowIndex = 0; rowIndex < 3; rowIndex++) {
                palette[rowIndex + 0x40] = gRaceHudSubScreenBgColors->mColors.mFrameColors[value / 10][rowIndex];
            }
            DC_FlushRange(&palette[0x40], 6);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x40], 0x4080, 6);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x40], 0x6080, 6);
            }
            GXS_EndLoadBGExtPltt();
            break;
        case COURSE_ID_CLOCK: {
            s32 rowOffsets[5] = {0, 5, 10, 16, 21};
            MapObject **objects;
            void *kindDrawList;
            u16 angle;

            kindDrawList = FindMapObjectKindDrawList0(MAP_OBJECT_KIND_ROTARY_GEAR);
            if (kindDrawList != NULL) {
                objects = RaceHudSubScreenGetMapObjects(kindDrawList);
                for (rowIndex = 0; rowIndex < 5; rowIndex++) {
                    angle = objects[rowIndex]->mAngle;
                    if (rowIndex == 4) {
                        shift = (angle * 0xb4) >> 16;
                    } else {
                        shift = (angle * 0x48) >> 16;
                    }
                    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
                        palette[rowOffsets[rowIndex] + colorIndex + 0x80] =
                            gRaceHudSubScreenBgColors->mColors.mGearColors[rowIndex][(colorIndex + shift) % 4];
                    }
                }
            }
            DC_FlushRange(&palette[0x80], 0x34);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x80], 0x4100, 0x34);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x80], 0x6100, 0x34);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case COURSE_ID_TOWN: {
            u8 colorIndexRows[6][20] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                                        {20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                                        {20, 20, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                                        {20, 20, 20, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                                        {20, 20, 20, 20, 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                                        {20, 20, 20, 20, 20, 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17}};
            u8 *colorIndexCursor;

            value = GetFirstBridgeAnimationFrame();
            if (value < 0x13) {
                colorIndex = 0;
            } else if (value < 0x2c) {
                colorIndex = 1;
            } else if (value < 0x38) {
                colorIndex = 2;
            } else if (value < 0x43) {
                colorIndex = 3;
            } else if (value < 0x4c) {
                colorIndex = 4;
            } else {
                colorIndex = 5;
            }
            colorIndexCursor = colorIndexRows[colorIndex];
            for (rowIndex = 0; rowIndex < 20; rowIndex++) {
                palette[rowIndex + 0x78] = gRaceHudSubScreenBgColors->mColors.mUnk_00[*colorIndexCursor];
                colorIndexCursor++;
            }
            DC_FlushRange(&palette[0x78], 0x28);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x78], 0x40f0, 0x28);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x78], 0x60f0, 0x28);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case COURSE_ID_BEACH:
            if (IsWaterPresent() != FALSE) {
                limit = GetWaterHeightFactor();
                for (offset = 7; offset > 0; offset--) {
                    threshold = (7 - offset) * 0.286f + -0.858f;
                    value = threshold > 0.0f ? threshold * 4096.0f + 0.5f : threshold * 4096.0f - 0.5f;
                    if (limit < value) {
                        break;
                    }
                }
                for (colorIndex = 0; colorIndex < offset; colorIndex++) {
                    palette[colorIndex + 0x50] = gRaceHudSubScreenBgColors->mColors.mUnk_00[0];
                }
                for (colorIndex = offset; colorIndex == offset; colorIndex++) {
                    palette[colorIndex + 0x50] = gRaceHudSubScreenBgColors->mColors.mUnk_00[1];
                }
                for (colorIndex = offset + 1; colorIndex < 8; colorIndex++) {
                    palette[colorIndex + 0x50] = gRaceHudSubScreenBgColors->mColors.mUnk_00[2];
                }
            }
            DC_FlushRange(&palette[0x50], 0x10);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x50], 0x40a0, 0x10);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x50], 0x60a0, 0x10);
            }
            GXS_EndLoadBGExtPltt();
            break;
        case COURSE_ID_KOOPA: {
            void *kindDrawList;
            MapObject **objects;
            KoopaBlock **blocks;

            kindDrawList = FindMapObjectKindDrawList0(0xd0);
            if (kindDrawList != NULL) {
                objects = RaceHudSubScreenGetMapObjects(kindDrawList);
                value = (objects[1]->mAngle * 0x48) >> 16;
                for (rowIndex = 0; rowIndex < 6; rowIndex++) {
                    palette[rowIndex + 0x54] = gRaceHudSubScreenBgColors->mColors.mKoopaColors
                                                   .mSecondObjectColors[(rowIndex + 0x48 - value) % 6];
                }
                offset = (objects[0]->mAngle << 5) >> 16;
                for (rowIndex = 0; rowIndex < 2; rowIndex++) {
                    for (colorIndex = 0; colorIndex < 3; colorIndex++) {
                        palette[colorIndex + rowIndex * 3 + 0x5a] =
                            gRaceHudSubScreenBgColors->mColors.mKoopaColors
                                .mFirstObjectColors[rowIndex][(colorIndex + 0x20 - offset) % 3];
                    }
                }
            }
            kindDrawList = FindMapObjectKindDrawList0(MAP_OBJECT_KIND_KOOPA_BLOCK);
            if (kindDrawList != NULL) {
                blocks = RaceHudSubScreenGetMapObjects(kindDrawList);
                for (rowIndex = 0; rowIndex < 4; rowIndex++) {
                    value = GetKoopaBlockProgress(blocks[rowIndex]);
                    if (rowIndex % 2 != 0) {
                        limit = (value << 3) >> 12;
                    } else {
                        limit = 8 - ((value << 3) >> 12);
                    }
                    for (colorIndex = 0; colorIndex < limit; colorIndex++) {
                        palette[rowIndex * 16 + colorIndex + 0x60] =
                            gRaceHudSubScreenBgColors->mColors.mKoopaColors.mKoopaBlockColors[0];
                    }
                    for (colorIndex = limit; colorIndex < limit + 8; colorIndex++) {
                        palette[rowIndex * 16 + colorIndex + 0x60] =
                            gRaceHudSubScreenBgColors->mColors.mKoopaColors.mKoopaBlockColors[1];
                    }
                    for (colorIndex = limit + 8; colorIndex < 16; colorIndex++) {
                        palette[rowIndex * 16 + colorIndex + 0x60] =
                            gRaceHudSubScreenBgColors->mColors.mKoopaColors.mKoopaBlockColors[0];
                    }
                }
            }
            DC_FlushRange(&palette[0x54], 0x98);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0x54], 0x40a8, 0x98);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0x54], 0x60a8, 0x98);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case COURSE_ID_MINI_STAGE3:
            if (IsWaterPresent() != FALSE) {
                limit = GetWaterHeightFactor();
                waterAngle = GetWaterHeightAngle();
                for (offset = 0; offset < 0x13; offset++) {
                    threshold = offset * 0.105f + -0.945f;
                    value = threshold > 0.0f ? threshold * 4096.0f + 0.5f : threshold * 4096.0f - 0.5f;
                    if (limit < value) {
                        break;
                    }
                }
                offset += 2;
                for (colorIndex = 0; colorIndex < offset - 2; colorIndex++) {
                    palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mUnk_00[0];
                }
                for (colorIndex = offset - 4; colorIndex < offset - 2; colorIndex++) {
                    if (colorIndex >= 0) {
                        palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mUnk_00[1];
                    }
                }
                for (colorIndex = offset - 2; colorIndex <= offset; colorIndex++) {
                    palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mUnk_00[2];
                }
                if (waterAngle >= 0x4000 && waterAngle < 0xc000) {
                    for (colorIndex = offset + 1; colorIndex <= offset + 2 && colorIndex < 0x15; colorIndex++) {
                        palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mUnk_00[3];
                    }
                    offset += 2;
                }
                for (colorIndex = offset + 1; colorIndex < 0x15; colorIndex++) {
                    palette[colorIndex + 0xe0] = gRaceHudSubScreenBgColors->mColors.mUnk_00[4];
                }
            }
            DC_FlushRange(&palette[0xe0], 0x2c);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette[0xe0], 0x41c0, 0x2c);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette[0xe0], 0x61c0, 0x2c);
            }
            GXS_EndLoadBGExtPltt();
            break;
    }
}

s32 CreateRaceHudSubScreenBombKouraWCells(void) {
    s32 itemCount;

    itemCount = 0;
    itemCount += gItemKinds[5].mObjectCount;
    itemCount += gItemKinds[9].mObjectCount;
    return CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenBombKouraWCells, itemCount);
}
