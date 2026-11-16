#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;
typedef struct Camera Camera;

// Declared here until the code that defines them is decompiled.

#include "code_02012b30.h" // MtxFx43

extern u16 race_sDarkeningFogDensity;
extern s16 race_sToonTableUpdateInterval;
extern Vec3 data_021653f0;

u32 ghdat_getGhostCourse(void *ghostRecord);
s32 ghdat_getGhostKart(void *ghostRecord);
s32 ghdat_getGhostCharacter(void *ghostRecord);
BOOL ghdat_getGhostNickName(void *ghostRecord, void *name);
BOOL ghdat_getGhostTime(void *ghostRecord, TimeRecord *timeRecord);
BOOL ghdat_getIsGhostValid(void *ghostRecord);
u16 race_getLastParticlePolygonId(void);
s32 race_getFirstObjectPolygonId(void);
// Returns TRUE and writes the number of update frames since race_20617D8 to a, or returns FALSE when
// that has not run yet.
s32 race_20617A8(u32 *framesOut);
// Stores the current mUpdateFrames in Race.mUpdateFramesAtEntryEnd; called when the end handler of the kart of the
// selected entry first runs.
u32 race_20617D8(void);
u32 race_setField34(void);
Camera *race_getCamera(void);
unsigned int race_getCameraField250(void);
MtxFx43 *race_getCameraMtx(void);
unsigned int race_getIsDarkeningActive(void);
void race_forceDarkeningFade(void);
void race_resetDarkeningFadeWaitCounter(void);
void race_startDarkening(void);
void race_updateDarkeningFog(s32 fadeLevel, s32 b);
void race_setupFog(void);
// Returns Race.mUpdateFramesMod2; changes nothing.
unsigned int race_getIsOddFrame(void);
// Returns Race.mUpdateFramesMod8; changes nothing.
unsigned int race_getFrameCounterModulo8(void);
// Returns Race.mUpdateFramesModKartCount; changes nothing.
unsigned int race_getFrameCounterModuloDriverCount(void);
unsigned int race_getFrameCounter(void);
// Sets Race.mStarted to 1 and starts the race clock (rstat_startTime); called once per race by UpdateRaceStartSequence
// when its mSequenceFrames is 180.
void race_start(void);
// Returns Race.mStarted (1 once the race has started); changes nothing.
unsigned int race_getState(void);
void race_vblank(void);
void race_finalize(void);
void race_renderRace(void);
// Sets the direction of light 0 that race_renderRace gives to the 3D engine (Race.mLightVectorX, Y and Z) from a.
void race_setLight0Direction(const Vec3 *lightVector);
void race_render(void);
void race_update(void);
void race_initG3d(void);
void race_initResManagement(void);
void race_initState(void);
void race_init(void);
unsigned int race_isAwardStaffRoll(void);
// Returns Race.mUseChainCameras: 1 for the kinds 3 to 5 of RaceSetup.fieldC, which other code also uses to tell
// those kinds apart; changes nothing.
unsigned int race_isCamAnimMode(void);
