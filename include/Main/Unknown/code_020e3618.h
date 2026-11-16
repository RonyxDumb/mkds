#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e0680.h"

// Block of eleven words.
typedef struct Unk020e039c {
    /* 00 */ u32 field0[11];
} Unk020e039c;

// Object of kind 0xcc (Bridge) that bridge_init fills. Its draw callback bridge_render is typed Unk020e3ef4 (the family
// layout of kinds 0xcb, 0xce, 0xd0 and 0xd1); the model pointer at +0x140, written by dcol_setModel, lies inside
// field13C.
typedef struct Bridge {
    /* 000 */ MapObject field0;
    /* 0a0 */ Unk020e38a0_28 fieldA0;
    /* 0c4 */ Unk020e38a0_28 fieldC4;
    /* 0e8 */ Vec3 fieldE8;
    /* 0f4 */ Vec3 fieldF4;
    /* 100 */ s32 field100;
    /* 104 */ s32 field104;
    /* 108 */ s32 field108;
    /* 10c */ s32 field10C;
    /* 110 */ s32 field110;
    /* 114 */ Vec3 field114;
    /* 120 */ s32 field120;
    /* 124 */ Vec3 field124;
    /* 130 */ s32 field130;
    /* 134 */ s32 field134;
    /* 138 */ s32 field138;
    /* 13c */ u8 field13C[0x8];
    /* 144 */ u16 field144;
    /* 146 */ u16 field146;
    /* 148 */ u16 field148;
    /* 14a */ u16 field14A;
    /* 14c */ u16 field14C;
    /* 14e */ u16 field14E;
    /* 150 */ u16 field150;
    /* 152 */ u8 field152[0x2];
    /* 154 */ s32 field154;
} Bridge;

BOOL bridge_isBridge(u32 kind);
void bridge_loadModel(void); /* no argument; also gives the model to the registered objects (dcol_setModel) */
void bridge_init(Bridge *bridge, struct CourseMapRow *courseRow);
void *choro_setupConfig(void);
void *choro_setupMainRenderPart(void);
void *choro_setupShadowRenderPart(void);
void *choro_setupLogicPart(void);
void choro_applyMainMaterial(void);
void choro_renderMain(s32 a, Unk020e1e98 *choropu, s32 c, u16 alpha);
