#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_021445e0.h"

typedef struct Unk021da2a8 {
    /* 0000 */ void *field0;
    /* 0004 */ u16 field4;
    /* 0006 */ u8 pad_06[2];
    /* 0008 */ u32 field8;
    /* 000c */ u16 fieldC;
    /* 000e */ u16 fieldE;
    /* 0010 */ u16 field10;
    /* 0012 */ u16 field12;
    /* 0014 */ u16 field14;
    /* 0016 */ u16 field16;
    /* 0018 */ u16 field18;
    /* 001a */ u8 pad_1a[0x18];
    /* 0032 */ u16 field32;
    /* 0034 */ u16 field34;
    /* 0036 */ u16 field36;
    /* 0038 */ u8 pad_38[8];
    /* 0040 */ s32 field40;
    /* 0044 */ u32 field44;
    /* 0048 */ u32 field48;
    /* 004c */ s32 (*field4C)(Unk021425e8 *);
    /* 0050 */ u16 field50;
    /* 0052 */ u16 field52;
    /* 0054 */ s32 field54;
    /* 0058 */ u32 field58;
    /* 005c */ u16 field5C;
    /* 005e */ u16 field5E;
    /* 0060 */ u16 field60;
    /* 0062 */ u8 pad_62[0x1e];
    /* 0080 */ u8 field80[0xf00];
    /* 0f80 */ u8 fieldF80[0xe0];
    /* 1060 */ u8 field1060[0x240];
    /* 12a0 */ u32 field12A0;
    /* 12a4 */ u32 field12A4;
    /* 12a8 */ u8 pad_12a8[0x100];
    /* 13a8 */ u32 field13A8;
    /* 13ac */ u32 (*field13AC)(void *, struct Unk021da2a8 *);
    /* 13b0 */ u32 field13B0;
    /* 13b4 */ u8 pad_13b4[0xc];
    /* 13c0 */ u8 field13C0[0x20];
    /* 13e0 */ WMDataSharingInfo field13E0;
    /* 1c00 */ WMDataSet field1C00;
    /* 1e00 */ WMDataSharingInfo field1E00;
} Unk021da2a8;

extern Unk021da2a8 *data_ov003_021da2a8;

u32 func_ov003_021cfa68(void);
void func_ov003_021cfaa8(void);
void func_ov003_021cfb80(void);
BOOL func_ov003_021cfb98(void *a);
u8 *func_ov003_021cfc1c(u32 a);
void func_ov003_021cfc40(u32 a);
BOOL func_ov003_021cfc4c(u32 a, u16 b, u16 c);
void func_ov003_021cfd44(Unk021425e8 *a);
BOOL func_ov003_021cfd88(void);
void func_ov003_021cfdc8(Unk021425e8 *event);
BOOL func_ov003_021cfde4(void);
int func_ov003_021cfe40(u16 c);
u16 func_ov003_021cfed8(void);
int func_ov003_021cff38(Unk021425e8Func a, u16 b);
void func_ov003_021cff50(Unk021425e8 *param_1);
u32 func_ov003_021cfff8(u16 param_1);
BOOL func_ov003_021d0078(void);
u32 func_ov003_021d010c(void);
u16 func_ov003_021d0118(void);
void func_ov003_021d0128(u32 a);
void func_ov003_021d0134(Unk021425e8 *a);
void func_ov003_021d0158(Unk021425e8 *event);
BOOL func_ov003_021d0180(void);
void func_ov003_021d01ac(Unk021425e8 *event);
BOOL func_ov003_021d01cc(void);
void func_ov003_021d0200(Unk021425e8 *event);
BOOL func_ov003_021d022c(void);
BOOL func_ov003_021d0258(void);
void func_ov003_021d02a0(Unk021425e8 *event);
BOOL func_ov003_021d02c0(void);
void func_ov003_021d02e8(Unk021425e8 *event);
BOOL func_ov003_021d032c(void);
BOOL func_ov003_021d0358(void);
BOOL func_ov003_021d0388(void);
void func_ov003_021d03c0(Unk021425e8 *event);
BOOL func_ov003_021d04a8(void);
void func_ov003_021d0530(Unk021425e8 *event);
BOOL func_ov003_021d0630(void);
void func_ov003_021d0680(Unk021425e8 *event);
BOOL func_ov003_021d06b0(void);
void func_ov003_021d0708(Unk021425e8 *event);
BOOL func_ov003_021d0760(void);
void func_ov003_021d079c(s32 value);
void func_ov003_021d07b0(u32 value);
void func_ov003_021d0810(Unk021da2a8 *a);
