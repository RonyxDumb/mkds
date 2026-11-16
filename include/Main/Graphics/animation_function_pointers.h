#pragma once
#include "types.h"

typedef struct NNSG3dRS NNSG3dRS;

typedef struct NNSG3dAnmObj NNSG3dAnmObj;

typedef struct NNSG3dAnmObjInitFunc NNSG3dAnmObjInitFunc;

typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;

typedef struct NNSG3dJntAnmResult NNSG3dJntAnmResult;

typedef struct NNSG3dVisAnmResult NNSG3dVisAnmResult;

typedef struct Vec3s16 Vec3s16;


extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(s32 szByte, s32 is4x4comp, s32 opt);

extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(s32 szByte, s32 is4pltt, s32 opt);




// Three rows of seven sound ids (0x1c bytes each), selected by the result of GetKartSoundTableRow.
extern s32 gKartSoundRowSoundIds[3][7];

extern u32 NNS_G3dAnmFmtNum;

extern NNSG3dAnmObjInitFunc NNS_G3dAnmObjInitFuncArray[];

extern BOOL (*NNS_G3dFuncBlendMatDefault)(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);

extern BOOL (*NNS_G3dFuncBlendJntDefault)(NNSG3dJntAnmResult *, const NNSG3dAnmObj *, u32);

extern BOOL (*NNS_G3dFuncBlendVisDefault)(NNSG3dVisAnmResult *, const NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmVisNsBvaDefault)(void *, NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmJntNsBcaDefault)(void *, NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmMatNsBtaDefault)(void *, NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmMatNsBtpDefault)(void *, NNSG3dAnmObj *, u32);

extern void (*NNS_G3dFuncAnmMatNsBmaDefault)(void *, NNSG3dAnmObj *, u32);

extern u32 (*NNS_GfdDefaultFuncAllocTexVram)();

extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)();

