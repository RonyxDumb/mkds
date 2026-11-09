#pragma once

#include "types.h"

typedef struct ModelAnimation ModelAnimation;

void UpdateJgState6(void);
void EnterJgState6(void);
void UpdateJgState5(void);
void EnterJgState5(void);
void UpdateJgState4(void);
void EnterJgState4(void);
void UpdateJgState3(void);
void EnterJgState3(void);
void UpdateJgState2(void);
void EnterJgState2(void);
void UpdateJgState1(void);
void EnterJgState1(void);
unsigned int JgState0ReturnArgument(unsigned int value);
void UpdateJgPosition(void);
void ComputeJgMatrixAndInverse(void);
void DrawJg(void);
void UpdateJg(void);
void AdvanceJgPointsAndSetTarget(Vec3 *offset, const Vec3 *endScale, const Vec3 *startScale);
void InitJgOffsets(void);
void CreateModelAnimation(u32 animationKind, void *model, ModelAnimation **animationSlot, void *nsbmdFile,
                          void *animationFile);
