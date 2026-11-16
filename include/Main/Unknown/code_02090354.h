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
    // State of sman_update: 0 at rest, 1 top goes up and down, 2 waits, 3 both parts come back;
    // sman_onDriverCollide and sman_onItemCollide set 1.
    /* c8 */ s32 mState;
} Sman;

// Array of Sman pointers at 0x00, its count at 0x04.
typedef struct SmanList {
    /* 00 */ Sman **mSmans;
    /* 04 */ u16 mSmanCount;
} SmanList;

void mgenit_setupFunctions(void);
s32 func_020905a8(KartKillerCursor *kartKillerCursor);
void TurnKartKillerTowardPointLink(KartKillerCursor *kartKillerCursor);
void AdvanceKartKillerAlongPointLinks(KartKillerCursor *kartKillerCursor);
s32 func_0209081c(KartKillerCursor *kartKillerCursor);
void kill_recalculateRoute(KartKillerCursor *kartKillerCursor, Unk02080b1c_00 *link);
void SetupKartKillerCursor(KartKillerCursor *kartKillerCursor, u32 kartIndex);
BOOL unlock_isFasterThanStaffGhost(u32 entryNumber, void *time);
void unlock_loadStaffGhostTime(void *heap);
BOOL unlock_hasUnlockedTrueTitleScreen(void);
s32 unlock_hasUnlockedTrueStaffRoll(void);
u32 unlock_tryUnlockCharacters(void);
u32 unlock_tryUnlockCups(void);
u32 unlock_tryUnlock(void);
u32 unlock_tryUnlock2(void);
u32 unlock_updateUnlocks(void);
void *sman_setupLogicPart(void);
void *sman_setupBottomRenderPart(void);
void *sman_setupTopRenderPart(void);
void sman_setupConfig(void);
void sman_update(void *a, Sman *sman); /* skipped for objects with mFlags & 4 (parked pool objects) */
void sman_globalLogicInit(SmanList *smanList);
void sman_renderBottom(void *mapObjectList, Sman *sman);
void sman_applyBottomMaterial(void *a);
void sman_loadBottomModel(void *a);
void sman_renderTop(void *mapObjectList, Sman *sman);
void sman_applyTopMaterial(void *a);
void sman_loadTopModel(void *a);
