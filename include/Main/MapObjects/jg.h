#pragma once

#include "types.h"

typedef struct ModelAnimation ModelAnimation;

void UpdateJgArrive(void *stateObject);
void EnterJgArrive(void *stateObject);
void UpdateJgLeave(void *stateObject);
void EnterJgLeave(void *stateObject);
void UpdateJgFollowKart(void *stateObject);
void EnterJgFollowKart(void *stateObject);
void UpdateJgFlag(void *stateObject);
void EnterJgFlag(void *stateObject);
void UpdateJgLap(void *stateObject);
void EnterJgLap(void *stateObject);
void UpdateJgReverse(void *stateObject);
void EnterJgReverse(void *stateObject);
void JgOffNop(void *stateObject);
void UpdateJgPosition(void);
void ComputeJgMatrixAndInverse(void);
void DrawJg(void);
void UpdateJg(void);
void AdvanceJgPointsAndSetTarget(Vec3 *offset, const Vec3 *endScale, const Vec3 *startScale);
void InitJgOffsets(void);
void CreateModelAnimation(u32 animationKind, void *model, ModelAnimation **animationSlot, void *nsbmdFile,
                          void *animationFile);

void EnterJgOff(void *stateObject);

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
