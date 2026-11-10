#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime
#include "Main/Unknown/code_02080b1c.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Sman: a map object of kind 0x19d in two parts (top and bottom models); state 1 sends the top up and down while the
// bottom part's scale drops to 0, and later both parts come back.
typedef struct Sman {
    /* 00 */ MapObject mMapObject;
    // The angle changes only while this is non-zero (states 0 and 3).
    /* a0 */ s32 mAngleZEnabled;
    /* a4 */ s32 mAngleZ;
    /* a8 */ s32 mAngleZPerFrame;
    // Counted in states 2 and 3 only.
    /* ac */ s32 mStateFrames;
    /* b0 */ s32 mTopRiseProgress;
    /* b4 */ s32 mBottomScale;
    /* b8 */ s32 mTopHeight;
    /* bc */ s32 mTopHeightPerFrame;
    /* c0 */ s32 mTopStartHeight;
    /* c4 */ s32 mTopLowHeight;
    // State of UpdateSman: 0 at rest, 1 top goes up and down, 2 waits, 3 both parts come back;
    // CollideKartWithSman and CollideItemObjectWithSman set 1.
    /* c8 */ s32 mState;
} Sman;

// Array of Sman pointers at 0x00, its count at 0x04.
typedef struct SmanList {
    /* 00 */ Sman **mSmans;
    /* 04 */ u16 mSmanCount;
} SmanList;

void SetupBattleItemEntries(void);
BOOL AdvanceKartKillerEndCount(KartKillerCursor *kartKillerCursor);
void TurnKartKillerTowardPointLink(KartKillerCursor *kartKillerCursor);
void AdvanceKartKillerAlongPointLinks(KartKillerCursor *kartKillerCursor);
BOOL AdvanceKartKillerCursor(KartKillerCursor *kartKillerCursor);
void ResetKartKillerCursorTo(KartKillerCursor *kartKillerCursor, RacePointLink *link);
void SetupKartKillerCursor(KartKillerCursor *kartKillerCursor, u32 kartIndex);
BOOL IsTimeLessThanStaffGhostTime(u32 entryNumber, MinuteSecondMillisecondTime *time);
void LoadStaffGhostTime(void *heap);
BOOL IsAllGrandPrixRecordsTopRank(void);
s32 GetStaffRollKindAfterGp(void);
u32 SetSecretMessageFlagsFromCups3And7(void);
u32 SetSecretMessageFlagsPerEngineClass(void);
u32 SetSecretMessageFlags(void);
u32 SetSecretMessageFlagsWrapper(void);
u32 SetAndWriteSecretMessageFlags(void);
void *CreateSmanUpdateList(void);
void *CreateSmanBottomDrawList(void);
void *CreateSmanTopDrawList(void);
void CreateSmanKindData(void);
void UpdateSman(void *mapObjectList, Sman *sman); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitSmanObjects(SmanList *smanList);
void DrawSmanBottom(void *mapObjectList, Sman *sman);
void SetupDrawSmanBottom(void *mapObjectList);
void CreateSmanBottom(void *mapObjectList);
void DrawSmanTop(void *mapObjectList, Sman *sman);
void SetupDrawSmanTop(void *mapObjectList);
void CreateSmanTop(void *mapObjectList);
