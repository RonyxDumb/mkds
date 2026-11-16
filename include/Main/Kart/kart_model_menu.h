#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h" // Camera, KartModelMenuData
#include "Main/Kart/point_link_cursor.h"
#include "Main/Kart/camera.h"
#include "model_material_set.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/character_animation.h"
#include "Main/Graphics/font_and_player_character.h"

// A sequence camera: its course map camera entry, the position curve, its reverse and the step along it.
typedef struct SequenceCameraEntry {
    /* 00 */ CourseMapCamera *mCourseMapCamera;
    /* 04 */ PosCurve mPosCurve;
    /* 40 */ PosCurve mReversePosCurve;
    /* 7c */ s16 mPosCurveStep;
    /* 7e */ s16 mUnk_7e;
    /* 80 */ s32 mUnk_80;
    /* 84 */ s32 mUnk_84;
} SequenceCameraEntry;

extern const s32 gCameraDefaultRows[2][3];

void StructHD_SomeLookAt(Camera *camera);
void StructHD_SomeFn_10(Camera *camera);
void StructHD_SomeFn_2(Camera *camera);
void StructHD_SomeFn(Camera *camera);
// Allocates g_GlobalHD (0x270 bytes), sets g_GlobalHD2 to NULL, runs StructHD_SomeFn, sets mKind 2, starts it
// at CourseMap.mFirstChainStartEntry and sets up its mPosCurve when the entry has a group. With no entry it sets
// g_GlobalMV.mCameraChainEnded to 1 and returns. InitializeGlobalTD calls it when g_GlobalCO.mRaceKind is 4.
void CreateGlobalHD_HD2_from_thumb(void);
// Allocates g_GlobalHD and g_GlobalHD2 (0x270 bytes each), runs StructHD_SomeFn on both, sets mKind 2, starts
// them at CourseMap.mFirstChainStartEntry and mSecondChainStartEntry and sets up their mPosCurve when the entries have
// a group. With no first entry it sets g_GlobalMV.mCameraChainEnded to 1 and returns. InitializeGlobalTD calls it when
// g_GlobalCO.mRaceKind is 3 or 5.
void CreateGlobalHD_HD2_V2_from_thumb(void);
void InitSequenceCameraEntry(SequenceCameraEntry *kind7Entry, CourseMapCamera *courseMapCamera);
void CreateAnotherGlobalHD_from_thumb(u32 followedKartIndex);
// Allocates the chase camera (g_GlobalHD5), sets it up behind the selected Kart (SetupCameraBehindKart), keeps that
// Kart's forward vector in mSavedKartForward and refreshes the projection.
void CreateGlobalHD5_from_thumb(void);
void InitCameraGlobals(void);
void ReadEmblemPalette_from_thumb(void *section);
u16 GetKartListCount(void);
u16 GetKartListNumber(void);
BOOL FindKartModelMenuCharacter(s32 *characterIndex, u32 kartIndex);
void ClearKartModelMenuRequests(void);
void QueueKartModelMenuLoad(void);

extern u16 gKartModelMenuLightLevel;
extern u16 gKartModelMenuTiltAngleOffset;
extern s32 gKartModelMenuMaxScale;
extern s32 gKartModelMenuScaleFactor;
extern u32 gKartModelMenuSpinStep;
extern s32 gKartModelMenuLookAtYOffset;
extern Vec3 gKartModelMenuLookAtTarget;
extern Vec3 gKartModelMenuCameraPosition;
extern Vec3 gKartModelMenuLightDirection;
extern char g_str_emblem_s_b_NCLR[16];
extern char g_str_kartoffsetdata_bin_0[20];
extern char g_str_charmenuparam_bin[20];
extern char g_str_kartmenuparam_bin[20];
extern char g_str_kart_select_select_nsbmd[28];
extern char g_str_kart_select_select_nsbtx[28];

extern NNSG3dResMatData *gSpecialKartBodyMaterial;
extern struct KartModels *g_GlobalAD00;
extern struct Nclr *g_EmblemPalettte;
extern KartModelMenuData *g_GlobalCE;

// Far plane the camera starts with and falls back to when the course setting is below 1.0 (1600 in fixed-point).
#define CAMERA_DEFAULT_FAR TO_FIXED12(1600)
