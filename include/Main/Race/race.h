#pragma once

#include "types.h"

typedef struct GhostRecordHead GhostRecordHead;
typedef struct TimeRecord TimeRecord;
typedef struct Camera Camera;
typedef struct Race Race;


#include "code_02012b30.h" // MtxFx43


u32 GetGhostRecordCourseId(GhostRecordHead *ghostRecord);
s32 GetGhostRecordKartIndex(GhostRecordHead *ghostRecord);
s32 GetGhostRecordCharacterIndex(GhostRecordHead *ghostRecord);
BOOL GetGhostRecordName(GhostRecordHead *ghostRecord, void *name);
BOOL GetGhostRecordTime(GhostRecordHead *ghostRecord, TimeRecord *timeRecord);
BOOL IsGhostRecordFilled(GhostRecordHead *ghostRecord);
u16 GetSplMaxPolyId(void);
s32 GetMapObjectFirstPolygonId(void);
// Returns TRUE and writes the number of update frames since SetRaceUpdateFramesAtEntryEnd to a, or returns FALSE when
// that has not run yet.
s32 TryGetRaceUpdateFramesSinceEntryEnd(u32 *framesOut);
// Stores the current mUpdateFrames in Race.mUpdateFramesAtEntryEnd; called when the end handler of the kart of the
// selected entry first runs.
u32 SetRaceUpdateFramesAtEntryEnd(void);
Race *SetRaceUpdateFramesUnlimited(void);
Camera *GetCurrentCamera(void);
unsigned int GetCurrentCameraKind(void);
MtxFx43 *GetCurrentViewMatrix(void);
unsigned int IsFadeFogActive(void);
void SetFadeFogHoldFramesToLimit(void);
void ClearFadeFogHoldFrames(void);
void StartFadeFog(void);
void BuildFadeFog(s32 fadeLevel, s32 flag);
void InitRaceFog(void);
// Returns Race.mUpdateFramesMod2; changes nothing.
unsigned int GetRaceUpdateFramesMod2(void);
// Returns Race.mUpdateFramesMod8; changes nothing.
unsigned int GetRaceUpdateFramesMod8(void);
// Returns Race.mUpdateFramesModKartCount; changes nothing.
unsigned int GetRaceUpdateFramesModKartCount(void);
unsigned int GetRaceUpdateFrames(void);
// Sets Race.mStarted to 1 and starts the race clock (StartRaceClock); called once per race by UpdateRaceStartSequence
// when its mSequenceFrames is 180.
void StartRace(void);
// Returns Race.mStarted (1 once the race has started); changes nothing.
unsigned int IsRaceStarted(void);
void RaceSceneAdvanceNop(void);
void ReleaseRace(void);
void DrawRaceWorld(void);
// Sets the direction of light 0 that DrawRaceWorld gives to the 3D engine (Race.mLightVectorX, Y and Z) from a.
void SetRaceLightVector(const Vec3 *lightVector);
void DrawRace(void);
void UpdateRace(void);
void Init3dEngine(void);
void InitFrmVramManagers(void);
void InitRaceFields(void);
void InitRace(void);
unsigned int IsRaceAwardOrStaffRoll(void);
// Returns Race.mUseChainCameras: 1 for the kinds 3 to 5 of RaceSetup.mRaceKind, which other code also uses to tell
// those kinds apart; changes nothing.
unsigned int GetRaceUseChainCameras(void);

extern u16 gFadeFogRemaining;
extern s16 gToonTableFramesLimit;
extern Vec3 gRaceLightVector;
extern const u16 gToonTableFirstColors[8];
extern const u16 gToonTableSecondColors[8];

// A WiFi race counts up to this many frames of RaceInfo.mUpdateFrames before the limit is reached.
#define RACE_WIFI_UPDATE_FRAMES_LIMIT 128
