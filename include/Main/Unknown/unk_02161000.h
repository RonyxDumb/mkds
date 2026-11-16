#pragma once

#include "types.h"

typedef struct Unk02170500 Unk02170500;
typedef struct NNSG3dAnmObj NNSG3dAnmObj;
typedef struct NNSG3dAnmObjInitFunc NNSG3dAnmObjInitFunc;
typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;
typedef struct NNSG3dJntAnmResult NNSG3dJntAnmResult;
typedef struct NNSG3dVisAnmResult NNSG3dVisAnmResult;
typedef struct Vec3s16 Vec3s16;

// Objects whose layout isn't known yet.
extern s16 FX_AtanTable_[];
extern s16 FX_AtanIdxTable_[];
extern s32 gLastSentChunkIndex;
extern u32 gLastSentBlockId;
extern s32 gPrevSentChunkIndex;
extern s32 gLastReplyIndex;
extern u32 gOwnIndex;
extern u16 data_02161790;
extern u16 data_02161794;
extern u16 data_02161798;
extern u16 data_0216179c;
extern const char aSelect_kart_s_b_ncgr[];
extern const char aSelect_kart_s_nce_ncgr[];
extern const char aSelect_kart_s_nce_ncer[];
extern const char aSelect_kart_s_o_nclr[];
extern const char aSelect_kart_s_b_nclr[];
extern const char aSelect_kart_s_nscr[];

extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(s32 a, s32 b, s32 c);
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(s32 a, s32 b, s32 c);
extern void (*spa_sDrawFuncs[])(s32 a, s32 b, s32 c, s32 d);
extern void (*spa_sMtxFuncs[])(s32 a, s32 b, void *c);
extern Vec3s16 spa_sUpVector;

extern u8 data_02161ad8;

extern u8 data_02161adc[];
extern u8 data_02161ae0[];
extern u8 data_02161ae4[];

// Seven word tables, entries 0x1c bytes apart, indexed by the result of func_0202578c.
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
extern void (*NNS_GfdDefaultFuncFreeTexVram)(void *);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(void *);

extern UnkFunc *NNS_G3dFuncAnmVisNsBvaDefault;
extern UnkFunc *NNS_G3dFuncAnmJntNsBcaDefault;
extern UnkFunc *NNS_G3dFuncAnmMatNsBtaDefault;
extern UnkFunc *NNS_G3dFuncAnmMatNsBtpDefault;
extern UnkFunc *NNS_G3dFuncAnmMatNsBmaDefault;
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)();
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)();

extern const char aSelect_character_gp_m_nce_ncgr_0[];
extern const char aSelect_character_gp_m_nce_ncer_0[];
extern const char aSelect_character_gp_m_o_nclr_0[];
extern const char aSelect_character_gp_m_bncl[];
extern const char aSelect_character_gp_title_m_nce_ncg_0[];
extern const char aSelect_character_gp_title_m_nce_nce_0[];
extern const char aSelect_character_gp_title_m_bncl[];
extern const char aSelect_character_gp_name_m_nce_ncgr_0[];
extern const char aSelect_character_gp_name_m_nce_ncer_0[];
extern const char aSelect_character_gp_name_m_bncl[];
extern const char aSelect_character_s_nce_ncgr_0[];
extern const char aSelect_character_s_nce_ncer_0[];
extern const char aSelect_character_s_o_nclr_0[];
extern const char aSelect_character_s_bncl[];
extern const char aSelect_character_s_bnbl[];

extern void (*data_02161844[])(NNSG3dJntAnmResult *);
extern void (*data_02161850[])(NNSG3dJntAnmResult *, void *, u8 *, u32);
extern void (*NNS_G3dFuncSbcMatTable[])(Unk02170500 *, u32, void *, u32);
extern void (*NNS_G3dFuncSbcShpTable[])(Unk02170500 *, u32, void *, u32);
extern void (*NNS_G3dFuncSbcTable[])(Unk02170500 *, u32);

// Strings from aKart_select_bmg on.
extern const char aKart_select_bmg[];
extern const char aSelect_character_gp_m_nce_ncgr_1[];
extern const char aSelect_character_gp_m_nce_ncer_1[];
extern const char aSelect_character_gp_m_o_nclr_1[];
extern const char aSelect_character_gp_m_bncl_0[];
extern const char aSelect_character_gp_title_m_nce_ncg_1[];
extern const char aSelect_character_gp_title_m_nce_nce_1[];
extern const char aSelect_character_gp_title_m_bncl_0[];
extern const char aSelect_character_gp_name_m_nce_ncgr_1[];
extern const char aSelect_character_gp_name_m_nce_ncer_1[];
extern const char aSelect_character_gp_name_m_bncl_0[];
extern const char aSelect_kart_s_b_ncgr_0[];
extern const char aSelect_kart_s_b_nclr_0[];
extern const char aSelect_kart_s_nscr_0[];
extern const char aSelect_kart_s_nce_ncgr_0[];
extern const char aSelect_kart__3[];
extern const char aSelect_kart__2[];
extern const char aSelect_kart__1[];
extern const char aSelect_kart__0[];
extern const char aSelect_kart_s_[];
extern const char aCommon_bmg_14[];
extern const char aMission_mr[];
