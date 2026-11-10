#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02147cd8.h" // Vec3s16
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "Main/Unknown/code_020653d0.h" // ParticipantKartRecord
#include "Main/Unknown/code_02087d0c.h" // ModelAnimation

// Object at gCourseModels: two Nsbmd pointers, then the words and halfwords the code tests. The flag halfwords
// live inside the embedded animation objects.
typedef struct CourseModels {
    /* 00 */ Nsbmd *mNsbmd;
    // NULL when '/course_model_V.nsbmd' is absent; drawn before the main model under the other projection argument.
    /* 04 */ Nsbmd *mVNsbmd;
    /* 08 */ u8 mUnk_08[0xc];
    /* 14 */ s32 mNsbtpFrameIndex;
    /* 18 */ u8 mUnk_18[8];
    /* 20 */ u16 mNsbtpAnmObjCount;
    /* 22 */ u8 mUnk_22[0x36];
    /* 58 */ u16 mNsbtaAnmObjCount;
    /* 5a */ u8 mUnk_5a[0x36];
    /* 90 */ u16 mVNsbtaAnmObjCount;
    /* 92 */ u8 mUnk_92[0x4e];
    /* e0 */ BOOL mRestoreFogEnableFlags;
    /* e4 */ u64 mSavedFogEnableFlags;
    /* ec */ BOOL mRestoreVFogEnableFlags;
    /* f0 */ u16 mSavedVFogEnableFlags;
} CourseModels;

extern CourseModels gCourseModels;
extern ModelAnimation data_usa_0217ab04;
extern ModelAnimation data_0217ab5c;
extern ModelAnimation data_usa_0217ab74;
extern MtxFx43 data_usa_0217abac;

extern const char data_usa_02165404[];
extern const char data_usa_02165418[];
extern const char data_usa_0216542c[];
extern const char data_usa_02165440[];
extern const char data_usa_02165454[];
extern const char data_usa_0216546c[];
extern const char data_usa_02165484[];
extern const Vec3s16 data_usa_021653fc;
extern const u32 data_usa_02154990[];
extern const u32 data_usa_021549a0[];
extern const u32 data_usa_021549b0[];
extern const u32 data_usa_021549c0[];
extern const u32 data_usa_021549d0[];
extern const u32 data_usa_021549e0[];
extern const u32 data_usa_021549f0[];
extern const u32 data_usa_02154a00[];
extern const u32 data_usa_02154a10[];
extern u32 data_usa_02154a20[];

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
