#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fixed_vector_math.h" // Vec3s16
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/Kart/kart_participant_record.h" // ParticipantKartRecord
#include "Main/Graphics/model_animation.h" // ModelAnimation

// Object at gCourseModels: two Nsbmd pointers, the three animation objects and the draw matrix, then the fog flags.
typedef struct CourseModels {
    /* 00 */ Nsbmd *mNsbmd;
    // NULL when '/course_model_V.nsbmd' is absent; drawn before the main model under the other projection argument.
    /* 04 */ Nsbmd *mVNsbmd;
    /* 08 */ ModelAnimation mNsbtpAnimation;
    /* 40 */ ModelAnimation mNsbtaAnimation;
    /* 78 */ ModelAnimation mVNsbtaAnimation;
    /* b0 */ MtxFx43 mMatrix;
    /* e0 */ BOOL mRestoreFogEnableFlags;
    /* e4 */ u64 mSavedFogEnableFlags;
    /* ec */ BOOL mRestoreVFogEnableFlags;
    /* f0 */ u16 mSavedVFogEnableFlags;
} CourseModels;

extern CourseModels gCourseModels;


s32 GetCourseModelNsbtpFrame(void);
void SetCourseModelsFogEnableFlags(u32 flag);
void InitCourseModelsFogEnableFlags(void);
void SetKoopaCourseLight2(void);
void DrawCourseModelV(void);
void DrawCourseModel(void);
void UpdateCourseModels(void);
void InitCourseModels(void *heap);
void WriteKartToParticipantRecord(Kart *kart);
void AdvancePeerKartCollisionSlot(Kart *kart);
void AdvancePeerKartMotionSlot(Kart *kart);
void AdvanceLocalKartMotionSlot(Kart *kart);
void AdvanceLocalKartCollisionSlot(Kart *kart);

extern char gCourseModelNsbtaName[20];
extern Vec3s16 gKoopaCourseLight2Vector;
extern const u32 gCourseModelShdwOff3MaterialName[4];
extern const u32 gCourseModelShdwOff1MaterialName[4];
extern char gCourseModelNsbtpName[20];
extern const u32 gCourseModelShdwOff2MaterialName[4];
extern char gCourseModelVNsbmdName[22];
extern char gCourseModelVNsbtxName[22];
extern const u32 gCourseModelYoganMaterialName[4];
extern const u32 gCourseModelShdwOff4MaterialName[4];
extern const u32 gCourseModelShdwOff5MaterialName[4];
extern char gCourseModelNsbmdName[20];
extern Vec3 gKartAwardStartPositions[3];
extern const u32 gCourseModelFalls02MaterialName[4];
extern char gCourseModelVNsbtaName[22];
extern const u32 gCourseModelFalls01MaterialName[4];
extern const u32 gCourseModelShdwOffMaterialName[4];
extern char gCourseModelNsbtxName[20];
