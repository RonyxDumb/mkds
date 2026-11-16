#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02147cd8.h" // Vec3s16
#include "Main/Unknown/code_020846c0.h" // Nsbmd

// Object at crsmdl_sState: two Nsbmd pointers, then the words and halfwords the code tests. The flag halfwords
// live inside the embedded animation objects. 0xf4 is the distance to the next symbol, so the object overlaps four
// other symbols: data_0217abcc at +0xb0 and the embedded objects data_0217ab24 at +8, data_0217ab5c at +0x40
// and data_0217ab94 at +0x78 (USA).
typedef struct CourseModels {
    /* 00 */ Nsbmd *mNsbmd;
    // NULL when '/course_model_V.nsbmd' is absent; drawn before the NitroMain model under the other projection argument.
    /* 04 */ Nsbmd *mVNsbmd;
    /* 08 */ u8 field8[0xc];
    /* 14 */ s32 mNsbtpFrameIndex;
    /* 18 */ u8 field18[8];
    /* 20 */ u16 mNsbtpAnmObjCount;
    /* 22 */ u8 field22[0x36];
    /* 58 */ u16 mNsbtaAnmObjCount;
    /* 5a */ u8 field5A[0x36];
    /* 90 */ u16 mVNsbtaAnmObjCount;
    /* 92 */ u8 field92[0x4e];
    /* e0 */ BOOL mRestoreFogEnableFlags;
    /* e4 */ u64 mSavedFogEnableFlags;
    /* ec */ BOOL mRestoreVFogEnableFlags;
    /* f0 */ u16 mSavedVFogEnableFlags;
} CourseModels;

// What func_020636f8 writes from 0x08 of the Unk0217aa14_754_04 it points to.
typedef struct Unk020636f8_B {
    /* 00 */ s16 field0;
    /* 02 */ s16 field2;
    /* 04 */ s16 field4;
    /* 06 */ s16 field6;
    /* 08 */ s16 field8;
    /* 0a */ u16 fieldA;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
} Unk020636f8_B;

extern CourseModels crsmdl_sState;
extern u8 data_0217ab24[];
extern u8 data_0217ab5c[];
extern u8 data_0217ab94[];
extern MtxFx43 data_0217abcc;

extern const char aCourse_model_n[];
extern const char aCourse_model_0[];
extern const char aCourse_model_1[];
extern const char aCourse_model_2[];
extern const char aCourse_model_v[];
extern const char aCourse_model_5[];
extern const char aCourse_model_3[];
extern const Vec3s16 crsmdl_sKoopaCrsLight2Dir;
extern const u32 crsmdl_sFalls01Mat[];
extern const u32 crsmdl_sShdwOff5Mat[];
extern const u32 crsmdl_sShdwOff4Mat[];
extern const u32 crsmdl_sShdwOff1Mat[];
extern const u32 crsmdl_sShdwOff2Mat[];
extern const u32 crsmdl_sShdwOff3Mat[];
extern const u32 crsmdl_sShdwOffMat[];
extern const u32 crsmdl_sYoganMat[];
extern const u32 crsmdl_sFalls02Mat[];
extern u32 crsmdl_sModelScale[];

s32 crsmdl_getNsbtpProgress(void);
void crsmdl_setFogFlags(u32 flag);
void crsmdl_setupFog(void);
void crsmdl_setupLights(void);
void crsmdl_renderSky(void);
void crsmdl_renderCourse(void);
void crsmdl_update(void);
void crsmdl_init(void *heap);
void func_020636f8(Kart *kart);
void func_020637c4(Kart *kart);
void func_020637e0(Kart *kart);
void func_02063830(Kart *kart);
void func_02063880(Kart *kart);
