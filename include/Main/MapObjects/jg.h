#pragma once

#include "types.h"

typedef struct ModelAnimation ModelAnimation;

void E7Fn2_13(void *stateObject);
void E7Fn2_12(void *stateObject);
void E7Fn2_11(void *stateObject);
void E7Fn2_10(void *stateObject);
void E7Fn2_9(void *stateObject);
void E7Fn2_8(void *stateObject);
void E7Fn2_7(void *stateObject);
void E7Fn2_6(void *stateObject);
void E7Fn2_5(void *stateObject);
void E7Fn2_4(void *stateObject);
void E7Fn2_3(void *stateObject);
void E7Fn2_2(void *stateObject);
void E7Fn2_1(void *stateObject);
void UpdateJgPosition(void);
void ComputeJgMatrixAndInverse(void);
void DrawJg(void);
void UpdateJg(void);
void AdvanceJgPointsAndSetTarget(Vec3 *offset, const Vec3 *endScale, const Vec3 *startScale);
void InitJgOffsets(void);
void CreateModelAnimation(u32 animationKind, void *model, ModelAnimation **animationSlot, void *nsbmdFile,
                          void *animationFile);

void E7Fn2_0(void *stateObject);

extern const Vec3 gJgVelocityDamping;
extern const Vec3 gJgVelocityFactors;
extern const Vec3 gJgModelOffset;
extern const Vec3 gJgFlagBaseOffset;
extern const Vec3 gJgFlagEndScale;
extern const Vec3 gJgFlagStartScale;
extern const Vec3 gJgLapBaseOffsetRaceEnded;
extern const Vec3 gJgReverseEndScale;
extern const Vec3 gJgReverseStartScale;
extern const Vec3 gJgLapBaseOffsetNotEnded;
extern const Vec3 gJgNoModelBaseOffset;
extern const Vec3 gJgReverseBaseOffset;
extern const Vec3 gJgSourcePoints[7];
