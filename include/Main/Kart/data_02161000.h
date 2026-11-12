#pragma once
#include "types.h"

typedef struct NNSG3dRS NNSG3dRS;

typedef struct NNSG3dAnmObj NNSG3dAnmObj;

typedef struct NNSG3dAnmObjInitFunc NNSG3dAnmObjInitFunc;

typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;

typedef struct NNSG3dJntAnmResult NNSG3dJntAnmResult;

typedef struct NNSG3dVisAnmResult NNSG3dVisAnmResult;

typedef struct Vec3s16 Vec3s16;

// Objects whose layout isn't known yet.











extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(s32 a, s32 b, s32 c);

extern u32 (*data_021619f4)(s32 a, s32 b, s32 c);




// Seven word tables, entries 0x1c bytes apart, indexed by the result of GetKartSoundTableRow.
extern u8 data_02161ae8[];

extern u8 data_02161aec[];

extern u8 data_02161af0[];

extern u8 data_02161af4[];

extern u8 data_02161af8[];

extern u8 data_02161afc[];

extern u8 data_02161b00[];

extern u32 NNS_G3dAnmFmtNum;

extern NNSG3dAnmObjInitFunc NNS_G3dAnmObjInitFuncArray[];

extern BOOL (*NNS_G3dFuncBlendMatDefault)(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);

extern BOOL (*NNS_G3dFuncBlendJntDefault)(NNSG3dJntAnmResult *, const NNSG3dAnmObj *, u32);

extern BOOL (*NNS_G3dFuncBlendVisDefault)(NNSG3dVisAnmResult *, const NNSG3dAnmObj *, u32);

extern void (*NNS_G3dSendTexSRT_FuncArray[])(NNSG3dMatAnmResult *);

extern u32 data_0216186c[2];

extern u32 data_02161874[2];

extern s32 data_0216189c[16];

extern u32 data_021618dc[];

extern u32 data_021618e0[];

extern u32 data_021618e8[];

extern Vec3 data_0216190c;

extern Vec3 data_02161918;

extern u32 data_02161924[];

extern u32 data_02161928[];

extern Vec3 data_02161930[];

extern Vec3 data_02161954;

extern Vec3 data_02161960;

extern s32 (*NNS_GfdDefaultFuncFreeTexVram)(u32);

extern s32 (*data_021619f8)(u32);

extern void (*NNS_G3dFuncAnmVisNsBvaDefault)(void *, NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmJntNsBcaDefault)(void *, NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmMatNsBtaDefault)(void *, NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmMatNsBtpDefault)(void *, NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmMatNsBmaDefault)(void *, NNSG3dAnmObj *, u32);

extern u32 (*NNS_GfdDefaultFuncAllocTexVram)();

extern u32 (*data_021619f4)();
















extern void (*NNS_G3dSendJointSRT_FuncArray[])(NNSG3dJntAnmResult *);

extern void (*NNS_G3dGetJointScale_FuncArray[])(NNSG3dJntAnmResult *, void *, u8 *, u32);

extern void (*NNS_G3dFuncSbcMatTable[])(NNSG3dRS *, u32, void *, u32);

extern void (*NNS_G3dFuncSbcShpTable[])(NNSG3dRS *, u32, void *, u32);

extern void (*NNS_G3dFuncSbcTable[])(NNSG3dRS *, u32);






















