#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // Camera, KartModelMenuData
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_02073eb8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020799a0.h"
#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_02077bc0.h"

// 0x88-byte object built from an entry of the table at CourseMap.mCameras: the entry, two PosCurve and two
// halfwords.
typedef struct Unk02077750 {
    /* 00 */ CourseMapCamera *mUnk_00;
    /* 04 */ PosCurve mUnk_04;
    /* 40 */ PosCurve mUnk_40;
    /* 7c */ s16 mUnk_7c;
    /* 7e */ s16 mUnk_7e;
    /* 80 */ s32 mUnk_80;
    /* 84 */ s32 mUnk_84;
} Unk02077750;

// Declared here until the code that defines them is decompiled.
extern const char aEmblem_s_b_ncl[];

void cam_updateLookAtEx(Camera *camera);
void cam_updateLookAt(Camera *camera);
void cam_updateFrustum(Camera *camera);
void cam_init(Camera *camera);
// Allocates cam_sIntroCameraTop (0x270 bytes), sets cam_sIntroCameraBottom to NULL, runs cam_init, sets mKind 2, starts it
// at CourseMap.mFirstChainStartEntry and sets up its mPosCurve when the entry has a group. With no entry it sets
// gRaceStatus->mUnk_4d0 to 1 and returns. race_init calls it when gRaceMultiConfig->mUnk_00c is 4.
void cam_setupIntroCamSingle(void);
// Allocates cam_sIntroCameraTop and cam_sIntroCameraBottom (0x270 bytes each), runs cam_init on both, sets mKind 2, starts
// them at CourseMap.mFirstChainStartEntry and mSecondChainStartEntry and sets up their mPosCurve when the entries have
// a group. With no first entry it sets gRaceStatus->mUnk_4d0 to 1 and returns. race_init calls it when
// gRaceMultiConfig->mUnk_00c is 3 or 5.
void cam_setupIntroCamDouble(void);
void cam_2077750(Unk02077750 *a, CourseMapCamera *courseMapCamera);
void cam_20777AC(u32 followedKartIndex);
// Allocates the chase camera (cam_sPlayerCamera), sets it up behind the selected Kart (cam_resetPlayerCamera), keeps that
// Kart's forward vector in mSavedKartForward and refreshes the projection.
void cam_setupPlayerCamera(void);
void cam_setupRaceParams(void);
void LoadEmblemSBNclr(void *a);
u16 GetKartListCount(void);
u16 func_02077a5c(void);
BOOL func_02077a70(s32 *characterIndex, u32 kartIndex);
void ClearKartModelMenuRequests(void);
void SPM_2077B3C(void);
