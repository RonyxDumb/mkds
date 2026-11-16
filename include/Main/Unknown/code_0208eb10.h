#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"

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

// Declared here until the code that defines them is decompiled.

#include "code_02012b30.h" // MtxFx43

typedef struct KartAiItemUse KartAiItemUse;

struct KartAi;

void trl_killTrail(PosStrip *strip);
PosStrip *trl_createTrailForDriver(s32 kartIndex);
PosStrip *trl_createTrail(const Vec3 *followedPos);
void trl_initPointForDriver(PosStripPoint *posStripPoint, PosStrip *posStrip);
void trl_initPoint(PosStripPoint *stripPoint, PosStrip *strip);
void trl_render(const MtxFx43 *matrix);
void trl_update(void);
void trl_init(void *heap);
void UseItemBehindAfterInUseOrNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208f434(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208f4e8(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208f5c4(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemByTrailKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208f6d4(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208f754(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208f810(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208f8ac(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208f9ac(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208fa50(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208fafc(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208fba0(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemAtNearTarget(KartAiItemUse *itemUse, struct KartAi *kartAi);
void ThrowItemByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
unsigned int func_0208fd88(unsigned int value);
