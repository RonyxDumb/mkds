#pragma once

#include "types.h"

typedef struct ModelAnimation ModelAnimation;

void UpdateJgState6(void *stateObject);
void EnterJgState6(void *stateObject);
void UpdateJgState5(void *stateObject);
void EnterJgState5(void *stateObject);
void UpdateJgState4(void *stateObject);
void EnterJgState4(void *stateObject);
void UpdateJgState3(void *stateObject);
void EnterJgState3(void *stateObject);
void UpdateJgState2(void *stateObject);
void EnterJgState2(void *stateObject);
void UpdateJgState1(void *stateObject);
void EnterJgState1(void *stateObject);
void JgState0Nop(void *stateObject);
void UpdateJgPosition(void);
void ComputeJgMatrixAndInverse(void);
void DrawJg(void);
void UpdateJg(void);
void AdvanceJgPointsAndSetTarget(Vec3 *offset, const Vec3 *endScale, const Vec3 *startScale);
void InitJgOffsets(void);
void CreateModelAnimation(u32 animationKind, void *model, ModelAnimation **animationSlot, void *nsbmdFile,
                          void *animationFile);

s32 *EnterJgState0(void);

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
