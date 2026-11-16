#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fixed_vector_math.h" // Vec3s16
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/Kart/kart_participant_record.h" // ParticipantKartRecord
#include "Main/Graphics/model_animation.h" // ModelAnimation

// Object at g_CourseHolder: two Nsbmd pointers, the three animation objects and the draw matrix, then the fog flags.
typedef struct CourseModels {
    /* 00 */ Nsbmd *mNsbmd;
    // NULL when '/course_model_V.nsbmd' is absent; drawn before the NtrMain model under the other projection argument.
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

extern CourseModels g_CourseHolder;


s32 GetCourseAnimNsbtpSomeValue(void);
void SetCourseModelsFogEnableFlags(u32 flag);
void InitCourseModelsFogEnableFlags(void);
void SetKoopaCourseLight2(void);
void DrawCourseModelV(void);
void DrawCourseModel(void);
void HandleCourseAnim(void);
void LoadCourseModelsAnimations(void *heap);
void WriteKartToParticipantRecord(Kart *kart);
void MQ_FnPtr4_Net_3(Kart *kart);
void MQ_FnPtr3_Net_3(Kart *kart);
void MQ_FnPtr3_Net_Not3(Kart *kart);
void MQ_FnPtr4_Net_Not3(Kart *kart);

extern char g_str_course_model_nsbta[20];
extern Vec3s16 gKoopaCourseLight2Vector;
extern const u32 g_str_ShdwOff3[4];
extern const u32 g_str_ShdwOff1[4];
extern char g_str_course_model_nsbtp[20];
extern const u32 g_str_ShdwOff2[4];
extern char g_str_course_model_V_nsbmd[22];
extern char g_str_course_model_V_nsbtx[22];
extern const u32 g_str_yogan[4];
extern const u32 g_str_ShdwOff4[4];
extern const u32 g_str_ShdwOff5[4];
extern char g_str_course_model_nsbmd[20];
extern Vec3 g_MaybeAwardPositionTable[3];
extern const u32 g_str_falls_02[4];
extern char g_str_course_model_V_nsbta[22];
extern const u32 g_str_falls_01[4];
extern const u32 g_str_ShdwOff[4];
extern char g_str_course_model_nsbtx[20];
