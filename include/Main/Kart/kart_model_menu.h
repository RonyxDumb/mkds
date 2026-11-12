#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217a000.h" // Camera, KartModelMenuData
#include "Main/Kart/point_link_cursor.h"
#include "Main/Kart/camera.h"
#include "code_02012b30.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/character_animation.h"

// 0x88-byte object built from an entry of the table at CourseMap.mCameras: the entry, two PosCurve and two
// halfwords.
typedef struct Kind7CameraEntry {
    /* 00 */ CourseMapCamera *mCourseMapCamera;
    /* 04 */ PosCurve mPosCurve;
    /* 40 */ PosCurve mReversePosCurve;
    /* 7c */ s16 mPosCurveStep;
    /* 7e */ s16 mUnk_7e;
    /* 80 */ s32 mUnk_80;
    /* 84 */ s32 mUnk_84;
} Kind7CameraEntry;

extern const char data_usa_02165714[];
extern const s32 gCameraDefaultRows[2][3];

void UpdateCameraView(Camera *camera);
void UpdateCameraViewWithWorldUp(Camera *camera);
void RefreshCameraProjection(Camera *camera);
void SetupCamera(Camera *camera);
// Allocates gFirstChainCamera (0x270 bytes), sets gSecondChainCamera to NULL, runs SetupCamera, sets mKind 2, starts it
// at CourseMap.mFirstChainStartEntry and sets up its mPosCurve when the entry has a group. With no entry it sets
// gRaceProgress.mUnk_4d0 to 1 and returns. InitRace calls it when gRaceSetup.mUnk_00c is 4.
void CreateFirstChainCamera(void);
// Allocates gFirstChainCamera and gSecondChainCamera (0x270 bytes each), runs SetupCamera on both, sets mKind 2, starts
// them at CourseMap.mFirstChainStartEntry and mSecondChainStartEntry and sets up their mPosCurve when the entries have
// a group. With no first entry it sets gRaceProgress.mUnk_4d0 to 1 and returns. InitRace calls it when
// gRaceSetup.mUnk_00c is 3 or 5.
void CreateChainCameraPair(void);
void InitKind7CameraEntry(Kind7CameraEntry *kind7Entry, CourseMapCamera *courseMapCamera);
void CreateEntryCamera(u32 followedKartIndex);
// Allocates the chase camera (gChaseCamera), sets it up behind the selected Kart (SetupCameraBehindKart), keeps that
// Kart's forward vector in mSavedKartForward and refreshes the projection.
void CreateChaseCamera(void);
void InitCameraGlobals(void);
void LoadEmblemSBNclr(void *section);
u16 GetKartListCount(void);
u16 GetKartListNumber(void);
BOOL FindKartModelMenuCharacter(s32 *characterIndex, u32 kartIndex);
void ClearKartModelMenuRequests(void);
void QueueKartModelMenuLoad(void);
