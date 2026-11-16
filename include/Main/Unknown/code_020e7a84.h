#pragma once

#include "types.h"

typedef struct Unk020e6514 Unk020e6514;

// A row of gJgKindRows seen at offset 4 or 8: its first word points at an animation object.
typedef struct JgKindRowAnimationView {
    /* 00 */ Unk020e6514 *field0;
    /* 04 */ u8 field4[0x0c];
} JgKindRowAnimationView;

// Object at 0x00 of a gJgKindRows row, as jg_render reads it: the word at 0x04.
typedef struct Unk020e9810 {
    /* 00 */ u8 field0[4];
    /* 04 */ void *field4;
} Unk020e9810;

extern JgKindRowAnimationView gJgKindRowNsbcaAnimations[];
extern JgKindRowAnimationView gJgKindRowNsbmaAnimations[];

void jg_state6Update(void);
void jg_state6Init(void);
void jg_state5Update(void);
void jg_state5Init(void);
void jg_respawningStateUpdate(void);
void jg_respawningStateInit(void);
void jg_state3Update(void);
void jg_state3Init(void);
void jg_state2Update(void);
void jg_state2Init(void);
void jg_state1Update(void);
void jg_state1Init(void);
unsigned int jg_idleStateUpdate(unsigned int value);
void UpdateJgPosition(void);
void ComputeJgMatrixAndInverse(void);
void jg_render(void);
void jg_update(void);
void AdvanceJgPointsAndSetTarget(Vec3 *offset, const Vec3 *endScale, const Vec3 *startScale);
void InitJgOffsets(void);
void CreateModelAnimation(u32 animationKind, void *model, void **animationSlot, void *nsbmdFile, void *animationFile);
