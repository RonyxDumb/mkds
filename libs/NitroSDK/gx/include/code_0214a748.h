#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

// Sixteen words written by G3i_OrthoW_ and G3i_FrustumW_.
typedef struct Unk0214ad4c {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ s32 field28;
    /* 2c */ s32 field2C;
    /* 30 */ s32 field30;
    /* 34 */ s32 field34;
    /* 38 */ s32 field38;
    /* 3c */ s32 field3C;
} Unk0214ad4c;

void G3X_SetFogTable(const void *fogTable);
s32 G3X_GetVectorMtx(void *m);
s32 G3X_GetClipMtx(void *m);
void G3X_SetFog(s32 enable, u32 fogMode, u32 fogSlope, u32 fogOffset);
void G3X_ResetMtxStack(void);
void G3X_InitMtxStack(void);
void G3X_ClearFifo(void);
void G3X_Reset(void);
void G3X_Init(void);
void G3i_LookAt_(const Vec3 *camPos, const Vec3 *camUp, const Vec3 *target, int draw, MtxFx43 *mtx);
void G3i_OrthoW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                 Unk0214ad4c *mtx);
void G3i_FrustumW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                   Unk0214ad4c *mtx);
