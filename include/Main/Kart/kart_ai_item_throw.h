#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"

// One point of a strip: its height, the frames since it was added and its position (the position shifted right by 4).
typedef struct PosStripPoint {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mHeight;
    /* 0c */ u16 mSinceAddedFrames;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ Vec3 mPos;
} PosStripPoint;

// A strip: a list of points that follows a position; the draw joins neighbouring points with quads.
typedef struct PosStrip {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ NNSFndList mPoints;
    /* 14 */ const Vec3 *mFollowedPos;
    /* 18 */ u32 mStopped;
    /* 1c */ u32 mHeight;
    /* 20 */ s32 mKartIndex;
    /* 24 */ s32 mOffsetX;
    /* 28 */ s32 mOffsetY;
    /* 2c */ s32 mOffsetZ;
} PosStrip;

typedef struct PosStripPoint PosStripPoint;
typedef struct PosStrip PosStrip;

#include "code_02012b30.h" // MtxFx43
#include "Main/MapObjects/data_02166000.h"

typedef struct KartAiItemUse KartAiItemUse;

struct KartAi;

void StopPosStrip(PosStrip *strip);
PosStrip *StartAwardKartPosStrip(s32 kartIndex);
PosStrip *StartPosStrip(const Vec3 *followedPos);
void SetPosStripPointFromKart(PosStripPoint *posStripPoint, PosStrip *posStrip);
void SetPosStripPointFromPos(PosStripPoint *stripPoint, PosStrip *strip);
void DrawPosStrips(const MtxFx43 *matrix);
void UpdatePosStrips(void);
void InitPosStrips(void *heap);
void UseItemBehindAfterInUseOrNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemBehindNearTargetAfterInUseEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemRandomAfterInUseOrBehindNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemAtNearTargetAheadDotAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemByTrailKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterInUseAtNearTargetAhead(KartAiItemUse *itemUse, struct KartAi *kartAi);
void HardUseItemAfterInUseAtNearTargetAhead(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void NormalUseItemAfterInUseAtNearTargetAheadDot(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterInUseAtNearTargetAheadDot(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemRandomAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemAtNearTargetAfterInUseEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi);
void EasyThrowItemRandomAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemRandomAfterInUseOrAtNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemAtNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
void BattleItemInUseNop(KartAiItemUse *itemUse, struct KartAi *kartAi);

void SetItemBitsEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi);

void HardSetItemBitsEveryCall(KartAiItemUse *itemUse, struct KartAi *kartAi);

extern u8 gPosStripFirstPolygonId;
extern u8 gPosStripAlphaDecreasePerFrame;
extern u16 gPosStripMaxAgeFrames;
extern u16 gPosStripPointsPerStrip;
extern s32 gPosStripDrawEnabled;
extern s32 gPosStripHeightDecreasePerFrame;
extern PosStripTexture gPosStripTexture;
extern s32 gAwardStripCharacterYOffsets[13][2];
extern s32 gAwardStripKartYOffsets[37];

extern s32 (*gSetPosStripPointFunction)();
extern struct PosStrips *gPosStrips;
