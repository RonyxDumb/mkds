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
extern s16 data_021614b4[];
extern s16 data_021615b8[];
extern s32 gLastSentChunkIndex;
extern u32 gLastSentBlockId;
extern s32 gPrevSentChunkIndex;
extern s32 gLastReplyIndex;
extern u32 gOwnIndex;
extern const char data_02161e64[];
extern const char data_02161e7c[];
extern const char data_02161e94[];
extern const char data_02161eac[];
extern const char data_02161ec4[];
extern const char data_02161edc[];

extern u32 (*data_021619ec)(s32 a, s32 b, s32 c);
extern u32 (*data_021619f4)(s32 a, s32 b, s32 c);
extern void (*data_02161ac0[])(s32 a, s32 b, s32 c, s32 d);
extern void (*data_02161ac8[])(s32 a, s32 b, void *c);
extern Vec3s16 data_02161ad0;

extern u8 data_02161ad8;

extern u8 gPitchRiseAboveLimitDivisor[];
extern u8 gPitchFallDivisor[];
extern u8 gPitchRiseDivisor[];

// Seven word tables, entries 0x1c bytes apart, indexed by the result of GetKartSoundTableRow.
extern u8 data_02161ae8[];
extern u8 data_02161aec[];
extern u8 data_02161af0[];
extern u8 data_02161af4[];
extern u8 data_02161af8[];
extern u8 data_02161afc[];
extern u8 data_02161b00[];

// Base address >> 12 of the first bank of each texture palette mask, indexed by mask >> 4 (8 halfwords).
extern u16 gTexturePaletteBaseTable[];
// 16 rows of 3 halfwords per texture bank mask: first run base >> 12, second run base >> 12, first run size >> 12.
extern u8 gTextureBlockTable[];
extern u8 data_021616ce[];
extern u8 data_021616d0[];

extern u32 data_021617d0;
extern NNSG3dAnmObjInitFunc data_021617f4[];
extern BOOL (*data_021617f0)(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);
extern BOOL (*data_021617ec)(NNSG3dJntAnmResult *, const NNSG3dAnmObj *, u32);
extern BOOL (*data_021617e8)(NNSG3dVisAnmResult *, const NNSG3dAnmObj *, u32);
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
extern s32 (*data_021619f0)(u32);
extern s32 (*data_021619f8)(u32);

extern void (*data_021617d4)(void *, NNSG3dAnmObj *, u32);
extern void (*data_021617d8)(void *, NNSG3dAnmObj *, u32);
extern void (*data_021617dc)(void *, NNSG3dAnmObj *, u32);
extern void (*data_021617e0)(void *, NNSG3dAnmObj *, u32);
extern void (*data_021617e4)(void *, NNSG3dAnmObj *, u32);
extern u32 (*data_021619ec)();
extern u32 (*data_021619f4)();

extern const char gSelectCharacterGpMNcgrName[];
extern const char gSelectCharacterGpMNcerName[];
extern const char gSelectCharacterGpMONclrName[];
extern const char gSelectCharacterGpMBnclName[];
extern const char gSelectCharacterGpTitleMNcgrName[];
extern const char gSelectCharacterGpTitleMNcerName[];
extern const char gSelectCharacterGpTitleMBnclName[];
extern const char gSelectCharacterGpNameMNcgrName[];
extern const char gSelectCharacterGpNameMNcerName[];
extern const char gSelectCharacterGpNameMBnclName[];
extern const char gSelectCharacterSNcgrName[];
extern const char gSelectCharacterSNcerName[];
extern const char gSelectCharacterSONclrName[];
extern const char gSelectCharacterSBnclName[];
extern const char gSelectCharacterSBnblName[];

extern void (*NNS_G3dSendJointSRT_FuncArray[])(NNSG3dJntAnmResult *);
extern void (*NNS_G3dGetJointScale_FuncArray[])(NNSG3dJntAnmResult *, void *, u8 *, u32);
extern void (*NNS_G3dFuncSbcMatTable[])(NNSG3dRS *, u32, void *, u32);
extern void (*NNS_G3dFuncSbcShpTable[])(NNSG3dRS *, u32, void *, u32);
extern void (*NNS_G3dFuncSbcTable[])(NNSG3dRS *, u32);

// Strings from gKartSelectBmgName on.
extern const char gKartSelectBmgName[];
extern const char gSelectCharacterGpMNcgrName2[];
extern const char gSelectCharacterGpMNcerName2[];
extern const char gSelectCharacterGpMONclrName2[];
extern const char gSelectCharacterGpMBnclName2[];
extern const char gSelectCharacterGpTitleMNcgrName2[];
extern const char gSelectCharacterGpTitleMNcerName2[];
extern const char gSelectCharacterGpTitleMBnclName2[];
extern const char gSelectCharacterGpNameMNcgrName2[];
extern const char gSelectCharacterGpNameMNcerName2[];
extern const char gSelectCharacterGpNameMBnclName2[];
extern const char gSelectKartSBNcgrName[];
extern const char gSelectKartSBNclrName[];
extern const char gSelectKartSNscrName[];
extern const char gSelectKartSNcgrName[];
extern const char gSelectKartSNcerName[];
extern const char gSelectKartSONclrName[];
extern const char gSelectKartSBnclName[];
extern const char gSelectKartSBnllName[];
extern const char gSelectKartSBnblName[];
extern const char gCommonBmgName2[];
extern const char data_usa_0216212c[];
